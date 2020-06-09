void DATA_NPE_LPMT_eff_0-20GeV_16volcut_1m_less75nscut_withfidcut()
{
//=========Macro generated from canvas: c15/
//=========  (Tue Jul  9 16:34:51 2019) by ROOT version 6.12/06
   TCanvas *c15 = new TCanvas("c15", "",65,52,800,600);
   gStyle->SetOptStat(0);
   c15->Range(-3750000,-0.8667566,3.375e+07,3.847631);
   c15->SetFillColor(0);
   c15->SetBorderMode(0);
   c15->SetBorderSize(2);
   c15->SetLogy();
   c15->SetBottomMargin(0.12);
   c15->SetFrameBorderMode(0);
   c15->SetFrameBorderMode(0);
   
   TH1F *Npe_LPMT_nueCC__1 = new TH1F("Npe_LPMT_nueCC__1","",12,0,3e+07);
   Npe_LPMT_nueCC__1->SetBinContent(1,1255);
   Npe_LPMT_nueCC__1->SetBinContent(2,236);
   Npe_LPMT_nueCC__1->SetBinContent(3,75);
   Npe_LPMT_nueCC__1->SetBinContent(4,42);
   Npe_LPMT_nueCC__1->SetBinContent(5,11);
   Npe_LPMT_nueCC__1->SetBinContent(6,16);
   Npe_LPMT_nueCC__1->SetBinContent(7,9);
   Npe_LPMT_nueCC__1->SetBinContent(8,2);
   Npe_LPMT_nueCC__1->SetBinContent(9,2);
   Npe_LPMT_nueCC__1->SetBinContent(10,1);
   Npe_LPMT_nueCC__1->SetBinContent(11,3);
   Npe_LPMT_nueCC__1->SetEntries(1652);
   Npe_LPMT_nueCC__1->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#3399ff");
   Npe_LPMT_nueCC__1->SetFillColor(ci);
   Npe_LPMT_nueCC__1->SetFillStyle(3002);

   ci = TColor::GetColor("#3399ff");
   Npe_LPMT_nueCC__1->SetLineColor(ci);
   Npe_LPMT_nueCC__1->SetLineWidth(5);
   Npe_LPMT_nueCC__1->GetXaxis()->SetTitle("NPE_{LPMT}");
   Npe_LPMT_nueCC__1->GetXaxis()->SetLabelFont(42);
   Npe_LPMT_nueCC__1->GetXaxis()->SetLabelSize(0.05);
   Npe_LPMT_nueCC__1->GetXaxis()->SetTitleSize(0.05);
   Npe_LPMT_nueCC__1->GetXaxis()->SetTitleFont(42);
   Npe_LPMT_nueCC__1->GetYaxis()->SetTitle("entries");
   Npe_LPMT_nueCC__1->GetYaxis()->SetLabelFont(42);
   Npe_LPMT_nueCC__1->GetYaxis()->SetLabelSize(0.05);
   Npe_LPMT_nueCC__1->GetYaxis()->SetTitleSize(0.035);
   Npe_LPMT_nueCC__1->GetYaxis()->SetTitleOffset(1.2);
   Npe_LPMT_nueCC__1->GetYaxis()->SetTitleFont(42);
   Npe_LPMT_nueCC__1->GetZaxis()->SetLabelFont(42);
   Npe_LPMT_nueCC__1->GetZaxis()->SetLabelSize(0.035);
   Npe_LPMT_nueCC__1->GetZaxis()->SetTitleSize(0.035);
   Npe_LPMT_nueCC__1->GetZaxis()->SetTitleFont(42);
   Npe_LPMT_nueCC__1->Draw("");
   
   TH1F *Npe_LPMT_nueCC_cut__2 = new TH1F("Npe_LPMT_nueCC_cut__2","",12,0,3e+07);
   Npe_LPMT_nueCC_cut__2->SetBinContent(1,697);
   Npe_LPMT_nueCC_cut__2->SetBinContent(2,101);
   Npe_LPMT_nueCC_cut__2->SetBinContent(3,29);
   Npe_LPMT_nueCC_cut__2->SetBinContent(4,20);
   Npe_LPMT_nueCC_cut__2->SetBinContent(5,2);
   Npe_LPMT_nueCC_cut__2->SetBinContent(6,7);
   Npe_LPMT_nueCC_cut__2->SetBinContent(7,2);
   Npe_LPMT_nueCC_cut__2->SetBinContent(11,1);
   Npe_LPMT_nueCC_cut__2->SetEntries(859);
   Npe_LPMT_nueCC_cut__2->SetStats(0);

   ci = TColor::GetColor("#ff0000");
   Npe_LPMT_nueCC_cut__2->SetFillColor(ci);
   Npe_LPMT_nueCC_cut__2->SetFillStyle(3002);

   ci = TColor::GetColor("#ff0000");
   Npe_LPMT_nueCC_cut__2->SetLineColor(ci);
   Npe_LPMT_nueCC_cut__2->SetLineWidth(5);
   Npe_LPMT_nueCC_cut__2->GetXaxis()->SetTitle("NPE_{LPMT}");
   Npe_LPMT_nueCC_cut__2->GetXaxis()->SetLabelFont(42);
   Npe_LPMT_nueCC_cut__2->GetXaxis()->SetLabelSize(0.035);
   Npe_LPMT_nueCC_cut__2->GetXaxis()->SetTitleSize(0.035);
   Npe_LPMT_nueCC_cut__2->GetXaxis()->SetTitleFont(42);
   Npe_LPMT_nueCC_cut__2->GetYaxis()->SetLabelFont(42);
   Npe_LPMT_nueCC_cut__2->GetYaxis()->SetLabelSize(0.035);
   Npe_LPMT_nueCC_cut__2->GetYaxis()->SetTitleSize(0.035);
   Npe_LPMT_nueCC_cut__2->GetYaxis()->SetTitleOffset(0);
   Npe_LPMT_nueCC_cut__2->GetYaxis()->SetTitleFont(42);
   Npe_LPMT_nueCC_cut__2->GetZaxis()->SetLabelFont(42);
   Npe_LPMT_nueCC_cut__2->GetZaxis()->SetLabelSize(0.035);
   Npe_LPMT_nueCC_cut__2->GetZaxis()->SetTitleSize(0.035);
   Npe_LPMT_nueCC_cut__2->GetZaxis()->SetTitleFont(42);
   Npe_LPMT_nueCC_cut__2->Draw("same");
   
   TH1F *Npe_LPMT_bkg1__3 = new TH1F("Npe_LPMT_bkg1__3","",12,0,3e+07);
   Npe_LPMT_bkg1__3->SetBinContent(1,145);
   Npe_LPMT_bkg1__3->SetBinContent(2,9);
   Npe_LPMT_bkg1__3->SetBinContent(3,2);
   Npe_LPMT_bkg1__3->SetBinContent(9,1);
   Npe_LPMT_bkg1__3->SetEntries(157);
   Npe_LPMT_bkg1__3->SetStats(0);

   ci = TColor::GetColor("#006600");
   Npe_LPMT_bkg1__3->SetFillColor(ci);
   Npe_LPMT_bkg1__3->SetFillStyle(3002);

   ci = TColor::GetColor("#006600");
   Npe_LPMT_bkg1__3->SetLineColor(ci);
   Npe_LPMT_bkg1__3->SetLineWidth(5);
   Npe_LPMT_bkg1__3->GetXaxis()->SetTitle("NPE_{LPMT}");
   Npe_LPMT_bkg1__3->GetXaxis()->SetLabelFont(42);
   Npe_LPMT_bkg1__3->GetXaxis()->SetLabelSize(0.035);
   Npe_LPMT_bkg1__3->GetXaxis()->SetTitleSize(0.035);
   Npe_LPMT_bkg1__3->GetXaxis()->SetTitleFont(42);
   Npe_LPMT_bkg1__3->GetYaxis()->SetLabelFont(42);
   Npe_LPMT_bkg1__3->GetYaxis()->SetLabelSize(0.035);
   Npe_LPMT_bkg1__3->GetYaxis()->SetTitleSize(0.035);
   Npe_LPMT_bkg1__3->GetYaxis()->SetTitleOffset(0);
   Npe_LPMT_bkg1__3->GetYaxis()->SetTitleFont(42);
   Npe_LPMT_bkg1__3->GetZaxis()->SetLabelFont(42);
   Npe_LPMT_bkg1__3->GetZaxis()->SetLabelSize(0.035);
   Npe_LPMT_bkg1__3->GetZaxis()->SetTitleSize(0.035);
   Npe_LPMT_bkg1__3->GetZaxis()->SetTitleFont(42);
   Npe_LPMT_bkg1__3->Draw("same");
   
   TLegend *leg = new TLegend(0.65,0.6,0.9,0.9,NULL,"brNDC");
   leg->SetBorderSize(1);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("Npe_LPMT_nueCC","#nu_{e} CC","l");

   ci = TColor::GetColor("#3399ff");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(5);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Npe_LPMT_nueCC_cut","#nu_{e} CC sel.","l");

   ci = TColor::GetColor("#ff0000");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(5);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Npe_LPMT_bkg1","res. bkg","l");

   ci = TColor::GetColor("#006600");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(5);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   c15->Modified();
   c15->cd();
   c15->SetSelected(c15);
}
