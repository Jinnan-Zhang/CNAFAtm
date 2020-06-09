void GENIE_logE_bins_channels_nueCC()
{
//=========Macro generated from canvas: c552/
//=========  (Thu Jul 18 16:41:12 2019) by ROOT version 6.12/06
   TCanvas *c552 = new TCanvas("c552", "",65,480,1000,600);
   gStyle->SetOptStat(0);
   c552->Range(-1.25625,-242.3839,1.30625,29069.98);
   c552->SetFillColor(0);
   c552->SetBorderMode(0);
   c552->SetBorderSize(2);
   c552->SetBottomMargin(0.12);
   c552->SetFrameBorderMode(0);
   c552->SetFrameBorderMode(0);
   
   TH1F *LogE_nueCC__11 = new TH1F("LogE_nueCC__11","",8,-1,1.05);
   LogE_nueCC__11->SetBinContent(0,1061);
   LogE_nueCC__11->SetBinContent(1,4782);
   LogE_nueCC__11->SetBinContent(2,12815);
   LogE_nueCC__11->SetBinContent(3,20845);
   LogE_nueCC__11->SetBinContent(4,25050);
   LogE_nueCC__11->SetBinContent(5,21468);
   LogE_nueCC__11->SetBinContent(6,14663);
   LogE_nueCC__11->SetBinContent(7,8272);
   LogE_nueCC__11->SetBinContent(8,4312);
   LogE_nueCC__11->SetBinContent(9,1906);
   LogE_nueCC__11->SetEntries(115174);
   LogE_nueCC__11->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#ff0000");
   LogE_nueCC__11->SetFillColor(ci);
   LogE_nueCC__11->SetFillStyle(3002);

   ci = TColor::GetColor("#ff0000");
   LogE_nueCC__11->SetLineColor(ci);
   LogE_nueCC__11->SetLineWidth(5);
   LogE_nueCC__11->GetXaxis()->SetTitle("log_{10} (True E_{#nu} [GeV])");
   LogE_nueCC__11->GetXaxis()->SetLabelFont(42);
   LogE_nueCC__11->GetXaxis()->SetLabelSize(0.05);
   LogE_nueCC__11->GetXaxis()->SetTitleSize(0.05);
   LogE_nueCC__11->GetXaxis()->SetTitleFont(42);
   LogE_nueCC__11->GetYaxis()->SetTitle("entries");
   LogE_nueCC__11->GetYaxis()->SetLabelFont(42);
   LogE_nueCC__11->GetYaxis()->SetLabelSize(0.05);
   LogE_nueCC__11->GetYaxis()->SetTitleSize(0.035);
   LogE_nueCC__11->GetYaxis()->SetTitleOffset(1.2);
   LogE_nueCC__11->GetYaxis()->SetTitleFont(42);
   LogE_nueCC__11->GetZaxis()->SetLabelFont(42);
   LogE_nueCC__11->GetZaxis()->SetLabelSize(0.035);
   LogE_nueCC__11->GetZaxis()->SetTitleSize(0.035);
   LogE_nueCC__11->GetZaxis()->SetTitleFont(42);
   LogE_nueCC__11->Draw("");
   
   TH1F *LogE_nueCC_COH__12 = new TH1F("LogE_nueCC_COH__12","",8,-1,1.05);
   LogE_nueCC_COH__12->SetBinContent(2,22);
   LogE_nueCC_COH__12->SetBinContent(3,216);
   LogE_nueCC_COH__12->SetBinContent(4,326);
   LogE_nueCC_COH__12->SetBinContent(5,295);
   LogE_nueCC_COH__12->SetBinContent(6,203);
   LogE_nueCC_COH__12->SetBinContent(7,97);
   LogE_nueCC_COH__12->SetBinContent(8,43);
   LogE_nueCC_COH__12->SetBinContent(9,17);
   LogE_nueCC_COH__12->SetEntries(1219);
   LogE_nueCC_COH__12->SetStats(0);

   ci = TColor::GetColor("#660033");
   LogE_nueCC_COH__12->SetLineColor(ci);
   LogE_nueCC_COH__12->SetLineWidth(4);
   LogE_nueCC_COH__12->GetXaxis()->SetLabelFont(42);
   LogE_nueCC_COH__12->GetXaxis()->SetLabelSize(0.035);
   LogE_nueCC_COH__12->GetXaxis()->SetTitleSize(0.035);
   LogE_nueCC_COH__12->GetXaxis()->SetTitleFont(42);
   LogE_nueCC_COH__12->GetYaxis()->SetLabelFont(42);
   LogE_nueCC_COH__12->GetYaxis()->SetLabelSize(0.035);
   LogE_nueCC_COH__12->GetYaxis()->SetTitleSize(0.035);
   LogE_nueCC_COH__12->GetYaxis()->SetTitleOffset(0);
   LogE_nueCC_COH__12->GetYaxis()->SetTitleFont(42);
   LogE_nueCC_COH__12->GetZaxis()->SetLabelFont(42);
   LogE_nueCC_COH__12->GetZaxis()->SetLabelSize(0.035);
   LogE_nueCC_COH__12->GetZaxis()->SetTitleSize(0.035);
   LogE_nueCC_COH__12->GetZaxis()->SetTitleFont(42);
   LogE_nueCC_COH__12->Draw("same");
   
   TH1F *LogE_nueCC_QEL__13 = new TH1F("LogE_nueCC_QEL__13","",8,-1,1.05);
   LogE_nueCC_QEL__13->SetBinContent(0,1061);
   LogE_nueCC_QEL__13->SetBinContent(1,4782);
   LogE_nueCC_QEL__13->SetBinContent(2,12759);
   LogE_nueCC_QEL__13->SetBinContent(3,18252);
   LogE_nueCC_QEL__13->SetBinContent(4,15296);
   LogE_nueCC_QEL__13->SetBinContent(5,8454);
   LogE_nueCC_QEL__13->SetBinContent(6,3681);
   LogE_nueCC_QEL__13->SetBinContent(7,1352);
   LogE_nueCC_QEL__13->SetBinContent(8,401);
   LogE_nueCC_QEL__13->SetBinContent(9,94);
   LogE_nueCC_QEL__13->SetEntries(66132);
   LogE_nueCC_QEL__13->SetStats(0);

   ci = TColor::GetColor("#660000");
   LogE_nueCC_QEL__13->SetLineColor(ci);
   LogE_nueCC_QEL__13->SetLineWidth(4);
   LogE_nueCC_QEL__13->GetXaxis()->SetLabelFont(42);
   LogE_nueCC_QEL__13->GetXaxis()->SetLabelSize(0.035);
   LogE_nueCC_QEL__13->GetXaxis()->SetTitleSize(0.035);
   LogE_nueCC_QEL__13->GetXaxis()->SetTitleFont(42);
   LogE_nueCC_QEL__13->GetYaxis()->SetLabelFont(42);
   LogE_nueCC_QEL__13->GetYaxis()->SetLabelSize(0.035);
   LogE_nueCC_QEL__13->GetYaxis()->SetTitleSize(0.035);
   LogE_nueCC_QEL__13->GetYaxis()->SetTitleOffset(0);
   LogE_nueCC_QEL__13->GetYaxis()->SetTitleFont(42);
   LogE_nueCC_QEL__13->GetZaxis()->SetLabelFont(42);
   LogE_nueCC_QEL__13->GetZaxis()->SetLabelSize(0.035);
   LogE_nueCC_QEL__13->GetZaxis()->SetTitleSize(0.035);
   LogE_nueCC_QEL__13->GetZaxis()->SetTitleFont(42);
   LogE_nueCC_QEL__13->Draw("same");
   
   TH1F *LogE_nueCC_RES__14 = new TH1F("LogE_nueCC_RES__14","",8,-1,1.05);
   LogE_nueCC_RES__14->SetBinContent(2,28);
   LogE_nueCC_RES__14->SetBinContent(3,2172);
   LogE_nueCC_RES__14->SetBinContent(4,8334);
   LogE_nueCC_RES__14->SetBinContent(5,9730);
   LogE_nueCC_RES__14->SetBinContent(6,5906);
   LogE_nueCC_RES__14->SetBinContent(7,2326);
   LogE_nueCC_RES__14->SetBinContent(8,809);
   LogE_nueCC_RES__14->SetBinContent(9,210);
   LogE_nueCC_RES__14->SetEntries(29515);
   LogE_nueCC_RES__14->SetStats(0);

   ci = TColor::GetColor("#cc0033");
   LogE_nueCC_RES__14->SetLineColor(ci);
   LogE_nueCC_RES__14->SetLineWidth(4);
   LogE_nueCC_RES__14->GetXaxis()->SetLabelFont(42);
   LogE_nueCC_RES__14->GetXaxis()->SetLabelSize(0.035);
   LogE_nueCC_RES__14->GetXaxis()->SetTitleSize(0.035);
   LogE_nueCC_RES__14->GetXaxis()->SetTitleFont(42);
   LogE_nueCC_RES__14->GetYaxis()->SetLabelFont(42);
   LogE_nueCC_RES__14->GetYaxis()->SetLabelSize(0.035);
   LogE_nueCC_RES__14->GetYaxis()->SetTitleSize(0.035);
   LogE_nueCC_RES__14->GetYaxis()->SetTitleOffset(0);
   LogE_nueCC_RES__14->GetYaxis()->SetTitleFont(42);
   LogE_nueCC_RES__14->GetZaxis()->SetLabelFont(42);
   LogE_nueCC_RES__14->GetZaxis()->SetLabelSize(0.035);
   LogE_nueCC_RES__14->GetZaxis()->SetTitleSize(0.035);
   LogE_nueCC_RES__14->GetZaxis()->SetTitleFont(42);
   LogE_nueCC_RES__14->Draw("same");
   
   TH1F *LogE_nueCC_DIS__15 = new TH1F("LogE_nueCC_DIS__15","",8,-1,1.05);
   LogE_nueCC_DIS__15->SetBinContent(2,6);
   LogE_nueCC_DIS__15->SetBinContent(3,205);
   LogE_nueCC_DIS__15->SetBinContent(4,1094);
   LogE_nueCC_DIS__15->SetBinContent(5,2989);
   LogE_nueCC_DIS__15->SetBinContent(6,4873);
   LogE_nueCC_DIS__15->SetBinContent(7,4497);
   LogE_nueCC_DIS__15->SetBinContent(8,3059);
   LogE_nueCC_DIS__15->SetBinContent(9,1585);
   LogE_nueCC_DIS__15->SetEntries(18308);
   LogE_nueCC_DIS__15->SetStats(0);

   ci = TColor::GetColor("#993300");
   LogE_nueCC_DIS__15->SetLineColor(ci);
   LogE_nueCC_DIS__15->SetLineWidth(4);
   LogE_nueCC_DIS__15->GetXaxis()->SetLabelFont(42);
   LogE_nueCC_DIS__15->GetXaxis()->SetLabelSize(0.035);
   LogE_nueCC_DIS__15->GetXaxis()->SetTitleSize(0.035);
   LogE_nueCC_DIS__15->GetXaxis()->SetTitleFont(42);
   LogE_nueCC_DIS__15->GetYaxis()->SetLabelFont(42);
   LogE_nueCC_DIS__15->GetYaxis()->SetLabelSize(0.035);
   LogE_nueCC_DIS__15->GetYaxis()->SetTitleSize(0.035);
   LogE_nueCC_DIS__15->GetYaxis()->SetTitleOffset(0);
   LogE_nueCC_DIS__15->GetYaxis()->SetTitleFont(42);
   LogE_nueCC_DIS__15->GetZaxis()->SetLabelFont(42);
   LogE_nueCC_DIS__15->GetZaxis()->SetLabelSize(0.035);
   LogE_nueCC_DIS__15->GetZaxis()->SetTitleSize(0.035);
   LogE_nueCC_DIS__15->GetZaxis()->SetTitleFont(42);
   LogE_nueCC_DIS__15->Draw("same");
   
   TLegend *leg = new TLegend(0.7,0.5,0.9,0.9,NULL,"brNDC");
   leg->SetBorderSize(1);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("LogE_nueCC","#nu_{e} CC - all","l");

   ci = TColor::GetColor("#ff0000");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(5);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("LogE_nueCC_COH","#nu_{e} CC - coh","l");

   ci = TColor::GetColor("#660033");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(4);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("LogE_nueCC_QEL","#nu_{e} CC - qel","l");

   ci = TColor::GetColor("#660000");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(4);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("LogE_nueCC_RES","#nu_{e} CC - res","l");

   ci = TColor::GetColor("#cc0033");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(4);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("LogE_nueCC_DIS","#nu_{e} CC - dis","l");

   ci = TColor::GetColor("#993300");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(4);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   c552->Modified();
   c552->cd();
   c552->SetSelected(c552);
}
