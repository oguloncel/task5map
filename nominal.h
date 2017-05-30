//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Aug 23 16:24:06 2016 by ROOT version 6.05/02
// from TTree nominal/tree
// found on file: Signal_step2.root
//////////////////////////////////////////////////////////

#ifndef nominal_h
#define nominal_h

#include "TROOT.h"
#include "TFile.h"
#include "TTree.h"
#include <vector>
#include <TChain.h>


class nominal {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   ULong64_t       eventNumber;
   UInt_t          runNumber;
   UInt_t          mcChannelNumber;
   Float_t         mu;
   UInt_t          backgroundFlags;
   std::vector<float>   *el_pt;
   std::vector<float>   *el_eta;
   std::vector<float>   *el_cl_eta;
   std::vector<float>   *el_phi;
   std::vector<float>   *el_e;
   std::vector<float>   *el_charge;
   std::vector<float>   *el_topoetcone20;
   std::vector<float>   *el_ptvarcone20;
   std::vector<float>   *el_d0sig;
   std::vector<float>   *el_delta_z0_sintheta;
   std::vector<float>   *mu_pt;
   std::vector<float>   *mu_eta;
   std::vector<float>   *mu_phi;
   std::vector<float>   *mu_e;
   std::vector<float>   *mu_charge;
   std::vector<float>   *mu_topoetcone20;
   std::vector<float>   *mu_ptvarcone30;
   std::vector<float>   *mu_d0sig;
   std::vector<float>   *mu_delta_z0_sintheta;
   std::vector<float>   *jet_pt;
   std::vector<float>   *jet_eta;
   std::vector<float>   *jet_phi;
   std::vector<float>   *jet_e;
   std::vector<float>   *jet_mv2c00;
   std::vector<float>   *jet_mv2c10;
   std::vector<float>   *jet_mv2c20;
   std::vector<float>   *jet_ip3dsv1;
   std::vector<float>   *jet_jvt;

   Float_t         met_met;
   Float_t         met_phi;
   Float_t         randomNumber;
   Float_t         nEl;
   Float_t         nMu;
   Float_t         nJets;
   Float_t         nBJets70;
   Float_t         nBJets77;
   Float_t         nBJets85;
   Float_t         pT_1lep;
   Float_t         pT_2lep;
   Float_t         pT_3lep;
   Float_t         eta_1lep;
   Float_t         eta_2lep;
   Float_t         eta_3lep;
   Float_t         phi_1lep;
   Float_t         phi_2lep;
   Float_t         phi_3lep;
   Float_t         pdgid_1lep;
   Float_t         pdgid_2lep;
   Float_t         pdgid_3lep;
   Float_t         charge_1lep;
   Float_t         charge_2lep;
   Float_t         charge_3lep;
   Float_t         pT_1jet;
   Float_t         pT_2jet;
   Float_t         pT_3jet;
   Float_t         ht;
   Float_t         mll;
   Int_t           RunNumber;
   Int_t           EventNumber;
   Int_t           lep1_origin;
   Int_t           lep2_origin;
   Int_t           lep3_origin;
   Int_t           lep1_pdgorigin;
   Int_t           lep2_pdgorigin;
   Int_t           lep3_pdgorigin;
   Int_t           lep1_istight;
   Int_t           lep2_istight;
   Int_t           lep3_istight;
   Int_t           lep1_type;
   Int_t           lep2_type;
   Int_t           lep3_type;
   Float_t         lep1_d0sig;
   Float_t         lep2_d0sig;
   Float_t         lep3_d0sig;
   Float_t         lep1_z0sintheta;
   Float_t         lep2_z0sintheta;
   Float_t         lep3_z0sintheta;
   Float_t         lep1_topoetcone;
   Float_t         lep2_topoetcone;
   Float_t         lep3_topoetcone;
   Float_t         lep1_topoetcone40;
   Float_t         lep2_topoetcone40;
   Float_t         lep3_topoetcone40;
   Float_t         lep1_ptvarcone;
   Float_t         lep2_ptvarcone;
   Float_t         lep3_ptvarcone;
   Int_t           ttbardecay;
   Int_t           zdecay;
   Float_t         weight0tag;
   Float_t         weight1tag;
   Float_t         weight2tag;
   Bool_t          lep1_Isol_LooseTrackOnly;
   Bool_t          lep1_Isol_Loose;
   Bool_t          lep1_Isol_Gradient;
   Bool_t          lep1_Isol_GradientLoose;
   Bool_t          lep1_Isol_FixedCutTightTrackOnly;
   Bool_t          lep1_Isol_FixedCutLoose;
   Bool_t          lep1_Isol_FixedCutTight;
   Bool_t          lep2_Isol_LooseTrackOnly;
   Bool_t          lep2_Isol_Loose;
   Bool_t          lep2_Isol_Gradient;
   Bool_t          lep2_Isol_GradientLoose;
   Bool_t          lep2_Isol_FixedCutTightTrackOnly;
   Bool_t          lep2_Isol_FixedCutLoose;
   Bool_t          lep2_Isol_FixedCutTight;
   Bool_t          lep3_Isol_LooseTrackOnly;
   Bool_t          lep3_Isol_Loose;
   Bool_t          lep3_Isol_Gradient;
   Bool_t          lep3_Isol_GradientLoose;
   Bool_t          lep3_Isol_FixedCutTightTrackOnly;
   Bool_t          lep3_Isol_FixedCutLoose;
   Bool_t          lep3_Isol_FixedCutTight;
   Bool_t          hasTrigMatchedEl;
   Bool_t          hasTrigMatchedMu;
   Int_t           TopHeavyFlavorFilterFlag;
   Bool_t          MEgamma;
   Int_t           numberTruePhotons;
   Float_t         m_truePhoton1_pt;
   Float_t         m_truePhoton2_pt;
   Float_t         m_truePhoton3_pt;
   std::vector<float>   *OSSF_M;
   Int_t           nOSSF;
   Float_t         t1_pt;
   Float_t         t1_eta;
   Float_t         t1_phi ;
   Float_t         t1_m;
   Int_t           t1_truth ;
   Float_t         t1lj_pt;
   Float_t         t1lj_eta;
   Float_t         t1lj_phi ;
   Float_t         t1lj_e;
   Float_t         t1lj_btag ;
   Float_t         t1e_pt;
   Float_t         t1e_eta;
   Float_t         t1e_phi ;
   Float_t         t1e_e;
   Float_t         t1e_charge;
   Float_t         t1m_pt;
   Float_t         t1m_eta;
   Float_t         t1m_phi;
   Float_t         t1m_e;
   Float_t         t1m_charge;
   Float_t         t2_pt;
   Float_t         t2_eta;
   Float_t         t2_phi;
   Float_t         t2_m;
   Float_t         t2bj_pt;
   Float_t         t2bj_eta;
   Float_t         t2bj_phi;
   Float_t         t2bj_e;
   Float_t         t2bj_btag;
   Float_t         t2l_pt;
   Float_t         t2l_eta;
   Float_t         t2l_phi ;
   Float_t         t2l_e;
   Float_t         t2l_charge;
   Float_t         t2l_flav;
   Float_t         xs_weight;
   Float_t         weight_mc;
   Float_t         weight_jvt;
   Float_t         weight_pileup;
   Float_t         weight_leptonSF;
   Float_t         weight_bTagSF_77;
   Float_t         totW;
   Float_t         totWF;
   Float_t          BDT;
   Bool_t          prompt;
   Int_t           code;

   // List of branches
   TBranch        *b_eventNumber;   //!
   TBranch        *b_runNumber;   //!
   TBranch        *b_mcChannelNumber;   //!
   TBranch        *b_mu;   //!
   TBranch        *b_backgroundFlags;   //!
   TBranch        *b_el_pt;   //!
   TBranch        *b_el_eta;   //!
   TBranch        *b_el_cl_eta;   //!
   TBranch        *b_el_phi;   //!
   TBranch        *b_el_e;   //!
   TBranch        *b_el_charge;   //!
   TBranch        *b_el_topoetcone20;   //!
   TBranch        *b_el_ptvarcone20;   //!
   TBranch        *b_el_d0sig;   //!
   TBranch        *b_el_delta_z0_sintheta;   //!
   TBranch        *b_mu_pt;   //!
   TBranch        *b_mu_eta;   //!
   TBranch        *b_mu_phi;   //!
   TBranch        *b_mu_e;   //!
   TBranch        *b_mu_charge;   //!
   TBranch        *b_mu_topoetcone20;   //!
   TBranch        *b_mu_ptvarcone30;   //!
   TBranch        *b_mu_d0sig;   //!
   TBranch        *b_mu_delta_z0_sintheta;   //!
   TBranch        *b_mu_true_type;   //!
   TBranch        *b_mu_true_origin;   //!
   TBranch        *b_jet_pt;   //!
   TBranch        *b_jet_eta;   //!
   TBranch        *b_jet_phi;   //!
   TBranch        *b_jet_e;   //!
   TBranch        *b_jet_mv2c00;   //!
   TBranch        *b_jet_mv2c10;   //!
   TBranch        *b_jet_mv2c20;   //!
   TBranch        *b_jet_ip3dsv1;   //!
   TBranch        *b_jet_jvt;   //!
   TBranch        *b_jet_truthflav;   //!
   TBranch        *b_met_met;   //!
   TBranch        *b_met_phi;   //!
   TBranch        *b_randomNumber;   //!
   TBranch        *b_nEl;   //!
   TBranch        *b_nMu;   //!
   TBranch        *b_nJets;   //!
   TBranch        *b_nBJets70;   //!
   TBranch        *b_nBJets77;   //!
   TBranch        *b_nBJets85;   //!
   TBranch        *b_pT_1lep;   //!
   TBranch        *b_pT_2lep;   //!
   TBranch        *b_pT_3lep;   //!
   TBranch        *b_eta_1lep;   //!
   TBranch        *b_eta_2lep;   //!
   TBranch        *b_eta_3lep;   //!
   TBranch        *b_phi_1lep;   //!
   TBranch        *b_phi_2lep;   //!
   TBranch        *b_phi_3lep;   //!
   TBranch        *b_pdgid_1lep;   //!
   TBranch        *b_pdgid_2lep;   //!
   TBranch        *b_pdgid_3lep;   //!
   TBranch        *b_charge_1lep;   //!
   TBranch        *b_charge_2lep;   //!
   TBranch        *b_charge_3lep;   //!
   TBranch        *b_pT_1jet;   //!
   TBranch        *b_pT_2jet;   //!
   TBranch        *b_pT_3jet;   //!
   TBranch        *b_ht;   //!
   TBranch        *b_mll;   //!
   TBranch        *b_RunNumber;   //!
   TBranch        *b_EventNumber;   //!
   TBranch        *b_lep1_origin;   //!
   TBranch        *b_lep2_origin;   //!
   TBranch        *b_lep3_origin;   //!
   TBranch        *b_lep1_pdgorigin;   //!
   TBranch        *b_lep2_pdgorigin;   //!
   TBranch        *b_lep3_pdgorigin;   //!
   TBranch        *b_lep1_istight;   //!
   TBranch        *b_lep2_istight;   //!
   TBranch        *b_lep3_istight;   //!
   TBranch        *b_lep1_type;   //!
   TBranch        *b_lep2_type;   //!
   TBranch        *b_lep3_type;   //!
   TBranch        *b_lep1_d0sig;   //!
   TBranch        *b_lep2_d0sig;   //!
   TBranch        *b_lep3_d0sig;   //!
   TBranch        *b_lep1_z0sintheta;   //!
   TBranch        *b_lep2_z0sintheta;   //!
   TBranch        *b_lep3_z0sintheta;   //!
   TBranch        *b_lep1_topoetcone;   //!
   TBranch        *b_lep2_topoetcone;   //!
   TBranch        *b_lep3_topoetcone;   //!
	 TBranch        *b_lep1_topoetcone40;
	 TBranch        *b_lep2_topoetcone40;
	 TBranch        *b_lep3_topoetcone40;
   TBranch        *b_lep1_ptvarcone;   //!
   TBranch        *b_lep2_ptvarcone;   //!
   TBranch        *b_lep3_ptvarcone;   //!
   TBranch        *b_ttbardecay;   //!
   TBranch        *b_zdecay;   //!
   TBranch        *b_weight0tag;   //!
   TBranch        *b_weight1tag;   //!
   TBranch        *b_weight2tag;   //!
   TBranch        *b_lep1_Isol_LooseTrackOnly;   //!
   TBranch        *b_lep1_Isol_Loose;   //!
   TBranch        *b_lep1_Isol_Gradient;   //!
   TBranch        *b_lep1_Isol_GradientLoose;   //!
   TBranch        *b_lep1_Isol_FixedCutTightTrackOnly;   //!
   TBranch        *b_lep1_Isol_FixedCutLoose;   //!
   TBranch        *b_lep1_Isol_FixedCutTight;   //!
   TBranch        *b_lep2_Isol_LooseTrackOnly;   //!
   TBranch        *b_lep2_Isol_Loose;   //!
   TBranch        *b_lep2_Isol_Gradient;   //!
   TBranch        *b_lep2_Isol_GradientLoose;   //!
   TBranch        *b_lep2_Isol_FixedCutTightTrackOnly;   //!
   TBranch        *b_lep2_Isol_FixedCutLoose;   //!
   TBranch        *b_lep2_Isol_FixedCutTight;   //!
   TBranch        *b_lep3_Isol_LooseTrackOnly;   //!
   TBranch        *b_lep3_Isol_Loose;   //!
   TBranch        *b_lep3_Isol_Gradient;   //!
   TBranch        *b_lep3_Isol_GradientLoose;   //!
   TBranch        *b_lep3_Isol_FixedCutTightTrackOnly;   //!
   TBranch        *b_lep3_Isol_FixedCutLoose;   //!
   TBranch        *b_lep3_Isol_FixedCutTight;   //!
   TBranch        *b_hasTrigMatchedEl;   //!
   TBranch        *b_hasTrigMatchedMu;   //!
   TBranch        *b_TopHeavyFlavorFilterFlag;   //!
   TBranch        *b_MEgamma;   //!
   TBranch        *b_numberTruePhotons;   //!
   TBranch        *b_m_truePhoton1_pt;   //!
   TBranch        *b_m_truePhoton2_pt;   //!
   TBranch        *b_m_truePhoton3_pt;   //!
   TBranch        *b_OSSF_M;   //!
   TBranch        *b_nOSSF;
   TBranch        *b_t1_pt;   //!
   TBranch        *b_t1_eta;   //!
   TBranch        *b_t1_phi;   //!
   TBranch        *b_t1_m;   //!
   TBranch        *b_t1_truth;   //!
   TBranch        *b_t1lj_pt;   //!
   TBranch        *b_t1lj_eta;   //!
   TBranch        *b_t1lj_phi;   //!
   TBranch        *b_t1lj_e;   //!
   TBranch        *b_t1lj_btag;   //!
   TBranch        *b_t1e_pt;   //!
   TBranch        *b_t1e_eta;   //!
   TBranch        *b_t1e_phi;   //!
   TBranch        *b_t1e_e;   //!
   TBranch        *b_t1e_charge;   //!
   TBranch        *b_t1m_pt;   //!
   TBranch        *b_t1m_eta;   //!
   TBranch        *b_t1m_phi;   //!
   TBranch        *b_t1m_e;   //!
   TBranch        *b_t1m_charge;   //!
   TBranch        *b_t2_pt;   //!
   TBranch        *b_t2_eta;   //!
   TBranch        *b_t2_phi;   //!
   TBranch        *b_t2_m;   //!
   TBranch        *b_t2bj_pt;   //!
   TBranch        *b_t2bj_eta;   //!
   TBranch        *b_t2bj_phi;   //!
   TBranch        *b_t2bj_e;   //!
   TBranch        *b_t2bj_btag;   //!
   TBranch        *b_t2l_pt;   //!
   TBranch        *b_t2l_eta;   //!
   TBranch        *b_t2l_phi;   //!
   TBranch        *b_t2l_e;   //!
   TBranch        *b_t2l_charge;   //!
   TBranch        *b_t2l_flav;   //!
   TBranch        *b_totW;   //!
   TBranch        *b_xs_weight;
   TBranch        *b_weight_mc;
   TBranch        *b_weight_jvt;
   TBranch        *b_weight_pileup;
   TBranch        *b_weight_leptonSF;
   TBranch        *b_weight_bTagSF_77;
   TBranch        *b_prompt;
   TBranch        *b_totWF;   //!
   TBranch        *b_BDT;   //!
  TBranch        *b_code;   //!
//! \param tree

   nominal(TTree *tree=0);
   virtual ~nominal();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif



