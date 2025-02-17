// @(#)root/mathmore:$Id: MinimTransformFunction.h 31763 2009-12-10 10:40:21Z moneta $
// Author: L. Moneta June 2009

/**********************************************************************
 *                                                                    *
 * Copyright (c) 2006  LCG ROOT Math Team, CERN/PH-SFT                *
 *                                                                    *
 *                                                                    *
 **********************************************************************/


// Header file for class MinimTransformFunction

#ifndef ROOT_Math_MinimTransformFunction
#define ROOT_Math_MinimTransformFunction


#ifndef ROOT_Math_IFunction
#include "Math/IFunction.h"
#endif

#ifndef ROOT_Math_MinimizerVariable
#include "Math/MinimizerVariable.h"
#endif


#include <vector> 
#include <map>

namespace ROOT { 

   namespace Math { 



/** 
   MinimTransformFunction class to perform a transformations on the 
   variables to deal with fixed or limited variables (support both double and single bounds)
   The class manages the passed function pointer 

   @ingroup MultiMin
*/ 
class MinimTransformFunction : public IMultiGradFunction { 

public: 

   typedef  ROOT::Math::IMultiGradFunction BaseGradFunc; 
   typedef  ROOT::Math::IMultiGradFunction::BaseFunc BaseFunc; 


   /** 
     Constructor from a IMultiGradFunction interface (which is managed by the class) 
     vector specifying the variable types (free, bounded or fixed, defined in enum EMinimVariableTypes )
     variable values (used for the fixed ones) and a map with the bounds (for the bounded variables)

   */ 
   MinimTransformFunction ( const IMultiGradFunction * f, const std::vector<EMinimVariableType> & types, const std::vector<double> & values, 
                            const std::map<unsigned int, std::pair<double, double> > & bounds); 


   /** 
      Destructor (delete function pointer)
   */ 
   ~MinimTransformFunction ()  {  
      if (fFunc) delete fFunc; 
   }  


   // method inherited from IFunction interface 

   unsigned int NDim() const { return fIndex.size(); } 

   unsigned int NTot() const { return fFunc->NDim(); } 

   /// clone:  not supported (since auto_ptr used in the fVariables)
   IMultiGenFunction * Clone() const { 
      return 0; 
   }


   /// transform from internal to external 
   /// result is cached also inside the class
   const double * Transformation( const double * x) const;


   /// inverse transformation (external -> internal)
   void  InvTransformation(const double * xext,  double * xint) const;

   /// inverse transformation for steps (external -> internal) at external point x
   void  InvStepTransformation(const double * x, const double * sext,  double * sint) const;

   ///transform gradient vector (external -> internal) at internal point x
   void GradientTransformation(const double * x, const double *gExt, double * gInt) const;  

   ///transform covariance matrix (internal -> external) at internal point x
   /// use row storages for matrices  m(i,j) = rep[ i * dim + j]
   void MatrixTransformation(const double * x, const double *covInt, double * covExt) const;  


private: 

   /// function evaluation
   virtual double DoEval(const double * x) const {       
      return (*fFunc)(Transformation(x)); 
   }

   /// calculate derivatives
   virtual double DoDerivative (const double * x, unsigned int icoord  ) const { 
      const MinimizerVariable & var = fVariables[ fIndex[icoord] ]; 
      double dExtdInt = (var.IsLimited() ) ? var.DerivativeIntToExt( x[icoord] ) : 1.0;
      double deriv =  fFunc->Derivative( Transformation(x) , fIndex[icoord] ); 
      //std::cout << "Derivative icoord (ext)" << fIndex[icoord] << "   dtrafo " << dExtdInt << "  " << deriv << std::endl;
      return deriv * dExtdInt; 
   }  

   // copy constructor for this class (disable by having it private) 
   MinimTransformFunction( const MinimTransformFunction & ) : 
      BaseFunc(), BaseGradFunc()
   {}

   // assignment operator for this class (disable by having it private) 
   MinimTransformFunction & operator= ( const MinimTransformFunction & ) { 
      return *this;
   }
   

private: 

   mutable std::vector<double>  fX;              // internal cached of external values
   std::vector<MinimizerVariable> fVariables;    // vector of variable settings and tranformation function
   std::vector<unsigned int>      fIndex;        // vector with external indices for internal variables    
   const IMultiGradFunction * fFunc;             // user function 

}; 

   } // end namespace Math

} // end namespace ROOT


#endif /* ROOT_Math_MinimTransformFunction */
