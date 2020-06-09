#ifndef BAYES_H
#define BAYES_H

using namespace std;

#include<iostream>
#include<list>
#include<string>
#include<sstream>
#include<fstream>

#include "TVectorD.h"
#include "TMatrixD.h"
#include "TGraph.h"
#include "TCanvas.h"
#include "TFile.h"
#include "TLegend.h"
#include "TH2F.h"

class Bayes {

 protected: 

  string _config;        // configuration file
  string _efile;         // obsolete
  string _matfile;       // MAT file (for MC):
                         // row1: #causes #effects
                         // row2: values for generated causes
                         // row3: values for selected causes
                         // row4: values for generated effects
                         // row5: values for selected effects
                         // MAT(#effect,#cause) 
                         // run duration (only for data, 0 for MC)
                         // cause center bins
                         // #causes for proton
                         // values for proton causes
                         // values for proton cause edges
                         // #causes for iron
                         // values for iron causes
                         // values for iron cause edges
  string _cfile;         // obsolete
  string _datfile;       // MAT for data:
                         // #effects
                         // values for selected effects
                         // run duration (second)
  string _truefile;      // MAT file used as data for testing
  string _proton_flux_file;   // proton flux file
  string _iron_flux_file;     // iron flux file
  string _corr_mult_2012_file;     //rate 2012 correction -> 2009

  int _noc;              // #causes
  int _noe;              // #effects
  int _maxiter;          // #iterations
  int _test;             // 0:default 1:for testing MC vs MC (read Mat#Vt-##x##.dat)
  float _Ntrue;          
  float _Tperiod;        // run duration

  int _year;             //used for 2012

  TVectorD _nEj;          // Number of measured events from Effect E_j
  TVectorD _nEgj;         // Number of events generated in effect bin E_j
  TVectorD _nCi;          // Number of true events from cause C_i
  TVectorD _nCgi;         // Number of events generated in cause bin C_i
  TVectorD _nCsi;         // Number of events selected in cause bin C_i
  TVectorD _nCcbi;        // Cause center bins

  int _ncomp;            // Number of primary CR elements
  int _npb;              // Number of energy bins for proton
  int _nib;              // Number of energy bins for iron
  TVectorD _pflux;         // proton flux vector (center bin energy)
  TVectorD _iflux;         // iron flux vector (center bin energy)
  TVectorD _pfluxL;         // proton flux vector  (lower edge energy) 
  TVectorD _ifluxL;         // iron flux vector  (lower edge energy) 
  TVectorD _pfluxU;         // proton flux vector (upper edge energy)
  TVectorD _ifluxU;         // iron flux vector (upper edge energy)

  TVectorD _pen;           // proton energy vector
  TVectorD _ien;           // iron energy vector
  TVectorD _pen_edg;       // proton energy edges
  TVectorD _ien_edg;       // iron energy edges

  TVectorD _pCi;
  TVectorD _pC0i;
  TVectorD _nbarCi;       // Estimated number of true events from cause C_i
  TVectorD _efficiencyCi; // efficiency for detecting cause C_i

  TVectorD _corr_mult_2012;  //2012 correction -> 2009
  
  TMatrixD _Pecji;          // mapping causes to effects
  TMatrixD _Pceij;          // mapping effects to causes
  TMatrixD _Mecji;
  TMatrixD _Munfij;         // unfolding matrix
  //TMatrixD _Vij;          // covariance matrix
  //TMatrixD _VnEstij;      // covariance matrix of effects
  //TMatrixD _dnCidnEj;     // error propagation matrix

  //  TFile *_rootFile;
  vector<TGraph*> ncplot;
  vector<TH2F*> HMAT;
  TH2F *h_mat;

  TMatrixD MatPlot;
  TFile * fmat;

 public :

  Bayes();
  ~Bayes();

  void Initialize(string config);  // obsolete
  void Init(string config);        // new
  void Read();                     // obsolete
  void ReadMAT();                  // new: Read MAT from MC
  void ReadDAT();                  // new: Read MAT from data
  void ReadTrueFile();             // new: Read true MC for testing MC vs MC
  void DumpMAT();                  // new: dumping MAT
  void Flux();                     // new: calculating flux
  void WriteFlux();                // new: writing out flux
  void SetPrior(string priorname); 
  void Normalize();
  void Unfold();                   // obsolete
  void Unfold2();                  // new
  void Efficiency();
  void Loop();

  void ReadMAT1D();                  // new: Read MAT 1D from MC
  void ReadDAT1D();                  // new: Read MAT 1D from data
  void DumpMAT1D();                  // new: dumping MAT1D
  void Flux1D();                     // new: calculating flux 1D
  void WriteFlux1D();                // new: writing out flux 1D
  void Smoothing();
  void OldSmoothing();
  void SmoothingPRD();
  void SmoothingGiulio();
};
#endif
