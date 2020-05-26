/*
Show the preliminary results
author: Jinnan Zhang:Jinnan.Zhang@ihep.ac.cn
*/
#include <vector>
#include <TH1.h>
#include <TF1.h>
#include <TGraph.h>
#include <TFile.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <iostream>
#include <TString.h>
using namespace std;

void ViewFlavor();

int ShowResult()
{
    return 0;
}
void ViewFlavor()
{
    TString PreFileName="result10.root";
    TH1::AddDirectory(false);
    TFile *ff_flavor=TFile::Open(PreFileName,"READ");
    
}