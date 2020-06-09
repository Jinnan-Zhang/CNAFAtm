void logNPE_hard_eff_0-20GeV_16volcut_1m_less75nscut()
{
//=========Macro generated from canvas: c217/
//=========  (Thu Jun 20 17:57:18 2019) by ROOT version 6.12/06
   TCanvas *c217 = new TCanvas("c217", "",117,57,800,600);
   gStyle->SetOptStat(0);
   c217->Range(5.2875,2.997865,7.4125,4.801607);
   c217->SetFillColor(0);
   c217->SetBorderMode(0);
   c217->SetBorderSize(2);
   c217->SetLogy();
   c217->SetBottomMargin(0.12);
   c217->SetFrameBorderMode(0);
   c217->SetFrameBorderMode(0);
   
   TH1F *logNPE_hard_nueCC__23 = new TH1F("logNPE_hard_nueCC__23","",7,5.5,7.2);
   logNPE_hard_nueCC__23->SetBinContent(0,16153);
   logNPE_hard_nueCC__23->SetBinContent(1,16903);
   logNPE_hard_nueCC__23->SetBinContent(2,22064);
   logNPE_hard_nueCC__23->SetBinContent(3,21534);
   logNPE_hard_nueCC__23->SetBinContent(4,16708);
   logNPE_hard_nueCC__23->SetBinContent(5,10846);
   logNPE_hard_nueCC__23->SetBinContent(6,6237);
   logNPE_hard_nueCC__23->SetBinContent(7,3276);
   logNPE_hard_nueCC__23->SetBinContent(8,1453);
   logNPE_hard_nueCC__23->SetEntries(115174);
   logNPE_hard_nueCC__23->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#ffcc00");
   logNPE_hard_nueCC__23->SetFillColor(ci);
   logNPE_hard_nueCC__23->SetFillStyle(3002);

   ci = TColor::GetColor("#ffcc00");
   logNPE_hard_nueCC__23->SetLineColor(ci);
   logNPE_hard_nueCC__23->SetLineWidth(5);
   logNPE_hard_nueCC__23->GetXaxis()->SetTitle("log_{10}(NPE_{LPMT})");
   logNPE_hard_nueCC__23->GetXaxis()->SetLabelFont(42);
   logNPE_hard_nueCC__23->GetXaxis()->SetTitleSize(0.05);
   logNPE_hard_nueCC__23->GetXaxis()->SetTitleFont(42);
   logNPE_hard_nueCC__23->GetYaxis()->SetTitle("entries");
   logNPE_hard_nueCC__23->GetYaxis()->SetLabelFont(42);
   logNPE_hard_nueCC__23->GetYaxis()->SetLabelSize(0.05);
   logNPE_hard_nueCC__23->GetYaxis()->SetTitleSize(0.035);
   logNPE_hard_nueCC__23->GetYaxis()->SetTitleOffset(1.2);
   logNPE_hard_nueCC__23->GetYaxis()->SetTitleFont(42);
   logNPE_hard_nueCC__23->GetZaxis()->SetLabelFont(42);
   logNPE_hard_nueCC__23->GetZaxis()->SetLabelSize(0.035);
   logNPE_hard_nueCC__23->GetZaxis()->SetTitleSize(0.035);
   logNPE_hard_nueCC__23->GetZaxis()->SetTitleFont(42);
   logNPE_hard_nueCC__23->Draw("");
   
   TH1F *logNPE_hard_nueCC_fidcut__24 = new TH1F("logNPE_hard_nueCC_fidcut__24","",7,5.5,7.2);
   logNPE_hard_nueCC_fidcut__24->SetBinContent(1,11885);
   logNPE_hard_nueCC_fidcut__24->SetBinContent(2,16037);
   logNPE_hard_nueCC_fidcut__24->SetBinContent(3,16150);
   logNPE_hard_nueCC_fidcut__24->SetBinContent(4,12742);
   logNPE_hard_nueCC_fidcut__24->SetBinContent(5,8398);
   logNPE_hard_nueCC_fidcut__24->SetBinContent(6,4821);
   logNPE_hard_nueCC_fidcut__24->SetBinContent(7,2585);
   logNPE_hard_nueCC_fidcut__24->SetBinContent(8,1186);
   logNPE_hard_nueCC_fidcut__24->SetEntries(73804);
   logNPE_hard_nueCC_fidcut__24->SetStats(0);

   ci = TColor::GetColor("#3399ff");
   logNPE_hard_nueCC_fidcut__24->SetFillColor(ci);
   logNPE_hard_nueCC_fidcut__24->SetFillStyle(3002);

   ci = TColor::GetColor("#3399ff");
   logNPE_hard_nueCC_fidcut__24->SetLineColor(ci);
   logNPE_hard_nueCC_fidcut__24->SetLineWidth(5);
   logNPE_hard_nueCC_fidcut__24->GetXaxis()->SetLabelFont(42);
   logNPE_hard_nueCC_fidcut__24->GetXaxis()->SetLabelSize(0.035);
   logNPE_hard_nueCC_fidcut__24->GetXaxis()->SetTitleSize(0.035);
   logNPE_hard_nueCC_fidcut__24->GetXaxis()->SetTitleFont(42);
   logNPE_hard_nueCC_fidcut__24->GetYaxis()->SetLabelFont(42);
   logNPE_hard_nueCC_fidcut__24->GetYaxis()->SetLabelSize(0.035);
   logNPE_hard_nueCC_fidcut__24->GetYaxis()->SetTitleSize(0.035);
   logNPE_hard_nueCC_fidcut__24->GetYaxis()->SetTitleOffset(0);
   logNPE_hard_nueCC_fidcut__24->GetYaxis()->SetTitleFont(42);
   logNPE_hard_nueCC_fidcut__24->GetZaxis()->SetLabelFont(42);
   logNPE_hard_nueCC_fidcut__24->GetZaxis()->SetLabelSize(0.035);
   logNPE_hard_nueCC_fidcut__24->GetZaxis()->SetTitleSize(0.035);
   logNPE_hard_nueCC_fidcut__24->GetZaxis()->SetTitleFont(42);
   logNPE_hard_nueCC_fidcut__24->Draw("same");
   
   TH1F *logNPE_hard_all_timecut__25 = new TH1F("logNPE_hard_all_timecut__25","",7,5.5,7.2);
   logNPE_hard_all_timecut__25->SetBinContent(1,9783);
   logNPE_hard_all_timecut__25->SetBinContent(2,9878);
   logNPE_hard_all_timecut__25->SetBinContent(3,8134);
   logNPE_hard_all_timecut__25->SetBinContent(4,5927);
   logNPE_hard_all_timecut__25->SetBinContent(5,4000);
   logNPE_hard_all_timecut__25->SetBinContent(6,2072);
   logNPE_hard_all_timecut__25->SetBinContent(7,898);
   logNPE_hard_all_timecut__25->SetBinContent(8,237);
   logNPE_hard_all_timecut__25->SetEntries(40929);
   logNPE_hard_all_timecut__25->SetStats(0);

   ci = TColor::GetColor("#333333");
   logNPE_hard_all_timecut__25->SetFillColor(ci);
   logNPE_hard_all_timecut__25->SetFillStyle(3002);

   ci = TColor::GetColor("#333333");
   logNPE_hard_all_timecut__25->SetLineColor(ci);
   logNPE_hard_all_timecut__25->SetLineWidth(5);
   logNPE_hard_all_timecut__25->GetXaxis()->SetTitle("log_{10}(NPE_{LPMT})");
   logNPE_hard_all_timecut__25->GetXaxis()->SetLabelFont(42);
   logNPE_hard_all_timecut__25->GetXaxis()->SetLabelSize(0.035);
   logNPE_hard_all_timecut__25->GetXaxis()->SetTitleSize(0.035);
   logNPE_hard_all_timecut__25->GetXaxis()->SetTitleFont(42);
   logNPE_hard_all_timecut__25->GetYaxis()->SetLabelFont(42);
   logNPE_hard_all_timecut__25->GetYaxis()->SetLabelSize(0.035);
   logNPE_hard_all_timecut__25->GetYaxis()->SetTitleSize(0.035);
   logNPE_hard_all_timecut__25->GetYaxis()->SetTitleOffset(0);
   logNPE_hard_all_timecut__25->GetYaxis()->SetTitleFont(42);
   logNPE_hard_all_timecut__25->GetZaxis()->SetLabelFont(42);
   logNPE_hard_all_timecut__25->GetZaxis()->SetLabelSize(0.035);
   logNPE_hard_all_timecut__25->GetZaxis()->SetTitleSize(0.035);
   logNPE_hard_all_timecut__25->GetZaxis()->SetTitleFont(42);
   logNPE_hard_all_timecut__25->Draw("same");
   
   TH1F *logNPE_hard_nueCC_timecut__26 = new TH1F("logNPE_hard_nueCC_timecut__26","",7,5.5,7.2);
   logNPE_hard_nueCC_timecut__26->SetBinContent(1,7311);
   logNPE_hard_nueCC_timecut__26->SetBinContent(2,7623);
   logNPE_hard_nueCC_timecut__26->SetBinContent(3,6902);
   logNPE_hard_nueCC_timecut__26->SetBinContent(4,5294);
   logNPE_hard_nueCC_timecut__26->SetBinContent(5,3609);
   logNPE_hard_nueCC_timecut__26->SetBinContent(6,1927);
   logNPE_hard_nueCC_timecut__26->SetBinContent(7,868);
   logNPE_hard_nueCC_timecut__26->SetBinContent(8,236);
   logNPE_hard_nueCC_timecut__26->SetEntries(33770);
   logNPE_hard_nueCC_timecut__26->SetStats(0);

   ci = TColor::GetColor("#ff0000");
   logNPE_hard_nueCC_timecut__26->SetFillColor(ci);
   logNPE_hard_nueCC_timecut__26->SetFillStyle(3002);

   ci = TColor::GetColor("#ff0000");
   logNPE_hard_nueCC_timecut__26->SetLineColor(ci);
   logNPE_hard_nueCC_timecut__26->SetLineWidth(5);
   logNPE_hard_nueCC_timecut__26->GetXaxis()->SetTitle("log_{10}(NPE_{LPMT})");
   logNPE_hard_nueCC_timecut__26->GetXaxis()->SetLabelFont(42);
   logNPE_hard_nueCC_timecut__26->GetXaxis()->SetLabelSize(0.035);
   logNPE_hard_nueCC_timecut__26->GetXaxis()->SetTitleSize(0.035);
   logNPE_hard_nueCC_timecut__26->GetXaxis()->SetTitleFont(42);
   logNPE_hard_nueCC_timecut__26->GetYaxis()->SetLabelFont(42);
   logNPE_hard_nueCC_timecut__26->GetYaxis()->SetLabelSize(0.035);
   logNPE_hard_nueCC_timecut__26->GetYaxis()->SetTitleSize(0.035);
   logNPE_hard_nueCC_timecut__26->GetYaxis()->SetTitleOffset(0);
   logNPE_hard_nueCC_timecut__26->GetYaxis()->SetTitleFont(42);
   logNPE_hard_nueCC_timecut__26->GetZaxis()->SetLabelFont(42);
   logNPE_hard_nueCC_timecut__26->GetZaxis()->SetLabelSize(0.035);
   logNPE_hard_nueCC_timecut__26->GetZaxis()->SetTitleSize(0.035);
   logNPE_hard_nueCC_timecut__26->GetZaxis()->SetTitleFont(42);
   logNPE_hard_nueCC_timecut__26->Draw("same");
   
   TH1F *logNPE_hard_bkg1__27 = new TH1F("logNPE_hard_bkg1__27","",7,5.5,7.2);
   logNPE_hard_bkg1__27->SetBinContent(1,2461);
   logNPE_hard_bkg1__27->SetBinContent(2,2250);
   logNPE_hard_bkg1__27->SetBinContent(3,1223);
   logNPE_hard_bkg1__27->SetBinContent(4,623);
   logNPE_hard_bkg1__27->SetBinContent(5,386);
   logNPE_hard_bkg1__27->SetBinContent(6,143);
   logNPE_hard_bkg1__27->SetBinContent(7,29);
   logNPE_hard_bkg1__27->SetBinContent(8,1);
   logNPE_hard_bkg1__27->SetEntries(7116);
   logNPE_hard_bkg1__27->SetStats(0);

   ci = TColor::GetColor("#006600");
   logNPE_hard_bkg1__27->SetFillColor(ci);
   logNPE_hard_bkg1__27->SetFillStyle(3002);

   ci = TColor::GetColor("#006600");
   logNPE_hard_bkg1__27->SetLineColor(ci);
   logNPE_hard_bkg1__27->SetLineWidth(5);
   logNPE_hard_bkg1__27->GetXaxis()->SetTitle("log_{10}(NPE_{LPMT})");
   logNPE_hard_bkg1__27->GetXaxis()->SetLabelFont(42);
   logNPE_hard_bkg1__27->GetXaxis()->SetLabelSize(0.035);
   logNPE_hard_bkg1__27->GetXaxis()->SetTitleSize(0.035);
   logNPE_hard_bkg1__27->GetXaxis()->SetTitleFont(42);
   logNPE_hard_bkg1__27->GetYaxis()->SetLabelFont(42);
   logNPE_hard_bkg1__27->GetYaxis()->SetLabelSize(0.035);
   logNPE_hard_bkg1__27->GetYaxis()->SetTitleSize(0.035);
   logNPE_hard_bkg1__27->GetYaxis()->SetTitleOffset(0);
   logNPE_hard_bkg1__27->GetYaxis()->SetTitleFont(42);
   logNPE_hard_bkg1__27->GetZaxis()->SetLabelFont(42);
   logNPE_hard_bkg1__27->GetZaxis()->SetLabelSize(0.035);
   logNPE_hard_bkg1__27->GetZaxis()->SetTitleSize(0.035);
   logNPE_hard_bkg1__27->GetZaxis()->SetTitleFont(42);
   logNPE_hard_bkg1__27->Draw("same");
   
   TLegend *leg = new TLegend(0.68,0.6,0.9,0.9,NULL,"brNDC");
   leg->SetBorderSize(1);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("logNPE_hard_nueCC","#nu_{e}^{CC}","l");

   ci = TColor::GetColor("#ffcc00");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(5);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("logNPE_hard_nueCC_fidcut","#nu_{e}^{CC} fid.","l");

   ci = TColor::GetColor("#3399ff");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(5);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("logNPE_hard_all_timecut","#All sel.","l");

   ci = TColor::GetColor("#333333");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(5);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("logNPE_hard_nueCC_timecut","#nu_{e}^{CC} sel.","l");

   ci = TColor::GetColor("#ff0000");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(5);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("logNPE_hard_bkg1","res. bkg","l");

   ci = TColor::GetColor("#006600");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(5);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   c217->Modified();
   c217->cd();
   c217->SetSelected(c217);
}
