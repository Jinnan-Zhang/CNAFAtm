// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dOdOdIsrcdISimEventDict
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
#include "SimEvent.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_JMcLcLSimEvent(void *p = 0);
   static void *newArray_JMcLcLSimEvent(Long_t size, void *p);
   static void delete_JMcLcLSimEvent(void *p);
   static void deleteArray_JMcLcLSimEvent(void *p);
   static void destruct_JMcLcLSimEvent(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::JM::SimEvent*)
   {
      ::JM::SimEvent *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::JM::SimEvent >(0);
      static ::ROOT::TGenericClassInfo 
         instance("JM::SimEvent", ::JM::SimEvent::Class_Version(), "SimEvent.h", 17,
                  typeid(::JM::SimEvent), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::JM::SimEvent::Dictionary, isa_proxy, 4,
                  sizeof(::JM::SimEvent) );
      instance.SetNew(&new_JMcLcLSimEvent);
      instance.SetNewArray(&newArray_JMcLcLSimEvent);
      instance.SetDelete(&delete_JMcLcLSimEvent);
      instance.SetDeleteArray(&deleteArray_JMcLcLSimEvent);
      instance.SetDestructor(&destruct_JMcLcLSimEvent);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::JM::SimEvent*)
   {
      return GenerateInitInstanceLocal((::JM::SimEvent*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::JM::SimEvent*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace JM {
//______________________________________________________________________________
atomic_TClass_ptr SimEvent::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *SimEvent::Class_Name()
{
   return "JM::SimEvent";
}

//______________________________________________________________________________
const char *SimEvent::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::JM::SimEvent*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int SimEvent::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::JM::SimEvent*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *SimEvent::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::JM::SimEvent*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *SimEvent::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::JM::SimEvent*)0x0)->GetClass(); }
   return fgIsA;
}

} // namespace JM
namespace JM {
//______________________________________________________________________________
void SimEvent::Streamer(TBuffer &R__b)
{
   // Stream an object of class JM::SimEvent.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(JM::SimEvent::Class(),this);
   } else {
      R__b.WriteClassBuffer(JM::SimEvent::Class(),this);
   }
}

} // namespace JM
namespace ROOT {
   // Wrappers around operator new
   static void *new_JMcLcLSimEvent(void *p) {
      return  p ? new(p) ::JM::SimEvent : new ::JM::SimEvent;
   }
   static void *newArray_JMcLcLSimEvent(Long_t nElements, void *p) {
      return p ? new(p) ::JM::SimEvent[nElements] : new ::JM::SimEvent[nElements];
   }
   // Wrapper around operator delete
   static void delete_JMcLcLSimEvent(void *p) {
      delete ((::JM::SimEvent*)p);
   }
   static void deleteArray_JMcLcLSimEvent(void *p) {
      delete [] ((::JM::SimEvent*)p);
   }
   static void destruct_JMcLcLSimEvent(void *p) {
      typedef ::JM::SimEvent current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::JM::SimEvent

namespace ROOT {
   static TClass *vectorlEJMcLcLSimTrackmUgR_Dictionary();
   static void vectorlEJMcLcLSimTrackmUgR_TClassManip(TClass*);
   static void *new_vectorlEJMcLcLSimTrackmUgR(void *p = 0);
   static void *newArray_vectorlEJMcLcLSimTrackmUgR(Long_t size, void *p);
   static void delete_vectorlEJMcLcLSimTrackmUgR(void *p);
   static void deleteArray_vectorlEJMcLcLSimTrackmUgR(void *p);
   static void destruct_vectorlEJMcLcLSimTrackmUgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<JM::SimTrack*>*)
   {
      vector<JM::SimTrack*> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<JM::SimTrack*>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<JM::SimTrack*>", -2, "vector", 339,
                  typeid(vector<JM::SimTrack*>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEJMcLcLSimTrackmUgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<JM::SimTrack*>) );
      instance.SetNew(&new_vectorlEJMcLcLSimTrackmUgR);
      instance.SetNewArray(&newArray_vectorlEJMcLcLSimTrackmUgR);
      instance.SetDelete(&delete_vectorlEJMcLcLSimTrackmUgR);
      instance.SetDeleteArray(&deleteArray_vectorlEJMcLcLSimTrackmUgR);
      instance.SetDestructor(&destruct_vectorlEJMcLcLSimTrackmUgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<JM::SimTrack*> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<JM::SimTrack*>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEJMcLcLSimTrackmUgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<JM::SimTrack*>*)0x0)->GetClass();
      vectorlEJMcLcLSimTrackmUgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEJMcLcLSimTrackmUgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEJMcLcLSimTrackmUgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<JM::SimTrack*> : new vector<JM::SimTrack*>;
   }
   static void *newArray_vectorlEJMcLcLSimTrackmUgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<JM::SimTrack*>[nElements] : new vector<JM::SimTrack*>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEJMcLcLSimTrackmUgR(void *p) {
      delete ((vector<JM::SimTrack*>*)p);
   }
   static void deleteArray_vectorlEJMcLcLSimTrackmUgR(void *p) {
      delete [] ((vector<JM::SimTrack*>*)p);
   }
   static void destruct_vectorlEJMcLcLSimTrackmUgR(void *p) {
      typedef vector<JM::SimTrack*> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<JM::SimTrack*>

namespace ROOT {
   static TClass *vectorlEJMcLcLSimTTHitmUgR_Dictionary();
   static void vectorlEJMcLcLSimTTHitmUgR_TClassManip(TClass*);
   static void *new_vectorlEJMcLcLSimTTHitmUgR(void *p = 0);
   static void *newArray_vectorlEJMcLcLSimTTHitmUgR(Long_t size, void *p);
   static void delete_vectorlEJMcLcLSimTTHitmUgR(void *p);
   static void deleteArray_vectorlEJMcLcLSimTTHitmUgR(void *p);
   static void destruct_vectorlEJMcLcLSimTTHitmUgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<JM::SimTTHit*>*)
   {
      vector<JM::SimTTHit*> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<JM::SimTTHit*>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<JM::SimTTHit*>", -2, "vector", 339,
                  typeid(vector<JM::SimTTHit*>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEJMcLcLSimTTHitmUgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<JM::SimTTHit*>) );
      instance.SetNew(&new_vectorlEJMcLcLSimTTHitmUgR);
      instance.SetNewArray(&newArray_vectorlEJMcLcLSimTTHitmUgR);
      instance.SetDelete(&delete_vectorlEJMcLcLSimTTHitmUgR);
      instance.SetDeleteArray(&deleteArray_vectorlEJMcLcLSimTTHitmUgR);
      instance.SetDestructor(&destruct_vectorlEJMcLcLSimTTHitmUgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<JM::SimTTHit*> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<JM::SimTTHit*>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEJMcLcLSimTTHitmUgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<JM::SimTTHit*>*)0x0)->GetClass();
      vectorlEJMcLcLSimTTHitmUgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEJMcLcLSimTTHitmUgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEJMcLcLSimTTHitmUgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<JM::SimTTHit*> : new vector<JM::SimTTHit*>;
   }
   static void *newArray_vectorlEJMcLcLSimTTHitmUgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<JM::SimTTHit*>[nElements] : new vector<JM::SimTTHit*>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEJMcLcLSimTTHitmUgR(void *p) {
      delete ((vector<JM::SimTTHit*>*)p);
   }
   static void deleteArray_vectorlEJMcLcLSimTTHitmUgR(void *p) {
      delete [] ((vector<JM::SimTTHit*>*)p);
   }
   static void destruct_vectorlEJMcLcLSimTTHitmUgR(void *p) {
      typedef vector<JM::SimTTHit*> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<JM::SimTTHit*>

namespace ROOT {
   static TClass *vectorlEJMcLcLSimPMTHitmUgR_Dictionary();
   static void vectorlEJMcLcLSimPMTHitmUgR_TClassManip(TClass*);
   static void *new_vectorlEJMcLcLSimPMTHitmUgR(void *p = 0);
   static void *newArray_vectorlEJMcLcLSimPMTHitmUgR(Long_t size, void *p);
   static void delete_vectorlEJMcLcLSimPMTHitmUgR(void *p);
   static void deleteArray_vectorlEJMcLcLSimPMTHitmUgR(void *p);
   static void destruct_vectorlEJMcLcLSimPMTHitmUgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<JM::SimPMTHit*>*)
   {
      vector<JM::SimPMTHit*> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<JM::SimPMTHit*>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<JM::SimPMTHit*>", -2, "vector", 339,
                  typeid(vector<JM::SimPMTHit*>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEJMcLcLSimPMTHitmUgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<JM::SimPMTHit*>) );
      instance.SetNew(&new_vectorlEJMcLcLSimPMTHitmUgR);
      instance.SetNewArray(&newArray_vectorlEJMcLcLSimPMTHitmUgR);
      instance.SetDelete(&delete_vectorlEJMcLcLSimPMTHitmUgR);
      instance.SetDeleteArray(&deleteArray_vectorlEJMcLcLSimPMTHitmUgR);
      instance.SetDestructor(&destruct_vectorlEJMcLcLSimPMTHitmUgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<JM::SimPMTHit*> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<JM::SimPMTHit*>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEJMcLcLSimPMTHitmUgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<JM::SimPMTHit*>*)0x0)->GetClass();
      vectorlEJMcLcLSimPMTHitmUgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEJMcLcLSimPMTHitmUgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEJMcLcLSimPMTHitmUgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<JM::SimPMTHit*> : new vector<JM::SimPMTHit*>;
   }
   static void *newArray_vectorlEJMcLcLSimPMTHitmUgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<JM::SimPMTHit*>[nElements] : new vector<JM::SimPMTHit*>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEJMcLcLSimPMTHitmUgR(void *p) {
      delete ((vector<JM::SimPMTHit*>*)p);
   }
   static void deleteArray_vectorlEJMcLcLSimPMTHitmUgR(void *p) {
      delete [] ((vector<JM::SimPMTHit*>*)p);
   }
   static void destruct_vectorlEJMcLcLSimPMTHitmUgR(void *p) {
      typedef vector<JM::SimPMTHit*> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<JM::SimPMTHit*>

namespace {
  void TriggerDictionaryInitialization_SimEventDict_Impl() {
    static const char* headers[] = {
"SimEvent.h",
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
#line 1 "SimEventDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
namespace JM{class __attribute__((annotate("$clingAutoload$SimEvent.h")))  SimEvent;}
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "SimEventDict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "SimEvent.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"JM::SimEvent", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("SimEventDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_SimEventDict_Impl, {}, classesHeaders, /*has no C++ module*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_SimEventDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_SimEventDict() {
  TriggerDictionaryInitialization_SimEventDict_Impl();
}
