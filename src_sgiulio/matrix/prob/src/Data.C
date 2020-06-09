#define Data_cxx
#include "Data.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
#include <fstream>

void Data::Loop(char* outputfile)
{
//   In a ROOT session, you can do:
//      Root > .L Data.C
//      Root > Data t
//      Root > t.GetEntry(12); // Fill t data members with entry number 12
//      Root > t.Show();       // Show values of entry 12
//      Root > t.Show(16);     // Read and show values of entry 16
//      Root > t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch

  const static int NBINS = 10;

  char* filename= new char[128];
  sprintf(filename, outputfile);
  //TFile f_out(filename, "RECREATE");
  ofstream myfile;
  myfile.open(filename);

  if (fChain == 0) return;
  Long64_t nentries = fChain->GetEntriesFast();
  std::cout << "Looping over " << fChain->GetEntriesFast() << " entries... " << std::endl;
  Long64_t nbytes = 0, nb = 0;

  TH2F *Npe_VS_Ev_Elec_LPMT_nueCC = new TH2F("Npe_VS_Ev_Elec_LPMT_nueCC","",NBINS,1.7,4.31,NBINS,5.,7.3);
  
  for (Long64_t jentry=0; jentry<nentries;jentry++) {
    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0) break;
    nb = fChain->GetEntry(jentry);   nbytes += nb;
    // if (Cut(ientry) < 0) continue;
    if(jentry%1000==0) std::cout <<"processing event "<<jentry<<std::endl;
    
    if(Tres_RMS<80 && CCint==1 && abs(init_lepID)==11 && newVradius<16000) {
      Npe_VS_Ev_Elec_LPMT_nueCC->Fill(log10(nuEnergy),log10(trueNPE_LPMT));
    }
  }
  
  for (int ii=1; ii<=NBINS; ii++) {
    for (int jj=1; jj<=NBINS; jj++) {
      std::cout<<ii<<":"<<jj<<"->"<<Npe_VS_Ev_Elec_LPMT_nueCC->GetBinContent(ii,jj)<<"  ";
      myfile << Npe_VS_Ev_Elec_LPMT_nueCC->GetBinContent(ii,jj) << "\t";
    }
    myfile << "\n";
  }
  
  myfile.close();
  std::cout << filename << " created" << std::endl;
  
}
