//
// File generated by core/utils/src/rootcint_tmp at Mon Mar  5 17:15:05 2012

// Do NOT change. Changes will be lost next time file is generated
//

#define R__DICTIONARY_FILENAME cintdIcintdIlibdIdll_stldIrootcint_multimap2
#include "RConfig.h" //rootcint 4834
#if !defined(R__ACCESS_IN_SYMBOL)
//Break the privacy of classes -- Disabled for the moment
#define private public
#define protected public
#endif

// Since CINT ignores the std namespace, we need to do so in this file.
namespace std {} using namespace std;
#include "rootcint_multimap2.h"

#include "TCollectionProxyInfo.h"
#include "TClass.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"

// START OF SHADOWS

namespace ROOT {
   namespace Shadow {
   } // of namespace Shadow
} // of namespace ROOT
// END OF SHADOWS

namespace ROOT {
   void multimaplEdoublecOcharmUgR_ShowMembers(void *obj, TMemberInspector &R__insp);
   static void multimaplEdoublecOcharmUgR_Dictionary();
   static void *new_multimaplEdoublecOcharmUgR(void *p = 0);
   static void *newArray_multimaplEdoublecOcharmUgR(Long_t size, void *p);
   static void delete_multimaplEdoublecOcharmUgR(void *p);
   static void deleteArray_multimaplEdoublecOcharmUgR(void *p);
   static void destruct_multimaplEdoublecOcharmUgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const multimap<double,char*>*)
   {
      multimap<double,char*> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(multimap<double,char*>),0);
      static ::ROOT::TGenericClassInfo 
         instance("multimap<double,char*>", -2, "prec_stl/multimap", 63,
                  typeid(multimap<double,char*>), DefineBehavior(ptr, ptr),
                  0, &multimaplEdoublecOcharmUgR_Dictionary, isa_proxy, 0,
                  sizeof(multimap<double,char*>) );
      instance.SetNew(&new_multimaplEdoublecOcharmUgR);
      instance.SetNewArray(&newArray_multimaplEdoublecOcharmUgR);
      instance.SetDelete(&delete_multimaplEdoublecOcharmUgR);
      instance.SetDeleteArray(&deleteArray_multimaplEdoublecOcharmUgR);
      instance.SetDestructor(&destruct_multimaplEdoublecOcharmUgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< multimap<double,char*> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const multimap<double,char*>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static void multimaplEdoublecOcharmUgR_Dictionary() {
      ::ROOT::GenerateInitInstanceLocal((const multimap<double,char*>*)0x0)->GetClass();
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_multimaplEdoublecOcharmUgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) multimap<double,char*> : new multimap<double,char*>;
   }
   static void *newArray_multimaplEdoublecOcharmUgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) multimap<double,char*>[nElements] : new multimap<double,char*>[nElements];
   }
   // Wrapper around operator delete
   static void delete_multimaplEdoublecOcharmUgR(void *p) {
      delete ((multimap<double,char*>*)p);
   }
   static void deleteArray_multimaplEdoublecOcharmUgR(void *p) {
      delete [] ((multimap<double,char*>*)p);
   }
   static void destruct_multimaplEdoublecOcharmUgR(void *p) {
      typedef multimap<double,char*> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class multimap<double,char*>

namespace ROOT {
   void multimaplEdoublecOdoublegR_ShowMembers(void *obj, TMemberInspector &R__insp);
   static void multimaplEdoublecOdoublegR_Dictionary();
   static void *new_multimaplEdoublecOdoublegR(void *p = 0);
   static void *newArray_multimaplEdoublecOdoublegR(Long_t size, void *p);
   static void delete_multimaplEdoublecOdoublegR(void *p);
   static void deleteArray_multimaplEdoublecOdoublegR(void *p);
   static void destruct_multimaplEdoublecOdoublegR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const multimap<double,double>*)
   {
      multimap<double,double> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(multimap<double,double>),0);
      static ::ROOT::TGenericClassInfo 
         instance("multimap<double,double>", -2, "prec_stl/multimap", 63,
                  typeid(multimap<double,double>), DefineBehavior(ptr, ptr),
                  0, &multimaplEdoublecOdoublegR_Dictionary, isa_proxy, 0,
                  sizeof(multimap<double,double>) );
      instance.SetNew(&new_multimaplEdoublecOdoublegR);
      instance.SetNewArray(&newArray_multimaplEdoublecOdoublegR);
      instance.SetDelete(&delete_multimaplEdoublecOdoublegR);
      instance.SetDeleteArray(&deleteArray_multimaplEdoublecOdoublegR);
      instance.SetDestructor(&destruct_multimaplEdoublecOdoublegR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< multimap<double,double> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const multimap<double,double>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static void multimaplEdoublecOdoublegR_Dictionary() {
      ::ROOT::GenerateInitInstanceLocal((const multimap<double,double>*)0x0)->GetClass();
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_multimaplEdoublecOdoublegR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) multimap<double,double> : new multimap<double,double>;
   }
   static void *newArray_multimaplEdoublecOdoublegR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) multimap<double,double>[nElements] : new multimap<double,double>[nElements];
   }
   // Wrapper around operator delete
   static void delete_multimaplEdoublecOdoublegR(void *p) {
      delete ((multimap<double,double>*)p);
   }
   static void deleteArray_multimaplEdoublecOdoublegR(void *p) {
      delete [] ((multimap<double,double>*)p);
   }
   static void destruct_multimaplEdoublecOdoublegR(void *p) {
      typedef multimap<double,double> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class multimap<double,double>

namespace ROOT {
   void multimaplEdoublecOintgR_ShowMembers(void *obj, TMemberInspector &R__insp);
   static void multimaplEdoublecOintgR_Dictionary();
   static void *new_multimaplEdoublecOintgR(void *p = 0);
   static void *newArray_multimaplEdoublecOintgR(Long_t size, void *p);
   static void delete_multimaplEdoublecOintgR(void *p);
   static void deleteArray_multimaplEdoublecOintgR(void *p);
   static void destruct_multimaplEdoublecOintgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const multimap<double,int>*)
   {
      multimap<double,int> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(multimap<double,int>),0);
      static ::ROOT::TGenericClassInfo 
         instance("multimap<double,int>", -2, "prec_stl/multimap", 63,
                  typeid(multimap<double,int>), DefineBehavior(ptr, ptr),
                  0, &multimaplEdoublecOintgR_Dictionary, isa_proxy, 0,
                  sizeof(multimap<double,int>) );
      instance.SetNew(&new_multimaplEdoublecOintgR);
      instance.SetNewArray(&newArray_multimaplEdoublecOintgR);
      instance.SetDelete(&delete_multimaplEdoublecOintgR);
      instance.SetDeleteArray(&deleteArray_multimaplEdoublecOintgR);
      instance.SetDestructor(&destruct_multimaplEdoublecOintgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< multimap<double,int> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const multimap<double,int>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static void multimaplEdoublecOintgR_Dictionary() {
      ::ROOT::GenerateInitInstanceLocal((const multimap<double,int>*)0x0)->GetClass();
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_multimaplEdoublecOintgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) multimap<double,int> : new multimap<double,int>;
   }
   static void *newArray_multimaplEdoublecOintgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) multimap<double,int>[nElements] : new multimap<double,int>[nElements];
   }
   // Wrapper around operator delete
   static void delete_multimaplEdoublecOintgR(void *p) {
      delete ((multimap<double,int>*)p);
   }
   static void deleteArray_multimaplEdoublecOintgR(void *p) {
      delete [] ((multimap<double,int>*)p);
   }
   static void destruct_multimaplEdoublecOintgR(void *p) {
      typedef multimap<double,int> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class multimap<double,int>

namespace ROOT {
   void multimaplEdoublecOlonggR_ShowMembers(void *obj, TMemberInspector &R__insp);
   static void multimaplEdoublecOlonggR_Dictionary();
   static void *new_multimaplEdoublecOlonggR(void *p = 0);
   static void *newArray_multimaplEdoublecOlonggR(Long_t size, void *p);
   static void delete_multimaplEdoublecOlonggR(void *p);
   static void deleteArray_multimaplEdoublecOlonggR(void *p);
   static void destruct_multimaplEdoublecOlonggR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const multimap<double,long>*)
   {
      multimap<double,long> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(multimap<double,long>),0);
      static ::ROOT::TGenericClassInfo 
         instance("multimap<double,long>", -2, "prec_stl/multimap", 63,
                  typeid(multimap<double,long>), DefineBehavior(ptr, ptr),
                  0, &multimaplEdoublecOlonggR_Dictionary, isa_proxy, 0,
                  sizeof(multimap<double,long>) );
      instance.SetNew(&new_multimaplEdoublecOlonggR);
      instance.SetNewArray(&newArray_multimaplEdoublecOlonggR);
      instance.SetDelete(&delete_multimaplEdoublecOlonggR);
      instance.SetDeleteArray(&deleteArray_multimaplEdoublecOlonggR);
      instance.SetDestructor(&destruct_multimaplEdoublecOlonggR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< multimap<double,long> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const multimap<double,long>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static void multimaplEdoublecOlonggR_Dictionary() {
      ::ROOT::GenerateInitInstanceLocal((const multimap<double,long>*)0x0)->GetClass();
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_multimaplEdoublecOlonggR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) multimap<double,long> : new multimap<double,long>;
   }
   static void *newArray_multimaplEdoublecOlonggR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) multimap<double,long>[nElements] : new multimap<double,long>[nElements];
   }
   // Wrapper around operator delete
   static void delete_multimaplEdoublecOlonggR(void *p) {
      delete ((multimap<double,long>*)p);
   }
   static void deleteArray_multimaplEdoublecOlonggR(void *p) {
      delete [] ((multimap<double,long>*)p);
   }
   static void destruct_multimaplEdoublecOlonggR(void *p) {
      typedef multimap<double,long> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class multimap<double,long>

namespace ROOT {
   void multimaplEdoublecOvoidmUgR_ShowMembers(void *obj, TMemberInspector &R__insp);
   static void multimaplEdoublecOvoidmUgR_Dictionary();
   static void *new_multimaplEdoublecOvoidmUgR(void *p = 0);
   static void *newArray_multimaplEdoublecOvoidmUgR(Long_t size, void *p);
   static void delete_multimaplEdoublecOvoidmUgR(void *p);
   static void deleteArray_multimaplEdoublecOvoidmUgR(void *p);
   static void destruct_multimaplEdoublecOvoidmUgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const multimap<double,void*>*)
   {
      multimap<double,void*> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(multimap<double,void*>),0);
      static ::ROOT::TGenericClassInfo 
         instance("multimap<double,void*>", -2, "prec_stl/multimap", 63,
                  typeid(multimap<double,void*>), DefineBehavior(ptr, ptr),
                  0, &multimaplEdoublecOvoidmUgR_Dictionary, isa_proxy, 0,
                  sizeof(multimap<double,void*>) );
      instance.SetNew(&new_multimaplEdoublecOvoidmUgR);
      instance.SetNewArray(&newArray_multimaplEdoublecOvoidmUgR);
      instance.SetDelete(&delete_multimaplEdoublecOvoidmUgR);
      instance.SetDeleteArray(&deleteArray_multimaplEdoublecOvoidmUgR);
      instance.SetDestructor(&destruct_multimaplEdoublecOvoidmUgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< multimap<double,void*> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const multimap<double,void*>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static void multimaplEdoublecOvoidmUgR_Dictionary() {
      ::ROOT::GenerateInitInstanceLocal((const multimap<double,void*>*)0x0)->GetClass();
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_multimaplEdoublecOvoidmUgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) multimap<double,void*> : new multimap<double,void*>;
   }
   static void *newArray_multimaplEdoublecOvoidmUgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) multimap<double,void*>[nElements] : new multimap<double,void*>[nElements];
   }
   // Wrapper around operator delete
   static void delete_multimaplEdoublecOvoidmUgR(void *p) {
      delete ((multimap<double,void*>*)p);
   }
   static void deleteArray_multimaplEdoublecOvoidmUgR(void *p) {
      delete [] ((multimap<double,void*>*)p);
   }
   static void destruct_multimaplEdoublecOvoidmUgR(void *p) {
      typedef multimap<double,void*> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class multimap<double,void*>

namespace ROOT {
   void multimaplElongcOcharmUgR_ShowMembers(void *obj, TMemberInspector &R__insp);
   static void multimaplElongcOcharmUgR_Dictionary();
   static void *new_multimaplElongcOcharmUgR(void *p = 0);
   static void *newArray_multimaplElongcOcharmUgR(Long_t size, void *p);
   static void delete_multimaplElongcOcharmUgR(void *p);
   static void deleteArray_multimaplElongcOcharmUgR(void *p);
   static void destruct_multimaplElongcOcharmUgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const multimap<long,char*>*)
   {
      multimap<long,char*> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(multimap<long,char*>),0);
      static ::ROOT::TGenericClassInfo 
         instance("multimap<long,char*>", -2, "prec_stl/multimap", 63,
                  typeid(multimap<long,char*>), DefineBehavior(ptr, ptr),
                  0, &multimaplElongcOcharmUgR_Dictionary, isa_proxy, 0,
                  sizeof(multimap<long,char*>) );
      instance.SetNew(&new_multimaplElongcOcharmUgR);
      instance.SetNewArray(&newArray_multimaplElongcOcharmUgR);
      instance.SetDelete(&delete_multimaplElongcOcharmUgR);
      instance.SetDeleteArray(&deleteArray_multimaplElongcOcharmUgR);
      instance.SetDestructor(&destruct_multimaplElongcOcharmUgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< multimap<long,char*> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const multimap<long,char*>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static void multimaplElongcOcharmUgR_Dictionary() {
      ::ROOT::GenerateInitInstanceLocal((const multimap<long,char*>*)0x0)->GetClass();
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_multimaplElongcOcharmUgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) multimap<long,char*> : new multimap<long,char*>;
   }
   static void *newArray_multimaplElongcOcharmUgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) multimap<long,char*>[nElements] : new multimap<long,char*>[nElements];
   }
   // Wrapper around operator delete
   static void delete_multimaplElongcOcharmUgR(void *p) {
      delete ((multimap<long,char*>*)p);
   }
   static void deleteArray_multimaplElongcOcharmUgR(void *p) {
      delete [] ((multimap<long,char*>*)p);
   }
   static void destruct_multimaplElongcOcharmUgR(void *p) {
      typedef multimap<long,char*> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class multimap<long,char*>

namespace ROOT {
   void multimaplElongcOdoublegR_ShowMembers(void *obj, TMemberInspector &R__insp);
   static void multimaplElongcOdoublegR_Dictionary();
   static void *new_multimaplElongcOdoublegR(void *p = 0);
   static void *newArray_multimaplElongcOdoublegR(Long_t size, void *p);
   static void delete_multimaplElongcOdoublegR(void *p);
   static void deleteArray_multimaplElongcOdoublegR(void *p);
   static void destruct_multimaplElongcOdoublegR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const multimap<long,double>*)
   {
      multimap<long,double> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(multimap<long,double>),0);
      static ::ROOT::TGenericClassInfo 
         instance("multimap<long,double>", -2, "prec_stl/multimap", 63,
                  typeid(multimap<long,double>), DefineBehavior(ptr, ptr),
                  0, &multimaplElongcOdoublegR_Dictionary, isa_proxy, 0,
                  sizeof(multimap<long,double>) );
      instance.SetNew(&new_multimaplElongcOdoublegR);
      instance.SetNewArray(&newArray_multimaplElongcOdoublegR);
      instance.SetDelete(&delete_multimaplElongcOdoublegR);
      instance.SetDeleteArray(&deleteArray_multimaplElongcOdoublegR);
      instance.SetDestructor(&destruct_multimaplElongcOdoublegR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< multimap<long,double> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const multimap<long,double>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static void multimaplElongcOdoublegR_Dictionary() {
      ::ROOT::GenerateInitInstanceLocal((const multimap<long,double>*)0x0)->GetClass();
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_multimaplElongcOdoublegR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) multimap<long,double> : new multimap<long,double>;
   }
   static void *newArray_multimaplElongcOdoublegR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) multimap<long,double>[nElements] : new multimap<long,double>[nElements];
   }
   // Wrapper around operator delete
   static void delete_multimaplElongcOdoublegR(void *p) {
      delete ((multimap<long,double>*)p);
   }
   static void deleteArray_multimaplElongcOdoublegR(void *p) {
      delete [] ((multimap<long,double>*)p);
   }
   static void destruct_multimaplElongcOdoublegR(void *p) {
      typedef multimap<long,double> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class multimap<long,double>

namespace ROOT {
   void multimaplElongcOintgR_ShowMembers(void *obj, TMemberInspector &R__insp);
   static void multimaplElongcOintgR_Dictionary();
   static void *new_multimaplElongcOintgR(void *p = 0);
   static void *newArray_multimaplElongcOintgR(Long_t size, void *p);
   static void delete_multimaplElongcOintgR(void *p);
   static void deleteArray_multimaplElongcOintgR(void *p);
   static void destruct_multimaplElongcOintgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const multimap<long,int>*)
   {
      multimap<long,int> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(multimap<long,int>),0);
      static ::ROOT::TGenericClassInfo 
         instance("multimap<long,int>", -2, "prec_stl/multimap", 63,
                  typeid(multimap<long,int>), DefineBehavior(ptr, ptr),
                  0, &multimaplElongcOintgR_Dictionary, isa_proxy, 0,
                  sizeof(multimap<long,int>) );
      instance.SetNew(&new_multimaplElongcOintgR);
      instance.SetNewArray(&newArray_multimaplElongcOintgR);
      instance.SetDelete(&delete_multimaplElongcOintgR);
      instance.SetDeleteArray(&deleteArray_multimaplElongcOintgR);
      instance.SetDestructor(&destruct_multimaplElongcOintgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< multimap<long,int> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const multimap<long,int>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static void multimaplElongcOintgR_Dictionary() {
      ::ROOT::GenerateInitInstanceLocal((const multimap<long,int>*)0x0)->GetClass();
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_multimaplElongcOintgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) multimap<long,int> : new multimap<long,int>;
   }
   static void *newArray_multimaplElongcOintgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) multimap<long,int>[nElements] : new multimap<long,int>[nElements];
   }
   // Wrapper around operator delete
   static void delete_multimaplElongcOintgR(void *p) {
      delete ((multimap<long,int>*)p);
   }
   static void deleteArray_multimaplElongcOintgR(void *p) {
      delete [] ((multimap<long,int>*)p);
   }
   static void destruct_multimaplElongcOintgR(void *p) {
      typedef multimap<long,int> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class multimap<long,int>

namespace ROOT {
   void multimaplElongcOlonggR_ShowMembers(void *obj, TMemberInspector &R__insp);
   static void multimaplElongcOlonggR_Dictionary();
   static void *new_multimaplElongcOlonggR(void *p = 0);
   static void *newArray_multimaplElongcOlonggR(Long_t size, void *p);
   static void delete_multimaplElongcOlonggR(void *p);
   static void deleteArray_multimaplElongcOlonggR(void *p);
   static void destruct_multimaplElongcOlonggR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const multimap<long,long>*)
   {
      multimap<long,long> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(multimap<long,long>),0);
      static ::ROOT::TGenericClassInfo 
         instance("multimap<long,long>", -2, "prec_stl/multimap", 63,
                  typeid(multimap<long,long>), DefineBehavior(ptr, ptr),
                  0, &multimaplElongcOlonggR_Dictionary, isa_proxy, 0,
                  sizeof(multimap<long,long>) );
      instance.SetNew(&new_multimaplElongcOlonggR);
      instance.SetNewArray(&newArray_multimaplElongcOlonggR);
      instance.SetDelete(&delete_multimaplElongcOlonggR);
      instance.SetDeleteArray(&deleteArray_multimaplElongcOlonggR);
      instance.SetDestructor(&destruct_multimaplElongcOlonggR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< multimap<long,long> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const multimap<long,long>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static void multimaplElongcOlonggR_Dictionary() {
      ::ROOT::GenerateInitInstanceLocal((const multimap<long,long>*)0x0)->GetClass();
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_multimaplElongcOlonggR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) multimap<long,long> : new multimap<long,long>;
   }
   static void *newArray_multimaplElongcOlonggR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) multimap<long,long>[nElements] : new multimap<long,long>[nElements];
   }
   // Wrapper around operator delete
   static void delete_multimaplElongcOlonggR(void *p) {
      delete ((multimap<long,long>*)p);
   }
   static void deleteArray_multimaplElongcOlonggR(void *p) {
      delete [] ((multimap<long,long>*)p);
   }
   static void destruct_multimaplElongcOlonggR(void *p) {
      typedef multimap<long,long> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class multimap<long,long>

namespace ROOT {
   void multimaplElongcOvoidmUgR_ShowMembers(void *obj, TMemberInspector &R__insp);
   static void multimaplElongcOvoidmUgR_Dictionary();
   static void *new_multimaplElongcOvoidmUgR(void *p = 0);
   static void *newArray_multimaplElongcOvoidmUgR(Long_t size, void *p);
   static void delete_multimaplElongcOvoidmUgR(void *p);
   static void deleteArray_multimaplElongcOvoidmUgR(void *p);
   static void destruct_multimaplElongcOvoidmUgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const multimap<long,void*>*)
   {
      multimap<long,void*> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(multimap<long,void*>),0);
      static ::ROOT::TGenericClassInfo 
         instance("multimap<long,void*>", -2, "prec_stl/multimap", 63,
                  typeid(multimap<long,void*>), DefineBehavior(ptr, ptr),
                  0, &multimaplElongcOvoidmUgR_Dictionary, isa_proxy, 0,
                  sizeof(multimap<long,void*>) );
      instance.SetNew(&new_multimaplElongcOvoidmUgR);
      instance.SetNewArray(&newArray_multimaplElongcOvoidmUgR);
      instance.SetDelete(&delete_multimaplElongcOvoidmUgR);
      instance.SetDeleteArray(&deleteArray_multimaplElongcOvoidmUgR);
      instance.SetDestructor(&destruct_multimaplElongcOvoidmUgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< multimap<long,void*> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const multimap<long,void*>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static void multimaplElongcOvoidmUgR_Dictionary() {
      ::ROOT::GenerateInitInstanceLocal((const multimap<long,void*>*)0x0)->GetClass();
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_multimaplElongcOvoidmUgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) multimap<long,void*> : new multimap<long,void*>;
   }
   static void *newArray_multimaplElongcOvoidmUgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) multimap<long,void*>[nElements] : new multimap<long,void*>[nElements];
   }
   // Wrapper around operator delete
   static void delete_multimaplElongcOvoidmUgR(void *p) {
      delete ((multimap<long,void*>*)p);
   }
   static void deleteArray_multimaplElongcOvoidmUgR(void *p) {
      delete [] ((multimap<long,void*>*)p);
   }
   static void destruct_multimaplElongcOvoidmUgR(void *p) {
      typedef multimap<long,void*> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class multimap<long,void*>

/********************************************************
* cint/cint/lib/dll_stl/rootcint_multimap2.cxx
* CAUTION: DON'T CHANGE THIS FILE. THIS FILE IS AUTOMATICALLY GENERATED
*          FROM HEADER FILES LISTED IN G__setup_cpp_environmentXXX().
*          CHANGE THOSE HEADER FILES AND REGENERATE THIS FILE.
********************************************************/

#ifdef G__MEMTEST
#undef malloc
#undef free
#endif

#if defined(__GNUC__) && __GNUC__ >= 4 && ((__GNUC_MINOR__ == 2 && __GNUC_PATCHLEVEL__ >= 1) || (__GNUC_MINOR__ >= 3))
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif

extern "C" void G__cpp_reset_tagtablerootcint_multimap2();

extern "C" void G__set_cpp_environmentrootcint_multimap2() {
  G__add_compiledheader("TObject.h");
  G__add_compiledheader("TMemberInspector.h");
  G__add_compiledheader("map");
  G__cpp_reset_tagtablerootcint_multimap2();
}
#include <new>
extern "C" int G__cpp_dllrevrootcint_multimap2() { return(30051515); }

/*********************************************************
* Member function Interface Method
*********************************************************/

/* Setting up global function */

/*********************************************************
* Member function Stub
*********************************************************/

/*********************************************************
* Global function Stub
*********************************************************/

/*********************************************************
* Get size of pointer to member function
*********************************************************/
class G__Sizep2memfuncrootcint_multimap2 {
 public:
  G__Sizep2memfuncrootcint_multimap2(): p(&G__Sizep2memfuncrootcint_multimap2::sizep2memfunc) {}
    size_t sizep2memfunc() { return(sizeof(p)); }
  private:
    size_t (G__Sizep2memfuncrootcint_multimap2::*p)();
};

size_t G__get_sizep2memfuncrootcint_multimap2()
{
  G__Sizep2memfuncrootcint_multimap2 a;
  G__setsizep2memfunc((int)a.sizep2memfunc());
  return((size_t)a.sizep2memfunc());
}


/*********************************************************
* virtual base class offset calculation interface
*********************************************************/

   /* Setting up class inheritance */

/*********************************************************
* Inheritance information setup/
*********************************************************/
extern "C" void G__cpp_setup_inheritancerootcint_multimap2() {

   /* Setting up class inheritance */
}

/*********************************************************
* typedef information setup/
*********************************************************/
extern "C" void G__cpp_setup_typetablerootcint_multimap2() {

   /* Setting up typedef entry */
   G__search_typename2("vector<ROOT::TSchemaHelper>",117,G__get_linked_tagnum(&G__rootcint_multimap2LN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR),0,-1);
   G__setnewtype(-1,NULL,0);
   G__search_typename2("reverse_iterator<const_iterator>",117,G__get_linked_tagnum(&G__rootcint_multimap2LN_reverse_iteratorlEvectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgRcLcLiteratorgR),0,G__get_linked_tagnum(&G__rootcint_multimap2LN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR));
   G__setnewtype(-1,NULL,0);
   G__search_typename2("reverse_iterator<iterator>",117,G__get_linked_tagnum(&G__rootcint_multimap2LN_reverse_iteratorlEvectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgRcLcLiteratorgR),0,G__get_linked_tagnum(&G__rootcint_multimap2LN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR));
   G__setnewtype(-1,NULL,0);
   G__search_typename2("vector<TVirtualArray*>",117,G__get_linked_tagnum(&G__rootcint_multimap2LN_vectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgR),0,-1);
   G__setnewtype(-1,NULL,0);
   G__search_typename2("reverse_iterator<const_iterator>",117,G__get_linked_tagnum(&G__rootcint_multimap2LN_reverse_iteratorlEvectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgRcLcLiteratorgR),0,G__get_linked_tagnum(&G__rootcint_multimap2LN_vectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgR));
   G__setnewtype(-1,NULL,0);
   G__search_typename2("reverse_iterator<iterator>",117,G__get_linked_tagnum(&G__rootcint_multimap2LN_reverse_iteratorlEvectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgRcLcLiteratorgR),0,G__get_linked_tagnum(&G__rootcint_multimap2LN_vectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgR));
   G__setnewtype(-1,NULL,0);
}

/*********************************************************
* Data Member information setup/
*********************************************************/

   /* Setting up class,struct,union tag member variable */
extern "C" void G__cpp_setup_memvarrootcint_multimap2() {
}
/***********************************************************
************************************************************
************************************************************
************************************************************
************************************************************
************************************************************
************************************************************
***********************************************************/

/*********************************************************
* Member function information setup for each class
*********************************************************/

/*********************************************************
* Member function information setup
*********************************************************/
extern "C" void G__cpp_setup_memfuncrootcint_multimap2() {
}

/*********************************************************
* Global variable information setup for each class
*********************************************************/
static void G__cpp_setup_global0() {

   /* Setting up global variables */
   G__resetplocal();

}

static void G__cpp_setup_global1() {

   G__resetglobalenv();
}
extern "C" void G__cpp_setup_globalrootcint_multimap2() {
  G__cpp_setup_global0();
  G__cpp_setup_global1();
}

/*********************************************************
* Global function information setup for each class
*********************************************************/
static void G__cpp_setup_func0() {
   G__lastifuncposition();

}

static void G__cpp_setup_func1() {
}

static void G__cpp_setup_func2() {

   G__resetifuncposition();
}

extern "C" void G__cpp_setup_funcrootcint_multimap2() {
  G__cpp_setup_func0();
  G__cpp_setup_func1();
  G__cpp_setup_func2();
}

/*********************************************************
* Class,struct,union,enum tag information setup
*********************************************************/
/* Setup class/struct taginfo */
G__linked_taginfo G__rootcint_multimap2LN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR = { "vector<ROOT::TSchemaHelper,allocator<ROOT::TSchemaHelper> >" , 99 , -1 };
G__linked_taginfo G__rootcint_multimap2LN_reverse_iteratorlEvectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgRcLcLiteratorgR = { "reverse_iterator<vector<ROOT::TSchemaHelper,allocator<ROOT::TSchemaHelper> >::iterator>" , 99 , -1 };
G__linked_taginfo G__rootcint_multimap2LN_vectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgR = { "vector<TVirtualArray*,allocator<TVirtualArray*> >" , 99 , -1 };
G__linked_taginfo G__rootcint_multimap2LN_reverse_iteratorlEvectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgRcLcLiteratorgR = { "reverse_iterator<vector<TVirtualArray*,allocator<TVirtualArray*> >::iterator>" , 99 , -1 };

/* Reset class/struct taginfo */
extern "C" void G__cpp_reset_tagtablerootcint_multimap2() {
  G__rootcint_multimap2LN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR.tagnum = -1 ;
  G__rootcint_multimap2LN_reverse_iteratorlEvectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgRcLcLiteratorgR.tagnum = -1 ;
  G__rootcint_multimap2LN_vectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgR.tagnum = -1 ;
  G__rootcint_multimap2LN_reverse_iteratorlEvectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgRcLcLiteratorgR.tagnum = -1 ;
}


extern "C" void G__cpp_setup_tagtablerootcint_multimap2() {

   /* Setting up class,struct,union tag entry */
   G__get_linked_tagnum_fwd(&G__rootcint_multimap2LN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR);
   G__get_linked_tagnum_fwd(&G__rootcint_multimap2LN_reverse_iteratorlEvectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgRcLcLiteratorgR);
   G__get_linked_tagnum_fwd(&G__rootcint_multimap2LN_vectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgR);
   G__get_linked_tagnum_fwd(&G__rootcint_multimap2LN_reverse_iteratorlEvectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgRcLcLiteratorgR);
}
extern "C" void G__cpp_setuprootcint_multimap2(void) {
  G__check_setup_version(30051515,"G__cpp_setuprootcint_multimap2()");
  G__set_cpp_environmentrootcint_multimap2();
  G__cpp_setup_tagtablerootcint_multimap2();

  G__cpp_setup_inheritancerootcint_multimap2();

  G__cpp_setup_typetablerootcint_multimap2();

  G__cpp_setup_memvarrootcint_multimap2();

  G__cpp_setup_memfuncrootcint_multimap2();
  G__cpp_setup_globalrootcint_multimap2();
  G__cpp_setup_funcrootcint_multimap2();

   if(0==G__getsizep2memfunc()) G__get_sizep2memfuncrootcint_multimap2();
  return;
}
class G__cpp_setup_initrootcint_multimap2 {
  public:
    G__cpp_setup_initrootcint_multimap2() { G__add_setup_func("rootcint_multimap2",(G__incsetup)(&G__cpp_setuprootcint_multimap2)); G__call_setup_funcs(); }
   ~G__cpp_setup_initrootcint_multimap2() { G__remove_setup_func("rootcint_multimap2"); }
};
G__cpp_setup_initrootcint_multimap2 G__cpp_setup_initializerrootcint_multimap2;

