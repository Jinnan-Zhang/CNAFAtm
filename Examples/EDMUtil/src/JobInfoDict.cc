// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dOdOdIsrcdIJobInfoDict
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
#include "JobInfo.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_JobInfo(void *p = 0);
   static void *newArray_JobInfo(Long_t size, void *p);
   static void delete_JobInfo(void *p);
   static void deleteArray_JobInfo(void *p);
   static void destruct_JobInfo(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::JobInfo*)
   {
      ::JobInfo *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::JobInfo >(0);
      static ::ROOT::TGenericClassInfo 
         instance("JobInfo", ::JobInfo::Class_Version(), "JobInfo.h", 8,
                  typeid(::JobInfo), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::JobInfo::Dictionary, isa_proxy, 4,
                  sizeof(::JobInfo) );
      instance.SetNew(&new_JobInfo);
      instance.SetNewArray(&newArray_JobInfo);
      instance.SetDelete(&delete_JobInfo);
      instance.SetDeleteArray(&deleteArray_JobInfo);
      instance.SetDestructor(&destruct_JobInfo);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::JobInfo*)
   {
      return GenerateInitInstanceLocal((::JobInfo*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::JobInfo*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr JobInfo::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *JobInfo::Class_Name()
{
   return "JobInfo";
}

//______________________________________________________________________________
const char *JobInfo::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::JobInfo*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int JobInfo::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::JobInfo*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *JobInfo::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::JobInfo*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *JobInfo::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::JobInfo*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void JobInfo::Streamer(TBuffer &R__b)
{
   // Stream an object of class JobInfo.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(JobInfo::Class(),this);
   } else {
      R__b.WriteClassBuffer(JobInfo::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_JobInfo(void *p) {
      return  p ? new(p) ::JobInfo : new ::JobInfo;
   }
   static void *newArray_JobInfo(Long_t nElements, void *p) {
      return p ? new(p) ::JobInfo[nElements] : new ::JobInfo[nElements];
   }
   // Wrapper around operator delete
   static void delete_JobInfo(void *p) {
      delete ((::JobInfo*)p);
   }
   static void deleteArray_JobInfo(void *p) {
      delete [] ((::JobInfo*)p);
   }
   static void destruct_JobInfo(void *p) {
      typedef ::JobInfo current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::JobInfo

namespace {
  void TriggerDictionaryInitialization_JobInfoDict_Impl() {
    static const char* headers[] = {
"JobInfo.h",
0
    };
    static const char* includePaths[] = {
"/afs/ihep.ac.cn/soft/juno/JUNO-ALL-SLC7/Pre-Release/J19v1r1-branch/ExternalLibs/ROOT/6.18.00/include",
"/afs/ihep.ac.cn/soft/juno/JUNO-ALL-SLC7/Pre-Release/J19v1r1-branch/offline/DataModel/EDMUtil/include/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "JobInfoDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate("$clingAutoload$JobInfo.h")))  JobInfo;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "JobInfoDict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "JobInfo.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"JobInfo", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("JobInfoDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_JobInfoDict_Impl, {}, classesHeaders, /*has no C++ module*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_JobInfoDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_JobInfoDict() {
  TriggerDictionaryInitialization_JobInfoDict_Impl();
}
