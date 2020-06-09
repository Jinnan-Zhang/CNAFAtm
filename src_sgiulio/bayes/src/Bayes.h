#ifndef BAYES_H
#define BAYES_H
#include <TVector.h>
#include<iostream>
#include<list>
#include<string>
#include<sstream>
#include<fstream>

#include "TVectorD.h"
#include "TMatrixD.h"
#include "TGraph.h"
#include "TGraphErrors.h"
#include "TCanvas.h"
#include "TFile.h"
#include "TLegend.h"
#include "TH2F.h"

class Bayes {

 protected: 

  //std::string _matfile;       // MAT file (for MC)
  std::string _matfile_sgn;
  std::string _matfile_bkg;
  std::string _Enormfile;
  std::string _NPE_file;      // MAT for data
  //std::string _databkgfile;
  std::string _unf_spectrum;  // unfolded spectrum
  std::string _input_folder;  // input path
  std::string _output_folder; // output path
  std::string _NPE_bins;      // VEC for data bins
  std::string _E_bins;        // VEC for energy bin values
  std::string _prior_file;    // VEC for external prior
  std::string priorname;      // VEC for prior
  std::string _trueE_file;    // VEC for true energy from fake data
  std::string _contE_file;    // VEC for contamination
  std::string _trueE_flux;    // VEC for true flux from Honda
  std::string _Honda_str;     // wxternal Honda flux file
  std::string _SK_file;       // external SK flux file
  std::string lowthr_energy;
  std::string lowthr_npe;
  std::string upthr_energy;
  std::string upthr_npe;
  std::string family;
  std::string MC_D_R;
  std::string num_iter;

  Float_t MC_DATA_ratio;
  Int_t Niter;
  int _noEnu;            // #causes
  int _noNPE;            // #effects
  float neffects;          // total effects
  float lowedge_E;
  float upedge_E;
  float lowedge_NPE;
  float upedge_NPE;

  TVectorD _En;          // Normalization  
  TVectorD _nNPEj;       // Number of measured events from Effect NPE_j
  //TVectorD _nEgj;         Number of events generated in effect bin E_j
  TVectorD _pCi;         // Prior normalized function from cause C_i
  TVectorD _pCn;         // Prior normalized function from cause C_i (re-calculated)
  TVectorD _nCgi;        // Number of events generated in cause bin C_i
  TVectorD _nCsi;        // Number of events selected in cause bin C_i
  TVectorD _nUNFi;       // Unfolded spectrum
  TVectorD err_nUNFi;    // Uncertainty on Unfolded spectrum
  TVectorD plot_err_nUNFi;
  TVectorD _nUNFn;       // Unfolded spectrum re-iterated
  TVectorD _ncont;       // Contamination
  TVectorD _nCtemp;
  TVectorD _Ebins;
  TVectorD plot_Ebins;
  TVectorD _NPEbins;
  TVectorD _trueFlux;
  TVectorD plot_trueFlux;
  TVectorD _trueE;
  TVectorD _trueE_recoE_ratio;
  TVectorD _trueE_recoE_ratio_err;
  TVectorD denom;
  TVectorD invdenom;
  TVectorD _efficiency;
  TVectorD _nUNFi_eff;
  TVectorD plot_nUNFi_eff;
  TVectorD err_trueE;
  TVectorD err_ratio;
  TVectorD errx;
  TVectorD errx0;
  TVectorD E_Honda;
  TVectorD Flux_Honda;
  TVectorD Flux_Honda_unosc;
  TVectorD E_SK;
  TVectorD Flux_SK;
  TVectorD errX_SK;
  TVectorD err_SK;

  char* ext_filename = new char[128];
  
  TVectorD _nuEflux;     // electron neutrino flux vector (center bin energy)
  TMatrixD _Aji;         // likelihood matrix
  TMatrixD _MUNFij;      // unfolding matrix

  //std::vector<TGraph*> ncplot;
  //std::vector<TH2F*> HMAT;
  //TH2F *h_mat;

 public :

  Bayes();
  ~Bayes();

  void Initialize(std::string config);  // obsolete
  void Init(std::string config);        // new
  void Read();                     // obsolete
  void ReadMAT();                  // new: Read MAT from MC
  void ReadDATA();                 // new: Read MAT from data
  void ReadTrueFile();             // new: Read true MC for testing MC vs MC
  void DumpMAT();                  // new: dumping MAT
  void Flux();                     // new: calculating flux
  void WriteFlux();                // new: writing out flux
  void SetPrior(std::string priorname); 
  void Normalize();
  void Unfold();                   // obsolete
  void Unfold2();                  // new
  void Efficiency();
  void Loop();
  void RawFlux();
  void Rescale();                 //new:rescale the flux with contamination

  void ReadMAT1D();                  // new: Read MAT 1D from MC
  void ReadDAT1D();                  // new: Read MAT 1D from data
  void DumpMAT1D();                  // new: dumping MAT1D
  void Flux1D();                     // new: calculating flux 1D
  void WriteFlux1D();                // new: writing out flux 1D
  void Smoothing();
};
#endif
