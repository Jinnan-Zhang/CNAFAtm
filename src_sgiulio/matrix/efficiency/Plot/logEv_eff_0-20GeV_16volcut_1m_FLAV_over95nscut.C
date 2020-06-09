void logEv_eff_0-20GeV_16volcut_1m_FLAV_over95nscut()
{
//=========Macro generated from canvas: c18/
//=========  (Mon May 27 10:29:27 2019) by ROOT version 6.12/06
   TCanvas *c18 = new TCanvas("c18", "",865,52,800,600);
   gStyle->SetOptStat(0);
   c18->Range(-0.4875,0.05218231,1.3875,5.44208);
   c18->SetFillColor(0);
   c18->SetBorderMode(0);
   c18->SetBorderSize(2);
   c18->SetLogy();
   c18->SetBottomMargin(0.12);
   c18->SetFrameBorderMode(0);
   c18->SetFrameBorderMode(0);
   
   TH1F *logEv_Numu__5 = new TH1F("logEv_Numu__5","",8,-0.3,1.2);
   logEv_Numu__5->SetBinContent(0,87094);
   logEv_Numu__5->SetBinContent(1,48287);
   logEv_Numu__5->SetBinContent(2,49855);
   logEv_Numu__5->SetBinContent(3,45140);
   logEv_Numu__5->SetBinContent(4,36061);
   logEv_Numu__5->SetBinContent(5,25957);
   logEv_Numu__5->SetBinContent(6,18520);
   logEv_Numu__5->SetBinContent(7,12497);
   logEv_Numu__5->SetBinContent(8,8354);
   logEv_Numu__5->SetBinContent(9,3065);
   logEv_Numu__5->SetMinimum(5);
   logEv_Numu__5->SetMaximum(80000);
   logEv_Numu__5->SetEntries(334830);
   logEv_Numu__5->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#ff9933");
   logEv_Numu__5->SetFillColor(ci);
   logEv_Numu__5->SetFillStyle(3002);

   ci = TColor::GetColor("#ff9933");
   logEv_Numu__5->SetLineColor(ci);
   logEv_Numu__5->SetLineWidth(5);
   logEv_Numu__5->GetXaxis()->SetTitle("log_{10}(E_{#nu} [GeV])");
   logEv_Numu__5->GetXaxis()->SetLabelFont(42);
   logEv_Numu__5->GetXaxis()->SetTitleSize(0.05);
   logEv_Numu__5->GetXaxis()->SetTitleFont(42);
   logEv_Numu__5->GetYaxis()->SetTitle("entries");
   logEv_Numu__5->GetYaxis()->SetLabelFont(42);
   logEv_Numu__5->GetYaxis()->SetLabelSize(0.05);
   logEv_Numu__5->GetYaxis()->SetTitleSize(0.035);
   logEv_Numu__5->GetYaxis()->SetTitleOffset(1.2);
   logEv_Numu__5->GetYaxis()->SetTitleFont(42);
   logEv_Numu__5->GetZaxis()->SetLabelFont(42);
   logEv_Numu__5->GetZaxis()->SetLabelSize(0.035);
   logEv_Numu__5->GetZaxis()->SetTitleSize(0.035);
   logEv_Numu__5->GetZaxis()->SetTitleFont(42);
   logEv_Numu__5->Draw("");
   
   TH1F *logEv_Numu_fidcut__6 = new TH1F("logEv_Numu_fidcut__6","",8,-0.3,1.2);
   logEv_Numu_fidcut__6->SetBinContent(0,64353);
   logEv_Numu_fidcut__6->SetBinContent(1,35599);
   logEv_Numu_fidcut__6->SetBinContent(2,36754);
   logEv_Numu_fidcut__6->SetBinContent(3,33076);
   logEv_Numu_fidcut__6->SetBinContent(4,25379);
   logEv_Numu_fidcut__6->SetBinContent(5,16287);
   logEv_Numu_fidcut__6->SetBinContent(6,9374);
   logEv_Numu_fidcut__6->SetBinContent(7,4677);
   logEv_Numu_fidcut__6->SetBinContent(8,2533);
   logEv_Numu_fidcut__6->SetBinContent(9,787);
   logEv_Numu_fidcut__6->SetEntries(228819);
   logEv_Numu_fidcut__6->SetStats(0);

   ci = TColor::GetColor("#3399ff");
   logEv_Numu_fidcut__6->SetFillColor(ci);
   logEv_Numu_fidcut__6->SetFillStyle(3002);

   ci = TColor::GetColor("#3399ff");
   logEv_Numu_fidcut__6->SetLineColor(ci);
   logEv_Numu_fidcut__6->SetLineWidth(5);
   logEv_Numu_fidcut__6->GetXaxis()->SetLabelFont(42);
   logEv_Numu_fidcut__6->GetXaxis()->SetLabelSize(0.035);
   logEv_Numu_fidcut__6->GetXaxis()->SetTitleSize(0.035);
   logEv_Numu_fidcut__6->GetXaxis()->SetTitleFont(42);
   logEv_Numu_fidcut__6->GetYaxis()->SetLabelFont(42);
   logEv_Numu_fidcut__6->GetYaxis()->SetLabelSize(0.035);
   logEv_Numu_fidcut__6->GetYaxis()->SetTitleSize(0.035);
   logEv_Numu_fidcut__6->GetYaxis()->SetTitleOffset(0);
   logEv_Numu_fidcut__6->GetYaxis()->SetTitleFont(42);
   logEv_Numu_fidcut__6->GetZaxis()->SetLabelFont(42);
   logEv_Numu_fidcut__6->GetZaxis()->SetLabelSize(0.035);
   logEv_Numu_fidcut__6->GetZaxis()->SetTitleSize(0.035);
   logEv_Numu_fidcut__6->GetZaxis()->SetTitleFont(42);
   logEv_Numu_fidcut__6->Draw("same");
   
   TH1F *logEv_Numu_timecut__7 = new TH1F("logEv_Numu_timecut__7","",8,-0.3,1.2);
   logEv_Numu_timecut__7->SetBinContent(0,1144);
   logEv_Numu_timecut__7->SetBinContent(1,20138);
   logEv_Numu_timecut__7->SetBinContent(2,25734);
   logEv_Numu_timecut__7->SetBinContent(3,24082);
   logEv_Numu_timecut__7->SetBinContent(4,18566);
   logEv_Numu_timecut__7->SetBinContent(5,11689);
   logEv_Numu_timecut__7->SetBinContent(6,6319);
   logEv_Numu_timecut__7->SetBinContent(7,2791);
   logEv_Numu_timecut__7->SetBinContent(8,1449);
   logEv_Numu_timecut__7->SetBinContent(9,445);
   logEv_Numu_timecut__7->SetEntries(112357);
   logEv_Numu_timecut__7->SetStats(0);

   ci = TColor::GetColor("#ff0000");
   logEv_Numu_timecut__7->SetFillColor(ci);
   logEv_Numu_timecut__7->SetFillStyle(3002);

   ci = TColor::GetColor("#ff0000");
   logEv_Numu_timecut__7->SetLineColor(ci);
   logEv_Numu_timecut__7->SetLineWidth(5);
   logEv_Numu_timecut__7->GetXaxis()->SetTitle("log_{10}(E_{#nu} [GeV])");
   logEv_Numu_timecut__7->GetXaxis()->SetLabelFont(42);
   logEv_Numu_timecut__7->GetXaxis()->SetLabelSize(0.035);
   logEv_Numu_timecut__7->GetXaxis()->SetTitleSize(0.035);
   logEv_Numu_timecut__7->GetXaxis()->SetTitleFont(42);
   logEv_Numu_timecut__7->GetYaxis()->SetLabelFont(42);
   logEv_Numu_timecut__7->GetYaxis()->SetLabelSize(0.035);
   logEv_Numu_timecut__7->GetYaxis()->SetTitleSize(0.035);
   logEv_Numu_timecut__7->GetYaxis()->SetTitleOffset(0);
   logEv_Numu_timecut__7->GetYaxis()->SetTitleFont(42);
   logEv_Numu_timecut__7->GetZaxis()->SetLabelFont(42);
   logEv_Numu_timecut__7->GetZaxis()->SetLabelSize(0.035);
   logEv_Numu_timecut__7->GetZaxis()->SetTitleSize(0.035);
   logEv_Numu_timecut__7->GetZaxis()->SetTitleFont(42);
   logEv_Numu_timecut__7->Draw("same");
   
   TH1F *logEv_bkg2__8 = new TH1F("logEv_bkg2__8","",8,-0.3,1.2);
   logEv_bkg2__8->SetBinContent(0,82);
   logEv_bkg2__8->SetBinContent(1,1301);
   logEv_bkg2__8->SetBinContent(2,2305);
   logEv_bkg2__8->SetBinContent(3,2712);
   logEv_bkg2__8->SetBinContent(4,2351);
   logEv_bkg2__8->SetBinContent(5,1757);
   logEv_bkg2__8->SetBinContent(6,1270);
   logEv_bkg2__8->SetBinContent(7,818);
   logEv_bkg2__8->SetBinContent(8,556);
   logEv_bkg2__8->SetBinContent(9,179);
   logEv_bkg2__8->SetEntries(13331);
   logEv_bkg2__8->SetStats(0);

   ci = TColor::GetColor("#006600");
   logEv_bkg2__8->SetFillColor(ci);
   logEv_bkg2__8->SetFillStyle(3002);

   ci = TColor::GetColor("#006600");
   logEv_bkg2__8->SetLineColor(ci);
   logEv_bkg2__8->SetLineWidth(5);
   logEv_bkg2__8->GetXaxis()->SetTitle("log_{10}(E_{#nu} [GeV])");
   logEv_bkg2__8->GetXaxis()->SetLabelFont(42);
   logEv_bkg2__8->GetXaxis()->SetLabelSize(0.035);
   logEv_bkg2__8->GetXaxis()->SetTitleSize(0.035);
   logEv_bkg2__8->GetXaxis()->SetTitleFont(42);
   logEv_bkg2__8->GetYaxis()->SetLabelFont(42);
   logEv_bkg2__8->GetYaxis()->SetLabelSize(0.035);
   logEv_bkg2__8->GetYaxis()->SetTitleSize(0.035);
   logEv_bkg2__8->GetYaxis()->SetTitleOffset(0);
   logEv_bkg2__8->GetYaxis()->SetTitleFont(42);
   logEv_bkg2__8->GetZaxis()->SetLabelFont(42);
   logEv_bkg2__8->GetZaxis()->SetLabelSize(0.035);
   logEv_bkg2__8->GetZaxis()->SetTitleSize(0.035);
   logEv_bkg2__8->GetZaxis()->SetTitleFont(42);
   logEv_bkg2__8->Draw("same");
   
   TLegend *leg = new TLegend(0.35,0.15,0.6,0.4,NULL,"brNDC");
   leg->SetBorderSize(1);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("logEv_Numu","#nu_{#mu} - inj.","l");

   ci = TColor::GetColor("#ff9933");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(5);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("logEv_Numu_fidcut","#nu_{#mu} - fid.","l");

   ci = TColor::GetColor("#3399ff");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(5);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("logEv_Numu_timecut","#nu_{#mu} - sel.","l");

   ci = TColor::GetColor("#ff0000");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(5);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("logEv_bkg2","Res. bkg","l");

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
