// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dOdOdIsrcdISimHeaderDict
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
#include "SimHeader.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_JMcLcLSimHeader(void *p = 0);
   static void *newArray_JMcLcLSimHeader(Long_t size, void *p);
   static void delete_JMcLcLSimHeader(void *p);
   static void deleteArray_JMcLcLSimHeader(void *p);
   static void destruct_JMcLcLSimHeader(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::JM::SimHeader*)
   {
      ::JM::SimHeader *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::JM::SimHeader >(0);
      static ::ROOT::TGenericClassInfo 
         instance("JM::SimHeader", ::JM::SimHeader::Class_Version(), "SimHeader.h", 11,
                  typeid(::JM::SimHeader), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::JM::SimHeader::Dictionary, isa_proxy, 4,
                  sizeof(::JM::SimHeader) );
      instance.SetNew(&new_JMcLcLSimHeader);
      instance.SetNewArray(&newArray_JMcLcLSimHeader);
      instance.SetDelete(&delete_JMcLcLSimHeader);
      instance.SetDeleteArray(&deleteArray_JMcLcLSimHeader);
      instance.SetDestructor(&destruct_JMcLcLSimHeader);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::JM::SimHeader*)
   {
      return GenerateInitInstanceLocal((::JM::SimHeader*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::JM::SimHeader*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace JM {
//______________________________________________________________________________
atomic_TClass_ptr SimHeader::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *SimHeader::Class_Name()
{
   return "JM::SimHeader";
}

//______________________________________________________________________________
const char *SimHeader::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::JM::SimHeader*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int SimHeader::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::JM::SimHeader*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *SimHeader::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::JM::SimHeader*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *SimHeader::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::JM::SimHeader*)0x0)->GetClass(); }
   return fgIsA;
}

} // namespace JM
namespace JM {
//______________________________________________________________________________
void SimHeader::Streamer(TBuffer &R__b)
{
   // Stream an object of class JM::SimHeader.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(JM::SimHeader::Class(),this);
   } else {
      R__b.WriteClassBuffer(JM::SimHeader::Class(),this);
   }
}

} // namespace JM
namespace ROOT {
   // Wrappers around operator new
   static void *new_JMcLcLSimHeader(void *p) {
      return  p ? new(p) ::JM::SimHeader : new ::JM::SimHeader;
   }
   static void *newArray_JMcLcLSimHeader(Long_t nElements, void *p) {
      return p ? new(p) ::JM::SimHeader[nElements] : new ::JM::SimHeader[nElements];
   }
   // Wrapper around operator delete
   static void delete_JMcLcLSimHeader(void *p) {
      delete ((::JM::SimHeader*)p);
   }
   static void deleteArray_JMcLcLSimHeader(void *p) {
      delete [] ((::JM::SimHeader*)p);
   }
   static void destruct_JMcLcLSimHeader(void *p) {
      typedef ::JM::SimHeader current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::JM::SimHeader

namespace {
  void TriggerDictionaryInitialization_SimHeaderDict_Impl() {
    static const char* headers[] = {
"SimHeader.h",
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
#line 1 "SimHeaderDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
namespace JM{class __attribute__((annotate("$clingAutoload$SimHeader.h")))  SimHeader;}
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "SimHeaderDict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "SimHeader.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"JM::SimHeader", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("SimHeaderDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_SimHeaderDict_Impl, {}, classesHeaders, /*has no C++ module*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_SimHeaderDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_SimHeaderDict() {
  TriggerDictionaryInitialization_SimHeaderDict_Impl();
}
