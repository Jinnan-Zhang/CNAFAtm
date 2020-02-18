// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dOdOdIsrcdISimPMTHitDict
#define R__NO_DEPRECATION

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "RConfig.h"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// The generated code does not explicitly qualifies STL entities
namespace std {} using namespace std;

// Header files passed as explicit arguments
#include "SimPMTHit.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_JMcLcLSimPMTHit(void *p = 0);
   static void *newArray_JMcLcLSimPMTHit(Long_t size, void *p);
   static void delete_JMcLcLSimPMTHit(void *p);
   static void deleteArray_JMcLcLSimPMTHit(void *p);
   static void destruct_JMcLcLSimPMTHit(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::JM::SimPMTHit*)
   {
      ::JM::SimPMTHit *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::JM::SimPMTHit >(0);
      static ::ROOT::TGenericClassInfo 
         instance("JM::SimPMTHit", ::JM::SimPMTHit::Class_Version(), "SimPMTHit.h", 10,
                  typeid(::JM::SimPMTHit), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::JM::SimPMTHit::Dictionary, isa_proxy, 4,
                  sizeof(::JM::SimPMTHit) );
      instance.SetNew(&new_JMcLcLSimPMTHit);
      instance.SetNewArray(&newArray_JMcLcLSimPMTHit);
      instance.SetDelete(&delete_JMcLcLSimPMTHit);
      instance.SetDeleteArray(&deleteArray_JMcLcLSimPMTHit);
      instance.SetDestructor(&destruct_JMcLcLSimPMTHit);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::JM::SimPMTHit*)
   {
      return GenerateInitInstanceLocal((::JM::SimPMTHit*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::JM::SimPMTHit*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace JM {
//______________________________________________________________________________
atomic_TClass_ptr SimPMTHit::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *SimPMTHit::Class_Name()
{
   return "JM::SimPMTHit";
}

//______________________________________________________________________________
const char *SimPMTHit::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::JM::SimPMTHit*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int SimPMTHit::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::JM::SimPMTHit*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *SimPMTHit::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::JM::SimPMTHit*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *SimPMTHit::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::JM::SimPMTHit*)0x0)->GetClass(); }
   return fgIsA;
}

} // namespace JM
namespace JM {
//______________________________________________________________________________
void SimPMTHit::Streamer(TBuffer &R__b)
{
   // Stream an object of class JM::SimPMTHit.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(JM::SimPMTHit::Class(),this);
   } else {
      R__b.WriteClassBuffer(JM::SimPMTHit::Class(),this);
   }
}

} // namespace JM
namespace ROOT {
   // Wrappers around operator new
   static void *new_JMcLcLSimPMTHit(void *p) {
      return  p ? new(p) ::JM::SimPMTHit : new ::JM::SimPMTHit;
   }
   static void *newArray_JMcLcLSimPMTHit(Long_t nElements, void *p) {
      return p ? new(p) ::JM::SimPMTHit[nElements] : new ::JM::SimPMTHit[nElements];
   }
   // Wrapper around operator delete
   static void delete_JMcLcLSimPMTHit(void *p) {
      delete ((::JM::SimPMTHit*)p);
   }
   static void deleteArray_JMcLcLSimPMTHit(void *p) {
      delete [] ((::JM::SimPMTHit*)p);
   }
   static void destruct_JMcLcLSimPMTHit(void *p) {
      typedef ::JM::SimPMTHit current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::JM::SimPMTHit

namespace ROOT {
   static TClass *vectorlEJMcLcLSimPMTHitgR_Dictionary();
   static void vectorlEJMcLcLSimPMTHitgR_TClassManip(TClass*);
   static void *new_vectorlEJMcLcLSimPMTHitgR(void *p = 0);
   static void *newArray_vectorlEJMcLcLSimPMTHitgR(Long_t size, void *p);
   static void delete_vectorlEJMcLcLSimPMTHitgR(void *p);
   static void deleteArray_vectorlEJMcLcLSimPMTHitgR(void *p);
   static void destruct_vectorlEJMcLcLSimPMTHitgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<JM::SimPMTHit>*)
   {
      vector<JM::SimPMTHit> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<JM::SimPMTHit>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<JM::SimPMTHit>", -2, "vector", 339,
                  typeid(vector<JM::SimPMTHit>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEJMcLcLSimPMTHitgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<JM::SimPMTHit>) );
      instance.SetNew(&new_vectorlEJMcLcLSimPMTHitgR);
      instance.SetNewArray(&newArray_vectorlEJMcLcLSimPMTHitgR);
      instance.SetDelete(&delete_vectorlEJMcLcLSimPMTHitgR);
      instance.SetDeleteArray(&deleteArray_vectorlEJMcLcLSimPMTHitgR);
      instance.SetDestructor(&destruct_vectorlEJMcLcLSimPMTHitgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<JM::SimPMTHit> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<JM::SimPMTHit>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEJMcLcLSimPMTHitgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<JM::SimPMTHit>*)0x0)->GetClass();
      vectorlEJMcLcLSimPMTHitgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEJMcLcLSimPMTHitgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEJMcLcLSimPMTHitgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<JM::SimPMTHit> : new vector<JM::SimPMTHit>;
   }
   static void *newArray_vectorlEJMcLcLSimPMTHitgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<JM::SimPMTHit>[nElements] : new vector<JM::SimPMTHit>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEJMcLcLSimPMTHitgR(void *p) {
      delete ((vector<JM::SimPMTHit>*)p);
   }
   static void deleteArray_vectorlEJMcLcLSimPMTHitgR(void *p) {
      delete [] ((vector<JM::SimPMTHit>*)p);
   }
   static void destruct_vectorlEJMcLcLSimPMTHitgR(void *p) {
      typedef vector<JM::SimPMTHit> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<JM::SimPMTHit>

namespace {
  void TriggerDictionaryInitialization_SimPMTHitDict_Impl() {
    static const char* headers[] = {
"SimPMTHit.h",
0
    };
    static const char* includePaths[] = {
"/afs/ihep.ac.cn/soft/juno/JUNO-ALL-SLC7/Pre-Release/J19v1r1-branch/offline/DataModel/SimEventV2",
"/afs/ihep.ac.cn/soft/juno/JUNO-ALL-SLC7/Pre-Release/J19v1r1-branch/offline/DataModel/BaseEvent",
"/afs/ihep.ac.cn/soft/juno/JUNO-ALL-SLC7/Pre-Release/J19v1r1-branch/offline/DataModel/EDMUtil",
"/afs/ihep.ac.cn/soft/juno/JUNO-ALL-SLC7/Pre-Release/J19v1r1-branch/ExternalLibs/ROOT/6.18.00/include",
"/afs/ihep.ac.cn/soft/juno/JUNO-ALL-SLC7/Pre-Release/J19v1r1-branch/offline/DataModel/SimEventV2/Event/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "SimPMTHitDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
namespace JM{class __attribute__((annotate("$clingAutoload$SimPMTHit.h")))  SimPMTHit;}
namespace std{template <typename _Tp> class __attribute__((annotate("$clingAutoload$bits/allocator.h")))  __attribute__((annotate("$clingAutoload$string")))  allocator;
}
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "SimPMTHitDict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "SimPMTHit.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"JM::SimPMTHit", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("SimPMTHitDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_SimPMTHitDict_Impl, {}, classesHeaders, /*has no C++ module*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_SimPMTHitDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_SimPMTHitDict() {
  TriggerDictionaryInitialization_SimPMTHitDict_Impl();
}
