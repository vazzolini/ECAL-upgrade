#define ProofNtuple_cxx

//////////////////////////////////////////////////////////
//
// Example of TSelector implementation to do generic
// processing (filling a simple ntuple, in this case).
// See tutorials/proof/runProof.C, option "ntuple", for an
// example of how to run this selector.
//
//////////////////////////////////////////////////////////

#include "ProofNtuple.h"
#include <TCanvas.h>
#include <TFrame.h>
#include <TPaveText.h>
#include <TMath.h>
#include <TNtuple.h>
#include <TRandom3.h>
#include <TString.h>
#include <TStyle.h>
#include <TSystem.h>
#include <TFile.h>
#include <TProofOutputFile.h>

ProofNtuple::~ProofNtuple()
{
   // Destructor

   SafeDelete(fNtp);
   SafeDelete(fFile);
   SafeDelete(fRandom);
}

void ProofNtuple::PlotNtuple(TNtuple *ntp, const char *ntptitle)
{
   // Make some plots from the ntuple 'ntp'

   //
   // Create a canvas, with 2 pads
   //
   TCanvas *c1 = new TCanvas(Form("cv-%s", ntp->GetName()), ntptitle,800,10,700,780);
   c1->Divide(1,2);
   TPad *pad1 = (TPad *) c1->GetPad(1);
   TPad *pad2 = (TPad *) c1->GetPad(2);
   //
   // Display a function of one ntuple column imposing a condition
   // on another column.
   pad1->cd();
   pad1->SetGrid();
   pad1->SetLogy();
   pad1->GetFrame()->SetFillColor(15);
   ntp->SetLineColor(1);
   ntp->SetFillStyle(1001);
   ntp->SetFillColor(45);
   ntp->Draw("3*px+2","px**2+py**2>1");
   ntp->SetFillColor(38);
   ntp->Draw("2*px+2","pz>2","same");
   ntp->SetFillColor(5);
   ntp->Draw("1.3*px+2","(px^2+py^2>4) && py>0","same");
   pad1->RedrawAxis();

   //
   // Display a 3-D scatter plot of 3 columns. Superimpose a different selection.
   pad2->cd();
   ntp->Draw("pz:py:px","(pz<10 && pz>6)+(pz<4 && pz>3)");
   ntp->SetMarkerColor(4);
   ntp->Draw("pz:py:px","pz<6 && pz>4","same");
   ntp->SetMarkerColor(5);
   ntp->Draw("pz:py:px","pz<4 && pz>3","same");
   TPaveText *l2 = new TPaveText(0.,0.6,0.9,0.95);
   l2->SetFillColor(42);
   l2->SetTextAlign(12);
   l2->AddText("You can interactively rotate this view in 2 ways:");
   l2->AddText("  - With the RotateCube in clicking in this pad");
   l2->AddText("  - Selecting View with x3d in the View menu");
   l2->Draw();

   // Final update
   c1->cd();
   c1->Update();
}

void ProofNtuple::Begin(TTree * /*tree*/)
{
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

   TNamed *out = (TNamed *) fInput->FindObject("PROOF_NTUPLE_DONT_PLOT");
   if (out) fPlotNtuple = kFALSE;
}

void ProofNtuple::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

   // We may be creating a dataset or a merge file: check it
   TNamed *nm = dynamic_cast<TNamed *>(fInput->FindObject("SimpleNtuple.root"));
   if (nm) {
      // Just create the object
      UInt_t opt = TProofOutputFile::kRegister | TProofOutputFile::kOverwrite | TProofOutputFile::kVerify;
      fProofFile = new TProofOutputFile("SimpleNtuple.root",
                                        TProofOutputFile::kDataset, opt, nm->GetTitle());
   } else {
      // For the ntuple, we use the automatic file merging facility
      // Check if an output URL has been given
      TNamed *out = (TNamed *) fInput->FindObject("PROOF_OUTPUTFILE_LOCATION");
      Info("SlaveBegin", "PROOF_OUTPUTFILE_LOCATION: %s", (out ? out->GetTitle() : "undef"));
      fProofFile = new TProofOutputFile("SimpleNtuple.root", (out ? out->GetTitle() : "M"));
      out = (TNamed *) fInput->FindObject("PROOF_OUTPUTFILE");
      if (out) fProofFile->SetOutputFileName(out->GetTitle());
   }

   // Open the file
   TDirectory *savedir = gDirectory;
   fFile = fProofFile->OpenFile("RECREATE");
   if (fFile && fFile->IsZombie()) SafeDelete(fFile);
   savedir->cd();

   // Cannot continue
   if (!fFile) {
      Info("SlaveBegin", "could not create '%s': instance is invalid!", fProofFile->GetName());
      return;
   }

   // Now we create the ntuple
   fNtp = new TNtuple("ntuple","Demo ntuple","px:py:pz:random:i");
   // File resident
   fNtp->SetDirectory(fFile);
   fNtp->AutoSave();

   // Init the random generator
   fRandom = new TRandom3(0);
}

Bool_t ProofNtuple::Process(Long64_t entry)
{
   // The Process() function is called for each entry in the tree (or possibly
   // keyed object in the case of PROOF) to be processed. The entry argument
   // specifies which entry in the currently loaded tree is to be processed.
   // It can be passed to either ProofNtuple::GetEntry() or TBranch::GetEntry()
   // to read either all or the required parts of the data. When processing
   // keyed objects with PROOF, the object is already loaded and is available
   // via the fObject pointer.
   //
   // This function should contain the "body" of the analysis. It can contain
   // simple or elaborate selection criteria, run algorithms on the data
   // of the event and typically fill histograms.
   //
   // The processing can be stopped by calling Abort().
   //
   // Use fStatus to set the return value of TTree::Process().
   //
   // The return value is currently not used.

   if (!fNtp) return kTRUE;

   // Fill ntuple
   Float_t px, py;
   fRandom->Rannor(px,py);
   Float_t pz = px*px + py*py;
   Float_t random = fRandom->Rndm();
   Int_t i = (Int_t) entry;
   fNtp->Fill(px,py,pz,random,i);

   return kTRUE;
}

void ProofNtuple::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

   // Write the ntuple to the file
   if (fFile) {
      Bool_t cleanup = kFALSE;
      TDirectory *savedir = gDirectory;
      if (fNtp->GetEntries() > 0) {
         fFile->cd();
         fNtp->Write();
         fProofFile->Print();
         fOutput->Add(fProofFile);
      } else {
         cleanup = kTRUE;
      }
      fNtp->SetDirectory(0);
      gDirectory = savedir;
      fFile->Close();
      // Cleanup, if needed
      if (cleanup) {
         TUrl uf(*(fFile->GetEndpointUrl()));
         SafeDelete(fFile);
         gSystem->Unlink(uf.GetFile());
         SafeDelete(fProofFile);
      }
   }
}

void ProofNtuple::Terminate()
{
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.

   // Do nothing is not requested (dataset creation run)
   if (!fPlotNtuple) return;

   // Get the ntuple form the file
   if ((fProofFile =
           dynamic_cast<TProofOutputFile*>(fOutput->FindObject("SimpleNtuple.root")))) {

      TString outputFile(fProofFile->GetOutputFileName());
      TString outputName(fProofFile->GetName());
      outputName += ".root";
      Printf("outputFile: %s", outputFile.Data());

      // Read the ntuple from the file
      fFile = TFile::Open(outputFile);
      if (fFile) {
         Printf("Managed to open file: %s", outputFile.Data());
         fNtp = (TNtuple *) fFile->Get("ntuple");
      } else {
         Error("Terminate", "could not open file: %s", outputFile.Data());
      }
      if (!fFile) return; 

   } else {
      Error("Terminate", "TProofOutputFile not found");
      return;
   }

   // Plot ntuples
   if (fNtp) PlotNtuple(fNtp, "proof ntuple");
}
