//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon May  6 18:42:31 2019 by ROOT version 6.12/06
// from TTree Data/Tree with custom variables
// found on file: /storage/DATA-02/juno/Users/sgiulio/Atmo/analysis/unfolding/treemaker_mu/trees/MC_mu_lowE.root
//////////////////////////////////////////////////////////

#ifndef Data_h
#define Data_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "vector"
#include "vector"

class Data {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Int_t           evtID;
   Int_t           init_lepID;
   Float_t         lepEnergy;
   Double_t        zenith_vert;
   Double_t        dist_0;
   Int_t           trueNPE;
   Int_t           trueNPE_LPMT_CD;
   Int_t           trueNPE_LPMT_WP;
   Int_t           trueNPE_SPMT;
   Float_t         trueVX;
   Float_t         trueVY;
   Float_t         trueVZ;
   Float_t         newVX;
   Float_t         newVY;
   Float_t         newVZ;
   Float_t         trueVradius;
   Float_t         newVradius;
   Float_t         vertex_shift;
   Float_t         Tres_Mean;
   Float_t         Tres_RMS;
   Float_t         Tres_Mean_trueV;
   Float_t         Tres_RMS_trueV;
   Double_t        PosX;
   Double_t        PosY;
   Double_t        PosZ;
   Double_t        PX;
   Double_t        PY;
   Double_t        PZ;
   Double_t        L_Rock;
   Double_t        L_VetoWater;
   Double_t        L_CDWater;
   Double_t        L_Acrylic;
   Double_t        L_Steel;
   Double_t        L_Scint;
   Double_t        E_Rock;
   Double_t        E_VetoWater;
   Double_t        E_CDWater;
   Double_t        E_Acrylic;
   Double_t        E_Steel;
   Double_t        E_Scint;
   std::vector<int>     *LPMT_CD_PMTID;
   std::vector<int>     *LPMT_WP_PMTID;
   std::vector<int>     *SPMT_PMTID;
   std::vector<float>   *LPMT_CD_Charge;
   std::vector<float>   *LPMT_WP_Charge;
   std::vector<float>   *theta_hitLPMT_CD;
   std::vector<float>   *phi_hitLPMT_CD;
   std::vector<float>   *theta_hitSPMT;
   std::vector<float>   *phi_hitSPMT;
   std::vector<float>   *theta_hitLPMT_WP;
   std::vector<float>   *phi_hitLPMT_WP;
   std::vector<float>   *hit_time_LPMT_CD;
   std::vector<float>   *hit_time_LPMT_WP;
   std::vector<float>   *hit_time_SPMT;

   // List of branches
   TBranch        *b_evtID;   //!
   TBranch        *b_init_lepID;   //!
   TBranch        *b_lepEnergy;   //!
   TBranch        *b_zenith_vert;   //!
   TBranch        *b_dist_0;   //!
   TBranch        *b_trueNPE;   //!
   TBranch        *b_trueNPE_LPMT_CD;   //!
   TBranch        *b_trueNPE_LPMT_WP;   //!
   TBranch        *b_trueNPE_SPMT;   //!
   TBranch        *b_trueVX;   //!
   TBranch        *b_trueVY;   //!
   TBranch        *b_trueVZ;   //!
   TBranch        *b_newVX;   //!
   TBranch        *b_newVY;   //!
   TBranch        *b_newVZ;   //!
   TBranch        *b_trueVradius;   //!
   TBranch        *b_newVradius;   //!
   TBranch        *b_vertex_shift;   //!
   TBranch        *b_Tres_Mean;   //!
   TBranch        *b_Tres_RMS;   //!
   TBranch        *b_Tres_Mean_trueV;   //!
   TBranch        *b_Tres_RMS_trueV;   //!
   TBranch        *b_PosX;   //!
   TBranch        *b_PosY;   //!
   TBranch        *b_PosZ;   //!
   TBranch        *b_PX;   //!
   TBranch        *b_PY;   //!
   TBranch        *b_PZ;   //!
   TBranch        *b_L_Rock;   //!
   TBranch        *b_L_VetoWater;   //!
   TBranch        *b_L_CDWater;   //!
   TBranch        *b_L_Acrylic;   //!
   TBranch        *b_L_Steel;   //!
   TBranch        *b_L_Scint;   //!
   TBranch        *b_E_Rock;   //!
   TBranch        *b_E_VetoWater;   //!
   TBranch        *b_E_CDWater;   //!
   TBranch        *b_E_Acrylic;   //!
   TBranch        *b_E_Steel;   //!
   TBranch        *b_E_Scint;   //!
   TBranch        *b_LPMT_CD_PMTID;   //!
   TBranch        *b_LPMT_WP_PMTID;   //!
   TBranch        *b_SPMT_PMTID;   //!
   TBranch        *b_LPMT_CD_Charge;   //!
   TBranch        *b_LPMT_WP_Charge;   //!
   TBranch        *b_theta_hitLPMT_CD;   //!
   TBranch        *b_phi_hitLPMT_CD;   //!
   TBranch        *b_theta_hitSPMT;   //!
   TBranch        *b_phi_hitSPMT;   //!
   TBranch        *b_theta_hitLPMT_WP;   //!
   TBranch        *b_phi_hitLPMT_WP;   //!
   TBranch        *b_hit_time_LPMT_CD;   //!
   TBranch        *b_hit_time_LPMT_WP;   //!
   TBranch        *b_hit_time_SPMT;   //!

   Data(TTree *tree=0);
   virtual ~Data();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
   virtual Float_t great_circle_distance(Float_t t1, Float_t p1, Float_t t2, Float_t p2);
};

#endif

#ifdef Data_cxx
Data::Data(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/storage/DATA-02/juno/Users/sgiulio/Atmo/analysis/unfolding/treemaker_mu/trees/MC_mu_low_medE.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("/storage/DATA-02/juno/Users/sgiulio/Atmo/analysis/unfolding/treemaker_mu/trees/MC_mu_low_medE.root");
      }
      f->GetObject("Data",tree);

   }
   Init(tree);
}

Data::~Data()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t Data::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t Data::LoadTree(Long64_t entry)
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

void Data::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   LPMT_CD_PMTID = 0;
   LPMT_WP_PMTID = 0;
   SPMT_PMTID = 0;
   LPMT_CD_Charge = 0;
   LPMT_WP_Charge = 0;
   theta_hitLPMT_CD = 0;
   phi_hitLPMT_CD = 0;
   theta_hitSPMT = 0;
   phi_hitSPMT = 0;
   theta_hitLPMT_WP = 0;
   phi_hitLPMT_WP = 0;
   hit_time_LPMT_CD = 0;
   hit_time_LPMT_WP = 0;
   hit_time_SPMT = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("evtID", &evtID, &b_evtID);
   fChain->SetBranchAddress("init_lepID", &init_lepID, &b_init_lepID);
   fChain->SetBranchAddress("lepEnergy", &lepEnergy, &b_lepEnergy);
   fChain->SetBranchAddress("zenith_vert", &zenith_vert, &b_zenith_vert);
   fChain->SetBranchAddress("dist_0", &dist_0, &b_dist_0);
   fChain->SetBranchAddress("trueNPE", &trueNPE, &b_trueNPE);
   fChain->SetBranchAddress("trueNPE_LPMT_CD", &trueNPE_LPMT_CD, &b_trueNPE_LPMT_CD);
   fChain->SetBranchAddress("trueNPE_LPMT_WP", &trueNPE_LPMT_WP, &b_trueNPE_LPMT_WP);
   fChain->SetBranchAddress("trueNPE_SPMT", &trueNPE_SPMT, &b_trueNPE_SPMT);
   fChain->SetBranchAddress("trueVX", &trueVX, &b_trueVX);
   fChain->SetBranchAddress("trueVY", &trueVY, &b_trueVY);
   fChain->SetBranchAddress("trueVZ", &trueVZ, &b_trueVZ);
   fChain->SetBranchAddress("newVX", &newVX, &b_newVX);
   fChain->SetBranchAddress("newVY", &newVY, &b_newVY);
   fChain->SetBranchAddress("newVZ", &newVZ, &b_newVZ);
   fChain->SetBranchAddress("trueVradius", &trueVradius, &b_trueVradius);
   fChain->SetBranchAddress("newVradius", &newVradius, &b_newVradius);
   fChain->SetBranchAddress("vertex_shift", &vertex_shift, &b_vertex_shift);
   fChain->SetBranchAddress("Tres_Mean", &Tres_Mean, &b_Tres_Mean);
   fChain->SetBranchAddress("Tres_RMS", &Tres_RMS, &b_Tres_RMS);
   fChain->SetBranchAddress("Tres_Mean_trueV", &Tres_Mean_trueV, &b_Tres_Mean_trueV);
   fChain->SetBranchAddress("Tres_RMS_trueV", &Tres_RMS_trueV, &b_Tres_RMS_trueV);
   fChain->SetBranchAddress("PosX", &PosX, &b_PosX);
   fChain->SetBranchAddress("PosY", &PosY, &b_PosY);
   fChain->SetBranchAddress("PosZ", &PosZ, &b_PosZ);
   fChain->SetBranchAddress("PX", &PX, &b_PX);
   fChain->SetBranchAddress("PY", &PY, &b_PY);
   fChain->SetBranchAddress("PZ", &PZ, &b_PZ);
   fChain->SetBranchAddress("L_Rock", &L_Rock, &b_L_Rock);
   fChain->SetBranchAddress("L_VetoWater", &L_VetoWater, &b_L_VetoWater);
   fChain->SetBranchAddress("L_CDWater", &L_CDWater, &b_L_CDWater);
   fChain->SetBranchAddress("L_Acrylic", &L_Acrylic, &b_L_Acrylic);
   fChain->SetBranchAddress("L_Steel", &L_Steel, &b_L_Steel);
   fChain->SetBranchAddress("L_Scint", &L_Scint, &b_L_Scint);
   fChain->SetBranchAddress("E_Rock", &E_Rock, &b_E_Rock);
   fChain->SetBranchAddress("E_VetoWater", &E_VetoWater, &b_E_VetoWater);
   fChain->SetBranchAddress("E_CDWater", &E_CDWater, &b_E_CDWater);
   fChain->SetBranchAddress("E_Acrylic", &E_Acrylic, &b_E_Acrylic);
   fChain->SetBranchAddress("E_Steel", &E_Steel, &b_E_Steel);
   fChain->SetBranchAddress("E_Scint", &E_Scint, &b_E_Scint);
   fChain->SetBranchAddress("LPMT_CD_PMTID", &LPMT_CD_PMTID, &b_LPMT_CD_PMTID);
   fChain->SetBranchAddress("LPMT_WP_PMTID", &LPMT_WP_PMTID, &b_LPMT_WP_PMTID);
   fChain->SetBranchAddress("SPMT_PMTID", &SPMT_PMTID, &b_SPMT_PMTID);
   fChain->SetBranchAddress("LPMT_CD_Charge", &LPMT_CD_Charge, &b_LPMT_CD_Charge);
   fChain->SetBranchAddress("LPMT_WP_Charge", &LPMT_WP_Charge, &b_LPMT_WP_Charge);
   fChain->SetBranchAddress("theta_hitLPMT_CD", &theta_hitLPMT_CD, &b_theta_hitLPMT_CD);
   fChain->SetBranchAddress("phi_hitLPMT_CD", &phi_hitLPMT_CD, &b_phi_hitLPMT_CD);
   fChain->SetBranchAddress("theta_hitSPMT", &theta_hitSPMT, &b_theta_hitSPMT);
   fChain->SetBranchAddress("phi_hitSPMT", &phi_hitSPMT, &b_phi_hitSPMT);
   fChain->SetBranchAddress("theta_hitLPMT_WP", &theta_hitLPMT_WP, &b_theta_hitLPMT_WP);
   fChain->SetBranchAddress("phi_hitLPMT_WP", &phi_hitLPMT_WP, &b_phi_hitLPMT_WP);
   fChain->SetBranchAddress("hit_time_LPMT_CD", &hit_time_LPMT_CD, &b_hit_time_LPMT_CD);
   fChain->SetBranchAddress("hit_time_LPMT_WP", &hit_time_LPMT_WP, &b_hit_time_LPMT_WP);
   fChain->SetBranchAddress("hit_time_SPMT", &hit_time_SPMT, &b_hit_time_SPMT);
   Notify();
}

Bool_t Data::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void Data::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t Data::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef Data_cxx
