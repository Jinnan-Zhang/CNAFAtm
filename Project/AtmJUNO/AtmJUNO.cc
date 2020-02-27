#include <TChain.h>
#include <TROOT.h>
#include <TTree.h>
#include <TFile.h>
#include <TSelector.h>
#include <TH1.h>
#include <TH2.h>
#include <TEntryList.h>
#include <TF1.h>
#include "TStyle.h"
#include "TCanvas.h"
#include "TPaveStats.h"
#include "TLine.h"
#include "TMath.h"
#include "AtmJUNO.h"
#include <iostream>

using std::cout;
using std::endl;

int main()
{
    Double_t add=10;
    TChain chh("evt");
    chh.Add("$SGD/user-detsim-1000.root");
    chh.MakeSelector("AtmSlector");
    // chh.Process("../src/h1analysis.C");
    return 0;
}