void GENIE_logNPE_bins_channels_numuCC()
{
//=========Macro generated from canvas: c82a/
//=========  (Thu Jul 18 16:41:07 2019) by ROOT version 6.12/06
   TCanvas *c82a = new TCanvas("c82a", "",65,52,1000,600);
   gStyle->SetOptStat(0);
   c82a->Range(5.5125,-2240.915,7.3875,37025.05);
   c82a->SetFillColor(0);
   c82a->SetBorderMode(0);
   c82a->SetBorderSize(2);
   c82a->SetBottomMargin(0.12);
   c82a->SetFrameBorderMode(0);
   c82a->SetFrameBorderMode(0);
   
   TH1F *LogNPE_numuCC__6 = new TH1F("LogNPE_numuCC__6","",8,5.7,7.2);
   LogNPE_numuCC__6->SetBinContent(0,57916);
   LogNPE_numuCC__6->SetBinContent(1,28512);
   LogNPE_numuCC__6->SetBinContent(2,31640);
   LogNPE_numuCC__6->SetBinContent(3,31083);
   LogNPE_numuCC__6->SetBinContent(4,27278);
   LogNPE_numuCC__6->SetBinContent(5,21340);
   LogNPE_numuCC__6->SetBinContent(6,14535);
   LogNPE_numuCC__6->SetBinContent(7,8762);
   LogNPE_numuCC__6->SetBinContent(8,3860);
   LogNPE_numuCC__6->SetBinContent(9,1271);
   LogNPE_numuCC__6->SetEntries(226197);
   LogNPE_numuCC__6->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   LogNPE_numuCC__6->SetFillColor(ci);
   LogNPE_numuCC__6->SetFillStyle(3002);

   ci = TColor::GetColor("#000099");
   LogNPE_numuCC__6->SetLineColor(ci);
   LogNPE_numuCC__6->SetLineWidth(5);
   LogNPE_numuCC__6->GetXaxis()->SetTitle("log_{10} (NPE_{LPMT})");
   LogNPE_numuCC__6->GetXaxis()->SetLabelFont(42);
   LogNPE_numuCC__6->GetXaxis()->SetLabelSize(0.05);
   LogNPE_numuCC__6->GetXaxis()->SetTitleSize(0.05);
   LogNPE_numuCC__6->GetXaxis()->SetTitleFont(42);
   LogNPE_numuCC__6->GetYaxis()->SetTitle("entries");
   LogNPE_numuCC__6->GetYaxis()->SetLabelFont(42);
   LogNPE_numuCC__6->GetYaxis()->SetLabelSize(0.05);
   LogNPE_numuCC__6->GetYaxis()->SetTitleSize(0.035);
   LogNPE_numuCC__6->GetYaxis()->SetTitleOffset(1.2);
   LogNPE_numuCC__6->GetYaxis()->SetTitleFont(42);
   LogNPE_numuCC__6->GetZaxis()->SetLabelFont(42);
   LogNPE_numuCC__6->GetZaxis()->SetLabelSize(0.035);
   LogNPE_numuCC__6->GetZaxis()->SetTitleSize(0.035);
   LogNPE_numuCC__6->GetZaxis()->SetTitleFont(42);
   LogNPE_numuCC__6->Draw("");
   
   TH1F *LogNPE_numuCC_COH__7 = new TH1F("LogNPE_numuCC_COH__7","",8,5.7,7.2);
   LogNPE_numuCC_COH__7->SetBinContent(0,277);
   LogNPE_numuCC_COH__7->SetBinContent(1,250);
   LogNPE_numuCC_COH__7->SetBinContent(2,362);
   LogNPE_numuCC_COH__7->SetBinContent(3,404);
   LogNPE_numuCC_COH__7->SetBinContent(4,346);
   LogNPE_numuCC_COH__7->SetBinContent(5,275);
   LogNPE_numuCC_COH__7->SetBinContent(6,195);
   LogNPE_numuCC_COH__7->SetBinContent(7,74);
   LogNPE_numuCC_COH__7->SetBinContent(8,17);
   LogNPE_numuCC_COH__7->SetBinContent(9,2);
   LogNPE_numuCC_COH__7->SetEntries(2202);
   LogNPE_numuCC_COH__7->SetStats(0);

   ci = TColor::GetColor("#6600ff");
   LogNPE_numuCC_COH__7->SetLineColor(ci);
   LogNPE_numuCC_COH__7->SetLineWidth(4);
   LogNPE_numuCC_COH__7->GetXaxis()->SetLabelFont(42);
   LogNPE_numuCC_COH__7->GetXaxis()->SetLabelSize(0.035);
   LogNPE_numuCC_COH__7->GetXaxis()->SetTitleSize(0.035);
   LogNPE_numuCC_COH__7->GetXaxis()->SetTitleFont(42);
   LogNPE_numuCC_COH__7->GetYaxis()->SetLabelFont(42);
   LogNPE_numuCC_COH__7->GetYaxis()->SetLabelSize(0.035);
   LogNPE_numuCC_COH__7->GetYaxis()->SetTitleSize(0.035);
   LogNPE_numuCC_COH__7->GetYaxis()->SetTitleOffset(0);
   LogNPE_numuCC_COH__7->GetYaxis()->SetTitleFont(42);
   LogNPE_numuCC_COH__7->GetZaxis()->SetLabelFont(42);
   LogNPE_numuCC_COH__7->GetZaxis()->SetLabelSize(0.035);
   LogNPE_numuCC_COH__7->GetZaxis()->SetTitleSize(0.035);
   LogNPE_numuCC_COH__7->GetZaxis()->SetTitleFont(42);
   LogNPE_numuCC_COH__7->Draw("same");
   
   TH1F *LogNPE_numuCC_QEL__8 = new TH1F("LogNPE_numuCC_QEL__8","",8,5.7,7.2);
   LogNPE_numuCC_QEL__8->SetBinContent(0,52563);
   LogNPE_numuCC_QEL__8->SetBinContent(1,19888);
   LogNPE_numuCC_QEL__8->SetBinContent(2,17495);
   LogNPE_numuCC_QEL__8->SetBinContent(3,13261);
   LogNPE_numuCC_QEL__8->SetBinContent(4,8460);
   LogNPE_numuCC_QEL__8->SetBinContent(5,4723);
   LogNPE_numuCC_QEL__8->SetBinContent(6,2011);
   LogNPE_numuCC_QEL__8->SetBinContent(7,562);
   LogNPE_numuCC_QEL__8->SetBinContent(8,29);
   LogNPE_numuCC_QEL__8->SetEntries(118992);
   LogNPE_numuCC_QEL__8->SetStats(0);

   ci = TColor::GetColor("#003366");
   LogNPE_numuCC_QEL__8->SetLineColor(ci);
   LogNPE_numuCC_QEL__8->SetLineWidth(4);
   LogNPE_numuCC_QEL__8->GetXaxis()->SetLabelFont(42);
   LogNPE_numuCC_QEL__8->GetXaxis()->SetLabelSize(0.035);
   LogNPE_numuCC_QEL__8->GetXaxis()->SetTitleSize(0.035);
   LogNPE_numuCC_QEL__8->GetXaxis()->SetTitleFont(42);
   LogNPE_numuCC_QEL__8->GetYaxis()->SetLabelFont(42);
   LogNPE_numuCC_QEL__8->GetYaxis()->SetLabelSize(0.035);
   LogNPE_numuCC_QEL__8->GetYaxis()->SetTitleSize(0.035);
   LogNPE_numuCC_QEL__8->GetYaxis()->SetTitleOffset(0);
   LogNPE_numuCC_QEL__8->GetYaxis()->SetTitleFont(42);
   LogNPE_numuCC_QEL__8->GetZaxis()->SetLabelFont(42);
   LogNPE_numuCC_QEL__8->GetZaxis()->SetLabelSize(0.035);
   LogNPE_numuCC_QEL__8->GetZaxis()->SetTitleSize(0.035);
   LogNPE_numuCC_QEL__8->GetZaxis()->SetTitleFont(42);
   LogNPE_numuCC_QEL__8->Draw("same");
   
   TH1F *LogNPE_numuCC_RES__9 = new TH1F("LogNPE_numuCC_RES__9","",8,5.7,7.2);
   LogNPE_numuCC_RES__9->SetBinContent(0,4239);
   LogNPE_numuCC_RES__9->SetBinContent(1,7149);
   LogNPE_numuCC_RES__9->SetBinContent(2,11177);
   LogNPE_numuCC_RES__9->SetBinContent(3,12939);
   LogNPE_numuCC_RES__9->SetBinContent(4,11605);
   LogNPE_numuCC_RES__9->SetBinContent(5,7731);
   LogNPE_numuCC_RES__9->SetBinContent(6,3871);
   LogNPE_numuCC_RES__9->SetBinContent(7,1353);
   LogNPE_numuCC_RES__9->SetBinContent(8,125);
   LogNPE_numuCC_RES__9->SetBinContent(9,2);
   LogNPE_numuCC_RES__9->SetEntries(60191);
   LogNPE_numuCC_RES__9->SetStats(0);

   ci = TColor::GetColor("#0066ff");
   LogNPE_numuCC_RES__9->SetLineColor(ci);
   LogNPE_numuCC_RES__9->SetLineWidth(4);
   LogNPE_numuCC_RES__9->GetXaxis()->SetLabelFont(42);
   LogNPE_numuCC_RES__9->GetXaxis()->SetLabelSize(0.035);
   LogNPE_numuCC_RES__9->GetXaxis()->SetTitleSize(0.035);
   LogNPE_numuCC_RES__9->GetXaxis()->SetTitleFont(42);
   LogNPE_numuCC_RES__9->GetYaxis()->SetLabelFont(42);
   LogNPE_numuCC_RES__9->GetYaxis()->SetLabelSize(0.035);
   LogNPE_numuCC_RES__9->GetYaxis()->SetTitleSize(0.035);
   LogNPE_numuCC_RES__9->GetYaxis()->SetTitleOffset(0);
   LogNPE_numuCC_RES__9->GetYaxis()->SetTitleFont(42);
   LogNPE_numuCC_RES__9->GetZaxis()->SetLabelFont(42);
   LogNPE_numuCC_RES__9->GetZaxis()->SetLabelSize(0.035);
   LogNPE_numuCC_RES__9->GetZaxis()->SetTitleSize(0.035);
   LogNPE_numuCC_RES__9->GetZaxis()->SetTitleFont(42);
   LogNPE_numuCC_RES__9->Draw("same");
   
   TH1F *LogNPE_numuCC_DIS__10 = new TH1F("LogNPE_numuCC_DIS__10","",8,5.7,7.2);
   LogNPE_numuCC_DIS__10->SetBinContent(0,837);
   LogNPE_numuCC_DIS__10->SetBinContent(1,1225);
   LogNPE_numuCC_DIS__10->SetBinContent(2,2606);
   LogNPE_numuCC_DIS__10->SetBinContent(3,4479);
   LogNPE_numuCC_DIS__10->SetBinContent(4,6867);
   LogNPE_numuCC_DIS__10->SetBinContent(5,8611);
   LogNPE_numuCC_DIS__10->SetBinContent(6,8458);
   LogNPE_numuCC_DIS__10->SetBinContent(7,6773);
   LogNPE_numuCC_DIS__10->SetBinContent(8,3689);
   LogNPE_numuCC_DIS__10->SetBinContent(9,1267);
   LogNPE_numuCC_DIS__10->SetEntries(44812);
   LogNPE_numuCC_DIS__10->SetStats(0);

   ci = TColor::GetColor("#666699");
   LogNPE_numuCC_DIS__10->SetLineColor(ci);
   LogNPE_numuCC_DIS__10->SetLineWidth(4);
   LogNPE_numuCC_DIS__10->GetXaxis()->SetLabelFont(42);
   LogNPE_numuCC_DIS__10->GetXaxis()->SetLabelSize(0.035);
   LogNPE_numuCC_DIS__10->GetXaxis()->SetTitleSize(0.035);
   LogNPE_numuCC_DIS__10->GetXaxis()->SetTitleFont(42);
   LogNPE_numuCC_DIS__10->GetYaxis()->SetLabelFont(42);
   LogNPE_numuCC_DIS__10->GetYaxis()->SetLabelSize(0.035);
   LogNPE_numuCC_DIS__10->GetYaxis()->SetTitleSize(0.035);
   LogNPE_numuCC_DIS__10->GetYaxis()->SetTitleOffset(0);
   LogNPE_numuCC_DIS__10->GetYaxis()->SetTitleFont(42);
   LogNPE_numuCC_DIS__10->GetZaxis()->SetLabelFont(42);
   LogNPE_numuCC_DIS__10->GetZaxis()->SetLabelSize(0.035);
   LogNPE_numuCC_DIS__10->GetZaxis()->SetTitleSize(0.035);
   LogNPE_numuCC_DIS__10->GetZaxis()->SetTitleFont(42);
   LogNPE_numuCC_DIS__10->Draw("same");
   
   TLegend *leg = new TLegend(0.7,0.5,0.9,0.9,NULL,"brNDC");
   leg->SetBorderSize(1);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("LogNPE_numuCC","#nu_{#mu} CC - all","l");

   ci = TColor::GetColor("#000099");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(5);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("LogNPE_numuCC_COH","#nu_{#mu} CC - coh","l");

   ci = TColor::GetColor("#6600ff");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(4);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("LogNPE_numuCC_QEL","#nu_{#mu} CC - qel","l");

   ci = TColor::GetColor("#003366");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(4);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("LogNPE_numuCC_RES","#nu_{#mu} CC - res","l");

   ci = TColor::GetColor("#0066ff");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(4);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("LogNPE_numuCC_DIS","#nu_{#mu} CC - dis","l");

   ci = TColor::GetColor("#666699");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(4);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   c82a->Modified();
   c82a->cd();
   c82a->SetSelected(c82a);
}
