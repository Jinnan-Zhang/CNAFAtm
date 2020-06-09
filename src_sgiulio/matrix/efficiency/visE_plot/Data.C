#define Data_cxx
#include "Data.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void Data::Loop()
{
   if (fChain == 0) return;
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);

   TCanvas *c80 = new TCanvas("c80","",1000,600);
   TLegend * leg80 = new TLegend(0.65,0.87,0.87,0.6);
   leg80->SetBorderSize(0);
   TH1F *VisE_nuNC = new TH1F("VisE_nuNC","",100,0.,20.1);
   TH1F *VisE_nueCC = new TH1F("VisE_nueCC","",100,0.,20.1);
   TH1F *VisE_numuCC = new TH1F("VisE_numuCC","",100,0.,20.1);
   VisE_nuNC->SetLineWidth(5);
   VisE_nuNC->SetLineColor(kSpring-1);
   VisE_nuNC->SetFillColor(kSpring-1);
   VisE_nuNC->SetFillStyle(3002);
   VisE_nueCC->SetLineWidth(5);
   VisE_nueCC->SetLineColor(kRed);
   VisE_nueCC->SetFillColor(kRed);
   VisE_nueCC->SetFillStyle(3002);
   VisE_numuCC->GetXaxis()->SetTitle("Visible Energy [GeV]");
   VisE_numuCC->GetYaxis()->SetTitle("entries");
   VisE_numuCC->GetXaxis()->SetTitleSize(0.05);
   VisE_numuCC->GetXaxis()->SetTitleOffset(0.9);
   VisE_numuCC->GetXaxis()->SetLabelSize(0.05);
   VisE_numuCC->GetYaxis()->SetLabelSize(0.05);
   VisE_numuCC->GetYaxis()->SetTitleOffset(1.2);
   VisE_numuCC->GetYaxis()->SetRangeUser(1,3.E5);
   VisE_numuCC->SetLineWidth(5);
   VisE_numuCC->SetLineColor(kBlue+2);
   VisE_numuCC->SetFillColor(kBlue+2);
   VisE_numuCC->SetFillStyle(3002);

   //////////////////////////////////////////////////////////////////////////
   TCanvas *c82 = new TCanvas("c82","",1000,600);
   TLegend * leg82 = new TLegend(0.65,0.87,0.87,0.6);
   leg82->SetBorderSize(0);
   TH1F *NPE_LPMT_CD_nuNC = new TH1F("NPE_LPMT_CD_nuNC","",100,0.,3.E7);
   TH1F *NPE_LPMT_CD_nueCC = new TH1F("NPE_LPMT_CD_nueCC","",100,0.,3.E7);
   TH1F *NPE_LPMT_CD_numuCC = new TH1F("NPE_LPMT_CD_numuCC","",100,0.,3.E7);
   NPE_LPMT_CD_nuNC->SetLineWidth(5);
   NPE_LPMT_CD_nuNC->SetLineColor(kSpring-1);
   NPE_LPMT_CD_nuNC->SetFillColor(kSpring-1);
   NPE_LPMT_CD_nuNC->SetFillStyle(3002);
   NPE_LPMT_CD_nueCC->SetLineWidth(5);
   NPE_LPMT_CD_nueCC->SetLineColor(kRed);
   NPE_LPMT_CD_nueCC->SetFillColor(kRed);
   NPE_LPMT_CD_nueCC->SetFillStyle(3002);
   NPE_LPMT_CD_numuCC->GetXaxis()->SetTitle("NPE");
   NPE_LPMT_CD_numuCC->GetYaxis()->SetTitle("entries");
   NPE_LPMT_CD_numuCC->GetXaxis()->SetTitleSize(0.05);
   NPE_LPMT_CD_numuCC->GetXaxis()->SetTitleOffset(0.9);
   NPE_LPMT_CD_numuCC->GetXaxis()->SetLabelSize(0.05);
   NPE_LPMT_CD_numuCC->GetYaxis()->SetLabelSize(0.05);
   NPE_LPMT_CD_numuCC->GetYaxis()->SetTitleOffset(1.2);
   NPE_LPMT_CD_numuCC->GetYaxis()->SetRangeUser(1,3.E5);
   NPE_LPMT_CD_numuCC->SetLineWidth(5);
   NPE_LPMT_CD_numuCC->SetLineColor(kBlue+2);
   NPE_LPMT_CD_numuCC->SetFillColor(kBlue+2);
   NPE_LPMT_CD_numuCC->SetFillStyle(3002);

   Long64_t nentries = fChain->GetEntriesFast();
   Long64_t nbytes = 0, nb = 0;
   //for (Long64_t jentry=0; jentry<nentries;jentry++) {
   for (Long64_t jentry=0; jentry<500000;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
      if(jentry%1000==0) cout <<"processing event "<<jentry<<endl;

      /*
      for (int kk=0; kk<nHadr; kk++){
	if((*pdgHadr)[kk] == 2212 || (*pdgHadr)[kk] == 2112) {
	  hadrEnergy+=((*EHadr)[kk]-sqrt(((*EHadr)[kk]*(*EHadr)[kk])-((*pHadr)[kk]*(*pHadr)[kk])));
	} else {
	  hadrEnergy+=(*EHadr)[kk];
	}
      }      
      */
      if(NCint==1) {
	VisE_nuNC->Fill(visEnergy,P_surv);
	NPE_LPMT_CD_nuNC->Fill(trueNPE_LPMT_CD,P_surv);
      } else if(CCint==1 && abs(init_lepID) == 11) {
	VisE_nueCC->Fill(visEnergy,P_surv);
	NPE_LPMT_CD_nueCC->Fill(trueNPE_LPMT_CD,P_surv);
      } else if(CCint==1 && abs(init_lepID) == 13) {
	VisE_numuCC->Fill(visEnergy,P_surv);
	NPE_LPMT_CD_numuCC->Fill(trueNPE_LPMT_CD,P_surv);
      }      

   }

   c80->cd();
   gPad->SetLogy();
   VisE_numuCC->Draw("HISTO");
   VisE_nueCC->Draw("HISTO SAME");
   VisE_nuNC->Draw("HISTO SAME");
   leg80->AddEntry(VisE_numuCC, "#nu_{#mu} CC" ,"l");
   leg80->AddEntry(VisE_nueCC, "#nu_{e} CC" ,"l");
   leg80->AddEntry(VisE_nuNC, "#nu_{x} NC" ,"l");
   leg80->Draw();
   c80->SaveAs("visEnergy.png");
   c80->SaveAs("visEnergy.pdf");
   c80->SaveAs("visEnergy.C");
   /////////////////////////////////////////////////
   c82->cd();
   gPad->SetLogy();
   NPE_LPMT_CD_numuCC->Draw("HISTO");
   NPE_LPMT_CD_nueCC->Draw("HISTO SAME");
   NPE_LPMT_CD_nuNC->Draw("HISTO SAME");
   leg82->AddEntry(NPE_LPMT_CD_numuCC, "#nu_{#mu} CC" ,"l");
   leg82->AddEntry(NPE_LPMT_CD_nueCC, "#nu_{e} CC" ,"l");
   leg82->AddEntry(NPE_LPMT_CD_nuNC, "#nu_{x} NC" ,"l");
   leg82->Draw();
   c82->SaveAs("NPE_LPMT_CD.png");
   c82->SaveAs("NPE_LPMT_CD.pdf");
   c82->SaveAs("NPE_LPMT_CD.C");

}
