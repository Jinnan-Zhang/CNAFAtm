// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dOdOdIsrcdIHeaderObjectDict
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
#include "HeaderObject.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void delete_JMcLcLHeaderObject(void *p);
   static void deleteArray_JMcLcLHeaderObject(void *p);
   static void destruct_JMcLcLHeaderObject(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::JM::HeaderObject*)
   {
      ::JM::HeaderObject *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::JM::HeaderObject >(0);
      static ::ROOT::TGenericClassInfo 
         instance("JM::HeaderObject", ::JM::HeaderObject::Class_Version(), "HeaderObject.h", 37,
                  typeid(::JM::HeaderObject), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::JM::HeaderObject::Dictionary, isa_proxy, 4,
                  sizeof(::JM::HeaderObject) );
      instance.SetDelete(&delete_JMcLcLHeaderObject);
      instance.SetDeleteArray(&deleteArray_JMcLcLHeaderObject);
      instance.SetDestructor(&destruct_JMcLcLHeaderObject);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::JM::HeaderObject*)
   {
      return GenerateInitInstanceLocal((::JM::HeaderObject*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::JM::HeaderObject*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace JM {
//______________________________________________________________________________
atomic_TClass_ptr HeaderObject::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *HeaderObject::Class_Name()
{
   return "JM::HeaderObject";
}

//______________________________________________________________________________
const char *HeaderObject::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::JM::HeaderObject*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int HeaderObject::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::JM::HeaderObject*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *HeaderObject::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::JM::HeaderObject*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *HeaderObject::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::JM::HeaderObject*)0x0)->GetClass(); }
   return fgIsA;
}

} // namespace JM
namespace JM {
//______________________________________________________________________________
void HeaderObject::Streamer(TBuffer &R__b)
{
   // Stream an object of class JM::HeaderObject.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(JM::HeaderObject::Class(),this);
   } else {
      R__b.WriteClassBuffer(JM::HeaderObject::Class(),this);
   }
}

} // namespace JM
namespace ROOT {
   // Wrapper around operator delete
   static void delete_JMcLcLHeaderObject(void *p) {
      delete ((::JM::HeaderObject*)p);
   }
   static void deleteArray_JMcLcLHeaderObject(void *p) {
      delete [] ((::JM::HeaderObject*)p);
   }
   static void destruct_JMcLcLHeaderObject(void *p) {
      typedef ::JM::HeaderObject current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::JM::HeaderObject

namespace {
  void TriggerDictionaryInitialization_HeaderObjectDict_Impl() {
    static const char* headers[] = {
"HeaderObject.h",
0
    };
    static const char* includePaths[] = {
"/afs/ihep.ac.cn/soft/juno/JUNO-ALL-SLC7/Pre-Release/J19v1r1-branch/ExternalLibs/ROOT/6.18.00/include",
"/afs/ihep.ac.cn/soft/juno/JUNO-ALL-SLC7/Pre-Release/J19v1r1-branch/offline/DataModel/BaseEvent/Event/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "HeaderObjectDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
namespace JM{class __attribute__((annotate("$clingAutoload$HeaderObject.h")))  HeaderObject;}
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "HeaderObjectDict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "HeaderObject.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"JM::HeaderObject", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("HeaderObjectDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_HeaderObjectDict_Impl, {}, classesHeaders, /*has no C++ module*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_HeaderObjectDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_HeaderObjectDict() {
  TriggerDictionaryInitialization_HeaderObjectDict_Impl();
}
