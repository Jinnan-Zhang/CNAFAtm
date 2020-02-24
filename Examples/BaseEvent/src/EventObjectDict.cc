// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dOdOdIsrcdIEventObjectDict
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
#include "EventObject.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_JMcLcLEventObject(void *p = 0);
   static void *newArray_JMcLcLEventObject(Long_t size, void *p);
   static void delete_JMcLcLEventObject(void *p);
   static void deleteArray_JMcLcLEventObject(void *p);
   static void destruct_JMcLcLEventObject(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::JM::EventObject*)
   {
      ::JM::EventObject *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::JM::EventObject >(0);
      static ::ROOT::TGenericClassInfo 
         instance("JM::EventObject", ::JM::EventObject::Class_Version(), "EventObject.h", 37,
                  typeid(::JM::EventObject), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::JM::EventObject::Dictionary, isa_proxy, 4,
                  sizeof(::JM::EventObject) );
      instance.SetNew(&new_JMcLcLEventObject);
      instance.SetNewArray(&newArray_JMcLcLEventObject);
      instance.SetDelete(&delete_JMcLcLEventObject);
      instance.SetDeleteArray(&deleteArray_JMcLcLEventObject);
      instance.SetDestructor(&destruct_JMcLcLEventObject);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::JM::EventObject*)
   {
      return GenerateInitInstanceLocal((::JM::EventObject*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::JM::EventObject*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace JM {
//______________________________________________________________________________
atomic_TClass_ptr EventObject::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *EventObject::Class_Name()
{
   return "JM::EventObject";
}

//______________________________________________________________________________
const char *EventObject::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::JM::EventObject*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int EventObject::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::JM::EventObject*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *EventObject::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::JM::EventObject*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *EventObject::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::JM::EventObject*)0x0)->GetClass(); }
   return fgIsA;
}

} // namespace JM
namespace JM {
//______________________________________________________________________________
void EventObject::Streamer(TBuffer &R__b)
{
   // Stream an object of class JM::EventObject.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(JM::EventObject::Class(),this);
   } else {
      R__b.WriteClassBuffer(JM::EventObject::Class(),this);
   }
}

} // namespace JM
namespace ROOT {
   // Wrappers around operator new
   static void *new_JMcLcLEventObject(void *p) {
      return  p ? new(p) ::JM::EventObject : new ::JM::EventObject;
   }
   static void *newArray_JMcLcLEventObject(Long_t nElements, void *p) {
      return p ? new(p) ::JM::EventObject[nElements] : new ::JM::EventObject[nElements];
   }
   // Wrapper around operator delete
   static void delete_JMcLcLEventObject(void *p) {
      delete ((::JM::EventObject*)p);
   }
   static void deleteArray_JMcLcLEventObject(void *p) {
      delete [] ((::JM::EventObject*)p);
   }
   static void destruct_JMcLcLEventObject(void *p) {
      typedef ::JM::EventObject current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::JM::EventObject

namespace {
  void TriggerDictionaryInitialization_EventObjectDict_Impl() {
    static const char* headers[] = {
"EventObject.h",
0
    };
    static const char* includePaths[] = {
"/afs/ihep.ac.cn/soft/juno/JUNO-ALL-SLC7/Pre-Release/J19v1r1-branch/ExternalLibs/ROOT/6.18.00/include",
"/afs/ihep.ac.cn/soft/juno/JUNO-ALL-SLC7/Pre-Release/J19v1r1-branch/offline/DataModel/BaseEvent/Event/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "EventObjectDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
namespace JM{class __attribute__((annotate("$clingAutoload$EventObject.h")))  EventObject;}
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "EventObjectDict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "EventObject.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"JM::EventObject", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("EventObjectDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_EventObjectDict_Impl, {}, classesHeaders, /*has no C++ module*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_EventObjectDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_EventObjectDict() {
  TriggerDictionaryInitialization_EventObjectDict_Impl();
}
