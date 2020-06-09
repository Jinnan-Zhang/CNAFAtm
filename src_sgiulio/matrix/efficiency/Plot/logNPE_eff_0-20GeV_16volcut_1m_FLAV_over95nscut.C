void logNPE_eff_0-20GeV_16volcut_1m_FLAV_over95nscut()
{
//=========Macro generated from canvas: c118/
//=========  (Mon May 27 10:29:31 2019) by ROOT version 6.12/06
   TCanvas *c118 = new TCanvas("c118", "",65,480,800,600);
   gStyle->SetOptStat(0);
   c118->Range(5.5125,-0.7229185,7.3875,5.301402);
   c118->SetFillColor(0);
   c118->SetBorderMode(0);
   c118->SetBorderSize(2);
   c118->SetLogy();
   c118->SetBottomMargin(0.12);
   c118->SetFrameBorderMode(0);
   c118->SetFrameBorderMode(0);
   
   TH1F *logNPE_Numu__13 = new TH1F("logNPE_Numu__13","",8,5.7,7.2);
   logNPE_Numu__13->SetBinContent(0,133589);
   logNPE_Numu__13->SetBinContent(1,38317);
   logNPE_Numu__13->SetBinContent(2,39152);
   logNPE_Numu__13->SetBinContent(3,36716);
   logNPE_Numu__13->SetBinContent(4,31070);
   logNPE_Numu__13->SetBinContent(5,23892);
   logNPE_Numu__13->SetBinContent(6,16322);
   logNPE_Numu__13->SetBinContent(7,9802);
   logNPE_Numu__13->SetBinContent(8,4439);
   logNPE_Numu__13->SetBinContent(9,1531);
   logNPE_Numu__13->SetMinimum(1);
   logNPE_Numu__13->SetMaximum(50000);
   logNPE_Numu__13->SetEntries(334830);
   logNPE_Numu__13->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#ff9933");
   logNPE_Numu__13->SetFillColor(ci);
   logNPE_Numu__13->SetFillStyle(3002);

   ci = TColor::GetColor("#ff9933");
   logNPE_Numu__13->SetLineColor(ci);
   logNPE_Numu__13->SetLineWidth(5);
   logNPE_Numu__13->GetXaxis()->SetTitle("log_{10}(NPE_{LPMT})");
   logNPE_Numu__13->GetXaxis()->SetLabelFont(42);
   logNPE_Numu__13->GetXaxis()->SetTitleSize(0.05);
   logNPE_Numu__13->GetXaxis()->SetTitleFont(42);
   logNPE_Numu__13->GetYaxis()->SetTitle("entries");
   logNPE_Numu__13->GetYaxis()->SetLabelFont(42);
   logNPE_Numu__13->GetYaxis()->SetLabelSize(0.05);
   logNPE_Numu__13->GetYaxis()->SetTitleSize(0.035);
   logNPE_Numu__13->GetYaxis()->SetTitleOffset(1.2);
   logNPE_Numu__13->GetYaxis()->SetTitleFont(42);
   logNPE_Numu__13->GetZaxis()->SetLabelFont(42);
   logNPE_Numu__13->GetZaxis()->SetLabelSize(0.035);
   logNPE_Numu__13->GetZaxis()->SetTitleSize(0.035);
   logNPE_Numu__13->GetZaxis()->SetTitleFont(42);
   logNPE_Numu__13->Draw("");
   
   TH1F *logNPE_Numu_fidcut__14 = new TH1F("logNPE_Numu_fidcut__14","",8,5.7,7.2);
   logNPE_Numu_fidcut__14->SetBinContent(1,27173);
   logNPE_Numu_fidcut__14->SetBinContent(2,27936);
   logNPE_Numu_fidcut__14->SetBinContent(3,26371);
   logNPE_Numu_fidcut__14->SetBinContent(4,21902);
   logNPE_Numu_fidcut__14->SetBinContent(5,15588);
   logNPE_Numu_fidcut__14->SetBinContent(6,9243);
   logNPE_Numu_fidcut__14->SetBinContent(7,4591);
   logNPE_Numu_fidcut__14->SetBinContent(8,1897);
   logNPE_Numu_fidcut__14->SetBinContent(9,777);
   logNPE_Numu_fidcut__14->SetEntries(135478);
   logNPE_Numu_fidcut__14->SetStats(0);

   ci = TColor::GetColor("#3399ff");
   logNPE_Numu_fidcut__14->SetFillColor(ci);
   logNPE_Numu_fidcut__14->SetFillStyle(3002);

   ci = TColor::GetColor("#3399ff");
   logNPE_Numu_fidcut__14->SetLineColor(ci);
   logNPE_Numu_fidcut__14->SetLineWidth(5);
   logNPE_Numu_fidcut__14->GetXaxis()->SetLabelFont(42);
   logNPE_Numu_fidcut__14->GetXaxis()->SetLabelSize(0.035);
   logNPE_Numu_fidcut__14->GetXaxis()->SetTitleSize(0.035);
   logNPE_Numu_fidcut__14->GetXaxis()->SetTitleFont(42);
   logNPE_Numu_fidcut__14->GetYaxis()->SetLabelFont(42);
   logNPE_Numu_fidcut__14->GetYaxis()->SetLabelSize(0.035);
   logNPE_Numu_fidcut__14->GetYaxis()->SetTitleSize(0.035);
   logNPE_Numu_fidcut__14->GetYaxis()->SetTitleOffset(0);
   logNPE_Numu_fidcut__14->GetYaxis()->SetTitleFont(42);
   logNPE_Numu_fidcut__14->GetZaxis()->SetLabelFont(42);
   logNPE_Numu_fidcut__14->GetZaxis()->SetLabelSize(0.035);
   logNPE_Numu_fidcut__14->GetZaxis()->SetTitleSize(0.035);
   logNPE_Numu_fidcut__14->GetZaxis()->SetTitleFont(42);
   logNPE_Numu_fidcut__14->Draw("same");
   
   TH1F *logNPE_Numu_timecut__15 = new TH1F("logNPE_Numu_timecut__15","",8,5.7,7.2);
   logNPE_Numu_timecut__15->SetBinContent(1,22375);
   logNPE_Numu_timecut__15->SetBinContent(2,23801);
   logNPE_Numu_timecut__15->SetBinContent(3,22400);
   logNPE_Numu_timecut__15->SetBinContent(4,18431);
   logNPE_Numu_timecut__15->SetBinContent(5,12889);
   logNPE_Numu_timecut__15->SetBinContent(6,7319);
   logNPE_Numu_timecut__15->SetBinContent(7,3386);
   logNPE_Numu_timecut__15->SetBinContent(8,1265);
   logNPE_Numu_timecut__15->SetBinContent(9,491);
   logNPE_Numu_timecut__15->SetEntries(112357);
   logNPE_Numu_timecut__15->SetStats(0);

   ci = TColor::GetColor("#ff0000");
   logNPE_Numu_timecut__15->SetFillColor(ci);
   logNPE_Numu_timecut__15->SetFillStyle(3002);

   ci = TColor::GetColor("#ff0000");
   logNPE_Numu_timecut__15->SetLineColor(ci);
   logNPE_Numu_timecut__15->SetLineWidth(5);
   logNPE_Numu_timecut__15->GetXaxis()->SetTitle("log_{10}(NPE_{LPMT})");
   logNPE_Numu_timecut__15->GetXaxis()->SetLabelFont(42);
   logNPE_Numu_timecut__15->GetXaxis()->SetLabelSize(0.035);
   logNPE_Numu_timecut__15->GetXaxis()->SetTitleSize(0.035);
   logNPE_Numu_timecut__15->GetXaxis()->SetTitleFont(42);
   logNPE_Numu_timecut__15->GetYaxis()->SetLabelFont(42);
   logNPE_Numu_timecut__15->GetYaxis()->SetLabelSize(0.035);
   logNPE_Numu_timecut__15->GetYaxis()->SetTitleSize(0.035);
   logNPE_Numu_timecut__15->GetYaxis()->SetTitleOffset(0);
   logNPE_Numu_timecut__15->GetYaxis()->SetTitleFont(42);
   logNPE_Numu_timecut__15->GetZaxis()->SetLabelFont(42);
   logNPE_Numu_timecut__15->GetZaxis()->SetLabelSize(0.035);
   logNPE_Numu_timecut__15->GetZaxis()->SetTitleSize(0.035);
   logNPE_Numu_timecut__15->GetZaxis()->SetTitleFont(42);
   logNPE_Numu_timecut__15->Draw("same");
   
   TH1F *logNPE_bkg2__16 = new TH1F("logNPE_bkg2__16","",8,5.7,7.2);
   logNPE_bkg2__16->SetBinContent(1,2611);
   logNPE_bkg2__16->SetBinContent(2,2726);
   logNPE_bkg2__16->SetBinContent(3,2492);
   logNPE_bkg2__16->SetBinContent(4,1838);
   logNPE_bkg2__16->SetBinContent(5,1329);
   logNPE_bkg2__16->SetBinContent(6,970);
   logNPE_bkg2__16->SetBinContent(7,660);
   logNPE_bkg2__16->SetBinContent(8,425);
   logNPE_bkg2__16->SetBinContent(9,280);
   logNPE_bkg2__16->SetEntries(13331);
   logNPE_bkg2__16->SetStats(0);

   ci = TColor::GetColor("#006600");
   logNPE_bkg2__16->SetFillColor(ci);
   logNPE_bkg2__16->SetFillStyle(3002);

   ci = TColor::GetColor("#006600");
   logNPE_bkg2__16->SetLineColor(ci);
   logNPE_bkg2__16->SetLineWidth(5);
   logNPE_bkg2__16->GetXaxis()->SetTitle("log_{10}(NPE_{LPMT})");
   logNPE_bkg2__16->GetXaxis()->SetLabelFont(42);
   logNPE_bkg2__16->GetXaxis()->SetLabelSize(0.035);
   logNPE_bkg2__16->GetXaxis()->SetTitleSize(0.035);
   logNPE_bkg2__16->GetXaxis()->SetTitleFont(42);
   logNPE_bkg2__16->GetYaxis()->SetLabelFont(42);
   logNPE_bkg2__16->GetYaxis()->SetLabelSize(0.035);
   logNPE_bkg2__16->GetYaxis()->SetTitleSize(0.035);
   logNPE_bkg2__16->GetYaxis()->SetTitleOffset(0);
   logNPE_bkg2__16->GetYaxis()->SetTitleFont(42);
   logNPE_bkg2__16->GetZaxis()->SetLabelFont(42);
   logNPE_bkg2__16->GetZaxis()->SetLabelSize(0.035);
   logNPE_bkg2__16->GetZaxis()->SetTitleSize(0.035);
   logNPE_bkg2__16->GetZaxis()->SetTitleFont(42);
   logNPE_bkg2__16->Draw("same");
   
   TLegend *leg = new TLegend(0.15,0.15,0.4,0.45,NULL,"brNDC");
   leg->SetBorderSize(1);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("logNPE_Numu","#nu_{#mu} FC","l");

   ci = TColor::GetColor("#ff9933");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(5);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("logNPE_Numu_fidcut","#nu_{#mu} FC fid.","l");

   ci = TColor::GetColor("#3399ff");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(5);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("logNPE_Numu_timecut","#nu_{#mu} FC sel.","l");

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
