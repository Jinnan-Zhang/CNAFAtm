#include "Data.h"
#include <iostream>

int main(int argc, char* argv[]){

  TTree *tree=0;

  TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/storage/DATA-02/juno/Users/sgiulio/Atmo/analysis/unfolding/treemaker/trees/DATA_10K_1m_TOT.root");
  if (!f || !f->IsOpen()) {
    f = new TFile("/storage/DATA-02/juno/Users/sgiulio/Atmo/analysis/unfolding/treemaker/trees/DATA_10K_1m_TOT.root");
  }
  f->GetObject("Data",tree);
  Data *a = new Data(tree);

  a->Loop();

  //return 1;

}
