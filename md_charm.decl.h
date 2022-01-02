#ifndef _DECL_md_charm_H_
#define _DECL_md_charm_H_
#include "charm++.h"
#include "envelope.h"
#include <memory>
#include "sdag.h"
/* DECLS: readonly CProxy_Control mainControl;
 */

/* DECLS: mainchare Control: Chare{
Control(CkArgMsg* impl_msg);
void finishOneStep(double impl_noname_0, double impl_noname_1);
};
 */
 class Control;
 class CkIndex_Control;
 class CProxy_Control;
/* --------------- index object ------------------ */
class CkIndex_Control:public CkIndex_Chare{
  public:
    typedef Control local_t;
    typedef CkIndex_Control index_t;
    typedef CProxy_Control proxy_t;
    typedef CProxy_Control element_t;

    static int __idx;
    static void __register(const char *s, size_t size);
    /* DECLS: Control(CkArgMsg* impl_msg);
     */
    // Entry point registration at startup
    
    static int reg_Control_CkArgMsg();
    // Entry point index lookup
    
    inline static int idx_Control_CkArgMsg() {
      static int epidx = reg_Control_CkArgMsg();
      return epidx;
    }

    
    static int ckNew(CkArgMsg* impl_msg) { return idx_Control_CkArgMsg(); }
    
    static void _call_Control_CkArgMsg(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_Control_CkArgMsg(void* impl_msg, void* impl_obj);
    /* DECLS: void finishOneStep(double impl_noname_0, double impl_noname_1);
     */
    // Entry point registration at startup
    
    static int reg_finishOneStep_marshall2();
    // Entry point index lookup
    
    inline static int idx_finishOneStep_marshall2() {
      static int epidx = reg_finishOneStep_marshall2();
      return epidx;
    }

    
    inline static int idx_finishOneStep(void (Control::*)(double impl_noname_0, double impl_noname_1) ) {
      return idx_finishOneStep_marshall2();
    }


    
    static int finishOneStep(double impl_noname_0, double impl_noname_1) { return idx_finishOneStep_marshall2(); }
    
    static void _call_finishOneStep_marshall2(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_finishOneStep_marshall2(void* impl_msg, void* impl_obj);
    
    static int _callmarshall_finishOneStep_marshall2(char* impl_buf, void* impl_obj_void);
    
    static void _marshallmessagepup_finishOneStep_marshall2(PUP::er &p,void *msg);
};
/* --------------- element proxy ------------------ */
class CProxy_Control:public CProxy_Chare{
  public:
    typedef Control local_t;
    typedef CkIndex_Control index_t;
    typedef CProxy_Control proxy_t;
    typedef CProxy_Control element_t;

    CProxy_Control(void) {};
    CProxy_Control(CkChareID __cid) : CProxy_Chare(__cid){  }
    CProxy_Control(const Chare *c) : CProxy_Chare(c){  }

    int ckIsDelegated(void) const
    { return CProxy_Chare::ckIsDelegated(); }
    inline CkDelegateMgr *ckDelegatedTo(void) const
    { return CProxy_Chare::ckDelegatedTo(); }
    inline CkDelegateData *ckDelegatedPtr(void) const
    { return CProxy_Chare::ckDelegatedPtr(); }
    CkGroupID ckDelegatedIdx(void) const
    { return CProxy_Chare::ckDelegatedIdx(); }

    inline void ckCheck(void) const
    { CProxy_Chare::ckCheck(); }
    const CkChareID &ckGetChareID(void) const
    { return CProxy_Chare::ckGetChareID(); }
    operator const CkChareID &(void) const
    { return ckGetChareID(); }

    void ckDelegate(CkDelegateMgr *dTo,CkDelegateData *dPtr=NULL)
    {       CProxy_Chare::ckDelegate(dTo,dPtr); }
    void ckUndelegate(void)
    {       CProxy_Chare::ckUndelegate(); }
    void pup(PUP::er &p)
    {       CProxy_Chare::pup(p);
    }

    void ckSetChareID(const CkChareID &c)
    {      CProxy_Chare::ckSetChareID(c); }
    Control *ckLocal(void) const
    { return (Control *)CkLocalChare(&ckGetChareID()); }
/* DECLS: Control(CkArgMsg* impl_msg);
 */
    static CkChareID ckNew(CkArgMsg* impl_msg, int onPE=CK_PE_ANY);
    static void ckNew(CkArgMsg* impl_msg, CkChareID* pcid, int onPE=CK_PE_ANY);

/* DECLS: void finishOneStep(double impl_noname_0, double impl_noname_1);
 */
    
    void finishOneStep(double impl_noname_0, double impl_noname_1, const CkEntryOptions *impl_e_opts=NULL);

};
#define Control_SDAG_CODE 
typedef CBaseT1<Chare, CProxy_Control>CBase_Control;

/* DECLS: array Patch: ArrayElement{
Patch();
void doOneStep();
void getAtomsFromAPatch(int atomsCnt, const AtomInfo *recvAtoms);
Patch(CkMigrateMessage* impl_msg);
};
 */
 class Patch;
 class CkIndex_Patch;
 class CProxy_Patch;
 class CProxyElement_Patch;
 class CProxySection_Patch;
/* --------------- index object ------------------ */
class CkIndex_Patch:public CkIndex_ArrayElement{
  public:
    typedef Patch local_t;
    typedef CkIndex_Patch index_t;
    typedef CProxy_Patch proxy_t;
    typedef CProxyElement_Patch element_t;
    typedef CProxySection_Patch section_t;

    static int __idx;
    static void __register(const char *s, size_t size);
    /* DECLS: Patch();
     */
    // Entry point registration at startup
    
    static int reg_Patch_void();
    // Entry point index lookup
    
    inline static int idx_Patch_void() {
      static int epidx = reg_Patch_void();
      return epidx;
    }

    
    static int ckNew() { return idx_Patch_void(); }
    
    static void _call_Patch_void(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_Patch_void(void* impl_msg, void* impl_obj);
    /* DECLS: void doOneStep();
     */
    // Entry point registration at startup
    
    static int reg_doOneStep_void();
    // Entry point index lookup
    
    inline static int idx_doOneStep_void() {
      static int epidx = reg_doOneStep_void();
      return epidx;
    }

    
    inline static int idx_doOneStep(void (Patch::*)() ) {
      return idx_doOneStep_void();
    }


    
    static int doOneStep() { return idx_doOneStep_void(); }
    
    static void _call_doOneStep_void(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_doOneStep_void(void* impl_msg, void* impl_obj);
    /* DECLS: void getAtomsFromAPatch(int atomsCnt, const AtomInfo *recvAtoms);
     */
    // Entry point registration at startup
    
    static int reg_getAtomsFromAPatch_marshall3();
    // Entry point index lookup
    
    inline static int idx_getAtomsFromAPatch_marshall3() {
      static int epidx = reg_getAtomsFromAPatch_marshall3();
      return epidx;
    }

    
    inline static int idx_getAtomsFromAPatch(void (Patch::*)(int atomsCnt, const AtomInfo *recvAtoms) ) {
      return idx_getAtomsFromAPatch_marshall3();
    }


    
    static int getAtomsFromAPatch(int atomsCnt, const AtomInfo *recvAtoms) { return idx_getAtomsFromAPatch_marshall3(); }
    
    static void _call_getAtomsFromAPatch_marshall3(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_getAtomsFromAPatch_marshall3(void* impl_msg, void* impl_obj);
    
    static int _callmarshall_getAtomsFromAPatch_marshall3(char* impl_buf, void* impl_obj_void);
    
    static void _marshallmessagepup_getAtomsFromAPatch_marshall3(PUP::er &p,void *msg);
    /* DECLS: Patch(CkMigrateMessage* impl_msg);
     */
    // Entry point registration at startup
    
    static int reg_Patch_CkMigrateMessage();
    // Entry point index lookup
    
    inline static int idx_Patch_CkMigrateMessage() {
      static int epidx = reg_Patch_CkMigrateMessage();
      return epidx;
    }

    
    static int ckNew(CkMigrateMessage* impl_msg) { return idx_Patch_CkMigrateMessage(); }
    
    static void _call_Patch_CkMigrateMessage(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_Patch_CkMigrateMessage(void* impl_msg, void* impl_obj);
};
/* --------------- element proxy ------------------ */
 class CProxyElement_Patch : public CProxyElement_ArrayElement{
  public:
    typedef Patch local_t;
    typedef CkIndex_Patch index_t;
    typedef CProxy_Patch proxy_t;
    typedef CProxyElement_Patch element_t;
    typedef CProxySection_Patch section_t;

    using array_index_t = CkArrayIndex1D;

    /* TRAM aggregators */

    CProxyElement_Patch(void) {
    }
    CProxyElement_Patch(const ArrayElement *e) : CProxyElement_ArrayElement(e){
    }

    void ckDelegate(CkDelegateMgr *dTo,CkDelegateData *dPtr=NULL)
    {       CProxyElement_ArrayElement::ckDelegate(dTo,dPtr); }
    void ckUndelegate(void)
    {       CProxyElement_ArrayElement::ckUndelegate(); }
    void pup(PUP::er &p)
    {       CProxyElement_ArrayElement::pup(p);
    }

    int ckIsDelegated(void) const
    { return CProxyElement_ArrayElement::ckIsDelegated(); }
    inline CkDelegateMgr *ckDelegatedTo(void) const
    { return CProxyElement_ArrayElement::ckDelegatedTo(); }
    inline CkDelegateData *ckDelegatedPtr(void) const
    { return CProxyElement_ArrayElement::ckDelegatedPtr(); }
    CkGroupID ckDelegatedIdx(void) const
    { return CProxyElement_ArrayElement::ckDelegatedIdx(); }

    inline void ckCheck(void) const
    { CProxyElement_ArrayElement::ckCheck(); }
    inline operator CkArrayID () const
    { return ckGetArrayID(); }
    inline CkArrayID ckGetArrayID(void) const
    { return CProxyElement_ArrayElement::ckGetArrayID(); }
    inline CkArray *ckLocalBranch(void) const
    { return CProxyElement_ArrayElement::ckLocalBranch(); }
    inline CkLocMgr *ckLocMgr(void) const
    { return CProxyElement_ArrayElement::ckLocMgr(); }

    inline static CkArrayID ckCreateEmptyArray(CkArrayOptions opts = CkArrayOptions())
    { return CProxyElement_ArrayElement::ckCreateEmptyArray(opts); }
    inline static void ckCreateEmptyArrayAsync(CkCallback cb, CkArrayOptions opts = CkArrayOptions())
    { CProxyElement_ArrayElement::ckCreateEmptyArrayAsync(cb, opts); }
    inline static CkArrayID ckCreateArray(CkArrayMessage *m,int ctor,const CkArrayOptions &opts)
    { return CProxyElement_ArrayElement::ckCreateArray(m,ctor,opts); }
    inline void ckInsertIdx(CkArrayMessage *m,int ctor,int onPe,const CkArrayIndex &idx)
    { CProxyElement_ArrayElement::ckInsertIdx(m,ctor,onPe,idx); }
    inline void doneInserting(void)
    { CProxyElement_ArrayElement::doneInserting(); }

    inline void ckBroadcast(CkArrayMessage *m, int ep, int opts=0) const
    { CProxyElement_ArrayElement::ckBroadcast(m,ep,opts); }
    inline void setReductionClient(CkReductionClientFn fn,void *param=NULL) const
    { CProxyElement_ArrayElement::setReductionClient(fn,param); }
    inline void ckSetReductionClient(CkReductionClientFn fn,void *param=NULL) const
    { CProxyElement_ArrayElement::ckSetReductionClient(fn,param); }
    inline void ckSetReductionClient(CkCallback *cb) const
    { CProxyElement_ArrayElement::ckSetReductionClient(cb); }

    inline void ckInsert(CkArrayMessage *m,int ctor,int onPe)
    { CProxyElement_ArrayElement::ckInsert(m,ctor,onPe); }
    inline void ckSend(CkArrayMessage *m, int ep, int opts = 0) const
    { CProxyElement_ArrayElement::ckSend(m,ep,opts); }
    inline void *ckSendSync(CkArrayMessage *m, int ep) const
    { return CProxyElement_ArrayElement::ckSendSync(m,ep); }
    inline const CkArrayIndex &ckGetIndex() const
    { return CProxyElement_ArrayElement::ckGetIndex(); }

    Patch *ckLocal(void) const
    { return (Patch *)CProxyElement_ArrayElement::ckLocal(); }

    CProxyElement_Patch(const CkArrayID &aid,const CkArrayIndex1D &idx,CK_DELCTOR_PARAM)
        :CProxyElement_ArrayElement(aid,idx,CK_DELCTOR_ARGS)
    {
}
    CProxyElement_Patch(const CkArrayID &aid,const CkArrayIndex1D &idx)
        :CProxyElement_ArrayElement(aid,idx)
    {
}

    CProxyElement_Patch(const CkArrayID &aid,const CkArrayIndex &idx,CK_DELCTOR_PARAM)
        :CProxyElement_ArrayElement(aid,idx,CK_DELCTOR_ARGS)
    {
}
    CProxyElement_Patch(const CkArrayID &aid,const CkArrayIndex &idx)
        :CProxyElement_ArrayElement(aid,idx)
    {
}
/* DECLS: Patch();
 */
    
    void insert(int onPE=-1, const CkEntryOptions *impl_e_opts=NULL);
/* DECLS: void doOneStep();
 */
    
    void doOneStep(const CkEntryOptions *impl_e_opts=NULL) ;

/* DECLS: void getAtomsFromAPatch(int atomsCnt, const AtomInfo *recvAtoms);
 */
    
    void getAtomsFromAPatch(int atomsCnt, const AtomInfo *recvAtoms, const CkEntryOptions *impl_e_opts=NULL) ;

/* DECLS: Patch(CkMigrateMessage* impl_msg);
 */

};
/* ---------------- collective proxy -------------- */
 class CProxy_Patch : public CProxy_ArrayElement{
  public:
    typedef Patch local_t;
    typedef CkIndex_Patch index_t;
    typedef CProxy_Patch proxy_t;
    typedef CProxyElement_Patch element_t;
    typedef CProxySection_Patch section_t;

    using array_index_t = CkArrayIndex1D;
    CProxy_Patch(void) {
    }
    CProxy_Patch(const ArrayElement *e) : CProxy_ArrayElement(e){
    }

    void ckDelegate(CkDelegateMgr *dTo,CkDelegateData *dPtr=NULL)
    {       CProxy_ArrayElement::ckDelegate(dTo,dPtr); }
    void ckUndelegate(void)
    {       CProxy_ArrayElement::ckUndelegate(); }
    void pup(PUP::er &p)
    {       CProxy_ArrayElement::pup(p);
    }

    int ckIsDelegated(void) const
    { return CProxy_ArrayElement::ckIsDelegated(); }
    inline CkDelegateMgr *ckDelegatedTo(void) const
    { return CProxy_ArrayElement::ckDelegatedTo(); }
    inline CkDelegateData *ckDelegatedPtr(void) const
    { return CProxy_ArrayElement::ckDelegatedPtr(); }
    CkGroupID ckDelegatedIdx(void) const
    { return CProxy_ArrayElement::ckDelegatedIdx(); }

    inline void ckCheck(void) const
    { CProxy_ArrayElement::ckCheck(); }
    inline operator CkArrayID () const
    { return ckGetArrayID(); }
    inline CkArrayID ckGetArrayID(void) const
    { return CProxy_ArrayElement::ckGetArrayID(); }
    inline CkArray *ckLocalBranch(void) const
    { return CProxy_ArrayElement::ckLocalBranch(); }
    inline CkLocMgr *ckLocMgr(void) const
    { return CProxy_ArrayElement::ckLocMgr(); }

    inline static CkArrayID ckCreateEmptyArray(CkArrayOptions opts = CkArrayOptions())
    { return CProxy_ArrayElement::ckCreateEmptyArray(opts); }
    inline static void ckCreateEmptyArrayAsync(CkCallback cb, CkArrayOptions opts = CkArrayOptions())
    { CProxy_ArrayElement::ckCreateEmptyArrayAsync(cb, opts); }
    inline static CkArrayID ckCreateArray(CkArrayMessage *m,int ctor,const CkArrayOptions &opts)
    { return CProxy_ArrayElement::ckCreateArray(m,ctor,opts); }
    inline void ckInsertIdx(CkArrayMessage *m,int ctor,int onPe,const CkArrayIndex &idx)
    { CProxy_ArrayElement::ckInsertIdx(m,ctor,onPe,idx); }
    inline void doneInserting(void)
    { CProxy_ArrayElement::doneInserting(); }

    inline void ckBroadcast(CkArrayMessage *m, int ep, int opts=0) const
    { CProxy_ArrayElement::ckBroadcast(m,ep,opts); }
    inline void setReductionClient(CkReductionClientFn fn,void *param=NULL) const
    { CProxy_ArrayElement::setReductionClient(fn,param); }
    inline void ckSetReductionClient(CkReductionClientFn fn,void *param=NULL) const
    { CProxy_ArrayElement::ckSetReductionClient(fn,param); }
    inline void ckSetReductionClient(CkCallback *cb) const
    { CProxy_ArrayElement::ckSetReductionClient(cb); }

    // Generalized array indexing:
    CProxyElement_Patch operator [] (const CkArrayIndex1D &idx) const
    { return CProxyElement_Patch(ckGetArrayID(), idx, CK_DELCTOR_CALL); }
    CProxyElement_Patch operator() (const CkArrayIndex1D &idx) const
    { return CProxyElement_Patch(ckGetArrayID(), idx, CK_DELCTOR_CALL); }
    CProxyElement_Patch operator [] (int idx) const 
        {return CProxyElement_Patch(ckGetArrayID(), CkArrayIndex1D(idx), CK_DELCTOR_CALL);}
    CProxyElement_Patch operator () (int idx) const 
        {return CProxyElement_Patch(ckGetArrayID(), CkArrayIndex1D(idx), CK_DELCTOR_CALL);}
    CProxy_Patch(const CkArrayID &aid,CK_DELCTOR_PARAM) 
        :CProxy_ArrayElement(aid,CK_DELCTOR_ARGS) {}
    CProxy_Patch(const CkArrayID &aid) 
        :CProxy_ArrayElement(aid) {}
/* DECLS: Patch();
 */
    
    static CkArrayID ckNew(const CkArrayOptions &opts = CkArrayOptions(), const CkEntryOptions *impl_e_opts=NULL);
    static void      ckNew(const CkArrayOptions &opts, CkCallback _ck_array_creation_cb, const CkEntryOptions *impl_e_opts=NULL);
    static CkArrayID ckNew(const int s1, const CkEntryOptions *impl_e_opts=NULL);
    static void ckNew(const int s1, CkCallback _ck_array_creation_cb, const CkEntryOptions *impl_e_opts=NULL);

/* DECLS: void doOneStep();
 */
    
    void doOneStep(const CkEntryOptions *impl_e_opts=NULL) ;

/* DECLS: void getAtomsFromAPatch(int atomsCnt, const AtomInfo *recvAtoms);
 */
    
    void getAtomsFromAPatch(int atomsCnt, const AtomInfo *recvAtoms, const CkEntryOptions *impl_e_opts=NULL) ;

/* DECLS: Patch(CkMigrateMessage* impl_msg);
 */

};
/* ---------------- section proxy -------------- */
 class CProxySection_Patch : public CProxySection_ArrayElement{
  public:
    typedef Patch local_t;
    typedef CkIndex_Patch index_t;
    typedef CProxy_Patch proxy_t;
    typedef CProxyElement_Patch element_t;
    typedef CProxySection_Patch section_t;

    using array_index_t = CkArrayIndex1D;
    CProxySection_Patch(void) {
    }

    void ckDelegate(CkDelegateMgr *dTo,CkDelegateData *dPtr=NULL)
    {       CProxySection_ArrayElement::ckDelegate(dTo,dPtr); }
    void ckUndelegate(void)
    {       CProxySection_ArrayElement::ckUndelegate(); }
    void pup(PUP::er &p)
    {       CProxySection_ArrayElement::pup(p);
    }

    int ckIsDelegated(void) const
    { return CProxySection_ArrayElement::ckIsDelegated(); }
    inline CkDelegateMgr *ckDelegatedTo(void) const
    { return CProxySection_ArrayElement::ckDelegatedTo(); }
    inline CkDelegateData *ckDelegatedPtr(void) const
    { return CProxySection_ArrayElement::ckDelegatedPtr(); }
    CkGroupID ckDelegatedIdx(void) const
    { return CProxySection_ArrayElement::ckDelegatedIdx(); }

    inline void ckCheck(void) const
    { CProxySection_ArrayElement::ckCheck(); }
    inline operator CkArrayID () const
    { return ckGetArrayID(); }
    inline CkArrayID ckGetArrayID(void) const
    { return CProxySection_ArrayElement::ckGetArrayID(); }
    inline CkArray *ckLocalBranch(void) const
    { return CProxySection_ArrayElement::ckLocalBranch(); }
    inline CkLocMgr *ckLocMgr(void) const
    { return CProxySection_ArrayElement::ckLocMgr(); }

    inline static CkArrayID ckCreateEmptyArray(CkArrayOptions opts = CkArrayOptions())
    { return CProxySection_ArrayElement::ckCreateEmptyArray(opts); }
    inline static void ckCreateEmptyArrayAsync(CkCallback cb, CkArrayOptions opts = CkArrayOptions())
    { CProxySection_ArrayElement::ckCreateEmptyArrayAsync(cb, opts); }
    inline static CkArrayID ckCreateArray(CkArrayMessage *m,int ctor,const CkArrayOptions &opts)
    { return CProxySection_ArrayElement::ckCreateArray(m,ctor,opts); }
    inline void ckInsertIdx(CkArrayMessage *m,int ctor,int onPe,const CkArrayIndex &idx)
    { CProxySection_ArrayElement::ckInsertIdx(m,ctor,onPe,idx); }
    inline void doneInserting(void)
    { CProxySection_ArrayElement::doneInserting(); }

    inline void ckBroadcast(CkArrayMessage *m, int ep, int opts=0) const
    { CProxySection_ArrayElement::ckBroadcast(m,ep,opts); }
    inline void setReductionClient(CkReductionClientFn fn,void *param=NULL) const
    { CProxySection_ArrayElement::setReductionClient(fn,param); }
    inline void ckSetReductionClient(CkReductionClientFn fn,void *param=NULL) const
    { CProxySection_ArrayElement::ckSetReductionClient(fn,param); }
    inline void ckSetReductionClient(CkCallback *cb) const
    { CProxySection_ArrayElement::ckSetReductionClient(cb); }

    inline void ckSend(CkArrayMessage *m, int ep, int opts = 0)
    { CProxySection_ArrayElement::ckSend(m,ep,opts); }
    inline CkSectionInfo &ckGetSectionInfo()
    { return CProxySection_ArrayElement::ckGetSectionInfo(); }
    inline CkSectionID *ckGetSectionIDs()
    { return CProxySection_ArrayElement::ckGetSectionIDs(); }
    inline CkSectionID &ckGetSectionID()
    { return CProxySection_ArrayElement::ckGetSectionID(); }
    inline CkSectionID &ckGetSectionID(int i)
    { return CProxySection_ArrayElement::ckGetSectionID(i); }
    inline CkArrayID ckGetArrayIDn(int i) const
    { return CProxySection_ArrayElement::ckGetArrayIDn(i); } 
    inline CkArrayIndex *ckGetArrayElements() const
    { return CProxySection_ArrayElement::ckGetArrayElements(); }
    inline CkArrayIndex *ckGetArrayElements(int i) const
    { return CProxySection_ArrayElement::ckGetArrayElements(i); }
    inline int ckGetNumElements() const
    { return CProxySection_ArrayElement::ckGetNumElements(); } 
    inline int ckGetNumElements(int i) const
    { return CProxySection_ArrayElement::ckGetNumElements(i); }    // Generalized array indexing:
    CProxyElement_Patch operator [] (const CkArrayIndex1D &idx) const
        {return CProxyElement_Patch(ckGetArrayID(), idx, CK_DELCTOR_CALL);}
    CProxyElement_Patch operator() (const CkArrayIndex1D &idx) const
        {return CProxyElement_Patch(ckGetArrayID(), idx, CK_DELCTOR_CALL);}
    CProxyElement_Patch operator [] (int idx) const 
        {return CProxyElement_Patch(ckGetArrayID(), *(CkArrayIndex1D*)&ckGetArrayElements()[idx], CK_DELCTOR_CALL);}
    CProxyElement_Patch operator () (int idx) const 
        {return CProxyElement_Patch(ckGetArrayID(), *(CkArrayIndex1D*)&ckGetArrayElements()[idx], CK_DELCTOR_CALL);}
    static CkSectionID ckNew(const CkArrayID &aid, CkArrayIndex1D *elems, int nElems, int factor=USE_DEFAULT_BRANCH_FACTOR) {
      return CkSectionID(aid, elems, nElems, factor);
    } 
    static CkSectionID ckNew(const CkArrayID &aid, const std::vector<CkArrayIndex1D> &elems, int factor=USE_DEFAULT_BRANCH_FACTOR) {
      return CkSectionID(aid, elems, factor);
    } 
    static CkSectionID ckNew(const CkArrayID &aid, int l, int u, int s, int factor=USE_DEFAULT_BRANCH_FACTOR) {
      std::vector<CkArrayIndex1D> al;
      for (int i=l; i<=u; i+=s) al.emplace_back(i);
      return CkSectionID(aid, al, factor);
    } 
    CProxySection_Patch(const CkArrayID &aid, CkArrayIndex *elems, int nElems, CK_DELCTOR_PARAM) 
        :CProxySection_ArrayElement(aid,elems,nElems,CK_DELCTOR_ARGS) {}
    CProxySection_Patch(const CkArrayID &aid, const std::vector<CkArrayIndex> &elems, CK_DELCTOR_PARAM) 
        :CProxySection_ArrayElement(aid,elems,CK_DELCTOR_ARGS) {}
    CProxySection_Patch(const CkArrayID &aid, CkArrayIndex *elems, int nElems, int factor=USE_DEFAULT_BRANCH_FACTOR) 
        :CProxySection_ArrayElement(aid,elems,nElems, factor) {}
    CProxySection_Patch(const CkArrayID &aid, const std::vector<CkArrayIndex> &elems, int factor=USE_DEFAULT_BRANCH_FACTOR) 
        :CProxySection_ArrayElement(aid,elems, factor) { ckAutoDelegate(); }
    CProxySection_Patch(const CkSectionID &sid)  
        :CProxySection_ArrayElement(sid) { ckAutoDelegate(); }
    CProxySection_Patch(int n, const CkArrayID *aid, CkArrayIndex const * const *elems, const int *nElems, CK_DELCTOR_PARAM) 
        :CProxySection_ArrayElement(n,aid,elems,nElems,CK_DELCTOR_ARGS) {}
    CProxySection_Patch(const std::vector<CkArrayID> &aid, const std::vector<std::vector<CkArrayIndex> > &elems, CK_DELCTOR_PARAM) 
        :CProxySection_ArrayElement(aid,elems,CK_DELCTOR_ARGS) {}
    CProxySection_Patch(int n, const CkArrayID *aid, CkArrayIndex const * const *elems, const int *nElems) 
        :CProxySection_ArrayElement(n,aid,elems,nElems) { ckAutoDelegate(); }
    CProxySection_Patch(const std::vector<CkArrayID> &aid, const std::vector<std::vector<CkArrayIndex> > &elems) 
        :CProxySection_ArrayElement(aid,elems) { ckAutoDelegate(); }
    CProxySection_Patch(int n, const CkArrayID *aid, CkArrayIndex const * const *elems, const int *nElems, int factor) 
        :CProxySection_ArrayElement(n,aid,elems,nElems, factor) { ckAutoDelegate(); }
    CProxySection_Patch(const std::vector<CkArrayID> &aid, const std::vector<std::vector<CkArrayIndex> > &elems, int factor) 
        :CProxySection_ArrayElement(aid,elems, factor) { ckAutoDelegate(); }
    static CkSectionID ckNew(const CkArrayID &aid, CkArrayIndex *elems, int nElems) {
      return CkSectionID(aid, elems, nElems);
    } 
    static CkSectionID ckNew(const CkArrayID &aid, const std::vector<CkArrayIndex> &elems) {
       return CkSectionID(aid, elems);
    } 
    static CkSectionID ckNew(const CkArrayID &aid, CkArrayIndex *elems, int nElems, int factor) {
      return CkSectionID(aid, elems, nElems, factor);
    } 
    static CkSectionID ckNew(const CkArrayID &aid, const std::vector<CkArrayIndex> &elems, int factor) {
      return CkSectionID(aid, elems, factor);
    } 
    void ckAutoDelegate(int opts=1) {
      if(ckIsDelegated()) return;
      CProxySection_ArrayElement::ckAutoDelegate(opts);
    } 
    void setReductionClient(CkCallback *cb) {
      CProxySection_ArrayElement::setReductionClient(cb);
    } 
    void resetSection() {
      CProxySection_ArrayElement::resetSection();
    } 
    static void contribute(CkSectionInfo &sid, int userData=-1, int fragSize=-1);
    static void contribute(int dataSize,void *data,CkReduction::reducerType type, CkSectionInfo &sid, int userData=-1, int fragSize=-1);
    template <typename T>
    static void contribute(std::vector<T> &data, CkReduction::reducerType type, CkSectionInfo &sid, int userData=-1, int fragSize=-1);
    static void contribute(CkSectionInfo &sid, const CkCallback &cb, int userData=-1, int fragSize=-1);
    static void contribute(int dataSize,void *data,CkReduction::reducerType type, CkSectionInfo &sid, const CkCallback &cb, int userData=-1, int fragSize=-1);
    template <typename T>
    static void contribute(std::vector<T> &data, CkReduction::reducerType type, CkSectionInfo &sid, const CkCallback &cb, int userData=-1, int fragSize=-1);
/* DECLS: Patch();
 */
    

/* DECLS: void doOneStep();
 */
    
    void doOneStep(const CkEntryOptions *impl_e_opts=NULL) ;

/* DECLS: void getAtomsFromAPatch(int atomsCnt, const AtomInfo *recvAtoms);
 */
    
    void getAtomsFromAPatch(int atomsCnt, const AtomInfo *recvAtoms, const CkEntryOptions *impl_e_opts=NULL) ;

/* DECLS: Patch(CkMigrateMessage* impl_msg);
 */

};
#define Patch_SDAG_CODE 
typedef CBaseT1<ArrayElementT<CkIndex1D>, CProxy_Patch>CBase_Patch;


/* ---------------- method closures -------------- */
class Closure_Control {
  public:


    struct finishOneStep_2_closure;

};

/* ---------------- method closures -------------- */
class Closure_Patch {
  public:


    struct doOneStep_2_closure;


    struct getAtomsFromAPatch_3_closure;


};

extern void _registermd_charm(void);
extern "C" void CkRegisterMainModule(void);
#endif
