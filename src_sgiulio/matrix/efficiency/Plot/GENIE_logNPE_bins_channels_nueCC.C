void GENIE_logNPE_bins_channels_nueCC()
{
//=========Macro generated from canvas: c82/
//=========  (Thu Jul 18 16:41:06 2019) by ROOT version 6.12/06
   TCanvas *c82 = new TCanvas("c82", "",65,480,1000,600);
   gStyle->SetOptStat(0);
   c82->Range(4.725,-411.3243,7.475,32427.63);
   c82->SetFillColor(0);
   c82->SetBorderMode(0);
   c82->SetBorderSize(2);
   c82->SetBottomMargin(0.12);
   c82->SetFrameBorderMode(0);
   c82->SetFrameBorderMode(0);
   
   TH1F *LogNPE_nueCC__1 = new TH1F("LogNPE_nueCC__1","",7,5,7.2);
   LogNPE_nueCC__1->SetBinContent(0,2155);
   LogNPE_nueCC__1->SetBinContent(1,6063);
   LogNPE_nueCC__1->SetBinContent(2,15919);
   LogNPE_nueCC__1->SetBinContent(3,26898);
   LogNPE_nueCC__1->SetBinContent(4,27924);
   LogNPE_nueCC__1->SetBinContent(5,19466);
   LogNPE_nueCC__1->SetBinContent(6,10605);
   LogNPE_nueCC__1->SetBinContent(7,4691);
   LogNPE_nueCC__1->SetBinContent(8,1453);
   LogNPE_nueCC__1->SetEntries(115174);
   LogNPE_nueCC__1->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#ff0000");
   LogNPE_nueCC__1->SetFillColor(ci);
   LogNPE_nueCC__1->SetFillStyle(3002);

   ci = TColor::GetColor("#ff0000");
   LogNPE_nueCC__1->SetLineColor(ci);
   LogNPE_nueCC__1->SetLineWidth(5);
   LogNPE_nueCC__1->GetXaxis()->SetTitle("log_{10} (NPE_{LPMT})");
   LogNPE_nueCC__1->GetXaxis()->SetLabelFont(42);
   LogNPE_nueCC__1->GetXaxis()->SetLabelSize(0.05);
   LogNPE_nueCC__1->GetXaxis()->SetTitleSize(0.05);
   LogNPE_nueCC__1->GetXaxis()->SetTitleFont(42);
   LogNPE_nueCC__1->GetYaxis()->SetTitle("entries");
   LogNPE_nueCC__1->GetYaxis()->SetLabelFont(42);
   LogNPE_nueCC__1->GetYaxis()->SetLabelSize(0.05);
   LogNPE_nueCC__1->GetYaxis()->SetTitleSize(0.035);
   LogNPE_nueCC__1->GetYaxis()->SetTitleOffset(1.2);
   LogNPE_nueCC__1->GetYaxis()->SetTitleFont(42);
   LogNPE_nueCC__1->GetZaxis()->SetLabelFont(42);
   LogNPE_nueCC__1->GetZaxis()->SetLabelSize(0.035);
   LogNPE_nueCC__1->GetZaxis()->SetTitleSize(0.035);
   LogNPE_nueCC__1->GetZaxis()->SetTitleFont(42);
   LogNPE_nueCC__1->Draw("");
   
   TH1F *LogNPE_nueCC_COH__2 = new TH1F("LogNPE_nueCC_COH__2","",7,5,7.2);
   LogNPE_nueCC_COH__2->SetBinContent(0,4);
   LogNPE_nueCC_COH__2->SetBinContent(1,9);
   LogNPE_nueCC_COH__2->SetBinContent(2,90);
   LogNPE_nueCC_COH__2->SetBinContent(3,288);
   LogNPE_nueCC_COH__2->SetBinContent(4,358);
   LogNPE_nueCC_COH__2->SetBinContent(5,267);
   LogNPE_nueCC_COH__2->SetBinContent(6,139);
   LogNPE_nueCC_COH__2->SetBinContent(7,53);
   LogNPE_nueCC_COH__2->SetBinContent(8,11);
   LogNPE_nueCC_COH__2->SetEntries(1219);
   LogNPE_nueCC_COH__2->SetStats(0);

   ci = TColor::GetColor("#660033");
   LogNPE_nueCC_COH__2->SetLineColor(ci);
   LogNPE_nueCC_COH__2->SetLineWidth(4);
   LogNPE_nueCC_COH__2->GetXaxis()->SetLabelFont(42);
   LogNPE_nueCC_COH__2->GetXaxis()->SetLabelSize(0.035);
   LogNPE_nueCC_COH__2->GetXaxis()->SetTitleSize(0.035);
   LogNPE_nueCC_COH__2->GetXaxis()->SetTitleFont(42);
   LogNPE_nueCC_COH__2->GetYaxis()->SetLabelFont(42);
   LogNPE_nueCC_COH__2->GetYaxis()->SetLabelSize(0.035);
   LogNPE_nueCC_COH__2->GetYaxis()->SetTitleSize(0.035);
   LogNPE_nueCC_COH__2->GetYaxis()->SetTitleOffset(0);
   LogNPE_nueCC_COH__2->GetYaxis()->SetTitleFont(42);
   LogNPE_nueCC_COH__2->GetZaxis()->SetLabelFont(42);
   LogNPE_nueCC_COH__2->GetZaxis()->SetLabelSize(0.035);
   LogNPE_nueCC_COH__2->GetZaxis()->SetTitleSize(0.035);
   LogNPE_nueCC_COH__2->GetZaxis()->SetTitleFont(42);
   LogNPE_nueCC_COH__2->Draw("same");
   
   TH1F *LogNPE_nueCC_QEL__3 = new TH1F("LogNPE_nueCC_QEL__3","",7,5,7.2);
   LogNPE_nueCC_QEL__3->SetBinContent(0,2115);
   LogNPE_nueCC_QEL__3->SetBinContent(1,5928);
   LogNPE_nueCC_QEL__3->SetBinContent(2,14773);
   LogNPE_nueCC_QEL__3->SetBinContent(3,20102);
   LogNPE_nueCC_QEL__3->SetBinContent(4,14419);
   LogNPE_nueCC_QEL__3->SetBinContent(5,6174);
   LogNPE_nueCC_QEL__3->SetBinContent(6,2027);
   LogNPE_nueCC_QEL__3->SetBinContent(7,509);
   LogNPE_nueCC_QEL__3->SetBinContent(8,85);
   LogNPE_nueCC_QEL__3->SetEntries(66132);
   LogNPE_nueCC_QEL__3->SetStats(0);

   ci = TColor::GetColor("#660000");
   LogNPE_nueCC_QEL__3->SetLineColor(ci);
   LogNPE_nueCC_QEL__3->SetLineWidth(4);
   LogNPE_nueCC_QEL__3->GetXaxis()->SetLabelFont(42);
   LogNPE_nueCC_QEL__3->GetXaxis()->SetLabelSize(0.035);
   LogNPE_nueCC_QEL__3->GetXaxis()->SetTitleSize(0.035);
   LogNPE_nueCC_QEL__3->GetXaxis()->SetTitleFont(42);
   LogNPE_nueCC_QEL__3->GetYaxis()->SetLabelFont(42);
   LogNPE_nueCC_QEL__3->GetYaxis()->SetLabelSize(0.035);
   LogNPE_nueCC_QEL__3->GetYaxis()->SetTitleSize(0.035);
   LogNPE_nueCC_QEL__3->GetYaxis()->SetTitleOffset(0);
   LogNPE_nueCC_QEL__3->GetYaxis()->SetTitleFont(42);
   LogNPE_nueCC_QEL__3->GetZaxis()->SetLabelFont(42);
   LogNPE_nueCC_QEL__3->GetZaxis()->SetLabelSize(0.035);
   LogNPE_nueCC_QEL__3->GetZaxis()->SetTitleSize(0.035);
   LogNPE_nueCC_QEL__3->GetZaxis()->SetTitleFont(42);
   LogNPE_nueCC_QEL__3->Draw("same");
   
   TH1F *LogNPE_nueCC_RES__4 = new TH1F("LogNPE_nueCC_RES__4","",7,5,7.2);
   LogNPE_nueCC_RES__4->SetBinContent(0,19);
   LogNPE_nueCC_RES__4->SetBinContent(1,81);
   LogNPE_nueCC_RES__4->SetBinContent(2,902);
   LogNPE_nueCC_RES__4->SetBinContent(3,5708);
   LogNPE_nueCC_RES__4->SetBinContent(4,10483);
   LogNPE_nueCC_RES__4->SetBinContent(5,7991);
   LogNPE_nueCC_RES__4->SetBinContent(6,3216);
   LogNPE_nueCC_RES__4->SetBinContent(7,922);
   LogNPE_nueCC_RES__4->SetBinContent(8,193);
   LogNPE_nueCC_RES__4->SetEntries(29515);
   LogNPE_nueCC_RES__4->SetStats(0);

   ci = TColor::GetColor("#cc0033");
   LogNPE_nueCC_RES__4->SetLineColor(ci);
   LogNPE_nueCC_RES__4->SetLineWidth(4);
   LogNPE_nueCC_RES__4->GetXaxis()->SetLabelFont(42);
   LogNPE_nueCC_RES__4->GetXaxis()->SetLabelSize(0.035);
   LogNPE_nueCC_RES__4->GetXaxis()->SetTitleSize(0.035);
   LogNPE_nueCC_RES__4->GetXaxis()->SetTitleFont(42);
   LogNPE_nueCC_RES__4->GetYaxis()->SetLabelFont(42);
   LogNPE_nueCC_RES__4->GetYaxis()->SetLabelSize(0.035);
   LogNPE_nueCC_RES__4->GetYaxis()->SetTitleSize(0.035);
   LogNPE_nueCC_RES__4->GetYaxis()->SetTitleOffset(0);
   LogNPE_nueCC_RES__4->GetYaxis()->SetTitleFont(42);
   LogNPE_nueCC_RES__4->GetZaxis()->SetLabelFont(42);
   LogNPE_nueCC_RES__4->GetZaxis()->SetLabelSize(0.035);
   LogNPE_nueCC_RES__4->GetZaxis()->SetTitleSize(0.035);
   LogNPE_nueCC_RES__4->GetZaxis()->SetTitleFont(42);
   LogNPE_nueCC_RES__4->Draw("same");
   
   TH1F *LogNPE_nueCC_DIS__5 = new TH1F("LogNPE_nueCC_DIS__5","",7,5,7.2);
   LogNPE_nueCC_DIS__5->SetBinContent(0,17);
   LogNPE_nueCC_DIS__5->SetBinContent(1,45);
   LogNPE_nueCC_DIS__5->SetBinContent(2,154);
   LogNPE_nueCC_DIS__5->SetBinContent(3,800);
   LogNPE_nueCC_DIS__5->SetBinContent(4,2664);
   LogNPE_nueCC_DIS__5->SetBinContent(5,5034);
   LogNPE_nueCC_DIS__5->SetBinContent(6,5223);
   LogNPE_nueCC_DIS__5->SetBinContent(7,3207);
   LogNPE_nueCC_DIS__5->SetBinContent(8,1164);
   LogNPE_nueCC_DIS__5->SetEntries(18308);
   LogNPE_nueCC_DIS__5->SetStats(0);

   ci = TColor::GetColor("#993300");
   LogNPE_nueCC_DIS__5->SetLineColor(ci);
   LogNPE_nueCC_DIS__5->SetLineWidth(4);
   LogNPE_nueCC_DIS__5->GetXaxis()->SetLabelFont(42);
   LogNPE_nueCC_DIS__5->GetXaxis()->SetLabelSize(0.035);
   LogNPE_nueCC_DIS__5->GetXaxis()->SetTitleSize(0.035);
   LogNPE_nueCC_DIS__5->GetXaxis()->SetTitleFont(42);
   LogNPE_nueCC_DIS__5->GetYaxis()->SetLabelFont(42);
   LogNPE_nueCC_DIS__5->GetYaxis()->SetLabelSize(0.035);
   LogNPE_nueCC_DIS__5->GetYaxis()->SetTitleSize(0.035);
   LogNPE_nueCC_DIS__5->GetYaxis()->SetTitleOffset(0);
   LogNPE_nueCC_DIS__5->GetYaxis()->SetTitleFont(42);
   LogNPE_nueCC_DIS__5->GetZaxis()->SetLabelFont(42);
   LogNPE_nueCC_DIS__5->GetZaxis()->SetLabelSize(0.035);
   LogNPE_nueCC_DIS__5->GetZaxis()->SetTitleSize(0.035);
   LogNPE_nueCC_DIS__5->GetZaxis()->SetTitleFont(42);
   LogNPE_nueCC_DIS__5->Draw("same");
   
   TLegend *leg = new TLegend(0.7,0.5,0.9,0.9,NULL,"brNDC");
   leg->SetBorderSize(1);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("LogNPE_nueCC","#nu_{e} CC - all","l");

   ci = TColor::GetColor("#ff0000");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(5);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("LogNPE_nueCC_COH","#nu_{e} CC - coh","l");

   ci = TColor::GetColor("#660033");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(4);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("LogNPE_nueCC_QEL","#nu_{e} CC - qel","l");

   ci = TColor::GetColor("#660000");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(4);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("LogNPE_nueCC_RES","#nu_{e} CC - res","l");

   ci = TColor::GetColor("#cc0033");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(4);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("LogNPE_nueCC_DIS","#nu_{e} CC - dis","l");

   ci = TColor::GetColor("#993300");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(4);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   c82->Modified();
   c82->cd();
   c82->SetSelected(c82);
}
