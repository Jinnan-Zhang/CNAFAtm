// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dOdOdIsrcdIUniqueIDTableDict
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
#include "UniqueIDTable.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_JMcLcLTablePerTree(void *p = 0);
   static void *newArray_JMcLcLTablePerTree(Long_t size, void *p);
   static void delete_JMcLcLTablePerTree(void *p);
   static void deleteArray_JMcLcLTablePerTree(void *p);
   static void destruct_JMcLcLTablePerTree(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::JM::TablePerTree*)
   {
      ::JM::TablePerTree *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::JM::TablePerTree >(0);
      static ::ROOT::TGenericClassInfo 
         instance("JM::TablePerTree", ::JM::TablePerTree::Class_Version(), "UniqueIDTable.h", 12,
                  typeid(::JM::TablePerTree), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::JM::TablePerTree::Dictionary, isa_proxy, 4,
                  sizeof(::JM::TablePerTree) );
      instance.SetNew(&new_JMcLcLTablePerTree);
      instance.SetNewArray(&newArray_JMcLcLTablePerTree);
      instance.SetDelete(&delete_JMcLcLTablePerTree);
      instance.SetDeleteArray(&deleteArray_JMcLcLTablePerTree);
      instance.SetDestructor(&destruct_JMcLcLTablePerTree);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::JM::TablePerTree*)
   {
      return GenerateInitInstanceLocal((::JM::TablePerTree*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::JM::TablePerTree*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_JMcLcLUniqueIDTable(void *p = 0);
   static void *newArray_JMcLcLUniqueIDTable(Long_t size, void *p);
   static void delete_JMcLcLUniqueIDTable(void *p);
   static void deleteArray_JMcLcLUniqueIDTable(void *p);
   static void destruct_JMcLcLUniqueIDTable(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::JM::UniqueIDTable*)
   {
      ::JM::UniqueIDTable *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::JM::UniqueIDTable >(0);
      static ::ROOT::TGenericClassInfo 
         instance("JM::UniqueIDTable", ::JM::UniqueIDTable::Class_Version(), "UniqueIDTable.h", 49,
                  typeid(::JM::UniqueIDTable), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::JM::UniqueIDTable::Dictionary, isa_proxy, 4,
                  sizeof(::JM::UniqueIDTable) );
      instance.SetNew(&new_JMcLcLUniqueIDTable);
      instance.SetNewArray(&newArray_JMcLcLUniqueIDTable);
      instance.SetDelete(&delete_JMcLcLUniqueIDTable);
      instance.SetDeleteArray(&deleteArray_JMcLcLUniqueIDTable);
      instance.SetDestructor(&destruct_JMcLcLUniqueIDTable);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::JM::UniqueIDTable*)
   {
      return GenerateInitInstanceLocal((::JM::UniqueIDTable*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::JM::UniqueIDTable*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace JM {
//______________________________________________________________________________
atomic_TClass_ptr TablePerTree::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TablePerTree::Class_Name()
{
   return "JM::TablePerTree";
}

//______________________________________________________________________________
const char *TablePerTree::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::JM::TablePerTree*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TablePerTree::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::JM::TablePerTree*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TablePerTree::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::JM::TablePerTree*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TablePerTree::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::JM::TablePerTree*)0x0)->GetClass(); }
   return fgIsA;
}

} // namespace JM
namespace JM {
//______________________________________________________________________________
atomic_TClass_ptr UniqueIDTable::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *UniqueIDTable::Class_Name()
{
   return "JM::UniqueIDTable";
}

//______________________________________________________________________________
const char *UniqueIDTable::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::JM::UniqueIDTable*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int UniqueIDTable::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::JM::UniqueIDTable*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *UniqueIDTable::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::JM::UniqueIDTable*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *UniqueIDTable::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::JM::UniqueIDTable*)0x0)->GetClass(); }
   return fgIsA;
}

} // namespace JM
namespace JM {
//______________________________________________________________________________
void TablePerTree::Streamer(TBuffer &R__b)
{
   // Stream an object of class JM::TablePerTree.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(JM::TablePerTree::Class(),this);
   } else {
      R__b.WriteClassBuffer(JM::TablePerTree::Class(),this);
   }
}

} // namespace JM
namespace ROOT {
   // Wrappers around operator new
   static void *new_JMcLcLTablePerTree(void *p) {
      return  p ? new(p) ::JM::TablePerTree : new ::JM::TablePerTree;
   }
   static void *newArray_JMcLcLTablePerTree(Long_t nElements, void *p) {
      return p ? new(p) ::JM::TablePerTree[nElements] : new ::JM::TablePerTree[nElements];
   }
   // Wrapper around operator delete
   static void delete_JMcLcLTablePerTree(void *p) {
      delete ((::JM::TablePerTree*)p);
   }
   static void deleteArray_JMcLcLTablePerTree(void *p) {
      delete [] ((::JM::TablePerTree*)p);
   }
   static void destruct_JMcLcLTablePerTree(void *p) {
      typedef ::JM::TablePerTree current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::JM::TablePerTree

namespace JM {
//______________________________________________________________________________
void UniqueIDTable::Streamer(TBuffer &R__b)
{
   // Stream an object of class JM::UniqueIDTable.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(JM::UniqueIDTable::Class(),this);
   } else {
      R__b.WriteClassBuffer(JM::UniqueIDTable::Class(),this);
   }
}

} // namespace JM
namespace ROOT {
   // Wrappers around operator new
   static void *new_JMcLcLUniqueIDTable(void *p) {
      return  p ? new(p) ::JM::UniqueIDTable : new ::JM::UniqueIDTable;
   }
   static void *newArray_JMcLcLUniqueIDTable(Long_t nElements, void *p) {
      return p ? new(p) ::JM::UniqueIDTable[nElements] : new ::JM::UniqueIDTable[nElements];
   }
   // Wrapper around operator delete
   static void delete_JMcLcLUniqueIDTable(void *p) {
      delete ((::JM::UniqueIDTable*)p);
   }
   static void deleteArray_JMcLcLUniqueIDTable(void *p) {
      delete [] ((::JM::UniqueIDTable*)p);
   }
   static void destruct_JMcLcLUniqueIDTable(void *p) {
      typedef ::JM::UniqueIDTable current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::JM::UniqueIDTable

namespace ROOT {
   static TClass *vectorlEvectorlEshortgRsPgR_Dictionary();
   static void vectorlEvectorlEshortgRsPgR_TClassManip(TClass*);
   static void *new_vectorlEvectorlEshortgRsPgR(void *p = 0);
   static void *newArray_vectorlEvectorlEshortgRsPgR(Long_t size, void *p);
   static void delete_vectorlEvectorlEshortgRsPgR(void *p);
   static void deleteArray_vectorlEvectorlEshortgRsPgR(void *p);
   static void destruct_vectorlEvectorlEshortgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<vector<short> >*)
   {
      vector<vector<short> > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<vector<short> >));
      static ::ROOT::TGenericClassInfo 
         instance("vector<vector<short> >", -2, "vector", 339,
                  typeid(vector<vector<short> >), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEvectorlEshortgRsPgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<vector<short> >) );
      instance.SetNew(&new_vectorlEvectorlEshortgRsPgR);
      instance.SetNewArray(&newArray_vectorlEvectorlEshortgRsPgR);
      instance.SetDelete(&delete_vectorlEvectorlEshortgRsPgR);
      instance.SetDeleteArray(&deleteArray_vectorlEvectorlEshortgRsPgR);
      instance.SetDestructor(&destruct_vectorlEvectorlEshortgRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<vector<short> > >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<vector<short> >*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEvectorlEshortgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<vector<short> >*)0x0)->GetClass();
      vectorlEvectorlEshortgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEvectorlEshortgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEvectorlEshortgRsPgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<vector<short> > : new vector<vector<short> >;
   }
   static void *newArray_vectorlEvectorlEshortgRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<vector<short> >[nElements] : new vector<vector<short> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEvectorlEshortgRsPgR(void *p) {
      delete ((vector<vector<short> >*)p);
   }
   static void deleteArray_vectorlEvectorlEshortgRsPgR(void *p) {
      delete [] ((vector<vector<short> >*)p);
   }
   static void destruct_vectorlEvectorlEshortgRsPgR(void *p) {
      typedef vector<vector<short> > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<vector<short> >

namespace ROOT {
   static TClass *vectorlEvectorlEintgRsPgR_Dictionary();
   static void vectorlEvectorlEintgRsPgR_TClassManip(TClass*);
   static void *new_vectorlEvectorlEintgRsPgR(void *p = 0);
   static void *newArray_vectorlEvectorlEintgRsPgR(Long_t size, void *p);
   static void delete_vectorlEvectorlEintgRsPgR(void *p);
   static void deleteArray_vectorlEvectorlEintgRsPgR(void *p);
   static void destruct_vectorlEvectorlEintgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<vector<int> >*)
   {
      vector<vector<int> > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<vector<int> >));
      static ::ROOT::TGenericClassInfo 
         instance("vector<vector<int> >", -2, "vector", 339,
                  typeid(vector<vector<int> >), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEvectorlEintgRsPgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<vector<int> >) );
      instance.SetNew(&new_vectorlEvectorlEintgRsPgR);
      instance.SetNewArray(&newArray_vectorlEvectorlEintgRsPgR);
      instance.SetDelete(&delete_vectorlEvectorlEintgRsPgR);
      instance.SetDeleteArray(&deleteArray_vectorlEvectorlEintgRsPgR);
      instance.SetDestructor(&destruct_vectorlEvectorlEintgRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<vector<int> > >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<vector<int> >*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEvectorlEintgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<vector<int> >*)0x0)->GetClass();
      vectorlEvectorlEintgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEvectorlEintgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEvectorlEintgRsPgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<vector<int> > : new vector<vector<int> >;
   }
   static void *newArray_vectorlEvectorlEintgRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<vector<int> >[nElements] : new vector<vector<int> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEvectorlEintgRsPgR(void *p) {
      delete ((vector<vector<int> >*)p);
   }
   static void deleteArray_vectorlEvectorlEintgRsPgR(void *p) {
      delete [] ((vector<vector<int> >*)p);
   }
   static void destruct_vectorlEvectorlEintgRsPgR(void *p) {
      typedef vector<vector<int> > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<vector<int> >

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
   static TClass *vectorlEshortgR_Dictionary();
   static void vectorlEshortgR_TClassManip(TClass*);
   static void *new_vectorlEshortgR(void *p = 0);
   static void *newArray_vectorlEshortgR(Long_t size, void *p);
   static void delete_vectorlEshortgR(void *p);
   static void deleteArray_vectorlEshortgR(void *p);
   static void destruct_vectorlEshortgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<short>*)
   {
      vector<short> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<short>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<short>", -2, "vector", 339,
                  typeid(vector<short>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEshortgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<short>) );
      instance.SetNew(&new_vectorlEshortgR);
      instance.SetNewArray(&newArray_vectorlEshortgR);
      instance.SetDelete(&delete_vectorlEshortgR);
      instance.SetDeleteArray(&deleteArray_vectorlEshortgR);
      instance.SetDestructor(&destruct_vectorlEshortgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<short> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<short>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEshortgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<short>*)0x0)->GetClass();
      vectorlEshortgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEshortgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEshortgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<short> : new vector<short>;
   }
   static void *newArray_vectorlEshortgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<short>[nElements] : new vector<short>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEshortgR(void *p) {
      delete ((vector<short>*)p);
   }
   static void deleteArray_vectorlEshortgR(void *p) {
      delete [] ((vector<short>*)p);
   }
   static void destruct_vectorlEshortgR(void *p) {
      typedef vector<short> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<short>

namespace ROOT {
   static TClass *vectorlEintgR_Dictionary();
   static void vectorlEintgR_TClassManip(TClass*);
   static void *new_vectorlEintgR(void *p = 0);
   static void *newArray_vectorlEintgR(Long_t size, void *p);
   static void delete_vectorlEintgR(void *p);
   static void deleteArray_vectorlEintgR(void *p);
   static void destruct_vectorlEintgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<int>*)
   {
      vector<int> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<int>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<int>", -2, "vector", 339,
                  typeid(vector<int>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEintgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<int>) );
      instance.SetNew(&new_vectorlEintgR);
      instance.SetNewArray(&newArray_vectorlEintgR);
      instance.SetDelete(&delete_vectorlEintgR);
      instance.SetDeleteArray(&deleteArray_vectorlEintgR);
      instance.SetDestructor(&destruct_vectorlEintgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<int> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<int>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEintgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<int>*)0x0)->GetClass();
      vectorlEintgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEintgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEintgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<int> : new vector<int>;
   }
   static void *newArray_vectorlEintgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<int>[nElements] : new vector<int>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEintgR(void *p) {
      delete ((vector<int>*)p);
   }
   static void deleteArray_vectorlEintgR(void *p) {
      delete [] ((vector<int>*)p);
   }
   static void destruct_vectorlEintgR(void *p) {
      typedef vector<int> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<int>

namespace ROOT {
   static TClass *maplEstringcOJMcLcLTablePerTreemUgR_Dictionary();
   static void maplEstringcOJMcLcLTablePerTreemUgR_TClassManip(TClass*);
   static void *new_maplEstringcOJMcLcLTablePerTreemUgR(void *p = 0);
   static void *newArray_maplEstringcOJMcLcLTablePerTreemUgR(Long_t size, void *p);
   static void delete_maplEstringcOJMcLcLTablePerTreemUgR(void *p);
   static void deleteArray_maplEstringcOJMcLcLTablePerTreemUgR(void *p);
   static void destruct_maplEstringcOJMcLcLTablePerTreemUgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<string,JM::TablePerTree*>*)
   {
      map<string,JM::TablePerTree*> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<string,JM::TablePerTree*>));
      static ::ROOT::TGenericClassInfo 
         instance("map<string,JM::TablePerTree*>", -2, "map", 100,
                  typeid(map<string,JM::TablePerTree*>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &maplEstringcOJMcLcLTablePerTreemUgR_Dictionary, isa_proxy, 0,
                  sizeof(map<string,JM::TablePerTree*>) );
      instance.SetNew(&new_maplEstringcOJMcLcLTablePerTreemUgR);
      instance.SetNewArray(&newArray_maplEstringcOJMcLcLTablePerTreemUgR);
      instance.SetDelete(&delete_maplEstringcOJMcLcLTablePerTreemUgR);
      instance.SetDeleteArray(&deleteArray_maplEstringcOJMcLcLTablePerTreemUgR);
      instance.SetDestructor(&destruct_maplEstringcOJMcLcLTablePerTreemUgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<string,JM::TablePerTree*> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const map<string,JM::TablePerTree*>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEstringcOJMcLcLTablePerTreemUgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const map<string,JM::TablePerTree*>*)0x0)->GetClass();
      maplEstringcOJMcLcLTablePerTreemUgR_TClassManip(theClass);
   return theClass;
   }

   static void maplEstringcOJMcLcLTablePerTreemUgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEstringcOJMcLcLTablePerTreemUgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<string,JM::TablePerTree*> : new map<string,JM::TablePerTree*>;
   }
   static void *newArray_maplEstringcOJMcLcLTablePerTreemUgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<string,JM::TablePerTree*>[nElements] : new map<string,JM::TablePerTree*>[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEstringcOJMcLcLTablePerTreemUgR(void *p) {
      delete ((map<string,JM::TablePerTree*>*)p);
   }
   static void deleteArray_maplEstringcOJMcLcLTablePerTreemUgR(void *p) {
      delete [] ((map<string,JM::TablePerTree*>*)p);
   }
   static void destruct_maplEstringcOJMcLcLTablePerTreemUgR(void *p) {
      typedef map<string,JM::TablePerTree*> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class map<string,JM::TablePerTree*>

namespace {
  void TriggerDictionaryInitialization_UniqueIDTableDict_Impl() {
    static const char* headers[] = {
"UniqueIDTable.h",
0
    };
    static const char* includePaths[] = {
"/afs/ihep.ac.cn/soft/juno/JUNO-ALL-SLC7/Pre-Release/J19v1r1-branch/ExternalLibs/ROOT/6.18.00/include",
"/afs/ihep.ac.cn/soft/juno/JUNO-ALL-SLC7/Pre-Release/J19v1r1-branch/offline/DataModel/EDMUtil/include/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "UniqueIDTableDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
namespace JM{class __attribute__((annotate("$clingAutoload$UniqueIDTable.h")))  TablePerTree;}
namespace JM{class __attribute__((annotate("$clingAutoload$UniqueIDTable.h")))  UniqueIDTable;}
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "UniqueIDTableDict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "UniqueIDTable.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"JM::TablePerTree", payloadCode, "@",
"JM::UniqueIDTable", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("UniqueIDTableDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_UniqueIDTableDict_Impl, {}, classesHeaders, /*has no C++ module*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_UniqueIDTableDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_UniqueIDTableDict() {
  TriggerDictionaryInitialization_UniqueIDTableDict_Impl();
}
