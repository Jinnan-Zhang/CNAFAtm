void logEv_eff_0-20GeV_16volcut_1m_over95nscut()
{
//=========Macro generated from canvas: c18/
//=========  (Thu Jun 20 17:55:02 2019) by ROOT version 6.12/06
   TCanvas *c18 = new TCanvas("c18", "",231,221,800,600);
   gStyle->SetOptStat(0);
   c18->Range(2.265,3.232813,4.415,4.970225);
   c18->SetFillColor(0);
   c18->SetBorderMode(0);
   c18->SetBorderSize(2);
   c18->SetLogy();
   c18->SetBottomMargin(0.12);
   c18->SetFrameBorderMode(0);
   c18->SetFrameBorderMode(0);
   
   TH1F *logEv_numuCC__10 = new TH1F("logEv_numuCC__10","",10,2.48,4.2);
   logEv_numuCC__10->SetBinContent(0,18252);
   logEv_numuCC__10->SetBinContent(1,22685);
   logEv_numuCC__10->SetBinContent(2,28670);
   logEv_numuCC__10->SetBinContent(3,33032);
   logEv_numuCC__10->SetBinContent(4,31185);
   logEv_numuCC__10->SetBinContent(5,27433);
   logEv_numuCC__10->SetBinContent(6,21764);
   logEv_numuCC__10->SetBinContent(7,15777);
   logEv_numuCC__10->SetBinContent(8,11670);
   logEv_numuCC__10->SetBinContent(9,7913);
   logEv_numuCC__10->SetBinContent(10,5525);
   logEv_numuCC__10->SetBinContent(11,2291);
   logEv_numuCC__10->SetEntries(226197);
   logEv_numuCC__10->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#ffcc00");
   logEv_numuCC__10->SetFillColor(ci);
   logEv_numuCC__10->SetFillStyle(3002);

   ci = TColor::GetColor("#ffcc00");
   logEv_numuCC__10->SetLineColor(ci);
   logEv_numuCC__10->SetLineWidth(5);
   logEv_numuCC__10->GetXaxis()->SetTitle("log_{10}(E_{#nu} [MeV])");
   logEv_numuCC__10->GetXaxis()->SetLabelFont(42);
   logEv_numuCC__10->GetXaxis()->SetTitleSize(0.05);
   logEv_numuCC__10->GetXaxis()->SetTitleFont(42);
   logEv_numuCC__10->GetYaxis()->SetTitle("entries");
   logEv_numuCC__10->GetYaxis()->SetLabelFont(42);
   logEv_numuCC__10->GetYaxis()->SetLabelSize(0.05);
   logEv_numuCC__10->GetYaxis()->SetTitleSize(0.035);
   logEv_numuCC__10->GetYaxis()->SetTitleOffset(1.2);
   logEv_numuCC__10->GetYaxis()->SetTitleFont(42);
   logEv_numuCC__10->GetZaxis()->SetLabelFont(42);
   logEv_numuCC__10->GetZaxis()->SetLabelSize(0.035);
   logEv_numuCC__10->GetZaxis()->SetTitleSize(0.035);
   logEv_numuCC__10->GetZaxis()->SetTitleFont(42);
   logEv_numuCC__10->Draw("");
   
   TH1F *logEv_numuCC_fidcut__11 = new TH1F("logEv_numuCC_fidcut__11","",10,2.48,4.2);
   logEv_numuCC_fidcut__11->SetBinContent(1,81);
   logEv_numuCC_fidcut__11->SetBinContent(2,13554);
   logEv_numuCC_fidcut__11->SetBinContent(3,23934);
   logEv_numuCC_fidcut__11->SetBinContent(4,22640);
   logEv_numuCC_fidcut__11->SetBinContent(5,19624);
   logEv_numuCC_fidcut__11->SetBinContent(6,14116);
   logEv_numuCC_fidcut__11->SetBinContent(7,8156);
   logEv_numuCC_fidcut__11->SetBinContent(8,4257);
   logEv_numuCC_fidcut__11->SetBinContent(9,1730);
   logEv_numuCC_fidcut__11->SetBinContent(10,739);
   logEv_numuCC_fidcut__11->SetBinContent(11,210);
   logEv_numuCC_fidcut__11->SetEntries(109041);
   logEv_numuCC_fidcut__11->SetStats(0);

   ci = TColor::GetColor("#3399ff");
   logEv_numuCC_fidcut__11->SetFillColor(ci);
   logEv_numuCC_fidcut__11->SetFillStyle(3002);

   ci = TColor::GetColor("#3399ff");
   logEv_numuCC_fidcut__11->SetLineColor(ci);
   logEv_numuCC_fidcut__11->SetLineWidth(5);
   logEv_numuCC_fidcut__11->GetXaxis()->SetLabelFont(42);
   logEv_numuCC_fidcut__11->GetXaxis()->SetLabelSize(0.035);
   logEv_numuCC_fidcut__11->GetXaxis()->SetTitleSize(0.035);
   logEv_numuCC_fidcut__11->GetXaxis()->SetTitleFont(42);
   logEv_numuCC_fidcut__11->GetYaxis()->SetLabelFont(42);
   logEv_numuCC_fidcut__11->GetYaxis()->SetLabelSize(0.035);
   logEv_numuCC_fidcut__11->GetYaxis()->SetTitleSize(0.035);
   logEv_numuCC_fidcut__11->GetYaxis()->SetTitleOffset(0);
   logEv_numuCC_fidcut__11->GetYaxis()->SetTitleFont(42);
   logEv_numuCC_fidcut__11->GetZaxis()->SetLabelFont(42);
   logEv_numuCC_fidcut__11->GetZaxis()->SetLabelSize(0.035);
   logEv_numuCC_fidcut__11->GetZaxis()->SetTitleSize(0.035);
   logEv_numuCC_fidcut__11->GetZaxis()->SetTitleFont(42);
   logEv_numuCC_fidcut__11->Draw("same");
   
   TH1F *logEv_numuCC_timecut__12 = new TH1F("logEv_numuCC_timecut__12","",10,2.48,4.2);
   logEv_numuCC_timecut__12->SetBinContent(1,79);
   logEv_numuCC_timecut__12->SetBinContent(2,12979);
   logEv_numuCC_timecut__12->SetBinContent(3,22629);
   logEv_numuCC_timecut__12->SetBinContent(4,21110);
   logEv_numuCC_timecut__12->SetBinContent(5,17868);
   logEv_numuCC_timecut__12->SetBinContent(6,12715);
   logEv_numuCC_timecut__12->SetBinContent(7,7166);
   logEv_numuCC_timecut__12->SetBinContent(8,3614);
   logEv_numuCC_timecut__12->SetBinContent(9,1354);
   logEv_numuCC_timecut__12->SetBinContent(10,580);
   logEv_numuCC_timecut__12->SetBinContent(11,151);
   logEv_numuCC_timecut__12->SetEntries(100245);
   logEv_numuCC_timecut__12->SetStats(0);

   ci = TColor::GetColor("#ff0000");
   logEv_numuCC_timecut__12->SetFillColor(ci);
   logEv_numuCC_timecut__12->SetFillStyle(3002);

   ci = TColor::GetColor("#ff0000");
   logEv_numuCC_timecut__12->SetLineColor(ci);
   logEv_numuCC_timecut__12->SetLineWidth(5);
   logEv_numuCC_timecut__12->GetXaxis()->SetTitle("log_{10}(E_{#nu} [MeV])");
   logEv_numuCC_timecut__12->GetXaxis()->SetLabelFont(42);
   logEv_numuCC_timecut__12->GetXaxis()->SetLabelSize(0.035);
   logEv_numuCC_timecut__12->GetXaxis()->SetTitleSize(0.035);
   logEv_numuCC_timecut__12->GetXaxis()->SetTitleFont(42);
   logEv_numuCC_timecut__12->GetYaxis()->SetLabelFont(42);
   logEv_numuCC_timecut__12->GetYaxis()->SetLabelSize(0.035);
   logEv_numuCC_timecut__12->GetYaxis()->SetTitleSize(0.035);
   logEv_numuCC_timecut__12->GetYaxis()->SetTitleOffset(0);
   logEv_numuCC_timecut__12->GetYaxis()->SetTitleFont(42);
   logEv_numuCC_timecut__12->GetZaxis()->SetLabelFont(42);
   logEv_numuCC_timecut__12->GetZaxis()->SetLabelSize(0.035);
   logEv_numuCC_timecut__12->GetZaxis()->SetTitleSize(0.035);
   logEv_numuCC_timecut__12->GetZaxis()->SetTitleFont(42);
   logEv_numuCC_timecut__12->Draw("same");
   
   TH1F *logEv_bkg2__13 = new TH1F("logEv_bkg2__13","",10,2.48,4.2);
   logEv_bkg2__13->SetBinContent(0,1);
   logEv_bkg2__13->SetBinContent(1,16);
   logEv_bkg2__13->SetBinContent(2,865);
   logEv_bkg2__13->SetBinContent(3,2678);
   logEv_bkg2__13->SetBinContent(4,4471);
   logEv_bkg2__13->SetBinContent(5,4754);
   logEv_bkg2__13->SetBinContent(6,4109);
   logEv_bkg2__13->SetBinContent(7,3204);
   logEv_bkg2__13->SetBinContent(8,2531);
   logEv_bkg2__13->SetBinContent(9,1699);
   logEv_bkg2__13->SetBinContent(10,1270);
   logEv_bkg2__13->SetBinContent(11,534);
   logEv_bkg2__13->SetEntries(26132);
   logEv_bkg2__13->SetStats(0);

   ci = TColor::GetColor("#006600");
   logEv_bkg2__13->SetFillColor(ci);
   logEv_bkg2__13->SetFillStyle(3002);

   ci = TColor::GetColor("#006600");
   logEv_bkg2__13->SetLineColor(ci);
   logEv_bkg2__13->SetLineWidth(5);
   logEv_bkg2__13->GetXaxis()->SetTitle("log_{10}(E_{#nu} [MeV])");
   logEv_bkg2__13->GetXaxis()->SetLabelFont(42);
   logEv_bkg2__13->GetXaxis()->SetLabelSize(0.035);
   logEv_bkg2__13->GetXaxis()->SetTitleSize(0.035);
   logEv_bkg2__13->GetXaxis()->SetTitleFont(42);
   logEv_bkg2__13->GetYaxis()->SetLabelFont(42);
   logEv_bkg2__13->GetYaxis()->SetLabelSize(0.035);
   logEv_bkg2__13->GetYaxis()->SetTitleSize(0.035);
   logEv_bkg2__13->GetYaxis()->SetTitleOffset(0);
   logEv_bkg2__13->GetYaxis()->SetTitleFont(42);
   logEv_bkg2__13->GetZaxis()->SetLabelFont(42);
   logEv_bkg2__13->GetZaxis()->SetLabelSize(0.035);
   logEv_bkg2__13->GetZaxis()->SetTitleSize(0.035);
   logEv_bkg2__13->GetZaxis()->SetTitleFont(42);
   logEv_bkg2__13->Draw("same");
   
   TLegend *leg = new TLegend(0.68,0.6,0.9,0.9,NULL,"brNDC");
   leg->SetBorderSize(1);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("logEv_numuCC","#nu_{#mu}^{CC} FC","l");

   ci = TColor::GetColor("#ffcc00");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(5);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("logEv_numuCC_fidcut","#nu_{#mu}^{CC} FC fid.","l");

   ci = TColor::GetColor("#3399ff");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(5);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("logEv_numuCC_timecut","#nu_{#mu}^{CC} FC sel.","l");

   ci = TColor::GetColor("#ff0000");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(5);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("logEv_bkg2","res. bkg","l");

   ci = TColor::GetColor("#006600");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(5);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   c18->Modified();
   c18->cd();
   c18->SetSelected(c18);
}
