#define Data_cxx
#include "Data.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
#include <TGraph.h>

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

   static const int TRES_BINS = 100;
   float TRES_MIN = 10.0;
   float TRES_MAX = 300;
   float TRES_CUT;
   int nueCC_all[TRES_BINS];
   int nueCC_cut[TRES_BINS];
   int bkg_cut[TRES_BINS];
   float purity[TRES_BINS];
   float contamination[TRES_BINS];

   Long64_t nentries = fChain->GetEntriesFast();
   std::cout << "Looping over " << fChain->GetEntries() << " entries... " << std::endl;
   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      if(jentry%1000==0) std::cout <<"processing event "<<jentry<<std::endl;
      if(trueNPE_LPMT < 150000. || newVradius > 16000) continue;

      for(int i=0; i<TRES_BINS; i++) {
	TRES_CUT = TRES_MIN+(((TRES_MAX-TRES_MIN)/TRES_BINS)*float(i));
	if(CCint==1 && abs(init_lepID)==11) { //nue CC
	  nueCC_all[i] += 1;
	  if(Tres_RMS<TRES_CUT) {
	    nueCC_cut[i] += 1;
	  }
	} else {
	  if(Tres_RMS<TRES_CUT) {
	    bkg_cut[i] += 1;
	  }
	}
      }	        	  

   }

   for(int i=0; i<TRES_BINS; i++) {
     purity[i] = float(nueCC_cut[i])/float(bkg_cut[i]);
     contamination[i] = float(nueCC_cut[i])/float(nueCC_all[i]);
   }
   TGraph *ROC = new TGraph(TRES_BINS,purity,contamination);
   TCanvas *cRoc = new TCanvas("cRoc","ROC Curve",0,0,800,700);
   cRoc->cd();
   ROC->Draw("AP");
   cRoc->SaveAs("ROC.root");
}
