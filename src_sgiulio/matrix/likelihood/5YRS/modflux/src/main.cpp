#include "Data.h"
#include <iostream>
#include "srtutils.cc"

int main(int argc, char* argv[]){

  std::string config = argv[1];
  std::string mode = GetValue("MODE",config.c_str());
  std::string bins_energy = GetValue("BINS_ENERGY",config.c_str());
  std::string bins_npe = GetValue("BINS_NPE",config.c_str());
  std::string lowthr_energy = GetValue("LOWTHR_E",config.c_str());
  std::string lowthr_npe = GetValue("LOWTHR_NPE",config.c_str());
  std::string upthr_energy = GetValue("UPTHR_E",config.c_str());
  std::string upthr_npe = GetValue("UPTHR_NPE",config.c_str());
  std::string outfold = GetValue("FOLDER",config.c_str());
  std::string _MCfile = GetFileName("MC_FILE",config.c_str());
  std::string _DATAfile = GetFileName("DATA_FILE",config.c_str());

  TTree *tree=0;
  TString string_nbinsNPE = bins_npe;
  Int_t nbinsNPE = atoi(string_nbinsNPE);
  TString string_nbinsE = bins_energy;
  Int_t nbinsE = atoi(string_nbinsE);
  TString string_lowedge_E = lowthr_energy;
  Float_t lowedge_E = atof(string_lowedge_E);
  TString string_upedge_E = upthr_energy;
  Float_t upedge_E = atof(string_upedge_E);
  TString string_lowedge_NPE = lowthr_npe;
  Float_t lowedge_NPE = atof(string_lowedge_NPE);
  TString string_upedge_NPE = upthr_npe;
  Float_t upedge_NPE = atof(string_upedge_NPE);


  if (mode == "MC") {

    std::cout << "Input MC file is: " << _MCfile << std::endl;
    TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject(_MCfile.c_str());
    if (!f || !f->IsOpen()) {
      f = new TFile(_MCfile.c_str());
    }
    f->GetObject("Data",tree);
    Data *a = new Data(tree);
    a->Initialize(config);
    a->GetMAT(nbinsE,lowedge_E,upedge_E,nbinsNPE,lowedge_NPE,upedge_NPE,outfold);
    //a->GetFlux(nbinsE,lowedge_E,upedge_E,nbinsNPE,lowedge_NPE,upedge_NPE,outfold);    
    a->GetFluxSpline(nbinsE,lowedge_E,upedge_E,nbinsNPE,lowedge_NPE,upedge_NPE,outfold);    
  } else if (mode == "DATA") {

    std::cout << "Input DATA file is: " << _DATAfile << std::endl;
    TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject(_DATAfile.c_str());
    if (!f || !f->IsOpen()) {
      f = new TFile(_DATAfile.c_str());
    }
    f->GetObject("Data",tree);
    Data *a = new Data(tree);
    a->Initialize(config);
    a->GetDATA(nbinsE,lowedge_E,upedge_E,nbinsNPE,lowedge_NPE,upedge_NPE,outfold);
    a->GetFluxSpline(nbinsE,lowedge_E,upedge_E,nbinsNPE,lowedge_NPE,upedge_NPE,outfold);    
  }

  return 1;
}
