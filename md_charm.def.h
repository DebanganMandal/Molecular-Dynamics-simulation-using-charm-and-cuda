
/* ---------------- method closures -------------- */
#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY

    struct Closure_Control::finishOneStep_2_closure : public SDAG::Closure {
            double impl_noname_0;
            double impl_noname_1;


      finishOneStep_2_closure() {
        init();
      }
      finishOneStep_2_closure(CkMigrateMessage*) {
        init();
      }
            double & getP0() { return impl_noname_0;}
            double & getP1() { return impl_noname_1;}
      void pup(PUP::er& __p) {
        __p | impl_noname_0;
        __p | impl_noname_1;
        packClosure(__p);
      }
      virtual ~finishOneStep_2_closure() {
      }
      PUPable_decl(SINGLE_ARG(finishOneStep_2_closure));
    };
#endif /* CK_TEMPLATES_ONLY */


/* ---------------- method closures -------------- */
#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY

    struct Closure_Patch::doOneStep_2_closure : public SDAG::Closure {
      

      doOneStep_2_closure() {
        init();
      }
      doOneStep_2_closure(CkMigrateMessage*) {
        init();
      }
            void pup(PUP::er& __p) {
        packClosure(__p);
      }
      virtual ~doOneStep_2_closure() {
      }
      PUPable_decl(SINGLE_ARG(doOneStep_2_closure));
    };
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY

    struct Closure_Patch::getAtomsFromAPatch_3_closure : public SDAG::Closure {
            int atomsCnt;
            AtomInfo *recvAtoms;

      CkMarshallMsg* _impl_marshall;
      char* _impl_buf_in;
      int _impl_buf_size;

      getAtomsFromAPatch_3_closure() {
        init();
        _impl_marshall = 0;
        _impl_buf_in = 0;
        _impl_buf_size = 0;
      }
      getAtomsFromAPatch_3_closure(CkMigrateMessage*) {
        init();
        _impl_marshall = 0;
        _impl_buf_in = 0;
        _impl_buf_size = 0;
      }
            int & getP0() { return atomsCnt;}
            AtomInfo *& getP1() { return recvAtoms;}
      void pup(PUP::er& __p) {
        __p | atomsCnt;
        packClosure(__p);
        __p | _impl_buf_size;
        bool hasMsg = (_impl_marshall != 0); __p | hasMsg;
        if (hasMsg) CkPupMessage(__p, (void**)&_impl_marshall);
        else PUParray(__p, _impl_buf_in, _impl_buf_size);
        if (__p.isUnpacking()) {
          char *impl_buf = _impl_marshall ? _impl_marshall->msgBuf : _impl_buf_in;
          PUP::fromMem implP(impl_buf);
  PUP::detail::TemporaryObjectHolder<int> atomsCnt;
  implP|atomsCnt;
  int impl_off_recvAtoms, impl_cnt_recvAtoms;
  implP|impl_off_recvAtoms;
  implP|impl_cnt_recvAtoms;
          impl_buf+=CK_ALIGN(implP.size(),16);
          recvAtoms = (AtomInfo *)(impl_buf+impl_off_recvAtoms);
        }
      }
      virtual ~getAtomsFromAPatch_3_closure() {
        if (_impl_marshall) CmiFree(UsrToEnv(_impl_marshall));
      }
      PUPable_decl(SINGLE_ARG(getAtomsFromAPatch_3_closure));
    };
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */


/* DEFS: readonly CProxy_Control mainControl;
 */
extern CProxy_Control mainControl;
#ifndef CK_TEMPLATES_ONLY
extern "C" void __xlater_roPup_mainControl(void *_impl_pup_er) {
  PUP::er &_impl_p=*(PUP::er *)_impl_pup_er;
  _impl_p|mainControl;
}
#endif /* CK_TEMPLATES_ONLY */

/* DEFS: mainchare Control: Chare{
Control(CkArgMsg* impl_msg);
void finishOneStep(double impl_noname_0, double impl_noname_1);
};
 */
#ifndef CK_TEMPLATES_ONLY
 int CkIndex_Control::__idx=0;
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
/* DEFS: Control(CkArgMsg* impl_msg);
 */
CkChareID CProxy_Control::ckNew(CkArgMsg* impl_msg, int impl_onPE)
{
  CkChareID impl_ret;
  CkCreateChare(CkIndex_Control::__idx, CkIndex_Control::idx_Control_CkArgMsg(), impl_msg, &impl_ret, impl_onPE);
  return impl_ret;
}
void CProxy_Control::ckNew(CkArgMsg* impl_msg, CkChareID* pcid, int impl_onPE)
{
  CkCreateChare(CkIndex_Control::__idx, CkIndex_Control::idx_Control_CkArgMsg(), impl_msg, pcid, impl_onPE);
}

// Entry point registration function
int CkIndex_Control::reg_Control_CkArgMsg() {
  int epidx = CkRegisterEp("Control(CkArgMsg* impl_msg)",
      reinterpret_cast<CkCallFnPtr>(_call_Control_CkArgMsg), CMessage_CkArgMsg::__idx, __idx, 0);
  CkRegisterMessagePupFn(epidx, (CkMessagePupFn)CkArgMsg::ckDebugPup);
  return epidx;
}

void CkIndex_Control::_call_Control_CkArgMsg(void* impl_msg, void* impl_obj_void)
{
  Control* impl_obj = static_cast<Control*>(impl_obj_void);
  new (impl_obj_void) Control((CkArgMsg*)impl_msg);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void finishOneStep(double impl_noname_0, double impl_noname_1);
 */
void CProxy_Control::finishOneStep(double impl_noname_0, double impl_noname_1, const CkEntryOptions *impl_e_opts)
{
  ckCheck();
  //Marshall: double impl_noname_0, double impl_noname_1
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|impl_noname_0;
    implP|impl_noname_1;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|impl_noname_0;
    implP|impl_noname_1;
  }
  if (ckIsDelegated()) {
    int destPE=CkChareMsgPrep(CkIndex_Control::idx_finishOneStep_marshall2(), impl_msg, &ckGetChareID());
    if (destPE!=-1) ckDelegatedTo()->ChareSend(ckDelegatedPtr(),CkIndex_Control::idx_finishOneStep_marshall2(), impl_msg, &ckGetChareID(),destPE);
  } else {
    CkSendMsg(CkIndex_Control::idx_finishOneStep_marshall2(), impl_msg, &ckGetChareID(),0);
  }
}

// Entry point registration function
int CkIndex_Control::reg_finishOneStep_marshall2() {
  int epidx = CkRegisterEp("finishOneStep(double impl_noname_0, double impl_noname_1)",
      reinterpret_cast<CkCallFnPtr>(_call_finishOneStep_marshall2), CkMarshallMsg::__idx, __idx, 0+CK_EP_NOKEEP);
  CkRegisterMarshallUnpackFn(epidx, _callmarshall_finishOneStep_marshall2);
  CkRegisterMessagePupFn(epidx, _marshallmessagepup_finishOneStep_marshall2);

  return epidx;
}

void CkIndex_Control::_call_finishOneStep_marshall2(void* impl_msg, void* impl_obj_void)
{
  Control* impl_obj = static_cast<Control*>(impl_obj_void);
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  envelope *env = UsrToEnv(impl_msg_typed);
  /*Unmarshall pup'd fields: double impl_noname_0, double impl_noname_1*/
  PUP::fromMem implP(impl_buf);
  PUP::detail::TemporaryObjectHolder<double> impl_noname_0;
  implP|impl_noname_0;
  PUP::detail::TemporaryObjectHolder<double> impl_noname_1;
  implP|impl_noname_1;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->finishOneStep(std::move(impl_noname_0.t), std::move(impl_noname_1.t));
}
int CkIndex_Control::_callmarshall_finishOneStep_marshall2(char* impl_buf, void* impl_obj_void) {
  Control* impl_obj = static_cast<Control*>(impl_obj_void);
  envelope *env = UsrToEnv(impl_buf);
  /*Unmarshall pup'd fields: double impl_noname_0, double impl_noname_1*/
  PUP::fromMem implP(impl_buf);
  PUP::detail::TemporaryObjectHolder<double> impl_noname_0;
  implP|impl_noname_0;
  PUP::detail::TemporaryObjectHolder<double> impl_noname_1;
  implP|impl_noname_1;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->finishOneStep(std::move(impl_noname_0.t), std::move(impl_noname_1.t));
  return implP.size();
}
void CkIndex_Control::_marshallmessagepup_finishOneStep_marshall2(PUP::er &implDestP,void *impl_msg) {
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  envelope *env = UsrToEnv(impl_msg_typed);
  /*Unmarshall pup'd fields: double impl_noname_0, double impl_noname_1*/
  PUP::fromMem implP(impl_buf);
  PUP::detail::TemporaryObjectHolder<double> impl_noname_0;
  implP|impl_noname_0;
  PUP::detail::TemporaryObjectHolder<double> impl_noname_1;
  implP|impl_noname_1;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  if (implDestP.hasComments()) implDestP.comment("impl_noname_0");
  implDestP|impl_noname_0;
  if (implDestP.hasComments()) implDestP.comment("impl_noname_1");
  implDestP|impl_noname_1;
}
PUPable_def(SINGLE_ARG(Closure_Control::finishOneStep_2_closure))
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
void CkIndex_Control::__register(const char *s, size_t size) {
  __idx = CkRegisterChare(s, size, TypeMainChare);
  CkRegisterBase(__idx, CkIndex_Chare::__idx);
  // REG: Control(CkArgMsg* impl_msg);
  idx_Control_CkArgMsg();
  CkRegisterMainChare(__idx, idx_Control_CkArgMsg());

  // REG: void finishOneStep(double impl_noname_0, double impl_noname_1);
  idx_finishOneStep_marshall2();

}
#endif /* CK_TEMPLATES_ONLY */

/* DEFS: array Patch: ArrayElement{
Patch();
void doOneStep();
void getAtomsFromAPatch(int atomsCnt, const AtomInfo *recvAtoms);
Patch(CkMigrateMessage* impl_msg);
};
 */
#ifndef CK_TEMPLATES_ONLY
 int CkIndex_Patch::__idx=0;
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
void CProxySection_Patch::contribute(CkSectionInfo &sid, int userData, int fragSize)
{
   CkArray *ckarr = CProxy_CkArray(sid.get_aid()).ckLocalBranch();
   CkMulticastMgr *mCastGrp = CProxy_CkMulticastMgr(ckarr->getmCastMgr()).ckLocalBranch();
   mCastGrp->contribute(sid, userData, fragSize);
}

void CProxySection_Patch::contribute(int dataSize,void *data,CkReduction::reducerType type, CkSectionInfo &sid, int userData, int fragSize)
{
   CkArray *ckarr = CProxy_CkArray(sid.get_aid()).ckLocalBranch();
   CkMulticastMgr *mCastGrp = CProxy_CkMulticastMgr(ckarr->getmCastMgr()).ckLocalBranch();
   mCastGrp->contribute(dataSize, data, type, sid, userData, fragSize);
}

template <typename T>
void CProxySection_Patch::contribute(std::vector<T> &data, CkReduction::reducerType type, CkSectionInfo &sid, int userData, int fragSize)
{
   CkArray *ckarr = CProxy_CkArray(sid.get_aid()).ckLocalBranch();
   CkMulticastMgr *mCastGrp = CProxy_CkMulticastMgr(ckarr->getmCastMgr()).ckLocalBranch();
   mCastGrp->contribute(data, type, sid, userData, fragSize);
}

void CProxySection_Patch::contribute(CkSectionInfo &sid, const CkCallback &cb, int userData, int fragSize)
{
   CkArray *ckarr = CProxy_CkArray(sid.get_aid()).ckLocalBranch();
   CkMulticastMgr *mCastGrp = CProxy_CkMulticastMgr(ckarr->getmCastMgr()).ckLocalBranch();
   mCastGrp->contribute(sid, cb, userData, fragSize);
}

void CProxySection_Patch::contribute(int dataSize,void *data,CkReduction::reducerType type, CkSectionInfo &sid, const CkCallback &cb, int userData, int fragSize)
{
   CkArray *ckarr = CProxy_CkArray(sid.get_aid()).ckLocalBranch();
   CkMulticastMgr *mCastGrp = CProxy_CkMulticastMgr(ckarr->getmCastMgr()).ckLocalBranch();
   mCastGrp->contribute(dataSize, data, type, sid, cb, userData, fragSize);
}

template <typename T>
void CProxySection_Patch::contribute(std::vector<T> &data, CkReduction::reducerType type, CkSectionInfo &sid, const CkCallback &cb, int userData, int fragSize)
{
   CkArray *ckarr = CProxy_CkArray(sid.get_aid()).ckLocalBranch();
   CkMulticastMgr *mCastGrp = CProxy_CkMulticastMgr(ckarr->getmCastMgr()).ckLocalBranch();
   mCastGrp->contribute(data, type, sid, cb, userData, fragSize);
}

#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
/* DEFS: Patch();
 */
void CProxyElement_Patch::insert(int onPE, const CkEntryOptions *impl_e_opts)
{ 
   void *impl_msg = CkAllocSysMsg(impl_e_opts);
   UsrToEnv(impl_msg)->setMsgtype(ArrayEltInitMsg);
   ckInsert((CkArrayMessage *)impl_msg,CkIndex_Patch::idx_Patch_void(),onPE);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void doOneStep();
 */
void CProxyElement_Patch::doOneStep(const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg(impl_e_opts);
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Patch::idx_doOneStep_void(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void getAtomsFromAPatch(int atomsCnt, const AtomInfo *recvAtoms);
 */
void CProxyElement_Patch::getAtomsFromAPatch(int atomsCnt, const AtomInfo *recvAtoms, const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  //Marshall: int atomsCnt, const AtomInfo *recvAtoms
  int impl_off=0;
  int impl_arrstart=0;
  int impl_off_recvAtoms, impl_cnt_recvAtoms;
  impl_off_recvAtoms=impl_off=CK_ALIGN(impl_off,sizeof(AtomInfo));
  impl_off+=(impl_cnt_recvAtoms=sizeof(AtomInfo)*(atomsCnt));
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|atomsCnt;
    implP|impl_off_recvAtoms;
    implP|impl_cnt_recvAtoms;
    impl_arrstart=CK_ALIGN(implP.size(),16);
    impl_off+=impl_arrstart;
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|atomsCnt;
    implP|impl_off_recvAtoms;
    implP|impl_cnt_recvAtoms;
  }
  char *impl_buf=impl_msg->msgBuf+impl_arrstart;
  memcpy(impl_buf+impl_off_recvAtoms,recvAtoms,impl_cnt_recvAtoms);
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Patch::idx_getAtomsFromAPatch_marshall3(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: Patch(CkMigrateMessage* impl_msg);
 */
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: Patch();
 */
CkArrayID CProxy_Patch::ckNew(const CkArrayOptions &opts, const CkEntryOptions *impl_e_opts)
{
  void *impl_msg = CkAllocSysMsg(impl_e_opts);
  UsrToEnv(impl_msg)->setMsgtype(ArrayEltInitMsg);
  CkArrayID gId = ckCreateArray((CkArrayMessage *)impl_msg, CkIndex_Patch::idx_Patch_void(), opts);
  return gId;
}
void CProxy_Patch::ckNew(const CkArrayOptions &opts, CkCallback _ck_array_creation_cb, const CkEntryOptions *impl_e_opts)
{
  void *impl_msg = CkAllocSysMsg(impl_e_opts);
  UsrToEnv(impl_msg)->setMsgtype(ArrayEltInitMsg);
  CkSendAsyncCreateArray(CkIndex_Patch::idx_Patch_void(), _ck_array_creation_cb, opts, impl_msg);
}
CkArrayID CProxy_Patch::ckNew(const int s1, const CkEntryOptions *impl_e_opts)
{
  void *impl_msg = CkAllocSysMsg(impl_e_opts);
  CkArrayOptions opts(s1);
  UsrToEnv(impl_msg)->setMsgtype(ArrayEltInitMsg);
  CkArrayID gId = ckCreateArray((CkArrayMessage *)impl_msg, CkIndex_Patch::idx_Patch_void(), opts);
  return gId;
}
void CProxy_Patch::ckNew(const int s1, CkCallback _ck_array_creation_cb, const CkEntryOptions *impl_e_opts)
{
  void *impl_msg = CkAllocSysMsg(impl_e_opts);
  CkArrayOptions opts(s1);
  UsrToEnv(impl_msg)->setMsgtype(ArrayEltInitMsg);
  CkSendAsyncCreateArray(CkIndex_Patch::idx_Patch_void(), _ck_array_creation_cb, opts, impl_msg);
}

// Entry point registration function
int CkIndex_Patch::reg_Patch_void() {
  int epidx = CkRegisterEp("Patch()",
      reinterpret_cast<CkCallFnPtr>(_call_Patch_void), 0, __idx, 0);
  return epidx;
}

void CkIndex_Patch::_call_Patch_void(void* impl_msg, void* impl_obj_void)
{
  Patch* impl_obj = static_cast<Patch*>(impl_obj_void);
  new (impl_obj_void) Patch();
  if(UsrToEnv(impl_msg)->isVarSysMsg() == 0)
    CkFreeSysMsg(impl_msg);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void doOneStep();
 */
void CProxy_Patch::doOneStep(const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg(impl_e_opts);
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckBroadcast(impl_amsg, CkIndex_Patch::idx_doOneStep_void(),0);
}

// Entry point registration function
int CkIndex_Patch::reg_doOneStep_void() {
  int epidx = CkRegisterEp("doOneStep()",
      reinterpret_cast<CkCallFnPtr>(_call_doOneStep_void), 0, __idx, 0);
  return epidx;
}

void CkIndex_Patch::_call_doOneStep_void(void* impl_msg, void* impl_obj_void)
{
  Patch* impl_obj = static_cast<Patch*>(impl_obj_void);
  impl_obj->doOneStep();
  if(UsrToEnv(impl_msg)->isVarSysMsg() == 0)
    CkFreeSysMsg(impl_msg);
}
PUPable_def(SINGLE_ARG(Closure_Patch::doOneStep_2_closure))
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void getAtomsFromAPatch(int atomsCnt, const AtomInfo *recvAtoms);
 */
void CProxy_Patch::getAtomsFromAPatch(int atomsCnt, const AtomInfo *recvAtoms, const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  //Marshall: int atomsCnt, const AtomInfo *recvAtoms
  int impl_off=0;
  int impl_arrstart=0;
  int impl_off_recvAtoms, impl_cnt_recvAtoms;
  impl_off_recvAtoms=impl_off=CK_ALIGN(impl_off,sizeof(AtomInfo));
  impl_off+=(impl_cnt_recvAtoms=sizeof(AtomInfo)*(atomsCnt));
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|atomsCnt;
    implP|impl_off_recvAtoms;
    implP|impl_cnt_recvAtoms;
    impl_arrstart=CK_ALIGN(implP.size(),16);
    impl_off+=impl_arrstart;
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|atomsCnt;
    implP|impl_off_recvAtoms;
    implP|impl_cnt_recvAtoms;
  }
  char *impl_buf=impl_msg->msgBuf+impl_arrstart;
  memcpy(impl_buf+impl_off_recvAtoms,recvAtoms,impl_cnt_recvAtoms);
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckBroadcast(impl_amsg, CkIndex_Patch::idx_getAtomsFromAPatch_marshall3(),0);
}

// Entry point registration function
int CkIndex_Patch::reg_getAtomsFromAPatch_marshall3() {
  int epidx = CkRegisterEp("getAtomsFromAPatch(int atomsCnt, const AtomInfo *recvAtoms)",
      reinterpret_cast<CkCallFnPtr>(_call_getAtomsFromAPatch_marshall3), CkMarshallMsg::__idx, __idx, 0+CK_EP_NOKEEP);
  CkRegisterMarshallUnpackFn(epidx, _callmarshall_getAtomsFromAPatch_marshall3);
  CkRegisterMessagePupFn(epidx, _marshallmessagepup_getAtomsFromAPatch_marshall3);

  return epidx;
}

void CkIndex_Patch::_call_getAtomsFromAPatch_marshall3(void* impl_msg, void* impl_obj_void)
{
  Patch* impl_obj = static_cast<Patch*>(impl_obj_void);
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  envelope *env = UsrToEnv(impl_msg_typed);
  /*Unmarshall pup'd fields: int atomsCnt, const AtomInfo *recvAtoms*/
  PUP::fromMem implP(impl_buf);
  PUP::detail::TemporaryObjectHolder<int> atomsCnt;
  implP|atomsCnt;
  int impl_off_recvAtoms, impl_cnt_recvAtoms;
  implP|impl_off_recvAtoms;
  implP|impl_cnt_recvAtoms;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  AtomInfo *recvAtoms=(AtomInfo *)(impl_buf+impl_off_recvAtoms);
  impl_obj->getAtomsFromAPatch(std::move(atomsCnt.t), recvAtoms);
}
int CkIndex_Patch::_callmarshall_getAtomsFromAPatch_marshall3(char* impl_buf, void* impl_obj_void) {
  Patch* impl_obj = static_cast<Patch*>(impl_obj_void);
  envelope *env = UsrToEnv(impl_buf);
  /*Unmarshall pup'd fields: int atomsCnt, const AtomInfo *recvAtoms*/
  PUP::fromMem implP(impl_buf);
  PUP::detail::TemporaryObjectHolder<int> atomsCnt;
  implP|atomsCnt;
  int impl_off_recvAtoms, impl_cnt_recvAtoms;
  implP|impl_off_recvAtoms;
  implP|impl_cnt_recvAtoms;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  AtomInfo *recvAtoms=(AtomInfo *)(impl_buf+impl_off_recvAtoms);
  impl_obj->getAtomsFromAPatch(std::move(atomsCnt.t), recvAtoms);
  return implP.size();
}
void CkIndex_Patch::_marshallmessagepup_getAtomsFromAPatch_marshall3(PUP::er &implDestP,void *impl_msg) {
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  envelope *env = UsrToEnv(impl_msg_typed);
  /*Unmarshall pup'd fields: int atomsCnt, const AtomInfo *recvAtoms*/
  PUP::fromMem implP(impl_buf);
  PUP::detail::TemporaryObjectHolder<int> atomsCnt;
  implP|atomsCnt;
  int impl_off_recvAtoms, impl_cnt_recvAtoms;
  implP|impl_off_recvAtoms;
  implP|impl_cnt_recvAtoms;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  AtomInfo *recvAtoms=(AtomInfo *)(impl_buf+impl_off_recvAtoms);
  if (implDestP.hasComments()) implDestP.comment("atomsCnt");
  implDestP|atomsCnt;
  if (implDestP.hasComments()) implDestP.comment("recvAtoms");
  implDestP.synchronize(PUP::sync_begin_array);
  for (int impl_i=0;impl_i*(sizeof(*recvAtoms))<impl_cnt_recvAtoms;impl_i++) {
    implDestP.synchronize(PUP::sync_item);
    implDestP|recvAtoms[impl_i];
  }
  implDestP.synchronize(PUP::sync_end_array);
}
PUPable_def(SINGLE_ARG(Closure_Patch::getAtomsFromAPatch_3_closure))
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: Patch(CkMigrateMessage* impl_msg);
 */

// Entry point registration function
int CkIndex_Patch::reg_Patch_CkMigrateMessage() {
  int epidx = CkRegisterEp("Patch(CkMigrateMessage* impl_msg)",
      reinterpret_cast<CkCallFnPtr>(_call_Patch_CkMigrateMessage), 0, __idx, 0);
  return epidx;
}

void CkIndex_Patch::_call_Patch_CkMigrateMessage(void* impl_msg, void* impl_obj_void)
{
  call_migration_constructor<Patch> c = impl_obj_void;
  c((CkMigrateMessage*)impl_msg);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: Patch();
 */
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void doOneStep();
 */
void CProxySection_Patch::doOneStep(const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg(impl_e_opts);
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Patch::idx_doOneStep_void(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void getAtomsFromAPatch(int atomsCnt, const AtomInfo *recvAtoms);
 */
void CProxySection_Patch::getAtomsFromAPatch(int atomsCnt, const AtomInfo *recvAtoms, const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  //Marshall: int atomsCnt, const AtomInfo *recvAtoms
  int impl_off=0;
  int impl_arrstart=0;
  int impl_off_recvAtoms, impl_cnt_recvAtoms;
  impl_off_recvAtoms=impl_off=CK_ALIGN(impl_off,sizeof(AtomInfo));
  impl_off+=(impl_cnt_recvAtoms=sizeof(AtomInfo)*(atomsCnt));
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|atomsCnt;
    implP|impl_off_recvAtoms;
    implP|impl_cnt_recvAtoms;
    impl_arrstart=CK_ALIGN(implP.size(),16);
    impl_off+=impl_arrstart;
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|atomsCnt;
    implP|impl_off_recvAtoms;
    implP|impl_cnt_recvAtoms;
  }
  char *impl_buf=impl_msg->msgBuf+impl_arrstart;
  memcpy(impl_buf+impl_off_recvAtoms,recvAtoms,impl_cnt_recvAtoms);
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Patch::idx_getAtomsFromAPatch_marshall3(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: Patch(CkMigrateMessage* impl_msg);
 */
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
void CkIndex_Patch::__register(const char *s, size_t size) {
  __idx = CkRegisterChare(s, size, TypeArray);
  CkRegisterArrayDimensions(__idx, 1);
  CkRegisterBase(__idx, CkIndex_ArrayElement::__idx);
  // REG: Patch();
  idx_Patch_void();
  CkRegisterDefaultCtor(__idx, idx_Patch_void());

  // REG: void doOneStep();
  idx_doOneStep_void();

  // REG: void getAtomsFromAPatch(int atomsCnt, const AtomInfo *recvAtoms);
  idx_getAtomsFromAPatch_marshall3();

  // REG: Patch(CkMigrateMessage* impl_msg);
  idx_Patch_CkMigrateMessage();
  CkRegisterMigCtor(__idx, idx_Patch_CkMigrateMessage());

}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
void _registermd_charm(void)
{
  static int _done = 0; if(_done) return; _done = 1;
  CkRegisterReadonly("mainControl","CProxy_Control",sizeof(mainControl),(void *) &mainControl,__xlater_roPup_mainControl);

/* REG: mainchare Control: Chare{
Control(CkArgMsg* impl_msg);
void finishOneStep(double impl_noname_0, double impl_noname_1);
};
*/
  CkIndex_Control::__register("Control", sizeof(Control));

/* REG: array Patch: ArrayElement{
Patch();
void doOneStep();
void getAtomsFromAPatch(int atomsCnt, const AtomInfo *recvAtoms);
Patch(CkMigrateMessage* impl_msg);
};
*/
  CkIndex_Patch::__register("Patch", sizeof(Patch));

}
extern "C" void CkRegisterMainModule(void) {
  _registermd_charm();
}
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
template <>
void CBase_Control::virtual_pup(PUP::er &p) {
    recursive_pup<Control>(dynamic_cast<Control*>(this), p);
}
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
template <>
void CBase_Patch::virtual_pup(PUP::er &p) {
    recursive_pup<Patch>(dynamic_cast<Patch*>(this), p);
}
#endif /* CK_TEMPLATES_ONLY */
