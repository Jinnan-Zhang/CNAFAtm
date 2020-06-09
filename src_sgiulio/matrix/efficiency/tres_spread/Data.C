#define Data_cxx
#include "Data.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void Data::Loop()
{
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;

   TCanvas *c80 = new TCanvas("c80","eCCRMS",800,800);
   TCanvas *c81 = new TCanvas("c81","eCCM",800,800);
   TCanvas *c82 = new TCanvas("c82","muCCRMS",800,800);
   TCanvas *c83 = new TCanvas("c83","muCCM",800,800);
   TCanvas *c84 = new TCanvas("c84","NCRMS",800,800);
   TCanvas *c85 = new TCanvas("c85","NCM",800,800);
   
   TH2F *Tres_RMS_shift_VS_vertex_shift_nueCC_h = new TH2F("Tres_RMS_shift_VS_vertex_shift_nueCC_h","",150,0.,6.,150,-5.,5.);
   Tres_RMS_shift_VS_vertex_shift_nueCC_h->GetXaxis()->SetTitle("vertex shift [m]");
   Tres_RMS_shift_VS_vertex_shift_nueCC_h->GetXaxis()->SetTitleSize(0.05);
   Tres_RMS_shift_VS_vertex_shift_nueCC_h->GetXaxis()->SetLabelSize(0.045);
   Tres_RMS_shift_VS_vertex_shift_nueCC_h->GetYaxis()->SetTitle("#sigma(t_{res}^{smearV}) - #sigma(t_{res}^{trueV}) [ns]");
   Tres_RMS_shift_VS_vertex_shift_nueCC_h->GetYaxis()->SetLabelSize(0.045);
   Tres_RMS_shift_VS_vertex_shift_nueCC_h->GetYaxis()->SetTitleOffset(1.35);
   TH2F *Tres_Mean_shift_VS_vertex_shift_nueCC_h = new TH2F("Tres_Mean_shift_VS_vertex_shift_nueCC_h","",150,0.,6.,150,-10.,10.);
   Tres_Mean_shift_VS_vertex_shift_nueCC_h->GetXaxis()->SetTitle("vertex shift [m]");
   Tres_Mean_shift_VS_vertex_shift_nueCC_h->GetYaxis()->SetTitle("< t_{res}^{smearV} > - < t_{res}^{trueV} > [ns]");
   TH2F *Tres_RMS_shift_VS_vertex_shift_numuCC_h = new TH2F("Tres_RMS_shift_VS_vertex_shift_numuCC_h","",150,0.,6.,150,-5.,5.);
   Tres_RMS_shift_VS_vertex_shift_numuCC_h->GetXaxis()->SetTitle("vertex shift [m]");
   Tres_RMS_shift_VS_vertex_shift_numuCC_h->GetXaxis()->SetTitleSize(0.05);
   Tres_RMS_shift_VS_vertex_shift_numuCC_h->GetXaxis()->SetLabelSize(0.045);
   Tres_RMS_shift_VS_vertex_shift_numuCC_h->GetYaxis()->SetTitle("#sigma(t_{res}^{smearV}) - #sigma(t_{res}^{trueV}) [ns]");
   Tres_RMS_shift_VS_vertex_shift_numuCC_h->GetYaxis()->SetLabelSize(0.045);
   Tres_RMS_shift_VS_vertex_shift_numuCC_h->GetYaxis()->SetTitleOffset(1.35);
   TH2F *Tres_Mean_shift_VS_vertex_shift_numuCC_h = new TH2F("Tres_Mean_shift_VS_vertex_shift_numuCC_h","",150,0.,6.,150,-10.,10.);
   Tres_Mean_shift_VS_vertex_shift_numuCC_h->GetXaxis()->SetTitle("vertex shift [m]");
   Tres_Mean_shift_VS_vertex_shift_numuCC_h->GetYaxis()->SetTitle("< t_{res}^{smearV} > - < t_{res}^{trueV} > [ns]");
   TH2F *Tres_RMS_shift_VS_vertex_shift_nuNC_h = new TH2F("Tres_RMS_shift_VS_vertex_shift_nuNC_h","",150,0.,6.,150,-5.,5.);
   Tres_RMS_shift_VS_vertex_shift_nuNC_h->GetXaxis()->SetTitle("vertex shift [m]");
   Tres_RMS_shift_VS_vertex_shift_nuNC_h->GetXaxis()->SetTitleSize(0.05);
   Tres_RMS_shift_VS_vertex_shift_nuNC_h->GetXaxis()->SetLabelSize(0.045); 
   Tres_RMS_shift_VS_vertex_shift_nuNC_h->GetYaxis()->SetTitle("#sigma(t_{res}^{smearV}) - #sigma(t_{res}^{trueV}) [ns]");
   Tres_RMS_shift_VS_vertex_shift_nuNC_h->GetYaxis()->SetLabelSize(0.045);
   Tres_RMS_shift_VS_vertex_shift_nuNC_h->GetYaxis()->SetTitleOffset(1.35);
   TH2F *Tres_Mean_shift_VS_vertex_shift_nuNC_h = new TH2F("Tres_Mean_shift_VS_vertex_shift_nuNC_h","",150,0.,6.,150,-10.,10.);
   Tres_Mean_shift_VS_vertex_shift_nuNC_h->GetXaxis()->SetTitle("vertex shift [m]");
   Tres_Mean_shift_VS_vertex_shift_nuNC_h->GetYaxis()->SetTitle("< t_{res}^{smearV} > - < t_{res}^{trueV} > [ns]");
   
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
     Long64_t ientry = LoadTree(jentry);
     if (ientry < 0) break;
     nb = fChain->GetEntry(jentry);   nbytes += nb;
     // if (Cut(ientry) < 0) continue;

   if(trueNPE_LPMT_WP < 60. && trueNPE_LPMT_CD>1.E5 && CCint==1 && abs(init_lepID)==11 && newVradius<16000.) Tres_RMS_shift_VS_vertex_shift_nueCC_h->Fill(vertex_shift/1000.,(Tres_RMS-Tres_RMS_trueV),P_surv);     
   if(trueNPE_LPMT_WP < 60. && trueNPE_LPMT_CD>1.E5 && CCint==1 && abs(init_lepID)==11 && newVradius<16000.) Tres_Mean_shift_VS_vertex_shift_nueCC_h->Fill(vertex_shift/1000.,(Tres_Mean-Tres_Mean_trueV),P_surv);

   if(trueNPE_LPMT_WP < 60. && trueNPE_LPMT_CD>1.E5 && CCint==1 && abs(init_lepID)==13 && newVradius<16000.) Tres_RMS_shift_VS_vertex_shift_numuCC_h->Fill(vertex_shift/1000.,(Tres_RMS-Tres_RMS_trueV),P_surv);
   if(trueNPE_LPMT_WP < 60. && trueNPE_LPMT_CD>1.E5 && CCint==1 && abs(init_lepID)==13 && newVradius<16000.) Tres_Mean_shift_VS_vertex_shift_numuCC_h->Fill(vertex_shift/1000.,(Tres_Mean-Tres_Mean_trueV),P_surv);

   if(trueNPE_LPMT_WP < 60. && trueNPE_LPMT_CD>1.E5 && NCint==1 && newVradius<16000.) Tres_RMS_shift_VS_vertex_shift_nuNC_h->Fill(vertex_shift/1000.,(Tres_RMS-Tres_RMS_trueV),P_surv);
   if(trueNPE_LPMT_WP < 60. && trueNPE_LPMT_CD>1.E5 && NCint==1 && newVradius<16000.) Tres_Mean_shift_VS_vertex_shift_nuNC_h->Fill(vertex_shift/1000.,(Tres_Mean-Tres_Mean_trueV),P_surv);
     
     c80->cd();
     gPad->SetLogz();
     Tres_RMS_shift_VS_vertex_shift_nueCC_h->Draw("colz");
     c81->cd();
     gPad->SetLogz();
     Tres_Mean_shift_VS_vertex_shift_nueCC_h->Draw("colz");
     c82->cd();
     gPad->SetLogz();
     Tres_RMS_shift_VS_vertex_shift_numuCC_h->Draw("colz");
     c83->cd();
     gPad->SetLogz();
     Tres_Mean_shift_VS_vertex_shift_numuCC_h->Draw("colz");
     c84->cd();
     gPad->SetLogz();
     Tres_RMS_shift_VS_vertex_shift_nuNC_h->Draw("colz");
     c85->cd();
     gPad->SetLogz();
     Tres_Mean_shift_VS_vertex_shift_nuNC_h->Draw("colz");
     
     c80->SaveAs("../Plot/Tres_RMS_shift_VS_vertex_shift_0-20GeV_1m_nueCC.pdf");
     c80->SaveAs("../Plot/Tres_RMS_shift_VS_vertex_shift_0-20GeV_1m nueCC.png");
     c80->SaveAs("../Plot/Tres_RMS_shift_VS_vertex_shift_0-20GeV_1m_nueCC.C");
     c81->SaveAs("../Plot/Tres_Mean_shift_VS_vertex_shift_0-20GeV_1m_nueCC.pdf");
     c81->SaveAs("../Plot/Tres_Mean_shift_VS_vertex_shift_0-20GeV_1m_nueCC.png");
     c81->SaveAs("../Plot/Tres_Mean_shift_VS_vertex_shift_0-20GeV_1m_nueCC.C");
     c82->SaveAs("../Plot/Tres_RMS_shift_VS_vertex_shift_0-20GeV_1m_numuCC.pdf");
     c82->SaveAs("../Plot/Tres_RMS_shift_VS_vertex_shift_0-20GeV_1m_numuCC.png");
     c82->SaveAs("../Plot/Tres_RMS_shift_VS_vertex_shift_0-20GeV_1m_numuCC.C");
     c83->SaveAs("../Plot/Tres_Mean_shift_VS_vertex_shift_0-20GeV_1m_numuCC.pdf");
     c83->SaveAs("../Plot/Tres_Mean_shift_VS_vertex_shift_0-20GeV_1m_numuCC.png");
     c83->SaveAs("../Plot/Tres_Mean_shift_VS_vertex_shift_0-20GeV_1m_numuCC.C");
     c84->SaveAs("../Plot/Tres_RMS_shift_VS_vertex_shift_0-20GeV_1m_nuNC.pdf");
     c84->SaveAs("../Plot/Tres_RMS_shift_VS_vertex_shift_0-20GeV_1m_nuNC.png");
     c84->SaveAs("../Plot/Tres_RMS_shift_VS_vertex_shift_0-20GeV_1m_nuNC.C");
     c85->SaveAs("../Plot/Tres_Mean_shift_VS_vertex_shift_0-20GeV_1m_nuNC.pdf");
     c85->SaveAs("../Plot/Tres_Mean_shift_VS_vertex_shift_0-20GeV_1m_nuNC.png");
     c85->SaveAs("../Plot/Tres_Mean_shift_VS_vertex_shift_0-20GeV_1m_nuNC.C");
     
   }
}
