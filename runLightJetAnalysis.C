#include "LightJetAnalysis.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <math.h>
#include <vector>
#include <stdlib.h>
#include <stdio.h>

#include "TString.h"

#if boostflag==1
#include "boost/program_options.hpp"
namespace po = boost::program_options;
#endif

using std::cout;
using std::endl;
using std::string;
using std::map;
using namespace std;

int main(int argc, char* argv[]){
    // argument parsing  ------------------------
    cout << "Called as: ";
    for(int ii=0; ii<argc; ++ii){
        cout << argv[ii] << " ";
    }
    cout << endl;

    // agruments ----------------------------------------------
    int fDebug         = 0;
    string infile      = "test.root";
    string outName     = "test_output.root";
    int nevents        = 10;

    #if boostflag==1 // command line parsing if boost is installed 
    po::options_description desc("Allowed options");
    desc.add_options()
      ("help", "produce help message")
      ("Debug",          po::value<int>(&fDebug) ->default_value(0) ,     "Debug flag")
      ("InFlie",         po::value<string>(&infile) ->default_value("test.root") ,     "input file")
      ("OutFile",        po::value<string>(&outName)->default_value("test_output.root"), "output file name")
      ("NEvents",        po::value<int>(&nevents)->default_value(10), "number of events to analyze")
      ;
    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);

    if (vm.count("help")>0){
        cout << desc << "\n";
        return 1;
    }
    #endif
    //------

   //-------------------------
   TFile* tf = new TFile(infile.c_str(), "open");
   TTree* tt = (TTree*) tf->Get("EventTree");

   LightJetAnalysis* analysis = new LightJetAnalysis(tt);
   analysis->Debug(fDebug);
   analysis->SetOutName(outName);
   analysis->SetNEvents(nevents);
   analysis->Begin();
   analysis->Loop();
   analysis->End();
   // ----------------------

   // that was it
   delete analysis;

   return 0;
}
