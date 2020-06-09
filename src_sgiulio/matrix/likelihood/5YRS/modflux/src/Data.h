//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri Nov  2 15:37:59 2018 by ROOT version 5.34/36
// from TTree Data/Tree with custom variables
// found on file: /storage/DATA-02/juno/Users/sgiulio/Atmo/analysis/unfolding/matrix/treemaker/trees/MC_1m.root
//////////////////////////////////////////////////////////

#ifndef Data_h
#define Data_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <string>
#include "TVectorD.h"
#include "TMatrixD.h"
#include <TRandom3.h>

// Header file for the classes stored in the TTree if any.
//#include "/storage/local/exp_soft/juno/GENIE/GENIE-2_12_10/lamp/GENIESupport/root/cint/cint/lib/prec_stl/vector"
//#include "/storage/local/exp_soft/juno/GENIE/GENIE-2_12_10/lamp/GENIESupport/root/cint/cint/lib/prec_stl/vector"

// Fixed size dimensions of array or collections stored in the TTree if any.

class Data {

 protected:

  std::string _likfile;            // Likelihood matrix
  std::string _all_matrix;         // Sgn+Bkg matrix
  std::string _sgn_matrix;         // Signal matrix
  std::string _bkg_matrix;         // Background matrix
  std::string _E_bins;             // Energy bins
  std::string _E_all_file;
  std::string _E_sgn_file;
  std::string _E_fidcut_file;
  std::string _E_allcuts_file;
  std::string _E_sgn_allcuts_file;
  std::string _E_all_fromdata;
  std::string _E_sgn_fromdata;
  std::string _E_fidcuts_fromdata;
  std::string _E_allcuts_fromdata;
  std::string _E_sgn_allcuts_fromdata;
  std::string _NPE_all_file;           // NPE values
  std::string _NPE_sgn_file;
  std::string _NPE_fidcuts_file;
  std::string _NPE_allcuts_file;       // NPE values for selected events
  std::string _NPE_sgn_allcuts_file;   // NPE values for selected signal events
  std::string _NPE_bins;               // NPE bins
  std::string _sourceflux;             // predicted neutrino flux from tables
  std::string family;                  // e/mu
  std::string osc_flag;
  std::string cut_tres_str;
  std:: string alpha_str;
  std:: string gamma_str;
  int id_family;
  float osc_weight;
  float cut_tres;
  float alphamod;
  float gammamod;
  TVectorD binlowedge;
  TVectorD bincenter;
  TVectorD binwidth;
  TVectorD Hwidth;
  /*
  ///////////////OSCILLATIONS/////////////
  double delta2m12 = 7.5E-5;
  double delta2m31 = 2.32E-3; // [eV^2]
  double delta2m32 = 2.32E-3; // [eV^2]
  double sin2theta12 = 0.31;
  double cos2theta12 = 1.0 - 0.31;
  double theta12 = asin(sqrt(sin2theta12));
  double sin2theta13 = 0.024; // NO
  double cos2theta13 = 1.0-0.024; // NO
  double theta13 = asin(sqrt(sin2theta13));
  double sin2theta23 = 0.5; //NO
  double cos2theta23 = 0.5; //NO
  double theta23 = asin(sqrt(sin2theta23));
  double deltaCP = 0.0;
  double alpha = (delta2m12/delta2m31);
  double fermi_const = 1.167E-5; // [GeV^-2]
  double N_e = 2.5; // electron density
  double V_fact, A_fact, Delta, C_fact; // V effective potential in matter
  double matt_delta2m31_Nu; // effective mass splitting in matter for neutrinos
  double matt_delta2m31_Nubar; // effective mass splitting in matter for antineutrinos
  double matt_2sin2theta13_Nu; // effective mixing angle in matter for neutrinos
  double matt_2sin2theta13_Nubar; // effective mixing angle in matter for antineutrinos
  double matt_theta13_Nu;
  double matt_theta13_Nubar;
  double phase1_Nu, phase2_Nu, phase3_Nu; //oscillation phases for neutrinos
  double phase1_Nubar, phase2_Nubar, phase3_Nubar; //oscillation phases for antineutrinos
  double P_s_NuMu1, P_s_NuMu2, P_s_NuMu3, P_s_NuMu; // survival probability NuMu
  double P_s_NuMubar1, P_s_NuMubar2, P_s_NuMubar3, P_s_NuMubar; // survival probability NuMubar
  double P_s_NuE, P_s_NuEbar; // survival probability for NuE
  double P_NuEtoNuMu1, P_NuEtoNuMu2, P_NuEtoNuMu3, P_NuEtoNuMu, P_NuEbartoNuMubar1, P_NuEbartoNuMubar2, P_NuEbartoNuMubar3, P_NuEbartoNuMubar; // NuE to NuMu transition probability
  ////////////////////////////////////////////
  */

public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Int_t           evtID;
   Int_t           init_nuID;
   Int_t           init_lepID;
   Float_t         nuEnergy;
   Bool_t          CCint;
   Bool_t          NCint;
   Bool_t          FC;
   Bool_t          PC;
   Float_t         lepEnergy;
   Float_t         L_osc_baseline;
   Float_t         P_surv;
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
   //Float_t         trueVradius;
   Float_t         newVradius;
   Float_t         vertex_shift_TS;
   Float_t         trueZENITH;
   Float_t         trueAZIMUTH;
   Float_t         Tres_Mean;
   Float_t         Tres_RMS;
   //Float_t         Tres_Mean_trueV;
   //Float_t         Tres_RMS_trueV;
   //std::vector<int>     *SPMT_PMTID;
   std::vector<float>   *theta_hitSPMT;
   std::vector<float>   *phi_hitSPMT;
   //std::vector<float>   *SPMT_Charge;
   std::vector<float>   *SPMT_Time;
   std::vector<float>   *SPMT_Tres;
   //std::vector<float>   *SPMT_Tres_trueV;

   // List of branches
   TBranch        *b_evtID;   //!
   TBranch        *b_init_nuID;   //!
   TBranch        *b_init_lepID;   //!
   TBranch        *b_nuEnergy;   //!
   TBranch        *b_CCint;   //!
   TBranch        *b_NCint;   //!
   TBranch        *b_FC;   //!
   TBranch        *b_PC;   //!
   TBranch        *b_lepEnergy;   //!
   TBranch        *b_L_osc_baseline;   //!
   TBranch        *b_P_surv;   //!
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
   //TBranch        *b_trueVradius;   //!
   TBranch        *b_newVradius;   //!
   TBranch        *b_vertex_shift_TS;   //!
   TBranch        *b_trueZENITH;   //!
   TBranch        *b_trueAZIMUTH;   //!
   TBranch        *b_Tres_Mean;   //!
   TBranch        *b_Tres_RMS;   //!
   //TBranch        *b_Tres_Mean_trueV;   //!
   //TBranch        *b_Tres_RMS_trueV;   //!
   //TBranch        *b_SPMT_PMTID;   //!
   TBranch        *b_theta_hitSPMT;   //!
   TBranch        *b_phi_hitSPMT;   //!
   //TBranch        *b_SPMT_Charge;   //!
   TBranch        *b_SPMT_Time;   //!
   TBranch        *b_SPMT_Tres;   //!
   //TBranch        *b_SPMT_Tres_trueV;   //!

   char* ext_filename = new char[128]; //file for graphical output

   Data(TTree *tree=0);
   virtual ~Data();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Initialize(std::string config);
   virtual void     GetFlux(Int_t nbinsE, Float_t lowedge_E, Float_t upedge_E, Int_t nbinsNPE, Float_t lowedge_NPE, Float_t upedge_NPE, std::string outfold);
   virtual void     GetFluxSpline(Int_t nbinsE, Float_t lowedge_E, Float_t upedge_E, Int_t nbinsNPE, Float_t lowedge_NPE, Float_t upedge_NPE, std::string outfold);
   virtual void     GetMAT(Int_t nbinsE, Float_t lowedge_E, Float_t upedge_E, Int_t nbinsNPE, Float_t lowedge_NPE, Float_t upedge_NPE, std::string outfold);
   virtual void     GetDATA(Int_t nbinsE, Float_t lowedge_E, Float_t upedge_E, Int_t nbinsNPE, Float_t lowedge_NPE, Float_t upedge_NPE, std::string outfold);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef Data_cxx
Data::Data(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
     TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/storage/DATA-02/juno/Users/sgiulio/Atmo/analysis/unfolding/treemaker/trees/MC_TESTSPMT25K_1m.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("/storage/DATA-02/juno/Users/sgiulio/Atmo/analysis/unfolding/treemaker/trees/MC_TESTSPMT25K_1m.root");
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
   //SPMT_PMTID = 0;
   theta_hitSPMT = 0;
   phi_hitSPMT = 0;
   //SPMT_Charge = 0;
   SPMT_Time = 0;
   SPMT_Tres = 0;
   //SPMT_Tres_trueV = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("evtID", &evtID, &b_evtID);
   fChain->SetBranchAddress("init_nuID", &init_nuID, &b_init_nuID);
   fChain->SetBranchAddress("init_lepID", &init_lepID, &b_init_lepID);
   fChain->SetBranchAddress("nuEnergy", &nuEnergy, &b_nuEnergy);
   fChain->SetBranchAddress("CCint", &CCint, &b_CCint);
   fChain->SetBranchAddress("NCint", &NCint, &b_NCint);
   fChain->SetBranchAddress("FC", &FC, &b_FC);
   fChain->SetBranchAddress("PC", &PC, &b_PC);
   fChain->SetBranchAddress("lepEnergy", &lepEnergy, &b_lepEnergy);
   fChain->SetBranchAddress("L_osc_baseline", &L_osc_baseline, &b_L_osc_baseline);
   fChain->SetBranchAddress("P_surv", &P_surv, &b_P_surv);
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
   //fChain->SetBranchAddress("trueVradius", &trueVradius, &b_trueVradius);
   fChain->SetBranchAddress("newVradius", &newVradius, &b_newVradius);
   fChain->SetBranchAddress("vertex_shift_TS", &vertex_shift_TS, &b_vertex_shift_TS);
   fChain->SetBranchAddress("trueZENITH", &trueZENITH, &b_trueZENITH);
   fChain->SetBranchAddress("trueAZIMUTH", &trueAZIMUTH, &b_trueAZIMUTH);
   fChain->SetBranchAddress("Tres_Mean", &Tres_Mean, &b_Tres_Mean);
   fChain->SetBranchAddress("Tres_RMS", &Tres_RMS, &b_Tres_RMS);
   //fChain->SetBranchAddress("Tres_Mean_trueV", &Tres_Mean_trueV, &b_Tres_Mean_trueV);
   //fChain->SetBranchAddress("Tres_RMS_trueV", &Tres_RMS_trueV, &b_Tres_RMS_trueV);
   //fChain->SetBranchAddress("SPMT_PMTID", &SPMT_PMTID, &b_SPMT_PMTID);
   fChain->SetBranchAddress("theta_hitSPMT", &theta_hitSPMT, &b_theta_hitSPMT);
   fChain->SetBranchAddress("phi_hitSPMT", &phi_hitSPMT, &b_phi_hitSPMT);
   //fChain->SetBranchAddress("SPMT_Charge", &SPMT_Charge, &b_SPMT_Charge);
   fChain->SetBranchAddress("SPMT_Time", &SPMT_Time, &b_SPMT_Time);
   fChain->SetBranchAddress("SPMT_Tres", &SPMT_Tres, &b_SPMT_Tres);
   //fChain->SetBranchAddress("SPMT_Tres_trueV", &SPMT_Tres_trueV, &b_SPMT_Tres_trueV);
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
