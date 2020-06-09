void LOGDATA_NPE_LPMT_eff_0-20GeV_16volcut_1m_over95nscut_withfidcut()
{
//=========Macro generated from canvas: c17/
//=========  (Tue Jul  9 16:34:54 2019) by ROOT version 6.12/06
   TCanvas *c17 = new TCanvas("c17", "",65,375,800,600);
   gStyle->SetOptStat(0);
   c17->Range(5.5125,0.7387057,7.3875,3.092735);
   c17->SetFillColor(0);
   c17->SetBorderMode(0);
   c17->SetBorderSize(2);
   c17->SetLogy();
   c17->SetBottomMargin(0.12);
   c17->SetFrameBorderMode(0);
   c17->SetFrameBorderMode(0);
   
   TH1F *Lognpe_LPMT_allcutsNumu__10 = new TH1F("Lognpe_LPMT_allcutsNumu__10","",12,5.7,7.2);
   Lognpe_LPMT_allcutsNumu__10->SetBinContent(0,2);
   Lognpe_LPMT_allcutsNumu__10->SetBinContent(1,330);
   Lognpe_LPMT_allcutsNumu__10->SetBinContent(2,341);
   Lognpe_LPMT_allcutsNumu__10->SetBinContent(3,380);
   Lognpe_LPMT_allcutsNumu__10->SetBinContent(4,337);
   Lognpe_LPMT_allcutsNumu__10->SetBinContent(5,321);
   Lognpe_LPMT_allcutsNumu__10->SetBinContent(6,261);
   Lognpe_LPMT_allcutsNumu__10->SetBinContent(7,198);
   Lognpe_LPMT_allcutsNumu__10->SetBinContent(8,165);
   Lognpe_LPMT_allcutsNumu__10->SetBinContent(9,88);
   Lognpe_LPMT_allcutsNumu__10->SetBinContent(10,64);
   Lognpe_LPMT_allcutsNumu__10->SetBinContent(11,43);
   Lognpe_LPMT_allcutsNumu__10->SetBinContent(12,21);
   Lognpe_LPMT_allcutsNumu__10->SetBinContent(13,14);
   Lognpe_LPMT_allcutsNumu__10->SetEntries(2565);
   Lognpe_LPMT_allcutsNumu__10->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#3399ff");
   Lognpe_LPMT_allcutsNumu__10->SetFillColor(ci);
   Lognpe_LPMT_allcutsNumu__10->SetFillStyle(3002);

   ci = TColor::GetColor("#3399ff");
   Lognpe_LPMT_allcutsNumu__10->SetLineColor(ci);
   Lognpe_LPMT_allcutsNumu__10->SetLineWidth(5);
   Lognpe_LPMT_allcutsNumu__10->GetXaxis()->SetTitle("log_{10} (NPE_{LPMT})");
   Lognpe_LPMT_allcutsNumu__10->GetXaxis()->SetLabelFont(42);
   Lognpe_LPMT_allcutsNumu__10->GetXaxis()->SetLabelSize(0.05);
   Lognpe_LPMT_allcutsNumu__10->GetXaxis()->SetTitleSize(0.05);
   Lognpe_LPMT_allcutsNumu__10->GetXaxis()->SetTitleFont(42);
   Lognpe_LPMT_allcutsNumu__10->GetYaxis()->SetTitle("entries");
   Lognpe_LPMT_allcutsNumu__10->GetYaxis()->SetLabelFont(42);
   Lognpe_LPMT_allcutsNumu__10->GetYaxis()->SetLabelSize(0.05);
   Lognpe_LPMT_allcutsNumu__10->GetYaxis()->SetTitleSize(0.035);
   Lognpe_LPMT_allcutsNumu__10->GetYaxis()->SetTitleOffset(1.2);
   Lognpe_LPMT_allcutsNumu__10->GetYaxis()->SetTitleFont(42);
   Lognpe_LPMT_allcutsNumu__10->GetZaxis()->SetLabelFont(42);
   Lognpe_LPMT_allcutsNumu__10->GetZaxis()->SetLabelSize(0.035);
   Lognpe_LPMT_allcutsNumu__10->GetZaxis()->SetTitleSize(0.035);
   Lognpe_LPMT_allcutsNumu__10->GetZaxis()->SetTitleFont(42);
   Lognpe_LPMT_allcutsNumu__10->Draw("");
   
   TH1F *Lognpe_LPMT_allcuts_numu__11 = new TH1F("Lognpe_LPMT_allcuts_numu__11","",12,5.7,7.2);
   Lognpe_LPMT_allcuts_numu__11->SetBinContent(0,2);
   Lognpe_LPMT_allcuts_numu__11->SetBinContent(1,298);
   Lognpe_LPMT_allcuts_numu__11->SetBinContent(2,310);
   Lognpe_LPMT_allcuts_numu__11->SetBinContent(3,335);
   Lognpe_LPMT_allcuts_numu__11->SetBinContent(4,305);
   Lognpe_LPMT_allcuts_numu__11->SetBinContent(5,286);
   Lognpe_LPMT_allcuts_numu__11->SetBinContent(6,239);
   Lognpe_LPMT_allcuts_numu__11->SetBinContent(7,176);
   Lognpe_LPMT_allcuts_numu__11->SetBinContent(8,144);
   Lognpe_LPMT_allcuts_numu__11->SetBinContent(9,74);
   Lognpe_LPMT_allcuts_numu__11->SetBinContent(10,51);
   Lognpe_LPMT_allcuts_numu__11->SetBinContent(11,39);
   Lognpe_LPMT_allcuts_numu__11->SetBinContent(12,14);
   Lognpe_LPMT_allcuts_numu__11->SetBinContent(13,10);
   Lognpe_LPMT_allcuts_numu__11->SetEntries(2283);
   Lognpe_LPMT_allcuts_numu__11->SetStats(0);

   ci = TColor::GetColor("#ff0000");
   Lognpe_LPMT_allcuts_numu__11->SetFillColor(ci);
   Lognpe_LPMT_allcuts_numu__11->SetFillStyle(3002);

   ci = TColor::GetColor("#ff0000");
   Lognpe_LPMT_allcuts_numu__11->SetLineColor(ci);
   Lognpe_LPMT_allcuts_numu__11->SetLineWidth(5);
   Lognpe_LPMT_allcuts_numu__11->GetXaxis()->SetTitle("log_{10} (NPE_{LPMT})");
   Lognpe_LPMT_allcuts_numu__11->GetXaxis()->SetLabelFont(42);
   Lognpe_LPMT_allcuts_numu__11->GetXaxis()->SetLabelSize(0.035);
   Lognpe_LPMT_allcuts_numu__11->GetXaxis()->SetTitleSize(0.035);
   Lognpe_LPMT_allcuts_numu__11->GetXaxis()->SetTitleFont(42);
   Lognpe_LPMT_allcuts_numu__11->GetYaxis()->SetLabelFont(42);
   Lognpe_LPMT_allcuts_numu__11->GetYaxis()->SetLabelSize(0.035);
   Lognpe_LPMT_allcuts_numu__11->GetYaxis()->SetTitleSize(0.035);
   Lognpe_LPMT_allcuts_numu__11->GetYaxis()->SetTitleOffset(0);
   Lognpe_LPMT_allcuts_numu__11->GetYaxis()->SetTitleFont(42);
   Lognpe_LPMT_allcuts_numu__11->GetZaxis()->SetLabelFont(42);
   Lognpe_LPMT_allcuts_numu__11->GetZaxis()->SetLabelSize(0.035);
   Lognpe_LPMT_allcuts_numu__11->GetZaxis()->SetTitleSize(0.035);
   Lognpe_LPMT_allcuts_numu__11->GetZaxis()->SetTitleFont(42);
   Lognpe_LPMT_allcuts_numu__11->Draw("same");
   
   TH1F *Lognpe_LPMT_allcuts_bkg2__12 = new TH1F("Lognpe_LPMT_allcuts_bkg2__12","",12,5.7,7.2);
   Lognpe_LPMT_allcuts_bkg2__12->SetBinContent(1,32);
   Lognpe_LPMT_allcuts_bkg2__12->SetBinContent(2,31);
   Lognpe_LPMT_allcuts_bkg2__12->SetBinContent(3,45);
   Lognpe_LPMT_allcuts_bkg2__12->SetBinContent(4,32);
   Lognpe_LPMT_allcuts_bkg2__12->SetBinContent(5,35);
   Lognpe_LPMT_allcuts_bkg2__12->SetBinContent(6,22);
   Lognpe_LPMT_allcuts_bkg2__12->SetBinContent(7,22);
   Lognpe_LPMT_allcuts_bkg2__12->SetBinContent(8,21);
   Lognpe_LPMT_allcuts_bkg2__12->SetBinContent(9,14);
   Lognpe_LPMT_allcuts_bkg2__12->SetBinContent(10,13);
   Lognpe_LPMT_allcuts_bkg2__12->SetBinContent(11,4);
   Lognpe_LPMT_allcuts_bkg2__12->SetBinContent(12,7);
   Lognpe_LPMT_allcuts_bkg2__12->SetBinContent(13,4);
   Lognpe_LPMT_allcuts_bkg2__12->SetEntries(282);
   Lognpe_LPMT_allcuts_bkg2__12->SetStats(0);

   ci = TColor::GetColor("#006600");
   Lognpe_LPMT_allcuts_bkg2__12->SetFillColor(ci);
   Lognpe_LPMT_allcuts_bkg2__12->SetFillStyle(3002);

   ci = TColor::GetColor("#006600");
   Lognpe_LPMT_allcuts_bkg2__12->SetLineColor(ci);
   Lognpe_LPMT_allcuts_bkg2__12->SetLineWidth(5);
   Lognpe_LPMT_allcuts_bkg2__12->GetXaxis()->SetTitle("log_{10} (NPE_{LPMT})");
   Lognpe_LPMT_allcuts_bkg2__12->GetXaxis()->SetLabelFont(42);
   Lognpe_LPMT_allcuts_bkg2__12->GetXaxis()->SetLabelSize(0.035);
   Lognpe_LPMT_allcuts_bkg2__12->GetXaxis()->SetTitleSize(0.035);
   Lognpe_LPMT_allcuts_bkg2__12->GetXaxis()->SetTitleFont(42);
   Lognpe_LPMT_allcuts_bkg2__12->GetYaxis()->SetLabelFont(42);
   Lognpe_LPMT_allcuts_bkg2__12->GetYaxis()->SetLabelSize(0.035);
   Lognpe_LPMT_allcuts_bkg2__12->GetYaxis()->SetTitleSize(0.035);
   Lognpe_LPMT_allcuts_bkg2__12->GetYaxis()->SetTitleOffset(0);
   Lognpe_LPMT_allcuts_bkg2__12->GetYaxis()->SetTitleFont(42);
   Lognpe_LPMT_allcuts_bkg2__12->GetZaxis()->SetLabelFont(42);
   Lognpe_LPMT_allcuts_bkg2__12->GetZaxis()->SetLabelSize(0.035);
   Lognpe_LPMT_allcuts_bkg2__12->GetZaxis()->SetTitleSize(0.035);
   Lognpe_LPMT_allcuts_bkg2__12->GetZaxis()->SetTitleFont(42);
   Lognpe_LPMT_allcuts_bkg2__12->Draw("same");
   
   TLegend *leg = new TLegend(0.7,0.65,0.9,0.9,NULL,"brNDC");
   leg->SetBorderSize(1);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("Lognpe_LPMT_allcutsNumu","sel.","l");

   ci = TColor::GetColor("#3399ff");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(5);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Lognpe_LPMT_allcuts_numu","#nu_{#mu} sel.","l");

   ci = TColor::GetColor("#ff0000");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(5);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Lognpe_LPMT_allcuts_bkg2","res. bkg","l");

   ci = TColor::GetColor("#006600");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(5);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   c17->Modified();
   c17->cd();
   c17->SetSelected(c17);
}
