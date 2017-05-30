//setbranch transformed into makefile system
//cuts applied
//TASK 5 from Carlo

#include <iostream>
#include "TFile.h"
#include "TTree.h"
#include "TLorentzVector.h"
#include "TF1.h"
#include "TRandom3.h"
#include "TCanvas.h"
#include "TH1F.h"
#include "TH1D.h"
#include "TH1.h"
#include "nominal.h" // Include nominal
#include "mymap.h"
void drawhisto();
string myparameter;
using namespace std;

int main()
{	
	cin << "which parameter do you want to plot?" << myparameter;
	selecthist(myparameter);
	int count=0;
	nominal N;
	TFile f("Z+jets_v9T3.root","READ");
	TTree *nominal = (TTree*)f.Get("nominal");
    N.Init((TTree *)f.Get("nominal"));
	count=nominal->GetEntries(); 

    for (int i=0; i<count; ++i) {
		
	N.GetEntry(i);

	currenthist.second->Fill(N.currentparameter);
	TCanvas *c = new TCanvas("c","c", 800,600);
    currenthist.second->Draw();
    c->SaveAs("plot4.pdf");                     
    f.Close();
	return 0
}

    
