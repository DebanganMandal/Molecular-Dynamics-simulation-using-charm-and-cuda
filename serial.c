#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <time.h>
#define frand() (rand()/(RAND_MAX+1.0))
/* Simulation Parameters  */
#define NUMDIMS 3 //dimensionality of the physical space
#define NUMATOMS 1000 //number of atoms in the simulation
#define NUMSTEPS 16 //number of time steps in the simulation
#define MASS 1.0 //mass of the atom
#define DT 1.0e-4 //time step in the simulation
#define CUTOFF 0.5
#define PI2 (3.1415926/2.0)
#define MIN(x,y) ((x)>(y)?(y):(x))
/* Simple defines for the pair potential and its derivative. * This potential is a harmonic well which smoothly saturates * to a maximum value at PI/2
*/
#define V(x) (sin(MIN(x, PI2))*sin(MIN(x, PI2)))
#define DV(x) (2.0*sin(MIN(x, PI2))*cos(MIN(x, PI2)))

double max(double a, double b){
    if(a > b){
        return a;
    }
    return b;
}
double min(double a, double b){
    if(a < b){
        return a;
    }
    return b;
}

typedef struct AtomInfo{
    double mass;
    double position[NUMDIMS];
    double velocity[NUMDIMS];
    double acceleration[NUMDIMS];
    double force[NUMDIMS];
}AtomInfo;

void initialize(AtomInfo *atoms);
void compute(AtomInfo *atoms, double *pPotential, double *pKinetic);
void update(AtomInfo *atoms);

int main(int argc, char *argv[]){
    double total_time = 0;
    double i_time = 1000000;
    AtomInfo atoms[NUMATOMS];
    double potential, kinetic, E0;
    int i;
//set intial positions, velocities, and accelerations
    initialize(atoms);
//compute the forces and energies
    compute(atoms, &potential, &kinetic);
    E0 = potential + kinetic;
printf("Potential,\tKinetic,\tChange Rate,\tTimePerStep(ms)\n"); //main time stepping loop
for(i=0; i<NUMSTEPS; i++){
double execTime = -(clock()/(double)CLOCKS_PER_SEC*1000);
compute(atoms, &potential, &kinetic);
execTime += (clock()/(double)CLOCKS_PER_SEC*1000);
total_time = max(total_time, execTime);
i_time = min(i_time, execTime);
printf("%lf \t %lf \t %lf \t %lf\n", potential, kinetic, (potential+kinetic-E0)/E0, execTime);
update(atoms);
}
    printf("\nTotal Time of execution : %lf\n",total_time);
    printf("\nBest Potential time : %lf\n",total_time - i_time);
    return EXIT_SUCCESS;
}


void initialize(AtomInfo *atoms){
    int i,j;
for(i=0; i<NUMATOMS; i++){
    AtomInfo *singleOne = atoms + i;
    singleOne->mass = MASS;
    for(j=0; j<NUMDIMS; j++){
        (singleOne->position)[j] = frand()*10;
        (singleOne->velocity)[j] = 0.0;
        (singleOne->acceleration)[j] = 0.0;
}
}
}


double distance(AtomInfo *atomA, AtomInfo *atomB);
double calKinetic(AtomInfo *atom);

void compute(AtomInfo *atoms, double *pPotential, double *pKinetic){
    int i,j, k;
    double potential = 0.0;
    double kinetic = 0.0;
for(i=0; i<NUMATOMS; i++){
        AtomInfo *atomA = atoms+i;
        for(k=0; k<NUMDIMS; k++)
            (atomA->force)[k] = 0.0;
        //compute potential energy and force
        for(j=0; j<NUMATOMS; j++){
            AtomInfo *atomB = atoms+j;
            if(i != j){
//first compute distance between atomA and atomB
double d = distance(atomA, atomB);
if(d > CUTOFF){
//attribute half of the potential energy to atomB

                   potential += 0.5*V(d);
for(k=0; k<NUMDIMS; k++)
(atomA->force)[k] -= ((atomA->position)[k] - (atomB->position)[k])*DV(d)/d;
    
}
//compute kinetic energy
}
            
        }
        kinetic += calKinetic(atomA);
    }
    *pPotential = potential;
    *pKinetic = kinetic;
}


double distance(AtomInfo *atomA, AtomInfo *atomB){
    double dist = 0.0;
    int i;
    for(i=0; i<NUMDIMS; i++){
        double abDist = (atomA->position)[i] - (atomB->position)[i];
        dist += abDist*abDist;
    }
    return sqrt(dist);
}


double calKinetic(AtomInfo *atom){
    double kinetic = 0.0;
    int i;
    for(i=0; i<NUMDIMS; i++){
        kinetic += (atom->velocity)[i] * (atom->velocity)[i]; 
    }
    return kinetic*0.5*(atom->mass);
}
//Perform the time integration, using a velocity Verlet algorithm


void update(AtomInfo *atoms){
int i, j;
    for(i=0; i<NUMATOMS; i++){
        AtomInfo *one = atoms+i;
        for(j=0; j<NUMDIMS; j++){
            (one->position)[j] += (one->velocity)[j]*DT + 0.5*DT*DT*(one->acceleration)[j];
            (one->velocity)[j] += 0.5*DT*((one->force)[j]/one->mass + (one->acceleration)[j]);
        }       
    }
}

