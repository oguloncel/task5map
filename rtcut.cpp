//setbranch transformed into makefile system
//cuts applied
//TASK 5 from Carlo

#include <iostream>
#include <string>
#include "TFile.h"
#include "TTree.h"
#include "TLorentzVector.h"
#include "TEntryList.h"
#include "TF1.h"
#include "TRandom3.h"
#include "TCanvas.h"
#include "TH1F.h"
#include "TH1D.h"
#include "TH1.h"
#include "nominal.h" // Include nominal
#include "mymap.h"
#include <map>
#include <utility>
#include <vector>
using namespace std;


int main()
{	
	vector<string> v={"zjets","tZ"}; //enter desired file labels here
	vector<string> x={"pT_1lep","pT_2lep","pT_3lep","nJets","ptsum"}; // enter desired parameters
	
	int count2=0;
	string a;
	string pdfname;
	int count=v.size();
	
	for (int i=0; i<count; ++i) {
		
    readf hede;
	a=hede.getFileName(v.at(i));

	nominal N;
	TFile f(a.c_str(),"READ");
	TTree *nominal = (TTree*)f.Get("nominal");
    N.Init((TTree *)f.Get("nominal"));
	
	count2=100;//nominal->GetEntries(); //Number of entries in the eventlist
	
	
	
	// Here begins the Histogram section
	////////////////
	
	ploth gg;
	
	//Loop Sector
	for (unsigned int b = 0; b < count2; ++b) {
	double progress = 100.0 * ((float) b) / ((float) count2);
	//if (!(b % 100)) 
	cout << "File:" << i+1 <<"/"<< count << " " << setprecision(3) << "[ " << progress << " % ] \r";
    
    N.fChain->GetEntry(nominal->GetEntry(b));
    
	
	gg.getHist("pT_1lep")->Fill(N.pT_1lep);	
	gg.getHist("pT_2lep")->Fill(N.pT_2lep);
	gg.getHist("pT_3lep")->Fill(N.pT_3lep);
	gg.getHist("nJets")->Fill(N.nJets);
	double newVar = N.pT_1lep+N.pT_2lep+N.pT_3lep;
	gg.getHist("ptsum")->Fill((newVar));
	}

    for(int i=0; i<x.size(); ++i){
	TCanvas *c = new TCanvas("c","c", 800,600);
    gg.getHist(x.at(i))->Draw();
    pdfname = a+"_"+x.at(i)+".pdf";
	c->SaveAs(pdfname.c_str());
	delete c;
	}
}	           
    return 0;

}	

 	

    
