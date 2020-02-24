// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dOdOdIsrcdIFileMetaDataDict
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
#include "FileMetaData.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_JMcLcLTreeMetaData(void *p = 0);
   static void *newArray_JMcLcLTreeMetaData(Long_t size, void *p);
   static void delete_JMcLcLTreeMetaData(void *p);
   static void deleteArray_JMcLcLTreeMetaData(void *p);
   static void destruct_JMcLcLTreeMetaData(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::JM::TreeMetaData*)
   {
      ::JM::TreeMetaData *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::JM::TreeMetaData >(0);
      static ::ROOT::TGenericClassInfo 
         instance("JM::TreeMetaData", ::JM::TreeMetaData::Class_Version(), "FileMetaData.h", 10,
                  typeid(::JM::TreeMetaData), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::JM::TreeMetaData::Dictionary, isa_proxy, 4,
                  sizeof(::JM::TreeMetaData) );
      instance.SetNew(&new_JMcLcLTreeMetaData);
      instance.SetNewArray(&newArray_JMcLcLTreeMetaData);
      instance.SetDelete(&delete_JMcLcLTreeMetaData);
      instance.SetDeleteArray(&deleteArray_JMcLcLTreeMetaData);
      instance.SetDestructor(&destruct_JMcLcLTreeMetaData);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::JM::TreeMetaData*)
   {
      return GenerateInitInstanceLocal((::JM::TreeMetaData*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::JM::TreeMetaData*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_JMcLcLFileMetaData(void *p = 0);
   static void *newArray_JMcLcLFileMetaData(Long_t size, void *p);
   static void delete_JMcLcLFileMetaData(void *p);
   static void deleteArray_JMcLcLFileMetaData(void *p);
   static void destruct_JMcLcLFileMetaData(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::JM::FileMetaData*)
   {
      ::JM::FileMetaData *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::JM::FileMetaData >(0);
      static ::ROOT::TGenericClassInfo 
         instance("JM::FileMetaData", ::JM::FileMetaData::Class_Version(), "FileMetaData.h", 32,
                  typeid(::JM::FileMetaData), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::JM::FileMetaData::Dictionary, isa_proxy, 4,
                  sizeof(::JM::FileMetaData) );
      instance.SetNew(&new_JMcLcLFileMetaData);
      instance.SetNewArray(&newArray_JMcLcLFileMetaData);
      instance.SetDelete(&delete_JMcLcLFileMetaData);
      instance.SetDeleteArray(&deleteArray_JMcLcLFileMetaData);
      instance.SetDestructor(&destruct_JMcLcLFileMetaData);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::JM::FileMetaData*)
   {
      return GenerateInitInstanceLocal((::JM::FileMetaData*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::JM::FileMetaData*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace JM {
//______________________________________________________________________________
atomic_TClass_ptr TreeMetaData::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TreeMetaData::Class_Name()
{
   return "JM::TreeMetaData";
}

//______________________________________________________________________________
const char *TreeMetaData::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::JM::TreeMetaData*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TreeMetaData::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::JM::TreeMetaData*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TreeMetaData::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::JM::TreeMetaData*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TreeMetaData::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::JM::TreeMetaData*)0x0)->GetClass(); }
   return fgIsA;
}

} // namespace JM
namespace JM {
//______________________________________________________________________________
atomic_TClass_ptr FileMetaData::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *FileMetaData::Class_Name()
{
   return "JM::FileMetaData";
}

//______________________________________________________________________________
const char *FileMetaData::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::JM::FileMetaData*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int FileMetaData::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::JM::FileMetaData*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *FileMetaData::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::JM::FileMetaData*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *FileMetaData::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::JM::FileMetaData*)0x0)->GetClass(); }
   return fgIsA;
}

} // namespace JM
namespace JM {
//______________________________________________________________________________
void TreeMetaData::Streamer(TBuffer &R__b)
{
   // Stream an object of class JM::TreeMetaData.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(JM::TreeMetaData::Class(),this);
   } else {
      R__b.WriteClassBuffer(JM::TreeMetaData::Class(),this);
   }
}

} // namespace JM
namespace ROOT {
   // Wrappers around operator new
   static void *new_JMcLcLTreeMetaData(void *p) {
      return  p ? new(p) ::JM::TreeMetaData : new ::JM::TreeMetaData;
   }
   static void *newArray_JMcLcLTreeMetaData(Long_t nElements, void *p) {
      return p ? new(p) ::JM::TreeMetaData[nElements] : new ::JM::TreeMetaData[nElements];
   }
   // Wrapper around operator delete
   static void delete_JMcLcLTreeMetaData(void *p) {
      delete ((::JM::TreeMetaData*)p);
   }
   static void deleteArray_JMcLcLTreeMetaData(void *p) {
      delete [] ((::JM::TreeMetaData*)p);
   }
   static void destruct_JMcLcLTreeMetaData(void *p) {
      typedef ::JM::TreeMetaData current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::JM::TreeMetaData

namespace JM {
//______________________________________________________________________________
void FileMetaData::Streamer(TBuffer &R__b)
{
   // Stream an object of class JM::FileMetaData.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(JM::FileMetaData::Class(),this);
   } else {
      R__b.WriteClassBuffer(JM::FileMetaData::Class(),this);
   }
}

} // namespace JM
namespace ROOT {
   // Wrappers around operator new
   static void *new_JMcLcLFileMetaData(void *p) {
      return  p ? new(p) ::JM::FileMetaData : new ::JM::FileMetaData;
   }
   static void *newArray_JMcLcLFileMetaData(Long_t nElements, void *p) {
      return p ? new(p) ::JM::FileMetaData[nElements] : new ::JM::FileMetaData[nElements];
   }
   // Wrapper around operator delete
   static void delete_JMcLcLFileMetaData(void *p) {
      delete ((::JM::FileMetaData*)p);
   }
   static void deleteArray_JMcLcLFileMetaData(void *p) {
      delete [] ((::JM::FileMetaData*)p);
   }
   static void destruct_JMcLcLFileMetaData(void *p) {
      typedef ::JM::FileMetaData current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::JM::FileMetaData

namespace ROOT {
   static TClass *vectorlEstringgR_Dictionary();
   static void vectorlEstringgR_TClassManip(TClass*);
   static void *new_vectorlEstringgR(void *p = 0);
   static void *newArray_vectorlEstringgR(Long_t size, void *p);
   static void delete_vectorlEstringgR(void *p);
   static void deleteArray_vectorlEstringgR(void *p);
   static void destruct_vectorlEstringgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<string>*)
   {
      vector<string> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<string>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<string>", -2, "vector", 339,
                  typeid(vector<string>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEstringgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<string>) );
      instance.SetNew(&new_vectorlEstringgR);
      instance.SetNewArray(&newArray_vectorlEstringgR);
      instance.SetDelete(&delete_vectorlEstringgR);
      instance.SetDeleteArray(&deleteArray_vectorlEstringgR);
      instance.SetDestructor(&destruct_vectorlEstringgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<string> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<string>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEstringgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<string>*)0x0)->GetClass();
      vectorlEstringgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEstringgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEstringgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<string> : new vector<string>;
   }
   static void *newArray_vectorlEstringgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<string>[nElements] : new vector<string>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEstringgR(void *p) {
      delete ((vector<string>*)p);
   }
   static void deleteArray_vectorlEstringgR(void *p) {
      delete [] ((vector<string>*)p);
   }
   static void destruct_vectorlEstringgR(void *p) {
      typedef vector<string> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<string>

namespace ROOT {
   static TClass *vectorlELong64_tgR_Dictionary();
   static void vectorlELong64_tgR_TClassManip(TClass*);
   static void *new_vectorlELong64_tgR(void *p = 0);
   static void *newArray_vectorlELong64_tgR(Long_t size, void *p);
   static void delete_vectorlELong64_tgR(void *p);
   static void deleteArray_vectorlELong64_tgR(void *p);
   static void destruct_vectorlELong64_tgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<Long64_t>*)
   {
      vector<Long64_t> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<Long64_t>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<Long64_t>", -2, "vector", 339,
                  typeid(vector<Long64_t>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlELong64_tgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<Long64_t>) );
      instance.SetNew(&new_vectorlELong64_tgR);
      instance.SetNewArray(&newArray_vectorlELong64_tgR);
      instance.SetDelete(&delete_vectorlELong64_tgR);
      instance.SetDeleteArray(&deleteArray_vectorlELong64_tgR);
      instance.SetDestructor(&destruct_vectorlELong64_tgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<Long64_t> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<Long64_t>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlELong64_tgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<Long64_t>*)0x0)->GetClass();
      vectorlELong64_tgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlELong64_tgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlELong64_tgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<Long64_t> : new vector<Long64_t>;
   }
   static void *newArray_vectorlELong64_tgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<Long64_t>[nElements] : new vector<Long64_t>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlELong64_tgR(void *p) {
      delete ((vector<Long64_t>*)p);
   }
   static void deleteArray_vectorlELong64_tgR(void *p) {
      delete [] ((vector<Long64_t>*)p);
   }
   static void destruct_vectorlELong64_tgR(void *p) {
      typedef vector<Long64_t> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<Long64_t>

namespace ROOT {
   static TClass *vectorlEJMcLcLTreeMetaDatamUgR_Dictionary();
   static void vectorlEJMcLcLTreeMetaDatamUgR_TClassManip(TClass*);
   static void *new_vectorlEJMcLcLTreeMetaDatamUgR(void *p = 0);
   static void *newArray_vectorlEJMcLcLTreeMetaDatamUgR(Long_t size, void *p);
   static void delete_vectorlEJMcLcLTreeMetaDatamUgR(void *p);
   static void deleteArray_vectorlEJMcLcLTreeMetaDatamUgR(void *p);
   static void destruct_vectorlEJMcLcLTreeMetaDatamUgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<JM::TreeMetaData*>*)
   {
      vector<JM::TreeMetaData*> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<JM::TreeMetaData*>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<JM::TreeMetaData*>", -2, "vector", 339,
                  typeid(vector<JM::TreeMetaData*>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEJMcLcLTreeMetaDatamUgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<JM::TreeMetaData*>) );
      instance.SetNew(&new_vectorlEJMcLcLTreeMetaDatamUgR);
      instance.SetNewArray(&newArray_vectorlEJMcLcLTreeMetaDatamUgR);
      instance.SetDelete(&delete_vectorlEJMcLcLTreeMetaDatamUgR);
      instance.SetDeleteArray(&deleteArray_vectorlEJMcLcLTreeMetaDatamUgR);
      instance.SetDestructor(&destruct_vectorlEJMcLcLTreeMetaDatamUgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<JM::TreeMetaData*> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<JM::TreeMetaData*>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEJMcLcLTreeMetaDatamUgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<JM::TreeMetaData*>*)0x0)->GetClass();
      vectorlEJMcLcLTreeMetaDatamUgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEJMcLcLTreeMetaDatamUgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEJMcLcLTreeMetaDatamUgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<JM::TreeMetaData*> : new vector<JM::TreeMetaData*>;
   }
   static void *newArray_vectorlEJMcLcLTreeMetaDatamUgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<JM::TreeMetaData*>[nElements] : new vector<JM::TreeMetaData*>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEJMcLcLTreeMetaDatamUgR(void *p) {
      delete ((vector<JM::TreeMetaData*>*)p);
   }
   static void deleteArray_vectorlEJMcLcLTreeMetaDatamUgR(void *p) {
      delete [] ((vector<JM::TreeMetaData*>*)p);
   }
   static void destruct_vectorlEJMcLcLTreeMetaDatamUgR(void *p) {
      typedef vector<JM::TreeMetaData*> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<JM::TreeMetaData*>

namespace ROOT {
   static TClass *maplEstringcOvectorlELong64_tgRsPgR_Dictionary();
   static void maplEstringcOvectorlELong64_tgRsPgR_TClassManip(TClass*);
   static void *new_maplEstringcOvectorlELong64_tgRsPgR(void *p = 0);
   static void *newArray_maplEstringcOvectorlELong64_tgRsPgR(Long_t size, void *p);
   static void delete_maplEstringcOvectorlELong64_tgRsPgR(void *p);
   static void deleteArray_maplEstringcOvectorlELong64_tgRsPgR(void *p);
   static void destruct_maplEstringcOvectorlELong64_tgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<string,vector<Long64_t> >*)
   {
      map<string,vector<Long64_t> > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<string,vector<Long64_t> >));
      static ::ROOT::TGenericClassInfo 
         instance("map<string,vector<Long64_t> >", -2, "map", 100,
                  typeid(map<string,vector<Long64_t> >), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &maplEstringcOvectorlELong64_tgRsPgR_Dictionary, isa_proxy, 0,
                  sizeof(map<string,vector<Long64_t> >) );
      instance.SetNew(&new_maplEstringcOvectorlELong64_tgRsPgR);
      instance.SetNewArray(&newArray_maplEstringcOvectorlELong64_tgRsPgR);
      instance.SetDelete(&delete_maplEstringcOvectorlELong64_tgRsPgR);
      instance.SetDeleteArray(&deleteArray_maplEstringcOvectorlELong64_tgRsPgR);
      instance.SetDestructor(&destruct_maplEstringcOvectorlELong64_tgRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<string,vector<Long64_t> > >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const map<string,vector<Long64_t> >*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEstringcOvectorlELong64_tgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const map<string,vector<Long64_t> >*)0x0)->GetClass();
      maplEstringcOvectorlELong64_tgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void maplEstringcOvectorlELong64_tgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEstringcOvectorlELong64_tgRsPgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<string,vector<Long64_t> > : new map<string,vector<Long64_t> >;
   }
   static void *newArray_maplEstringcOvectorlELong64_tgRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<string,vector<Long64_t> >[nElements] : new map<string,vector<Long64_t> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEstringcOvectorlELong64_tgRsPgR(void *p) {
      delete ((map<string,vector<Long64_t> >*)p);
   }
   static void deleteArray_maplEstringcOvectorlELong64_tgRsPgR(void *p) {
      delete [] ((map<string,vector<Long64_t> >*)p);
   }
   static void destruct_maplEstringcOvectorlELong64_tgRsPgR(void *p) {
      typedef map<string,vector<Long64_t> > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class map<string,vector<Long64_t> >

namespace {
  void TriggerDictionaryInitialization_FileMetaDataDict_Impl() {
    static const char* headers[] = {
"FileMetaData.h",
0
    };
    static const char* includePaths[] = {
"/afs/ihep.ac.cn/soft/juno/JUNO-ALL-SLC7/Pre-Release/J19v1r1-branch/ExternalLibs/ROOT/6.18.00/include",
"/afs/ihep.ac.cn/soft/juno/JUNO-ALL-SLC7/Pre-Release/J19v1r1-branch/offline/DataModel/EDMUtil/include/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "FileMetaDataDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
namespace JM{class __attribute__((annotate("$clingAutoload$FileMetaData.h")))  TreeMetaData;}
namespace JM{class __attribute__((annotate("$clingAutoload$FileMetaData.h")))  FileMetaData;}
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "FileMetaDataDict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "FileMetaData.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"JM::FileMetaData", payloadCode, "@",
"JM::TreeMetaData", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("FileMetaDataDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_FileMetaDataDict_Impl, {}, classesHeaders, /*has no C++ module*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_FileMetaDataDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_FileMetaDataDict() {
  TriggerDictionaryInitialization_FileMetaDataDict_Impl();
}
