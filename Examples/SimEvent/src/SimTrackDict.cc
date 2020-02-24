// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dOdOdIsrcdISimTrackDict
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
#include "SimTrack.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_JMcLcLSimTrack(void *p = 0);
   static void *newArray_JMcLcLSimTrack(Long_t size, void *p);
   static void delete_JMcLcLSimTrack(void *p);
   static void deleteArray_JMcLcLSimTrack(void *p);
   static void destruct_JMcLcLSimTrack(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::JM::SimTrack*)
   {
      ::JM::SimTrack *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::JM::SimTrack >(0);
      static ::ROOT::TGenericClassInfo 
         instance("JM::SimTrack", ::JM::SimTrack::Class_Version(), "SimTrack.h", 9,
                  typeid(::JM::SimTrack), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::JM::SimTrack::Dictionary, isa_proxy, 4,
                  sizeof(::JM::SimTrack) );
      instance.SetNew(&new_JMcLcLSimTrack);
      instance.SetNewArray(&newArray_JMcLcLSimTrack);
      instance.SetDelete(&delete_JMcLcLSimTrack);
      instance.SetDeleteArray(&deleteArray_JMcLcLSimTrack);
      instance.SetDestructor(&destruct_JMcLcLSimTrack);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::JM::SimTrack*)
   {
      return GenerateInitInstanceLocal((::JM::SimTrack*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::JM::SimTrack*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace JM {
//______________________________________________________________________________
atomic_TClass_ptr SimTrack::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *SimTrack::Class_Name()
{
   return "JM::SimTrack";
}

//______________________________________________________________________________
const char *SimTrack::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::JM::SimTrack*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int SimTrack::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::JM::SimTrack*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *SimTrack::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::JM::SimTrack*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *SimTrack::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::JM::SimTrack*)0x0)->GetClass(); }
   return fgIsA;
}

} // namespace JM
namespace JM {
//______________________________________________________________________________
void SimTrack::Streamer(TBuffer &R__b)
{
   // Stream an object of class JM::SimTrack.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(JM::SimTrack::Class(),this);
   } else {
      R__b.WriteClassBuffer(JM::SimTrack::Class(),this);
   }
}

} // namespace JM
namespace ROOT {
   // Wrappers around operator new
   static void *new_JMcLcLSimTrack(void *p) {
      return  p ? new(p) ::JM::SimTrack : new ::JM::SimTrack;
   }
   static void *newArray_JMcLcLSimTrack(Long_t nElements, void *p) {
      return p ? new(p) ::JM::SimTrack[nElements] : new ::JM::SimTrack[nElements];
   }
   // Wrapper around operator delete
   static void delete_JMcLcLSimTrack(void *p) {
      delete ((::JM::SimTrack*)p);
   }
   static void deleteArray_JMcLcLSimTrack(void *p) {
      delete [] ((::JM::SimTrack*)p);
   }
   static void destruct_JMcLcLSimTrack(void *p) {
      typedef ::JM::SimTrack current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::JM::SimTrack

namespace ROOT {
   static TClass *vectorlEJMcLcLSimTrackgR_Dictionary();
   static void vectorlEJMcLcLSimTrackgR_TClassManip(TClass*);
   static void *new_vectorlEJMcLcLSimTrackgR(void *p = 0);
   static void *newArray_vectorlEJMcLcLSimTrackgR(Long_t size, void *p);
   static void delete_vectorlEJMcLcLSimTrackgR(void *p);
   static void deleteArray_vectorlEJMcLcLSimTrackgR(void *p);
   static void destruct_vectorlEJMcLcLSimTrackgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<JM::SimTrack>*)
   {
      vector<JM::SimTrack> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<JM::SimTrack>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<JM::SimTrack>", -2, "vector", 339,
                  typeid(vector<JM::SimTrack>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEJMcLcLSimTrackgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<JM::SimTrack>) );
      instance.SetNew(&new_vectorlEJMcLcLSimTrackgR);
      instance.SetNewArray(&newArray_vectorlEJMcLcLSimTrackgR);
      instance.SetDelete(&delete_vectorlEJMcLcLSimTrackgR);
      instance.SetDeleteArray(&deleteArray_vectorlEJMcLcLSimTrackgR);
      instance.SetDestructor(&destruct_vectorlEJMcLcLSimTrackgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<JM::SimTrack> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<JM::SimTrack>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEJMcLcLSimTrackgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<JM::SimTrack>*)0x0)->GetClass();
      vectorlEJMcLcLSimTrackgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEJMcLcLSimTrackgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEJMcLcLSimTrackgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<JM::SimTrack> : new vector<JM::SimTrack>;
   }
   static void *newArray_vectorlEJMcLcLSimTrackgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<JM::SimTrack>[nElements] : new vector<JM::SimTrack>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEJMcLcLSimTrackgR(void *p) {
      delete ((vector<JM::SimTrack>*)p);
   }
   static void deleteArray_vectorlEJMcLcLSimTrackgR(void *p) {
      delete [] ((vector<JM::SimTrack>*)p);
   }
   static void destruct_vectorlEJMcLcLSimTrackgR(void *p) {
      typedef vector<JM::SimTrack> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<JM::SimTrack>

namespace {
  void TriggerDictionaryInitialization_SimTrackDict_Impl() {
    static const char* headers[] = {
"SimTrack.h",
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
#line 1 "SimTrackDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
namespace JM{class __attribute__((annotate("$clingAutoload$SimTrack.h")))  SimTrack;}
namespace std{template <typename _Tp> class __attribute__((annotate("$clingAutoload$bits/allocator.h")))  __attribute__((annotate("$clingAutoload$string")))  allocator;
}
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "SimTrackDict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "SimTrack.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"JM::SimTrack", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("SimTrackDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_SimTrackDict_Impl, {}, classesHeaders, /*has no C++ module*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_SimTrackDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_SimTrackDict() {
  TriggerDictionaryInitialization_SimTrackDict_Impl();
}
