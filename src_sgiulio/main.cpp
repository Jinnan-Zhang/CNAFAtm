#include "Data.h"
#include <iostream>
#include "srtutils.cc"

int main(int argc, char* argv[]){

  TTree *tree=0;
  std::string config = argv[1];
  std::string _MCfile = GetFileName("MC_FILE",config.c_str());

  std::cout << "Input MC file is: " << _MCfile << std::endl;

  TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject(_MCfile.c_str());
  if (!f || !f->IsOpen()) {
    f = new TFile(_MCfile.c_str());
  }
  f->GetObject("Data",tree);
  Data *a = new Data(tree);

  a->Loop();

  //return 1;

}
