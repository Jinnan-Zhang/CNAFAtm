#include <TFile.h>
#include <TH1.h>
#include <TH2.h>
#include <TString.h>

void MatrixCom(TString filename = "../data/UnfoldData.root");

int OutCompare()
{
    MatrixCom();
    return 0;
}

void MatrixCom(TString filename)
{
    TFile *ff_Unfold = TFile::Open(filename, "READ");
    TH2 *h_eCCM = dynamic_cast<TH2D *>(ff_Unfold->Get("eCC_Likely_hood"));
    TH2 *h_muCCM = dynamic_cast<TH2D *>(ff_Unfold->Get("muCC_Likely_hood"));
    TFile *ff_Out = TFile::Open("../data/LikelihoodMatrix.root", "RECREATE");
    h_eCCM->Write();
    h_muCCM->Write();
}