void LOGDATA_NPE_LPMT_eff_0-20GeV_16volcut_1m_less75nscut_withfidcut()
{
//=========Macro generated from canvas: c7/
//=========  (Tue Jul  9 16:34:53 2019) by ROOT version 6.12/06
   TCanvas *c7 = new TCanvas("c7", "",1120,375,800,600);
   gStyle->SetOptStat(0);
   c7->Range(4.725,0.4272624,7.475,2.691493);
   c7->SetFillColor(0);
   c7->SetBorderMode(0);
   c7->SetBorderSize(2);
   c7->SetLogy();
   c7->SetBottomMargin(0.12);
   c7->SetFrameBorderMode(0);
   c7->SetFrameBorderMode(0);
   
   TH1F *Lognpe_LPMT_allcutsNue__7 = new TH1F("Lognpe_LPMT_allcutsNue__7","",12,5,7.2);
   Lognpe_LPMT_allcutsNue__7->SetBinContent(1,20);
   Lognpe_LPMT_allcutsNue__7->SetBinContent(2,67);
   Lognpe_LPMT_allcutsNue__7->SetBinContent(3,100);
   Lognpe_LPMT_allcutsNue__7->SetBinContent(4,149);
   Lognpe_LPMT_allcutsNue__7->SetBinContent(5,154);
   Lognpe_LPMT_allcutsNue__7->SetBinContent(6,149);
   Lognpe_LPMT_allcutsNue__7->SetBinContent(7,126);
   Lognpe_LPMT_allcutsNue__7->SetBinContent(8,113);
   Lognpe_LPMT_allcutsNue__7->SetBinContent(9,66);
   Lognpe_LPMT_allcutsNue__7->SetBinContent(10,33);
   Lognpe_LPMT_allcutsNue__7->SetBinContent(11,26);
   Lognpe_LPMT_allcutsNue__7->SetBinContent(12,10);
   Lognpe_LPMT_allcutsNue__7->SetBinContent(13,3);
   Lognpe_LPMT_allcutsNue__7->SetEntries(1016);
   Lognpe_LPMT_allcutsNue__7->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#3399ff");
   Lognpe_LPMT_allcutsNue__7->SetFillColor(ci);
   Lognpe_LPMT_allcutsNue__7->SetFillStyle(3002);

   ci = TColor::GetColor("#3399ff");
   Lognpe_LPMT_allcutsNue__7->SetLineColor(ci);
   Lognpe_LPMT_allcutsNue__7->SetLineWidth(5);
   Lognpe_LPMT_allcutsNue__7->GetXaxis()->SetTitle("log_{10} (NPE_{LPMT})");
   Lognpe_LPMT_allcutsNue__7->GetXaxis()->SetLabelFont(42);
   Lognpe_LPMT_allcutsNue__7->GetXaxis()->SetLabelSize(0.05);
   Lognpe_LPMT_allcutsNue__7->GetXaxis()->SetTitleSize(0.05);
   Lognpe_LPMT_allcutsNue__7->GetXaxis()->SetTitleFont(42);
   Lognpe_LPMT_allcutsNue__7->GetYaxis()->SetTitle("entries");
   Lognpe_LPMT_allcutsNue__7->GetYaxis()->SetLabelFont(42);
   Lognpe_LPMT_allcutsNue__7->GetYaxis()->SetLabelSize(0.05);
   Lognpe_LPMT_allcutsNue__7->GetYaxis()->SetTitleSize(0.035);
   Lognpe_LPMT_allcutsNue__7->GetYaxis()->SetTitleOffset(1.2);
   Lognpe_LPMT_allcutsNue__7->GetYaxis()->SetTitleFont(42);
   Lognpe_LPMT_allcutsNue__7->GetZaxis()->SetLabelFont(42);
   Lognpe_LPMT_allcutsNue__7->GetZaxis()->SetLabelSize(0.035);
   Lognpe_LPMT_allcutsNue__7->GetZaxis()->SetTitleSize(0.035);
   Lognpe_LPMT_allcutsNue__7->GetZaxis()->SetTitleFont(42);
   Lognpe_LPMT_allcutsNue__7->Draw("");
   
   TH1F *Lognpe_LPMT_allcuts_nue__8 = new TH1F("Lognpe_LPMT_allcuts_nue__8","",12,5,7.2);
   Lognpe_LPMT_allcuts_nue__8->SetBinContent(1,20);
   Lognpe_LPMT_allcuts_nue__8->SetBinContent(2,67);
   Lognpe_LPMT_allcuts_nue__8->SetBinContent(3,93);
   Lognpe_LPMT_allcuts_nue__8->SetBinContent(4,120);
   Lognpe_LPMT_allcuts_nue__8->SetBinContent(5,131);
   Lognpe_LPMT_allcuts_nue__8->SetBinContent(6,133);
   Lognpe_LPMT_allcuts_nue__8->SetBinContent(7,115);
   Lognpe_LPMT_allcuts_nue__8->SetBinContent(8,101);
   Lognpe_LPMT_allcuts_nue__8->SetBinContent(9,63);
   Lognpe_LPMT_allcuts_nue__8->SetBinContent(10,32);
   Lognpe_LPMT_allcuts_nue__8->SetBinContent(11,25);
   Lognpe_LPMT_allcuts_nue__8->SetBinContent(12,10);
   Lognpe_LPMT_allcuts_nue__8->SetBinContent(13,2);
   Lognpe_LPMT_allcuts_nue__8->SetEntries(912);
   Lognpe_LPMT_allcuts_nue__8->SetStats(0);

   ci = TColor::GetColor("#ff0000");
   Lognpe_LPMT_allcuts_nue__8->SetFillColor(ci);
   Lognpe_LPMT_allcuts_nue__8->SetFillStyle(3002);

   ci = TColor::GetColor("#ff0000");
   Lognpe_LPMT_allcuts_nue__8->SetLineColor(ci);
   Lognpe_LPMT_allcuts_nue__8->SetLineWidth(5);
   Lognpe_LPMT_allcuts_nue__8->GetXaxis()->SetTitle("log_{10} (NPE_{LPMT})");
   Lognpe_LPMT_allcuts_nue__8->GetXaxis()->SetLabelFont(42);
   Lognpe_LPMT_allcuts_nue__8->GetXaxis()->SetLabelSize(0.035);
   Lognpe_LPMT_allcuts_nue__8->GetXaxis()->SetTitleSize(0.035);
   Lognpe_LPMT_allcuts_nue__8->GetXaxis()->SetTitleFont(42);
   Lognpe_LPMT_allcuts_nue__8->GetYaxis()->SetLabelFont(42);
   Lognpe_LPMT_allcuts_nue__8->GetYaxis()->SetLabelSize(0.035);
   Lognpe_LPMT_allcuts_nue__8->GetYaxis()->SetTitleSize(0.035);
   Lognpe_LPMT_allcuts_nue__8->GetYaxis()->SetTitleOffset(0);
   Lognpe_LPMT_allcuts_nue__8->GetYaxis()->SetTitleFont(42);
   Lognpe_LPMT_allcuts_nue__8->GetZaxis()->SetLabelFont(42);
   Lognpe_LPMT_allcuts_nue__8->GetZaxis()->SetLabelSize(0.035);
   Lognpe_LPMT_allcuts_nue__8->GetZaxis()->SetTitleSize(0.035);
   Lognpe_LPMT_allcuts_nue__8->GetZaxis()->SetTitleFont(42);
   Lognpe_LPMT_allcuts_nue__8->Draw("same");
   
   TH1F *Lognpe_LPMT_allcuts_bkg1__9 = new TH1F("Lognpe_LPMT_allcuts_bkg1__9","",12,5,7.2);
   Lognpe_LPMT_allcuts_bkg1__9->SetBinContent(3,7);
   Lognpe_LPMT_allcuts_bkg1__9->SetBinContent(4,29);
   Lognpe_LPMT_allcuts_bkg1__9->SetBinContent(5,23);
   Lognpe_LPMT_allcuts_bkg1__9->SetBinContent(6,16);
   Lognpe_LPMT_allcuts_bkg1__9->SetBinContent(7,11);
   Lognpe_LPMT_allcuts_bkg1__9->SetBinContent(8,12);
   Lognpe_LPMT_allcuts_bkg1__9->SetBinContent(9,3);
   Lognpe_LPMT_allcuts_bkg1__9->SetBinContent(10,1);
   Lognpe_LPMT_allcuts_bkg1__9->SetBinContent(11,1);
   Lognpe_LPMT_allcuts_bkg1__9->SetBinContent(13,1);
   Lognpe_LPMT_allcuts_bkg1__9->SetEntries(104);
   Lognpe_LPMT_allcuts_bkg1__9->SetStats(0);

   ci = TColor::GetColor("#006600");
   Lognpe_LPMT_allcuts_bkg1__9->SetFillColor(ci);
   Lognpe_LPMT_allcuts_bkg1__9->SetFillStyle(3002);

   ci = TColor::GetColor("#006600");
   Lognpe_LPMT_allcuts_bkg1__9->SetLineColor(ci);
   Lognpe_LPMT_allcuts_bkg1__9->SetLineWidth(5);
   Lognpe_LPMT_allcuts_bkg1__9->GetXaxis()->SetTitle("log_{10} (NPE_{LPMT})");
   Lognpe_LPMT_allcuts_bkg1__9->GetXaxis()->SetLabelFont(42);
   Lognpe_LPMT_allcuts_bkg1__9->GetXaxis()->SetLabelSize(0.035);
   Lognpe_LPMT_allcuts_bkg1__9->GetXaxis()->SetTitleSize(0.035);
   Lognpe_LPMT_allcuts_bkg1__9->GetXaxis()->SetTitleFont(42);
   Lognpe_LPMT_allcuts_bkg1__9->GetYaxis()->SetLabelFont(42);
   Lognpe_LPMT_allcuts_bkg1__9->GetYaxis()->SetLabelSize(0.035);
   Lognpe_LPMT_allcuts_bkg1__9->GetYaxis()->SetTitleSize(0.035);
   Lognpe_LPMT_allcuts_bkg1__9->GetYaxis()->SetTitleOffset(0);
   Lognpe_LPMT_allcuts_bkg1__9->GetYaxis()->SetTitleFont(42);
   Lognpe_LPMT_allcuts_bkg1__9->GetZaxis()->SetLabelFont(42);
   Lognpe_LPMT_allcuts_bkg1__9->GetZaxis()->SetLabelSize(0.035);
   Lognpe_LPMT_allcuts_bkg1__9->GetZaxis()->SetTitleSize(0.035);
   Lognpe_LPMT_allcuts_bkg1__9->GetZaxis()->SetTitleFont(42);
   Lognpe_LPMT_allcuts_bkg1__9->Draw("same");
   
   TLegend *leg = new TLegend(0.7,0.65,0.9,0.9,NULL,"brNDC");
   leg->SetBorderSize(1);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("Lognpe_LPMT_allcutsNue","sel.","l");

   ci = TColor::GetColor("#3399ff");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(5);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Lognpe_LPMT_allcuts_nue","#nu_{e} sel.","l");

   ci = TColor::GetColor("#ff0000");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(5);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Lognpe_LPMT_allcuts_bkg1","res. bkg","l");

   ci = TColor::GetColor("#006600");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(5);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   c7->Modified();
   c7->cd();
   c7->SetSelected(c7);
}
