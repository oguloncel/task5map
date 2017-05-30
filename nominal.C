#include "nominal.h"
#include <TStyle.h>
#include <TCanvas.h>

void nominal::Loop()
{
//   In a ROOT session, you can do:
//      root> .L nominal.C
//      root> nominal t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
   }
}

nominal::nominal(TTree *tree) : fChain(0)
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("Z+jets_v9T3.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("Z+jets_v9T3.root");
      }
      f->GetObject("nominal",tree);

   }
   Init(tree);
}

nominal::~nominal()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t nominal::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t nominal::LoadTree(Long64_t entry)
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

void nominal::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make.txt changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   el_pt = 0;
   el_eta = 0;
   el_cl_eta = 0;
   el_phi = 0;
   el_e = 0;
   el_charge = 0;
   el_topoetcone20 = 0;
   el_ptvarcone20 = 0;
   el_d0sig = 0;
   el_delta_z0_sintheta = 0;
   mu_pt = 0;
   mu_eta = 0;
   mu_phi = 0;
   mu_e = 0;
   mu_charge = 0;
   mu_topoetcone20 = 0;
   mu_ptvarcone30 = 0;
   mu_d0sig = 0;
   mu_delta_z0_sintheta = 0;
   jet_pt = 0;
   jet_eta = 0;
   jet_phi = 0;
   jet_e = 0;
   jet_mv2c00 = 0;
   jet_mv2c10 = 0;
   jet_mv2c20 = 0;
   jet_ip3dsv1 = 0;
   jet_jvt = 0;
   OSSF_M = 0;
   nOSSF=0;
   prompt = 0;
   totWF=0;
   BDT=0;
  code=0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);
   fChain->SetBranchAddress("eventNumber", &eventNumber, &b_eventNumber);
   fChain->SetBranchAddress("runNumber", &runNumber, &b_runNumber);
   fChain->SetBranchAddress("mcChannelNumber", &mcChannelNumber, &b_mcChannelNumber);
   fChain->SetBranchAddress("mu", &mu, &b_mu);
   fChain->SetBranchAddress("backgroundFlags", &backgroundFlags, &b_backgroundFlags);
   fChain->SetBranchAddress("el_pt", &el_pt, &b_el_pt);
   fChain->SetBranchAddress("el_eta", &el_eta, &b_el_eta);
   fChain->SetBranchAddress("el_cl_eta", &el_cl_eta, &b_el_cl_eta);
   fChain->SetBranchAddress("el_phi", &el_phi, &b_el_phi);
   fChain->SetBranchAddress("el_e", &el_e, &b_el_e);
   fChain->SetBranchAddress("el_charge", &el_charge, &b_el_charge);
   fChain->SetBranchAddress("el_topoetcone20", &el_topoetcone20, &b_el_topoetcone20);
   fChain->SetBranchAddress("el_ptvarcone20", &el_ptvarcone20, &b_el_ptvarcone20);
   fChain->SetBranchAddress("el_d0sig", &el_d0sig, &b_el_d0sig);
   fChain->SetBranchAddress("el_delta_z0_sintheta", &el_delta_z0_sintheta, &b_el_delta_z0_sintheta);
   fChain->SetBranchAddress("mu_pt", &mu_pt, &b_mu_pt);
   fChain->SetBranchAddress("mu_eta", &mu_eta, &b_mu_eta);
   fChain->SetBranchAddress("mu_phi", &mu_phi, &b_mu_phi);
   fChain->SetBranchAddress("mu_e", &mu_e, &b_mu_e);
   fChain->SetBranchAddress("mu_charge", &mu_charge, &b_mu_charge);
   fChain->SetBranchAddress("mu_topoetcone20", &mu_topoetcone20, &b_mu_topoetcone20);
   fChain->SetBranchAddress("mu_ptvarcone30", &mu_ptvarcone30, &b_mu_ptvarcone30);
   fChain->SetBranchAddress("mu_d0sig", &mu_d0sig, &b_mu_d0sig);
   fChain->SetBranchAddress("mu_delta_z0_sintheta", &mu_delta_z0_sintheta, &b_mu_delta_z0_sintheta);
   fChain->SetBranchAddress("jet_pt", &jet_pt, &b_jet_pt);
   fChain->SetBranchAddress("jet_eta", &jet_eta, &b_jet_eta);
   fChain->SetBranchAddress("jet_phi", &jet_phi, &b_jet_phi);
   fChain->SetBranchAddress("jet_e", &jet_e, &b_jet_e);
   fChain->SetBranchAddress("jet_mv2c00", &jet_mv2c00, &b_jet_mv2c00);
   fChain->SetBranchAddress("jet_mv2c10", &jet_mv2c10, &b_jet_mv2c10);
   fChain->SetBranchAddress("jet_mv2c20", &jet_mv2c20, &b_jet_mv2c20);
   fChain->SetBranchAddress("jet_ip3dsv1", &jet_ip3dsv1, &b_jet_ip3dsv1);
   fChain->SetBranchAddress("jet_jvt", &jet_jvt, &b_jet_jvt);
   fChain->SetBranchAddress("met_met", &met_met, &b_met_met);
   fChain->SetBranchAddress("met_phi", &met_phi, &b_met_phi);
   fChain->SetBranchAddress("randomNumber", &randomNumber, &b_randomNumber);
   fChain->SetBranchAddress("nEl", &nEl, &b_nEl);
   fChain->SetBranchAddress("nMu", &nMu, &b_nMu);
   fChain->SetBranchAddress("nJets", &nJets, &b_nJets);
   fChain->SetBranchAddress("nBJets70", &nBJets70, &b_nBJets70);
   fChain->SetBranchAddress("nBJets77", &nBJets77, &b_nBJets77);
   fChain->SetBranchAddress("nBJets85", &nBJets85, &b_nBJets85);
   fChain->SetBranchAddress("pT_1lep", &pT_1lep, &b_pT_1lep);
   fChain->SetBranchAddress("pT_2lep", &pT_2lep, &b_pT_2lep);
   fChain->SetBranchAddress("pT_3lep", &pT_3lep, &b_pT_3lep);
   fChain->SetBranchAddress("eta_1lep", &eta_1lep, &b_eta_1lep);
   fChain->SetBranchAddress("eta_2lep", &eta_2lep, &b_eta_2lep);
   fChain->SetBranchAddress("eta_3lep", &eta_3lep, &b_eta_3lep);
   fChain->SetBranchAddress("phi_1lep", &phi_1lep, &b_phi_1lep);
   fChain->SetBranchAddress("phi_2lep", &phi_2lep, &b_phi_2lep);
   fChain->SetBranchAddress("phi_3lep", &phi_3lep, &b_phi_3lep);
   fChain->SetBranchAddress("pdgid_1lep", &pdgid_1lep, &b_pdgid_1lep);
   fChain->SetBranchAddress("pdgid_2lep", &pdgid_2lep, &b_pdgid_2lep);
   fChain->SetBranchAddress("pdgid_3lep", &pdgid_3lep, &b_pdgid_3lep);
   fChain->SetBranchAddress("charge_1lep", &charge_1lep, &b_charge_1lep);
   fChain->SetBranchAddress("charge_2lep", &charge_2lep, &b_charge_2lep);
   fChain->SetBranchAddress("charge_3lep", &charge_3lep, &b_charge_3lep);
   fChain->SetBranchAddress("pT_1jet", &pT_1jet, &b_pT_1jet);
   fChain->SetBranchAddress("pT_2jet", &pT_2jet, &b_pT_2jet);
   fChain->SetBranchAddress("pT_3jet", &pT_3jet, &b_pT_3jet);
   fChain->SetBranchAddress("ht", &ht, &b_ht);
   fChain->SetBranchAddress("mll", &mll, &b_mll);
   fChain->SetBranchAddress("RunNumber", &RunNumber, &b_RunNumber);
   fChain->SetBranchAddress("EventNumber", &EventNumber, &b_EventNumber);
   fChain->SetBranchAddress("lep1_origin", &lep1_origin, &b_lep1_origin);
   fChain->SetBranchAddress("lep2_origin", &lep2_origin, &b_lep2_origin);
   fChain->SetBranchAddress("lep3_origin", &lep3_origin, &b_lep3_origin);
   fChain->SetBranchAddress("lep1_pdgorigin", &lep1_pdgorigin, &b_lep1_pdgorigin);
   fChain->SetBranchAddress("lep2_pdgorigin", &lep2_pdgorigin, &b_lep2_pdgorigin);
   fChain->SetBranchAddress("lep3_pdgorigin", &lep3_pdgorigin, &b_lep3_pdgorigin);
   fChain->SetBranchAddress("lep1_istight", &lep1_istight, &b_lep1_istight);
   fChain->SetBranchAddress("lep2_istight", &lep2_istight, &b_lep2_istight);
   fChain->SetBranchAddress("lep3_istight", &lep3_istight, &b_lep3_istight);
   fChain->SetBranchAddress("lep1_type", &lep1_type, &b_lep1_type);
   fChain->SetBranchAddress("lep2_type", &lep2_type, &b_lep2_type);
   fChain->SetBranchAddress("lep3_type", &lep3_type, &b_lep3_type);
   fChain->SetBranchAddress("lep1_d0sig", &lep1_d0sig, &b_lep1_d0sig);
   fChain->SetBranchAddress("lep2_d0sig", &lep2_d0sig, &b_lep2_d0sig);
   fChain->SetBranchAddress("lep3_d0sig", &lep3_d0sig, &b_lep3_d0sig);
   fChain->SetBranchAddress("lep1_z0sintheta", &lep1_z0sintheta, &b_lep1_z0sintheta);
   fChain->SetBranchAddress("lep2_z0sintheta", &lep2_z0sintheta, &b_lep2_z0sintheta);
   fChain->SetBranchAddress("lep3_z0sintheta", &lep3_z0sintheta, &b_lep3_z0sintheta);
   fChain->SetBranchAddress("lep1_topoetcone", &lep1_topoetcone, &b_lep1_topoetcone);
   fChain->SetBranchAddress("lep2_topoetcone", &lep2_topoetcone, &b_lep2_topoetcone);
   fChain->SetBranchAddress("lep3_topoetcone", &lep3_topoetcone, &b_lep3_topoetcone);
   fChain->SetBranchAddress("lep1_topoetcone40", &lep1_topoetcone40, &b_lep1_topoetcone40);
   fChain->SetBranchAddress("lep2_topoetcone40", &lep2_topoetcone40, &b_lep2_topoetcone40);
   fChain->SetBranchAddress("lep3_topoetcone40", &lep3_topoetcone40, &b_lep3_topoetcone40);
   fChain->SetBranchAddress("lep1_ptvarcone", &lep1_ptvarcone, &b_lep1_ptvarcone);
   fChain->SetBranchAddress("lep2_ptvarcone", &lep2_ptvarcone, &b_lep2_ptvarcone);
   fChain->SetBranchAddress("lep3_ptvarcone", &lep3_ptvarcone, &b_lep3_ptvarcone);
   fChain->SetBranchAddress("ttbardecay", &ttbardecay, &b_ttbardecay);
   fChain->SetBranchAddress("zdecay", &zdecay, &b_zdecay);
   fChain->SetBranchAddress("weight0tag", &weight0tag, &b_weight0tag);
   fChain->SetBranchAddress("weight1tag", &weight1tag, &b_weight1tag);
   fChain->SetBranchAddress("weight2tag", &weight2tag, &b_weight2tag);
   fChain->SetBranchAddress("lep1_Isol_LooseTrackOnly", &lep1_Isol_LooseTrackOnly, &b_lep1_Isol_LooseTrackOnly);
   fChain->SetBranchAddress("lep1_Isol_Loose", &lep1_Isol_Loose, &b_lep1_Isol_Loose);
   fChain->SetBranchAddress("lep1_Isol_Gradient", &lep1_Isol_Gradient, &b_lep1_Isol_Gradient);
   fChain->SetBranchAddress("lep1_Isol_GradientLoose", &lep1_Isol_GradientLoose, &b_lep1_Isol_GradientLoose);
   fChain->SetBranchAddress("lep1_Isol_FixedCutTightTrackOnly", &lep1_Isol_FixedCutTightTrackOnly, &b_lep1_Isol_FixedCutTightTrackOnly);
   fChain->SetBranchAddress("lep1_Isol_FixedCutLoose", &lep1_Isol_FixedCutLoose, &b_lep1_Isol_FixedCutLoose);
   fChain->SetBranchAddress("lep1_Isol_FixedCutTight", &lep1_Isol_FixedCutTight, &b_lep1_Isol_FixedCutTight);
   fChain->SetBranchAddress("lep2_Isol_LooseTrackOnly", &lep2_Isol_LooseTrackOnly, &b_lep2_Isol_LooseTrackOnly);
   fChain->SetBranchAddress("lep2_Isol_Loose", &lep2_Isol_Loose, &b_lep2_Isol_Loose);
   fChain->SetBranchAddress("lep2_Isol_Gradient", &lep2_Isol_Gradient, &b_lep2_Isol_Gradient);
   fChain->SetBranchAddress("lep2_Isol_GradientLoose", &lep2_Isol_GradientLoose, &b_lep2_Isol_GradientLoose);
   fChain->SetBranchAddress("lep2_Isol_FixedCutTightTrackOnly", &lep2_Isol_FixedCutTightTrackOnly, &b_lep2_Isol_FixedCutTightTrackOnly);
   fChain->SetBranchAddress("lep2_Isol_FixedCutLoose", &lep2_Isol_FixedCutLoose, &b_lep2_Isol_FixedCutLoose);
   fChain->SetBranchAddress("lep2_Isol_FixedCutTight", &lep2_Isol_FixedCutTight, &b_lep2_Isol_FixedCutTight);
   fChain->SetBranchAddress("lep3_Isol_LooseTrackOnly", &lep3_Isol_LooseTrackOnly, &b_lep3_Isol_LooseTrackOnly);
   fChain->SetBranchAddress("lep3_Isol_Loose", &lep3_Isol_Loose, &b_lep3_Isol_Loose);
   fChain->SetBranchAddress("lep3_Isol_Gradient", &lep3_Isol_Gradient, &b_lep3_Isol_Gradient);
   fChain->SetBranchAddress("lep3_Isol_GradientLoose", &lep3_Isol_GradientLoose, &b_lep3_Isol_GradientLoose);
   fChain->SetBranchAddress("lep3_Isol_FixedCutTightTrackOnly", &lep3_Isol_FixedCutTightTrackOnly, &b_lep3_Isol_FixedCutTightTrackOnly);
   fChain->SetBranchAddress("lep3_Isol_FixedCutLoose", &lep3_Isol_FixedCutLoose, &b_lep3_Isol_FixedCutLoose);
   fChain->SetBranchAddress("lep3_Isol_FixedCutTight", &lep3_Isol_FixedCutTight, &b_lep3_Isol_FixedCutTight);
   fChain->SetBranchAddress("hasTrigMatchedEl", &hasTrigMatchedEl, &b_hasTrigMatchedEl);
   fChain->SetBranchAddress("hasTrigMatchedMu", &hasTrigMatchedMu, &b_hasTrigMatchedMu);
   fChain->SetBranchAddress("TopHeavyFlavorFilterFlag", &TopHeavyFlavorFilterFlag, &b_TopHeavyFlavorFilterFlag);
   fChain->SetBranchAddress("MEgamma", &MEgamma, &b_MEgamma);
   fChain->SetBranchAddress("numberTruePhotons", &numberTruePhotons, &b_numberTruePhotons);
   fChain->SetBranchAddress("m_truePhoton1_pt", &m_truePhoton1_pt, &b_m_truePhoton1_pt);
   fChain->SetBranchAddress("m_truePhoton2_pt", &m_truePhoton2_pt, &b_m_truePhoton2_pt);
   fChain->SetBranchAddress("m_truePhoton3_pt", &m_truePhoton3_pt, &b_m_truePhoton3_pt);
   fChain->SetBranchAddress("OSSF_M", &OSSF_M, &b_OSSF_M);
   fChain->SetBranchAddress("nOSSF", &nOSSF, &b_nOSSF);
   fChain->SetBranchAddress("t1_pt", &t1_pt, &b_t1_pt);
   fChain->SetBranchAddress("t1_eta", &t1_eta, &b_t1_eta);
   fChain->SetBranchAddress("t1_phi ", &t1_phi , &b_t1_phi);
   fChain->SetBranchAddress("t1_m", &t1_m, &b_t1_m);
   fChain->SetBranchAddress("t1_truth ", &t1_truth , &b_t1_truth);
   fChain->SetBranchAddress("t1lj_pt", &t1lj_pt, &b_t1lj_pt);
   fChain->SetBranchAddress("t1lj_eta", &t1lj_eta, &b_t1lj_eta);
   fChain->SetBranchAddress("t1lj_phi ", &t1lj_phi , &b_t1lj_phi);
   fChain->SetBranchAddress("t1lj_e", &t1lj_e, &b_t1lj_e);
   fChain->SetBranchAddress("t1lj_btag ", &t1lj_btag , &b_t1lj_btag);
   fChain->SetBranchAddress("t1e_pt", &t1e_pt, &b_t1e_pt);
   fChain->SetBranchAddress("t1e_eta", &t1e_eta, &b_t1e_eta);
   fChain->SetBranchAddress("t1e_phi ", &t1e_phi , &b_t1e_phi);
   fChain->SetBranchAddress("t1e_e", &t1e_e, &b_t1e_e);
   fChain->SetBranchAddress("t1e_charge", &t1e_charge, &b_t1e_charge);
   fChain->SetBranchAddress("t1m_pt", &t1m_pt, &b_t1m_pt);
   fChain->SetBranchAddress("t1m_eta", &t1m_eta, &b_t1m_eta);
   fChain->SetBranchAddress("t1m_phi", &t1m_phi, &b_t1m_phi);
   fChain->SetBranchAddress("t1m_e", &t1m_e, &b_t1m_e);
   fChain->SetBranchAddress("t1m_charge", &t1m_charge, &b_t1m_charge);
   fChain->SetBranchAddress("t2_pt", &t2_pt, &b_t2_pt);
   fChain->SetBranchAddress("t2_eta", &t2_eta, &b_t2_eta);
   fChain->SetBranchAddress("t2_phi", &t2_phi, &b_t2_phi);
   fChain->SetBranchAddress("t2_m", &t2_m, &b_t2_m);
   fChain->SetBranchAddress("t2bj_pt", &t2bj_pt, &b_t2bj_pt);
   fChain->SetBranchAddress("t2bj_eta", &t2bj_eta, &b_t2bj_eta);
   fChain->SetBranchAddress("t2bj_phi", &t2bj_phi, &b_t2bj_phi);
   fChain->SetBranchAddress("t2bj_e", &t2bj_e, &b_t2bj_e);
   fChain->SetBranchAddress("t2bj_btag", &t2bj_btag, &b_t2bj_btag);
   fChain->SetBranchAddress("t2l_pt", &t2l_pt, &b_t2l_pt);
   fChain->SetBranchAddress("t2l_eta", &t2l_eta, &b_t2l_eta);
   fChain->SetBranchAddress("t2l_phi ", &t2l_phi , &b_t2l_phi);
   fChain->SetBranchAddress("t2l_e", &t2l_e, &b_t2l_e);
   fChain->SetBranchAddress("t2l_charge", &t2l_charge, &b_t2l_charge);
   fChain->SetBranchAddress("t2l_flav", &t2l_flav, &b_t2l_flav);
   fChain->SetBranchAddress("totWF", &totWF, &b_totWF);
   fChain->SetBranchAddress("BDT", &BDT, &b_BDT);
   fChain->SetBranchAddress("totW", &totW, &b_totW);
  fChain->SetBranchAddress("fake_code", &code, &b_code);
   fChain->SetBranchAddress("prompt", &prompt, &b_prompt);
   fChain->SetBranchAddress("xs_weight", &xs_weight, &b_xs_weight);
   fChain->SetBranchAddress("weight_mc", &weight_mc, &b_weight_mc);
   fChain->SetBranchAddress("weight_jvt", &weight_jvt, &b_weight_jvt);
   fChain->SetBranchAddress("weight_pileup", &weight_pileup, &b_weight_pileup);
   fChain->SetBranchAddress("weight_leptonSF", &weight_leptonSF, &b_weight_leptonSF);
   fChain->SetBranchAddress("weight_bTagSF_77", &weight_bTagSF_77, &b_weight_bTagSF_77);
   Notify();
}

Bool_t nominal::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make.txt changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void nominal::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t nominal::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
