//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Jul  7 13:55:08 2014 by ROOT version 5.34/17
// from TTree EventTree/Event Tree for TruthJets
// found on file: test.root
//////////////////////////////////////////////////////////

#ifndef LightJetAnalysisBase_h
#define LightJetAnalysisBase_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.

class LightJetAnalysisBase {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Int_t           EventNumber;
   Int_t           NPV;
   Int_t           NParticlesFilled;
   Float_t         Pt[10000];   //[NParticlesFilled]
   Float_t         Eta[10000];   //[NParticlesFilled]
   Float_t         Phi[10000];   //[NParticlesFilled]
   Float_t         IsHS[10000];   //[NParticlesFilled]
   Float_t         PtMomentPU01_03[10000];   //[NParticlesFilled]
   Float_t         PtMomentHS01_03[10000];   //[NParticlesFilled]
   Float_t         PtMomentAll01_03[10000];   //[NParticlesFilled]
   Float_t         PtMomentPU02_03[10000];   //[NParticlesFilled]
   Float_t         PtMomentHS02_03[10000];   //[NParticlesFilled]
   Float_t         PtMomentAll02_03[10000];   //[NParticlesFilled]
   Float_t         PtMomentPU03_03[10000];   //[NParticlesFilled]
   Float_t         PtMomentHS03_03[10000];   //[NParticlesFilled]
   Float_t         PtMomentAll03_03[10000];   //[NParticlesFilled]
   Float_t         PtMomentPU03_05[10000];   //[NParticlesFilled]
   Float_t         PtMomentHS03_05[10000];   //[NParticlesFilled]
   Float_t         PtMomentAll03_05[10000];   //[NParticlesFilled]
   Float_t         JVFMoment01_03[10000];   //[NParticlesFilled]
   Float_t         JVFMoment02_03[10000];   //[NParticlesFilled]
   Float_t         JVFMoment03_03[10000];   //[NParticlesFilled]
   Float_t         JVFMoment03_05[10000];   //[NParticlesFilled]
   Float_t         JVFMoment01_03_gaus[10000];   //[NParticlesFilled]
   Float_t         JVFMoment02_03_gaus[10000];   //[NParticlesFilled]
   Float_t         JVFMoment03_03_gaus[10000];   //[NParticlesFilled]
   Float_t         JVFMoment03_05_gaus[10000];   //[NParticlesFilled]
   Float_t         ParticleAlphaC[10000];   //[NParticlesFilled]
   Float_t         ParticleAlphaF[10000];   //[NParticlesFilled]

   // List of branches
   TBranch        *b_EventNumber;   //!
   TBranch        *b_NPV;   //!
   TBranch        *b_NParticlesFilled;   //!
   TBranch        *b_Pt;   //!
   TBranch        *b_Eta;   //!
   TBranch        *b_Phi;   //!
   TBranch        *b_IsHS;   //!
   TBranch        *b_PtMomentPU01_03;   //!
   TBranch        *b_PtMomentHS01_03;   //!
   TBranch        *b_PtMomentAll01_03;   //!
   TBranch        *b_PtMomentPU02_03;   //!
   TBranch        *b_PtMomentHS02_03;   //!
   TBranch        *b_PtMomentAll02_03;   //!
   TBranch        *b_PtMomentPU03_03;   //!
   TBranch        *b_PtMomentHS03_03;   //!
   TBranch        *b_PtMomentAll03_03;   //!
   TBranch        *b_PtMomentPU03_05;   //!
   TBranch        *b_PtMomentHS03_05;   //!
   TBranch        *b_PtMomentAll03_05;   //!
   TBranch        *b_JVFMoment01_03;   //!
   TBranch        *b_JVFMoment02_03;   //!
   TBranch        *b_JVFMoment03_03;   //!
   TBranch        *b_JVFMoment03_05;   //!
   TBranch        *b_JVFMoment01_03_gaus;   //!
   TBranch        *b_JVFMoment02_03_gaus;   //!
   TBranch        *b_JVFMoment03_03_gaus;   //!
   TBranch        *b_JVFMoment03_05_gaus;   //!
   TBranch        *b_ParticleAlphaC;   //!
   TBranch        *b_ParticleAlphaF;   //!

   LightJetAnalysisBase(TTree *tree=0);
   virtual ~LightJetAnalysisBase();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef LightJetAnalysisBase_cxx
LightJetAnalysisBase::LightJetAnalysisBase(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("test.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("test.root");
      }
      f->GetObject("EventTree",tree);

   }
   Init(tree);
}

LightJetAnalysisBase::~LightJetAnalysisBase()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t LightJetAnalysisBase::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t LightJetAnalysisBase::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void LightJetAnalysisBase::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("EventNumber", &EventNumber, &b_EventNumber);
   fChain->SetBranchAddress("NPV", &NPV, &b_NPV);
   fChain->SetBranchAddress("NParticlesFilled", &NParticlesFilled, &b_NParticlesFilled);
   fChain->SetBranchAddress("Pt", Pt, &b_Pt);
   fChain->SetBranchAddress("Eta", Eta, &b_Eta);
   fChain->SetBranchAddress("Phi", Phi, &b_Phi);
   fChain->SetBranchAddress("IsHS", IsHS, &b_IsHS);
   fChain->SetBranchAddress("PtMomentPU01_03", PtMomentPU01_03, &b_PtMomentPU01_03);
   fChain->SetBranchAddress("PtMomentHS01_03", PtMomentHS01_03, &b_PtMomentHS01_03);
   fChain->SetBranchAddress("PtMomentAll01_03", PtMomentAll01_03, &b_PtMomentAll01_03);
   fChain->SetBranchAddress("PtMomentPU02_03", PtMomentPU02_03, &b_PtMomentPU02_03);
   fChain->SetBranchAddress("PtMomentHS02_03", PtMomentHS02_03, &b_PtMomentHS02_03);
   fChain->SetBranchAddress("PtMomentAll02_03", PtMomentAll02_03, &b_PtMomentAll02_03);
   fChain->SetBranchAddress("PtMomentPU03_03", PtMomentPU03_03, &b_PtMomentPU03_03);
   fChain->SetBranchAddress("PtMomentHS03_03", PtMomentHS03_03, &b_PtMomentHS03_03);
   fChain->SetBranchAddress("PtMomentAll03_03", PtMomentAll03_03, &b_PtMomentAll03_03);
   fChain->SetBranchAddress("PtMomentPU03_05", PtMomentPU03_05, &b_PtMomentPU03_05);
   fChain->SetBranchAddress("PtMomentHS03_05", PtMomentHS03_05, &b_PtMomentHS03_05);
   fChain->SetBranchAddress("PtMomentAll03_05", PtMomentAll03_05, &b_PtMomentAll03_05);
   fChain->SetBranchAddress("JVFMoment01_03", JVFMoment01_03, &b_JVFMoment01_03);
   fChain->SetBranchAddress("JVFMoment02_03", JVFMoment02_03, &b_JVFMoment02_03);
   fChain->SetBranchAddress("JVFMoment03_03", JVFMoment03_03, &b_JVFMoment03_03);
   fChain->SetBranchAddress("JVFMoment03_05", JVFMoment03_05, &b_JVFMoment03_05);
   fChain->SetBranchAddress("JVFMoment01_03_gaus", JVFMoment01_03_gaus, &b_JVFMoment01_03_gaus);
   fChain->SetBranchAddress("JVFMoment02_03_gaus", JVFMoment02_03_gaus, &b_JVFMoment02_03_gaus);
   fChain->SetBranchAddress("JVFMoment03_03_gaus", JVFMoment03_03_gaus, &b_JVFMoment03_03_gaus);
   fChain->SetBranchAddress("JVFMoment03_05_gaus", JVFMoment03_05_gaus, &b_JVFMoment03_05_gaus);
   fChain->SetBranchAddress("ParticleAlphaC", ParticleAlphaC, &b_ParticleAlphaC);
   fChain->SetBranchAddress("ParticleAlphaF", ParticleAlphaF, &b_ParticleAlphaF);
   Notify();
}

Bool_t LightJetAnalysisBase::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void LightJetAnalysisBase::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t LightJetAnalysisBase::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef LightJetAnalysisBase_cxx
