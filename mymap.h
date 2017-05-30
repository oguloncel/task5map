#include "TH1F.h"
#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <cmath>
#include "TH1F.h"
#include "TH1.h"
#include <vector>
#include "TFile.h"
#include <iostream>
#include <string>
#include "TCanvas.h"
#include "TFile.h"
#include "TTree.h"
#include "TH1.h"
#include "nominal.h" // Include nominal
#include <map>
#include <utility>

//Define pairs for root files associated with labels
class readf{

private:
std::string filelabel= "";
std::string filename= "";
std::map<std::string, std::string> files = {
	std::make_pair<std::string, std::string>("zjets", "Z+jets_v9T3.root"),
	std::make_pair<std::string, std::string>("tZ", "tZ_v9T3.root"),
	std::make_pair<std::string, std::string>("ttz", "ttZ_v9T3.root"),
	std::make_pair<std::string, std::string>("4l", "4l_v9T3.root"),
};

public:
std::string getFileName(std::string filelabel);

};


class ploth{

private:
std::string histlabel= "";       
std::string histlabel2= "";          
std::map<std::string, TH1F> hists = {
  std::make_pair<std::string, TH1F>("pT_1lep", {"pT_1lep", "lepton 1 pT; #font[52]{p}_{T} [GeV]; Events", 200, 0, 300}),
  std::make_pair<std::string, TH1F>("pT_2lep", {"pT_2lep", "lepton 2 pT; #font[52]{p}_{T} [GeV]; Events", 200, 0, 300}),
  std::make_pair<std::string, TH1F>("pT_3lep", {"pT_3lep", "lepton 3 pT; #font[52]{p}_{T} [GeV]; Events", 200, 0, 300}),
  std::make_pair<std::string, TH1F>("nlep",    {"nlep", "Leptons number; #font[52]{Lepton multiplicity}; Events", 12, 0, 12}),
  std::make_pair<std::string, TH1F>("nJets",   {"nJets", "Jets multiplicity; #font[52]{Jet ultiplicity}; Events ", 10, 0, 10}),
  std::make_pair<std::string, TH1F>("ptsum",   {"ptsum", "ptsum multiplicity; #font[52]{Jet ultiplicity}; Events ", 200, 0, 200}),
};

public:
	TH1F* getHist(std::string histlabel){return &hists.at(histlabel);};
    //friend void PlotSB(std::string a);
};
