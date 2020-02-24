// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dOdOdIsrcdISmartRefDict
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
#include "SmartRef.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_JMcLcLSmartRef(void *p = 0);
   static void *newArray_JMcLcLSmartRef(Long_t size, void *p);
   static void delete_JMcLcLSmartRef(void *p);
   static void deleteArray_JMcLcLSmartRef(void *p);
   static void destruct_JMcLcLSmartRef(void *p);
   static void streamer_JMcLcLSmartRef(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::JM::SmartRef*)
   {
      ::JM::SmartRef *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::JM::SmartRef >(0);
      static ::ROOT::TGenericClassInfo 
         instance("JM::SmartRef", ::JM::SmartRef::Class_Version(), "SmartRef.h", 16,
                  typeid(::JM::SmartRef), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::JM::SmartRef::Dictionary, isa_proxy, 17,
                  sizeof(::JM::SmartRef) );
      instance.SetNew(&new_JMcLcLSmartRef);
      instance.SetNewArray(&newArray_JMcLcLSmartRef);
      instance.SetDelete(&delete_JMcLcLSmartRef);
      instance.SetDeleteArray(&deleteArray_JMcLcLSmartRef);
      instance.SetDestructor(&destruct_JMcLcLSmartRef);
      instance.SetStreamerFunc(&streamer_JMcLcLSmartRef);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::JM::SmartRef*)
   {
      return GenerateInitInstanceLocal((::JM::SmartRef*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::JM::SmartRef*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace JM {
//______________________________________________________________________________
atomic_TClass_ptr SmartRef::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *SmartRef::Class_Name()
{
   return "JM::SmartRef";
}

//______________________________________________________________________________
const char *SmartRef::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::JM::SmartRef*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int SmartRef::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::JM::SmartRef*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *SmartRef::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::JM::SmartRef*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *SmartRef::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::JM::SmartRef*)0x0)->GetClass(); }
   return fgIsA;
}

} // namespace JM
namespace ROOT {
   // Wrappers around operator new
   static void *new_JMcLcLSmartRef(void *p) {
      return  p ? new(p) ::JM::SmartRef : new ::JM::SmartRef;
   }
   static void *newArray_JMcLcLSmartRef(Long_t nElements, void *p) {
      return p ? new(p) ::JM::SmartRef[nElements] : new ::JM::SmartRef[nElements];
   }
   // Wrapper around operator delete
   static void delete_JMcLcLSmartRef(void *p) {
      delete ((::JM::SmartRef*)p);
   }
   static void deleteArray_JMcLcLSmartRef(void *p) {
      delete [] ((::JM::SmartRef*)p);
   }
   static void destruct_JMcLcLSmartRef(void *p) {
      typedef ::JM::SmartRef current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_JMcLcLSmartRef(TBuffer &buf, void *obj) {
      ((::JM::SmartRef*)obj)->::JM::SmartRef::Streamer(buf);
   }
} // end of namespace ROOT for class ::JM::SmartRef

namespace {
  void TriggerDictionaryInitialization_SmartRefDict_Impl() {
    static const char* headers[] = {
"SmartRef.h",
0
    };
    static const char* includePaths[] = {
"/afs/ihep.ac.cn/soft/juno/JUNO-ALL-SLC7/Pre-Release/J19v1r1-branch/ExternalLibs/ROOT/6.18.00/include",
"/afs/ihep.ac.cn/soft/juno/JUNO-ALL-SLC7/Pre-Release/J19v1r1-branch/offline/DataModel/EDMUtil/EDMUtil/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "SmartRefDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
namespace JM{class __attribute__((annotate("$clingAutoload$SmartRef.h")))  SmartRef;}
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "SmartRefDict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "SmartRef.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"JM::SmartRef", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("SmartRefDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_SmartRefDict_Impl, {}, classesHeaders, /*has no C++ module*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_SmartRefDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_SmartRefDict() {
  TriggerDictionaryInitialization_SmartRefDict_Impl();
}
