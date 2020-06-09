void logNPE_eff_0-20GeV_16volcut_1m_over95nscut()
{
//=========Macro generated from canvas: c118/
//=========  (Thu Jun 20 17:56:31 2019) by ROOT version 6.12/06
   TCanvas *c118 = new TCanvas("c118", "",307,297,800,600);
   gStyle->SetOptStat(0);
   c118->Range(5.5125,3.055984,7.3875,4.969097);
   c118->SetFillColor(0);
   c118->SetBorderMode(0);
   c118->SetBorderSize(2);
   c118->SetLogy();
   c118->SetBottomMargin(0.12);
   c118->SetFrameBorderMode(0);
   c118->SetFrameBorderMode(0);
   
   TH1F *logNPE_numuCC__19 = new TH1F("logNPE_numuCC__19","",8,5.7,7.2);
   logNPE_numuCC__19->SetBinContent(0,57916);
   logNPE_numuCC__19->SetBinContent(1,28512);
   logNPE_numuCC__19->SetBinContent(2,31640);
   logNPE_numuCC__19->SetBinContent(3,31083);
   logNPE_numuCC__19->SetBinContent(4,27278);
   logNPE_numuCC__19->SetBinContent(5,21340);
   logNPE_numuCC__19->SetBinContent(6,14535);
   logNPE_numuCC__19->SetBinContent(7,8762);
   logNPE_numuCC__19->SetBinContent(8,3860);
   logNPE_numuCC__19->SetBinContent(9,1271);
   logNPE_numuCC__19->SetEntries(226197);
   logNPE_numuCC__19->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#ffcc00");
   logNPE_numuCC__19->SetFillColor(ci);
   logNPE_numuCC__19->SetFillStyle(3002);

   ci = TColor::GetColor("#ffcc00");
   logNPE_numuCC__19->SetLineColor(ci);
   logNPE_numuCC__19->SetLineWidth(5);
   logNPE_numuCC__19->GetXaxis()->SetTitle("log_{10}(NPE_{LPMT})");
   logNPE_numuCC__19->GetXaxis()->SetLabelFont(42);
   logNPE_numuCC__19->GetXaxis()->SetTitleSize(0.05);
   logNPE_numuCC__19->GetXaxis()->SetTitleFont(42);
   logNPE_numuCC__19->GetYaxis()->SetTitle("entries");
   logNPE_numuCC__19->GetYaxis()->SetLabelFont(42);
   logNPE_numuCC__19->GetYaxis()->SetLabelSize(0.05);
   logNPE_numuCC__19->GetYaxis()->SetTitleSize(0.035);
   logNPE_numuCC__19->GetYaxis()->SetTitleOffset(1.2);
   logNPE_numuCC__19->GetYaxis()->SetTitleFont(42);
   logNPE_numuCC__19->GetZaxis()->SetLabelFont(42);
   logNPE_numuCC__19->GetZaxis()->SetLabelSize(0.035);
   logNPE_numuCC__19->GetZaxis()->SetTitleSize(0.035);
   logNPE_numuCC__19->GetZaxis()->SetTitleFont(42);
   logNPE_numuCC__19->Draw("");
   
   TH1F *logNPE_numuCC_fidcut__20 = new TH1F("logNPE_numuCC_fidcut__20","",8,5.7,7.2);
   logNPE_numuCC_fidcut__20->SetBinContent(0,91);
   logNPE_numuCC_fidcut__20->SetBinContent(1,19733);
   logNPE_numuCC_fidcut__20->SetBinContent(2,22134);
   logNPE_numuCC_fidcut__20->SetBinContent(3,21889);
   logNPE_numuCC_fidcut__20->SetBinContent(4,18739);
   logNPE_numuCC_fidcut__20->SetBinContent(5,13390);
   logNPE_numuCC_fidcut__20->SetBinContent(6,7525);
   logNPE_numuCC_fidcut__20->SetBinContent(7,3627);
   logNPE_numuCC_fidcut__20->SetBinContent(8,1357);
   logNPE_numuCC_fidcut__20->SetBinContent(9,556);
   logNPE_numuCC_fidcut__20->SetEntries(109041);
   logNPE_numuCC_fidcut__20->SetStats(0);

   ci = TColor::GetColor("#3399ff");
   logNPE_numuCC_fidcut__20->SetFillColor(ci);
   logNPE_numuCC_fidcut__20->SetFillStyle(3002);

   ci = TColor::GetColor("#3399ff");
   logNPE_numuCC_fidcut__20->SetLineColor(ci);
   logNPE_numuCC_fidcut__20->SetLineWidth(5);
   logNPE_numuCC_fidcut__20->GetXaxis()->SetLabelFont(42);
   logNPE_numuCC_fidcut__20->GetXaxis()->SetLabelSize(0.035);
   logNPE_numuCC_fidcut__20->GetXaxis()->SetTitleSize(0.035);
   logNPE_numuCC_fidcut__20->GetXaxis()->SetTitleFont(42);
   logNPE_numuCC_fidcut__20->GetYaxis()->SetLabelFont(42);
   logNPE_numuCC_fidcut__20->GetYaxis()->SetLabelSize(0.035);
   logNPE_numuCC_fidcut__20->GetYaxis()->SetTitleSize(0.035);
   logNPE_numuCC_fidcut__20->GetYaxis()->SetTitleOffset(0);
   logNPE_numuCC_fidcut__20->GetYaxis()->SetTitleFont(42);
   logNPE_numuCC_fidcut__20->GetZaxis()->SetLabelFont(42);
   logNPE_numuCC_fidcut__20->GetZaxis()->SetLabelSize(0.035);
   logNPE_numuCC_fidcut__20->GetZaxis()->SetTitleSize(0.035);
   logNPE_numuCC_fidcut__20->GetZaxis()->SetTitleFont(42);
   logNPE_numuCC_fidcut__20->Draw("same");
   
   TH1F *logNPE_numuCC_timecut__21 = new TH1F("logNPE_numuCC_timecut__21","",8,5.7,7.2);
   logNPE_numuCC_timecut__21->SetBinContent(0,88);
   logNPE_numuCC_timecut__21->SetBinContent(1,18976);
   logNPE_numuCC_timecut__21->SetBinContent(2,20886);
   logNPE_numuCC_timecut__21->SetBinContent(3,20338);
   logNPE_numuCC_timecut__21->SetBinContent(4,16986);
   logNPE_numuCC_timecut__21->SetBinContent(5,11982);
   logNPE_numuCC_timecut__21->SetBinContent(6,6576);
   logNPE_numuCC_timecut__21->SetBinContent(7,2975);
   logNPE_numuCC_timecut__21->SetBinContent(8,1031);
   logNPE_numuCC_timecut__21->SetBinContent(9,407);
   logNPE_numuCC_timecut__21->SetEntries(100245);
   logNPE_numuCC_timecut__21->SetStats(0);

   ci = TColor::GetColor("#ff0000");
   logNPE_numuCC_timecut__21->SetFillColor(ci);
   logNPE_numuCC_timecut__21->SetFillStyle(3002);

   ci = TColor::GetColor("#ff0000");
   logNPE_numuCC_timecut__21->SetLineColor(ci);
   logNPE_numuCC_timecut__21->SetLineWidth(5);
   logNPE_numuCC_timecut__21->GetXaxis()->SetTitle("log_{10}(NPE_{LPMT})");
   logNPE_numuCC_timecut__21->GetXaxis()->SetLabelFont(42);
   logNPE_numuCC_timecut__21->GetXaxis()->SetLabelSize(0.035);
   logNPE_numuCC_timecut__21->GetXaxis()->SetTitleSize(0.035);
   logNPE_numuCC_timecut__21->GetXaxis()->SetTitleFont(42);
   logNPE_numuCC_timecut__21->GetYaxis()->SetLabelFont(42);
   logNPE_numuCC_timecut__21->GetYaxis()->SetLabelSize(0.035);
   logNPE_numuCC_timecut__21->GetYaxis()->SetTitleSize(0.035);
   logNPE_numuCC_timecut__21->GetYaxis()->SetTitleOffset(0);
   logNPE_numuCC_timecut__21->GetYaxis()->SetTitleFont(42);
   logNPE_numuCC_timecut__21->GetZaxis()->SetLabelFont(42);
   logNPE_numuCC_timecut__21->GetZaxis()->SetLabelSize(0.035);
   logNPE_numuCC_timecut__21->GetZaxis()->SetTitleSize(0.035);
   logNPE_numuCC_timecut__21->GetZaxis()->SetTitleFont(42);
   logNPE_numuCC_timecut__21->Draw("same");
   
   TH1F *logNPE_bkg2__22 = new TH1F("logNPE_bkg2__22","",8,5.7,7.2);
   logNPE_bkg2__22->SetBinContent(0,35);
   logNPE_bkg2__22->SetBinContent(1,6152);
   logNPE_bkg2__22->SetBinContent(2,5577);
   logNPE_bkg2__22->SetBinContent(3,4659);
   logNPE_bkg2__22->SetBinContent(4,3363);
   logNPE_bkg2__22->SetBinContent(5,2331);
   logNPE_bkg2__22->SetBinContent(6,1706);
   logNPE_bkg2__22->SetBinContent(7,1166);
   logNPE_bkg2__22->SetBinContent(8,719);
   logNPE_bkg2__22->SetBinContent(9,424);
   logNPE_bkg2__22->SetEntries(26132);
   logNPE_bkg2__22->SetStats(0);

   ci = TColor::GetColor("#006600");
   logNPE_bkg2__22->SetFillColor(ci);
   logNPE_bkg2__22->SetFillStyle(3002);

   ci = TColor::GetColor("#006600");
   logNPE_bkg2__22->SetLineColor(ci);
   logNPE_bkg2__22->SetLineWidth(5);
   logNPE_bkg2__22->GetXaxis()->SetTitle("log_{10}(NPE_{LPMT})");
   logNPE_bkg2__22->GetXaxis()->SetLabelFont(42);
   logNPE_bkg2__22->GetXaxis()->SetLabelSize(0.035);
   logNPE_bkg2__22->GetXaxis()->SetTitleSize(0.035);
   logNPE_bkg2__22->GetXaxis()->SetTitleFont(42);
   logNPE_bkg2__22->GetYaxis()->SetLabelFont(42);
   logNPE_bkg2__22->GetYaxis()->SetLabelSize(0.035);
   logNPE_bkg2__22->GetYaxis()->SetTitleSize(0.035);
   logNPE_bkg2__22->GetYaxis()->SetTitleOffset(0);
   logNPE_bkg2__22->GetYaxis()->SetTitleFont(42);
   logNPE_bkg2__22->GetZaxis()->SetLabelFont(42);
   logNPE_bkg2__22->GetZaxis()->SetLabelSize(0.035);
   logNPE_bkg2__22->GetZaxis()->SetTitleSize(0.035);
   logNPE_bkg2__22->GetZaxis()->SetTitleFont(42);
   logNPE_bkg2__22->Draw("same");
   
   TLegend *leg = new TLegend(0.68,0.6,0.9,0.9,NULL,"brNDC");
   leg->SetBorderSize(1);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("logNPE_numuCC","#nu_{#mu}^{CC} FC","l");

   ci = TColor::GetColor("#ffcc00");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(5);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("logNPE_numuCC_fidcut","#nu_{#mu}^{CC} FC fid.","l");

   ci = TColor::GetColor("#3399ff");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(5);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("logNPE_numuCC_timecut","#nu_{#mu}^{CC} FC sel.","l");

   ci = TColor::GetColor("#ff0000");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(5);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("logNPE_bkg2","res. bkg","l");

   ci = TColor::GetColor("#006600");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(5);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   c118->Modified();
   c118->cd();
   c118->SetSelected(c118);
}
