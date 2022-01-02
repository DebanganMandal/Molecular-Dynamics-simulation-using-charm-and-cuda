class AtomInfo;
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "md_charm.decl.h"
/* readonly */
CProxy_Control mainControl;
/* Simulation Parameters */
#define NUMDIMS 3 //dimensionality of the physical space
#define NUMATOMS 1000 //number of atoms in the simulation
#define NUMPATCH 50 //number of compute objects (every compute object stands for a virtual processor)
#define NUMSTEPS 16 //number of time steps in the simulation
#define MASS 1.0 //mass of the atom
#define DT 1.0e-4 //time step in the simulation
#define CUTOFF 0.5
#define PI2 (3.1415926/2.0)
#define MIN(x,y) ((x)>(y)?(y):(x))
#define frand() (rand()/(RAND_MAX+1.0))
/* Simple defines for the pair potential and its derivative.
* This potential is a harmonic well which smoothly saturates
* to a maximum value at PI/2
*/
#define V(x) (sin(MIN(x, PI2))*sin(MIN(x, PI2)))
#define DV(x) (2.0*sin(MIN(x, PI2))*cos(MIN(x, PI2)))
class AtomInfo
{
public:
 double mass;
 double position[NUMDIMS];
 double velocity[NUMDIMS];
 double acceleration[NUMDIMS];
 double force[NUMDIMS];
public:
 AtomInfo()
 {
 mass = MASS;
 for(int i=0; i<NUMDIMS; i++)
 {
 position[i] = frand()*10;
 velocity[i] = 0.0;
 acceleration[i] = 0.0;
 force[i] = 0.0;
 }
 }
 double distance(AtomInfo *B)
 {
 double dist = 0.0;
 for(int i=0; i<NUMDIMS; i++)
 {
 double abDist = position[i] - (B->position)[i];
 dist += abDist*abDist;
 }
 return sqrt(dist);
 }
 double calKinetic()
 {
 double k = 0.0;
 for(int i=0; i<NUMDIMS; i++)
 k += velocity[i]*velocity[i];
 return k*0.5*mass;
 }
 void pup(PUP::er &p)
 {
 p|mass;
 PUParray(p, position, NUMDIMS);
 PUParray(p, velocity, NUMDIMS);
 PUParray(p, acceleration, NUMDIMS);
 PUParray(p, force, NUMDIMS);
 }
};
/* The following class defines methods that would control the execution of the whole program */
class Control: public Chare
{
private:
 double beginTime;
 double endTime;
 int numArrivals;
 int stepsSoFar;
 double totalPotential;
 double totalKinetic;
 CProxy_Patch patches;
public:
 Control(CkArgMsg *m)
 {
 delete m;
 //initialize control parameters
 numArrivals = 0;
 stepsSoFar = 0;
 mainControl = thishandle;
 //initialize every patch which contains part of total atoms
 patches = CProxy_Patch::ckNew(NUMPATCH);
 //timing and begin simulation
 beginTime = CkWallTimer();
 patches.doOneStep();
 }
 void finishOneStep(double partPotential, double partKinetic)
 {
 numArrivals++;
 totalPotential += partPotential;
 totalKinetic += partKinetic;
 if(numArrivals == NUMPATCH)
 {
 endTime = CkWallTimer();
 //output one step timing
 CkPrintf("Potential: %lf, Kinetic: %lf, Timing: %lf sec/step\n", totalPotential, totalKinetic,
endTime-beginTime);
 numArrivals = 0;
 totalPotential = 0.0;
 totalKinetic = 0.0;
 if(++stepsSoFar == NUMSTEPS)
 {
 CkExit();
 }
 else
 {
beginTime = CkWallTimer();
 patches.doOneStep();
 }
 }
 }
};
/* array [1D] for patches */
class Patch: public CBase_Patch
{
private:
 AtomInfo *atoms;
 int numAtoms;
 int patchesArrived;
 double potential;
 double kinetic;
public:
 Patch()
 {
 numAtoms = NUMATOMS/NUMPATCH;
 atoms = new AtomInfo[numAtoms];
 patchesArrived = 0;
 potential = 0.0;
 kinetic = 0.0;
 }
 Patch(CkMigrateMessage *m)
 {}
 void doOneStep()
 {
 //first do calculation within the patch
 for(int i=0; i<numAtoms; i++)
 {
 AtomInfo *atomA = atoms+i;
 for(int j=0; j<numAtoms; j++)
 {
 AtomInfo *atomB = atoms+j;
 if(i!=j)
 {
 double d = atomA->distance(atomB);
 if(d>CUTOFF)
 {
 potential += 0.5*V(d);
 for(int k=0; k<NUMDIMS; k++)
 (atomA->force)[k] -= ((atomA->position)[k] - (atomB->position)[k])*DV(d)/d;
 }
 }
 }
 }
 //then send my own atoms to other patches
 //pup my atoms' info
 for(int i=0; i<thisIndex; i++)
 {
 thisProxy[i].getAtomsFromAPatch(numAtoms, atoms);
 }
 for(int i=thisIndex+1; i<NUMPATCH; i++)
 {
 thisProxy[i].getAtomsFromAPatch(numAtoms, atoms);
 }
 }
 void getAtomsFromAPatch(int atomsCnt, AtomInfo *recvAtoms)
 {
 //do one calculations
 for(int i=0; i<numAtoms; i++)
 {
 AtomInfo *atomA = atoms+i;
 for(int j=0; j<atomsCnt; j++)
 {
 AtomInfo *atomB = recvAtoms+j;
 double d = atomA->distance(atomB);
 if(d>CUTOFF)
 {
 potential += 0.5*V(d);
 for(int k=0; k<NUMDIMS; k++)
 (atomA->force)[k] -= ((atomA->position)[k] - (atomB->position)[k])*DV(d)/d;
 }
 }
 }
 if(++patchesArrived == NUMPATCH-1)
 { //have all other patches
 //compute kinetics
 patchesArrived = 0;
 for(int i=0; i<numAtoms; i++)
 kinetic += (atoms+i)->calKinetic();
 //update all my atoms' position
 update();
 mainControl.finishOneStep(potential, kinetic);
 }
 }
 void pup(PUP::er &p)
 {
 CBase_Patch::pup(p);
 p|numAtoms;
 if(p.isUnpacking())
 atoms = new AtomInfo[numAtoms];
 PUParray(p, atoms, numAtoms);
 }
 ~Patch()
 {
 delete[] atoms;
 }
private:
 void update()
 {
 for(int i=0; i<numAtoms; i++)
 {
 AtomInfo *one = atoms+i;
 for(int j=0; j<NUMDIMS; j++)
 {
 (one->position)[j] += (one->velocity)[j]*DT + 0.5*DT*DT*(one->acceleration)[j];
 (one->velocity)[j] += 0.5*DT*((one->force)[j]/one->mass + (one->acceleration)[j]);
 (one->acceleration)[j] = (one->force)[j]/one->mass;
 }
 }
 }
};
#include "md_charm.def.h"
