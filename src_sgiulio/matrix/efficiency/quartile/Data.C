#define Data_cxx
#include "Data.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <vector>
#include <iostream>

void Data::Loop()
{
//   In a ROOT session, you can do:
//      root> .L Data.C
//      root> Data t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries
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
   if (fChain == 0) return;

   std::vector <float> Energy_vec;
   int counter = 0;
   
   Long64_t nentries = fChain->GetEntriesFast();
   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;

      if(jentry%1000==0) std::cout <<"processing event "<<jentry<<endl;

      if (trueNPE_LPMT>1.E5 && newVradius<16000.) Energy_vec.push_back(trueNPE_LPMT);
   }

   sort(Energy_vec.begin(), Energy_vec.end());
   for (int jj=0; jj<int(Energy_vec.size()); jj++) {
     counter+=1;
     if(float(counter)>(Energy_vec.size()/4.)) {
       std::cout<<"counter is "<<jj<<" and logenergy is "<<(Energy_vec)[jj]<<" --> "<<log10((Energy_vec)[jj])<<endl;
       counter = 0;
     }
   }
   std::cout<<"maxenergy is "<<(Energy_vec)[Energy_vec.size()-1]<<" --> "<<log10((Energy_vec)[Energy_vec.size()-1])<<endl;
   
}
