#include <math.h>
#include <vector>
#include <string>
#include <sstream>
#include <set>
#include <algorithm>


#include "TFile.h"
#include "TTree.h"
#include "TMath.h"
#include "TVector3.h"
#include "TH1D.h"


#include "fastjet/ClusterSequence.hh"
#include "fastjet/PseudoJet.hh"  
#include "fastjet/tools/Filter.hh"
#include "fastjet/Selector.hh"
#include "fastjet/tools/Subtractor.hh"
#include "fastjet/ClusterSequenceArea.hh"
#include "fastjet/tools/JetMedianBackgroundEstimator.hh"

#include "LightJetAnalysis.h"

using namespace std;


// Constructor 
LightJetAnalysis::LightJetAnalysis(TTree* tree){
    if(debug_) cout << "LightJetAnalysis::LightJetAnalysis Start " << endl;
    debug_   = false;
    outname_ = "test.root";

    Init(tree);

    if(debug_) cout << "LightJetAnalysis::LightJetAnalysis End " << endl;
}

// Destructor 
LightJetAnalysis::~LightJetAnalysis(){
}

// Begin method
void LightJetAnalysis::Begin(){
    
    // create output file 
    outfile_ = new TFile(outname_.c_str(), "recreate");

    // declare histos
    h_clpt    = new TH1D("cl_pt", "", 100, 0, 500);

   return;
}

// End
void LightJetAnalysis::End(){
    
    outfile_->Write();

    delete outfile_;
    return;
}

// loop method
void LightJetAnalysis::Loop(){
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<min(nentries,nevents_);jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;


      // now call analyze method
      Analyze();
   }
   return;
}


// Analyze method, called for each event
// -> do event by event calculation and filling of histos here
void LightJetAnalysis::Analyze(){

    cout << "---------------------------- " << endl;
    cout << "Event Number " << EventNumber  << endl; 


    cout << "PtMomentPU01_03 " << PtMomentPU01_03[0] << endl;
    fastjet::PseudoJet particle;
    vector<fastjet::PseudoJet> particles;

    // loop
    particle.reset_PtYPhiM(Pt[0], Eta[0], Phi[0], 0);


    return; 
}
