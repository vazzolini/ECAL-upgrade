// @(#)root/tmva $Id: Factory.h 40005 2011-06-27 15:29:10Z stelzer $   
// Author: Andreas Hoecker, Peter Speckmayer, Joerg Stelzer, Helge Voss, Kai Voss, Eckhard von Toerne, Jan Therhaag 

/**********************************************************************************
 * Project: TMVA - a Root-integrated toolkit for multivariate data analysis       *
 * Package: TMVA                                                                  *
 * Class  : Factory                                                               *
 * Web    : http://tmva.sourceforge.net                                           *
 *                                                                                *
 * Description:                                                                   *
 *      This is the main MVA steering class: it creates (books) all MVA methods,  *
 *      and guides them through the training, testing and evaluation phases.      *
 *                                                                                *
 * Authors (alphabetical):                                                        *
 *      Andreas Hoecker <Andreas.Hocker@cern.ch> - CERN, Switzerland              *
 *      Joerg Stelzer   <stelzer@cern.ch>        - DESY, Germany                  *
 *      Peter Speckmayer <peter.speckmayer@cern.ch> - CERN, Switzerland           *
 *      Jan Therhaag          <Jan.Therhaag@cern.ch>   - U of Bonn, Germany       *
 *      Eckhard v. Toerne     <evt@uni-bonn.de>        - U of Bonn, Germany       *
 *      Helge Voss      <Helge.Voss@cern.ch>     - MPI-K Heidelberg, Germany      *
 *      Kai Voss        <Kai.Voss@cern.ch>       - U. of Victoria, Canada         *
 *                                                                                *
 * Copyright (c) 2005-2011:                                                       *
 *      CERN, Switzerland                                                         *
 *      U. of Victoria, Canada                                                    *
 *      MPI-K Heidelberg, Germany                                                 *
 *      U. of Bonn, Germany                                                       *
 *                                                                                *
 * Redistribution and use in source and binary forms, with or without             *
 * modification, are permitted according to the terms listed in LICENSE           *
 * (http://tmva.sourceforge.net/LICENSE)                                          *
 **********************************************************************************/

#ifndef ROOT_TMVA_Factory
#define ROOT_TMVA_Factory

//////////////////////////////////////////////////////////////////////////
//                                                                      //
// Factory                                                              //
//                                                                      //
// This is the main MVA steering class: it creates all MVA methods,     //
// and guides them through the training, testing and evaluation         //
// phases                                                               //
//                                                                      //
//////////////////////////////////////////////////////////////////////////

#include <string>
#include <vector>
#include <map>
#ifndef ROOT_TCut
#include "TCut.h"
#endif

#ifndef ROOT_TMVA_Configurable
#include "TMVA/Configurable.h"
#endif
#ifndef ROOT_TMVA_Types
#include "TMVA/Types.h"
#endif
#ifndef ROOT_TMVA_DataSet
#include "TMVA/DataSet.h"
#endif

class TFile;
class TTree;
class TDirectory;

namespace TMVA {

   class IMethod;
   class MethodBase;
   class DataInputHandler;
   class DataSetInfo;
   class DataSetManager;
   class VariableTransformBase;

   class Factory : public Configurable {
   public:

      typedef std::vector<IMethod*> MVector;

      // no default  constructor
      Factory( TString theJobName, TFile* theTargetFile, TString theOption = "" );

      // default destructor
      virtual ~Factory();

      virtual const char*  GetName() const { return "Factory"; }

      // add events to training and testing trees
      void AddSignalTrainingEvent    ( const std::vector<Double_t>& event, Double_t weight = 1.0 );
      void AddBackgroundTrainingEvent( const std::vector<Double_t>& event, Double_t weight = 1.0 );
      void AddSignalTestEvent        ( const std::vector<Double_t>& event, Double_t weight = 1.0 );
      void AddBackgroundTestEvent    ( const std::vector<Double_t>& event, Double_t weight = 1.0 );
      void AddTrainingEvent( const TString& className, const std::vector<Double_t>& event, Double_t weight );
      void AddTestEvent    ( const TString& className, const std::vector<Double_t>& event, Double_t weight );
      void AddEvent        ( const TString& className, Types::ETreeType tt, const std::vector<Double_t>& event, Double_t weight );
      Bool_t UserAssignEvents(UInt_t clIndex);
      TTree* CreateEventAssignTrees( const TString& name );

      DataSetInfo& AddDataSet( DataSetInfo& );
      DataSetInfo& AddDataSet( const TString&  );

      // special case: signal/background

      // Data input related
      void SetInputTrees( const TString& signalFileName, const TString& backgroundFileName, 
                          Double_t signalWeight=1.0, Double_t backgroundWeight=1.0 );
      void SetInputTrees( TTree* inputTree, const TCut& SigCut, const TCut& BgCut );
      // Set input trees  at once
      void SetInputTrees( TTree* signal, TTree* background, 
                          Double_t signalWeight=1.0, Double_t backgroundWeight=1.0) ;

      void AddSignalTree( TTree* signal,    Double_t weight=1.0, Types::ETreeType treetype = Types::kMaxTreeType );
      void AddSignalTree( TString datFileS, Double_t weight=1.0, Types::ETreeType treetype = Types::kMaxTreeType );
      void AddSignalTree( TTree* signal, Double_t weight, const TString& treetype );      

      // ... depreciated, kept for backwards compatibility
      void SetSignalTree( TTree* signal, Double_t weight=1.0);

      void AddBackgroundTree( TTree* background, Double_t weight=1.0, Types::ETreeType treetype = Types::kMaxTreeType );
      void AddBackgroundTree( TString datFileB,  Double_t weight=1.0, Types::ETreeType treetype = Types::kMaxTreeType );
      void AddBackgroundTree( TTree* background, Double_t weight, const TString & treetype );

      // ... depreciated, kept for backwards compatibility
      void SetBackgroundTree( TTree* background, Double_t weight=1.0 );

      void SetSignalWeightExpression( const TString& variable );
      void SetBackgroundWeightExpression( const TString& variable );

      // special case: regression
      void AddRegressionTree( TTree* tree, Double_t weight = 1.0,  
                              Types::ETreeType treetype = Types::kMaxTreeType ) { 
         AddTree( tree, "Regression", weight, "", treetype ); 
      }

      // general

      // Data input related
      void SetTree( TTree* tree, const TString& className, Double_t weight ); // depreciated
      void AddTree( TTree* tree, const TString& className, Double_t weight=1.0,
                    const TCut& cut = "",
                    Types::ETreeType tt = Types::kMaxTreeType );
      void AddTree( TTree* tree, const TString& className, Double_t weight, const TCut& cut, const TString& treeType );

      // set input variable
      void SetInputVariables  ( std::vector<TString>* theVariables ); // depreciated
      void AddVariable        ( const TString& expression, const TString& title, const TString& unit,
                                char type='F', Double_t min = 0, Double_t max = 0 );
      void AddVariable        ( const TString& expression, char type='F',
                                Double_t min = 0, Double_t max = 0 );
      void AddTarget          ( const TString& expression, const TString& title = "", const TString& unit = "",
                                Double_t min = 0, Double_t max = 0 );
      void AddRegressionTarget( const TString& expression, const TString& title = "", const TString& unit = "",
                                Double_t min = 0, Double_t max = 0 )
      {
         AddTarget( expression, title, unit, min, max );
      }
      void AddSpectator         ( const TString& expression, const TString& title = "", const TString& unit = "",
                                Double_t min = 0, Double_t max = 0 );

      // set weight for class
      void SetWeightExpression( const TString& variable, const TString& className = "" );

      // set cut for class
      void SetCut( const TString& cut, const TString& className = "" );
      void SetCut( const TCut& cut, const TString& className = "" );
      void AddCut( const TString& cut, const TString& className = "" );
      void AddCut( const TCut& cut, const TString& className = "" );


      //  prepare input tree for training
      void PrepareTrainingAndTestTree( const TCut& cut, const TString& splitOpt );
      void PrepareTrainingAndTestTree( TCut sigcut, TCut bkgcut, const TString& splitOpt );

      // ... deprecated, kept for backwards compatibility 
      void PrepareTrainingAndTestTree( const TCut& cut, Int_t Ntrain, Int_t Ntest = -1 );

      void PrepareTrainingAndTestTree( const TCut& cut, Int_t NsigTrain, Int_t NbkgTrain, Int_t NsigTest, Int_t NbkgTest, 
                                       const TString& otherOpt="SplitMode=Random:!V" );

      MethodBase* BookMethod( TString theMethodName, TString methodTitle, TString theOption = "" );
      MethodBase* BookMethod( Types::EMVA theMethod,  TString methodTitle, TString theOption = "" );
      MethodBase* BookMethod( TMVA::Types::EMVA /*theMethod*/, 
                              TString /*methodTitle*/, 
                              TString /*methodOption*/, 
                              TMVA::Types::EMVA /*theCommittee*/, 
                              TString /*committeeOption = ""*/ ) { return 0; } 

      // optimize all booked methods (well, if desired by the method)
      void OptimizeAllMethods                 (TString fomType="ROCIntegral", TString fitType="FitGA");
      void OptimizeAllMethodsForClassification(TString fomType="ROCIntegral", TString fitType="FitGA") { OptimizeAllMethods(fomType,fitType); }
      void OptimizeAllMethodsForRegression    (TString fomType="ROCIntegral", TString fitType="FitGA") { OptimizeAllMethods(fomType,fitType); }

      // training for all booked methods
      void TrainAllMethods                 ();
      void TrainAllMethodsForClassification( void ) { TrainAllMethods(); }
      void TrainAllMethodsForRegression    ( void ) { TrainAllMethods(); }

      // testing
      void TestAllMethods();

      // performance evaluation
      void EvaluateAllMethods( void );
      void EvaluateAllVariables( TString options = "" ); 
  
      // delete all methods and reset the method vector
      void DeleteAllMethods( void );

      // accessors
      IMethod* GetMethod( const TString& title ) const;

      Bool_t Verbose( void ) const { return fVerbose; }
      void SetVerbose( Bool_t v=kTRUE );

      // make ROOT-independent C++ class for classifier response 
      // (classifier-specific implementation)
      // If no classifier name is given, help messages for all booked 
      // classifiers are printed
      virtual void MakeClass( const TString& methodTitle = "" ) const;

      // prints classifier-specific hepl messages, dedicated to 
      // help with the optimisation and configuration options tuning.
      // If no classifier name is given, help messages for all booked 
      // classifiers are printed
      void PrintHelpMessage( const TString& methodTitle = "" ) const;

      static TDirectory* RootBaseDir() { return (TDirectory*)fgTargetFile; }

   private:

      // the beautiful greeting message
      void Greetings();

      void WriteDataInformation();

      DataInputHandler&        DataInput() { return *fDataInputHandler; }
      DataSetInfo&             DefaultDataSetInfo();
      void                     SetInputTreesFromEventAssignTrees();


   private:

      // data members


      DataSetManager* fDataSetManager; // DSMTEST

      static TFile*                             fgTargetFile;     //! ROOT output file

      DataInputHandler*                         fDataInputHandler;

      std::vector<TMVA::VariableTransformBase*> fDefaultTrfs;     //! list of transformations on default DataSet

      // cd to local directory
      TString                                   fOptions;         //! option string given by construction (presently only "V")
      TString                                   fTransformations; //! List of transformations to test
      Bool_t                                    fVerbose;         //! verbose mode

      MVector                                   fMethods;         //! all MVA methods
      TString                                   fJobName;         //! jobname, used as extension in weight file names

      // flag determining the way training and test data are assigned to Factory
      enum DataAssignType { kUndefined = 0, 
                            kAssignTrees,
                            kAssignEvents };
      DataAssignType                            fDataAssignType;  //! flags for data assigning
      std::vector<TTree*>                       fTrainAssignTree; //! for each class: tmp tree if user wants to assign the events directly
      std::vector<TTree*>                       fTestAssignTree;  //! for each class: tmp tree if user wants to assign the events directly

      Int_t                                     fATreeType;          // type of event (=classIndex)
      Float_t                                   fATreeWeight;        // weight of the event
      Float_t*                                  fATreeEvent;         // event variables

      Types::EAnalysisType                      fAnalysisType;    //! the training type

   protected:

      ClassDef(Factory,0)  // The factory creates all MVA methods, and performs their training and testing
   };

} // namespace TMVA

#endif

