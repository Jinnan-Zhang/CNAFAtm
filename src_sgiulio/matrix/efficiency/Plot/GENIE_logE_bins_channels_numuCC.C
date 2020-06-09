void GENIE_logE_bins_channels_numuCC()
{
//=========Macro generated from canvas: c552a/
//=========  (Thu Jul 18 16:41:13 2019) by ROOT version 6.12/06
   TCanvas *c552a = new TCanvas("c552a", "",65,52,1000,600);
   gStyle->SetOptStat(0);
   c552a->Range(-0.46875,2165.331,1.21875,37046.74);
   c552a->SetFillColor(0);
   c552a->SetBorderMode(0);
   c552a->SetBorderSize(2);
   c552a->SetBottomMargin(0.12);
   c552a->SetFrameBorderMode(0);
   c552a->SetFrameBorderMode(0);
   
   TH1F *LogE_numuCC__16 = new TH1F("LogE_numuCC__16","",8,-0.3,1.05);
   LogE_numuCC__16->SetBinContent(0,48301);
   LogE_numuCC__16->SetBinContent(1,29693);
   LogE_numuCC__16->SetBinContent(2,32263);
   LogE_numuCC__16->SetBinContent(3,30399);
   LogE_numuCC__16->SetBinContent(4,25454);
   LogE_numuCC__16->SetBinContent(5,20292);
   LogE_numuCC__16->SetBinContent(6,14617);
   LogE_numuCC__16->SetBinContent(7,10694);
   LogE_numuCC__16->SetBinContent(8,7585);
   LogE_numuCC__16->SetBinContent(9,6899);
   LogE_numuCC__16->SetEntries(226197);
   LogE_numuCC__16->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   LogE_numuCC__16->SetFillColor(ci);
   LogE_numuCC__16->SetFillStyle(3002);

   ci = TColor::GetColor("#000099");
   LogE_numuCC__16->SetLineColor(ci);
   LogE_numuCC__16->SetLineWidth(5);
   LogE_numuCC__16->GetXaxis()->SetTitle("log_{10} (True E_{#nu} [GeV])");
   LogE_numuCC__16->GetXaxis()->SetLabelFont(42);
   LogE_numuCC__16->GetXaxis()->SetLabelSize(0.05);
   LogE_numuCC__16->GetXaxis()->SetTitleSize(0.05);
   LogE_numuCC__16->GetXaxis()->SetTitleFont(42);
   LogE_numuCC__16->GetYaxis()->SetTitle("entries");
   LogE_numuCC__16->GetYaxis()->SetLabelFont(42);
   LogE_numuCC__16->GetYaxis()->SetLabelSize(0.05);
   LogE_numuCC__16->GetYaxis()->SetTitleSize(0.035);
   LogE_numuCC__16->GetYaxis()->SetTitleOffset(1.2);
   LogE_numuCC__16->GetYaxis()->SetTitleFont(42);
   LogE_numuCC__16->GetZaxis()->SetLabelFont(42);
   LogE_numuCC__16->GetZaxis()->SetLabelSize(0.035);
   LogE_numuCC__16->GetZaxis()->SetTitleSize(0.035);
   LogE_numuCC__16->GetZaxis()->SetTitleFont(42);
   LogE_numuCC__16->Draw("");
   
   TH1F *LogE_numuCC_COH__17 = new TH1F("LogE_numuCC_COH__17","",8,-0.3,1.05);
   LogE_numuCC_COH__17->SetBinContent(0,107);
   LogE_numuCC_COH__17->SetBinContent(1,276);
   LogE_numuCC_COH__17->SetBinContent(2,395);
   LogE_numuCC_COH__17->SetBinContent(3,398);
   LogE_numuCC_COH__17->SetBinContent(4,328);
   LogE_numuCC_COH__17->SetBinContent(5,265);
   LogE_numuCC_COH__17->SetBinContent(6,185);
   LogE_numuCC_COH__17->SetBinContent(7,120);
   LogE_numuCC_COH__17->SetBinContent(8,70);
   LogE_numuCC_COH__17->SetBinContent(9,58);
   LogE_numuCC_COH__17->SetEntries(2202);
   LogE_numuCC_COH__17->SetStats(0);

   ci = TColor::GetColor("#6600ff");
   LogE_numuCC_COH__17->SetLineColor(ci);
   LogE_numuCC_COH__17->SetLineWidth(4);
   LogE_numuCC_COH__17->GetXaxis()->SetLabelFont(42);
   LogE_numuCC_COH__17->GetXaxis()->SetLabelSize(0.035);
   LogE_numuCC_COH__17->GetXaxis()->SetTitleSize(0.035);
   LogE_numuCC_COH__17->GetXaxis()->SetTitleFont(42);
   LogE_numuCC_COH__17->GetYaxis()->SetLabelFont(42);
   LogE_numuCC_COH__17->GetYaxis()->SetLabelSize(0.035);
   LogE_numuCC_COH__17->GetYaxis()->SetTitleSize(0.035);
   LogE_numuCC_COH__17->GetYaxis()->SetTitleOffset(0);
   LogE_numuCC_COH__17->GetYaxis()->SetTitleFont(42);
   LogE_numuCC_COH__17->GetZaxis()->SetLabelFont(42);
   LogE_numuCC_COH__17->GetZaxis()->SetLabelSize(0.035);
   LogE_numuCC_COH__17->GetZaxis()->SetTitleSize(0.035);
   LogE_numuCC_COH__17->GetZaxis()->SetTitleFont(42);
   LogE_numuCC_COH__17->Draw("same");
   
   TH1F *LogE_numuCC_QEL__18 = new TH1F("LogE_numuCC_QEL__18","",8,-0.3,1.05);
   LogE_numuCC_QEL__18->SetBinContent(0,47494);
   LogE_numuCC_QEL__18->SetBinContent(1,22692);
   LogE_numuCC_QEL__18->SetBinContent(2,18351);
   LogE_numuCC_QEL__18->SetBinContent(3,12841);
   LogE_numuCC_QEL__18->SetBinContent(4,7863);
   LogE_numuCC_QEL__18->SetBinContent(5,4763);
   LogE_numuCC_QEL__18->SetBinContent(6,2476);
   LogE_numuCC_QEL__18->SetBinContent(7,1365);
   LogE_numuCC_QEL__18->SetBinContent(8,688);
   LogE_numuCC_QEL__18->SetBinContent(9,459);
   LogE_numuCC_QEL__18->SetEntries(118992);
   LogE_numuCC_QEL__18->SetStats(0);

   ci = TColor::GetColor("#003366");
   LogE_numuCC_QEL__18->SetLineColor(ci);
   LogE_numuCC_QEL__18->SetLineWidth(4);
   LogE_numuCC_QEL__18->GetXaxis()->SetLabelFont(42);
   LogE_numuCC_QEL__18->GetXaxis()->SetLabelSize(0.035);
   LogE_numuCC_QEL__18->GetXaxis()->SetTitleSize(0.035);
   LogE_numuCC_QEL__18->GetXaxis()->SetTitleFont(42);
   LogE_numuCC_QEL__18->GetYaxis()->SetLabelFont(42);
   LogE_numuCC_QEL__18->GetYaxis()->SetLabelSize(0.035);
   LogE_numuCC_QEL__18->GetYaxis()->SetTitleSize(0.035);
   LogE_numuCC_QEL__18->GetYaxis()->SetTitleOffset(0);
   LogE_numuCC_QEL__18->GetYaxis()->SetTitleFont(42);
   LogE_numuCC_QEL__18->GetZaxis()->SetLabelFont(42);
   LogE_numuCC_QEL__18->GetZaxis()->SetLabelSize(0.035);
   LogE_numuCC_QEL__18->GetZaxis()->SetTitleSize(0.035);
   LogE_numuCC_QEL__18->GetZaxis()->SetTitleFont(42);
   LogE_numuCC_QEL__18->Draw("same");
   
   TH1F *LogE_numuCC_RES__19 = new TH1F("LogE_numuCC_RES__19","",8,-0.3,1.05);
   LogE_numuCC_RES__19->SetBinContent(0,610);
   LogE_numuCC_RES__19->SetBinContent(1,6116);
   LogE_numuCC_RES__19->SetBinContent(2,11687);
   LogE_numuCC_RES__19->SetBinContent(3,13575);
   LogE_numuCC_RES__19->SetBinContent(4,11564);
   LogE_numuCC_RES__19->SetBinContent(5,7763);
   LogE_numuCC_RES__19->SetBinContent(6,4428);
   LogE_numuCC_RES__19->SetBinContent(7,2404);
   LogE_numuCC_RES__19->SetBinContent(8,1258);
   LogE_numuCC_RES__19->SetBinContent(9,786);
   LogE_numuCC_RES__19->SetEntries(60191);
   LogE_numuCC_RES__19->SetStats(0);

   ci = TColor::GetColor("#0066ff");
   LogE_numuCC_RES__19->SetLineColor(ci);
   LogE_numuCC_RES__19->SetLineWidth(4);
   LogE_numuCC_RES__19->GetXaxis()->SetLabelFont(42);
   LogE_numuCC_RES__19->GetXaxis()->SetLabelSize(0.035);
   LogE_numuCC_RES__19->GetXaxis()->SetTitleSize(0.035);
   LogE_numuCC_RES__19->GetXaxis()->SetTitleFont(42);
   LogE_numuCC_RES__19->GetYaxis()->SetLabelFont(42);
   LogE_numuCC_RES__19->GetYaxis()->SetLabelSize(0.035);
   LogE_numuCC_RES__19->GetYaxis()->SetTitleSize(0.035);
   LogE_numuCC_RES__19->GetYaxis()->SetTitleOffset(0);
   LogE_numuCC_RES__19->GetYaxis()->SetTitleFont(42);
   LogE_numuCC_RES__19->GetZaxis()->SetLabelFont(42);
   LogE_numuCC_RES__19->GetZaxis()->SetLabelSize(0.035);
   LogE_numuCC_RES__19->GetZaxis()->SetTitleSize(0.035);
   LogE_numuCC_RES__19->GetZaxis()->SetTitleFont(42);
   LogE_numuCC_RES__19->Draw("same");
   
   TH1F *LogE_numuCC_DIS__20 = new TH1F("LogE_numuCC_DIS__20","",8,-0.3,1.05);
   LogE_numuCC_DIS__20->SetBinContent(0,90);
   LogE_numuCC_DIS__20->SetBinContent(1,609);
   LogE_numuCC_DIS__20->SetBinContent(2,1830);
   LogE_numuCC_DIS__20->SetBinContent(3,3585);
   LogE_numuCC_DIS__20->SetBinContent(4,5699);
   LogE_numuCC_DIS__20->SetBinContent(5,7501);
   LogE_numuCC_DIS__20->SetBinContent(6,7528);
   LogE_numuCC_DIS__20->SetBinContent(7,6805);
   LogE_numuCC_DIS__20->SetBinContent(8,5569);
   LogE_numuCC_DIS__20->SetBinContent(9,5596);
   LogE_numuCC_DIS__20->SetEntries(44812);
   LogE_numuCC_DIS__20->SetStats(0);

   ci = TColor::GetColor("#666699");
   LogE_numuCC_DIS__20->SetLineColor(ci);
   LogE_numuCC_DIS__20->SetLineWidth(4);
   LogE_numuCC_DIS__20->GetXaxis()->SetLabelFont(42);
   LogE_numuCC_DIS__20->GetXaxis()->SetLabelSize(0.035);
   LogE_numuCC_DIS__20->GetXaxis()->SetTitleSize(0.035);
   LogE_numuCC_DIS__20->GetXaxis()->SetTitleFont(42);
   LogE_numuCC_DIS__20->GetYaxis()->SetLabelFont(42);
   LogE_numuCC_DIS__20->GetYaxis()->SetLabelSize(0.035);
   LogE_numuCC_DIS__20->GetYaxis()->SetTitleSize(0.035);
   LogE_numuCC_DIS__20->GetYaxis()->SetTitleOffset(0);
   LogE_numuCC_DIS__20->GetYaxis()->SetTitleFont(42);
   LogE_numuCC_DIS__20->GetZaxis()->SetLabelFont(42);
   LogE_numuCC_DIS__20->GetZaxis()->SetLabelSize(0.035);
   LogE_numuCC_DIS__20->GetZaxis()->SetTitleSize(0.035);
   LogE_numuCC_DIS__20->GetZaxis()->SetTitleFont(42);
   LogE_numuCC_DIS__20->Draw("same");
   
   TLegend *leg = new TLegend(0.7,0.5,0.9,0.9,NULL,"brNDC");
   leg->SetBorderSize(1);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("LogE_numuCC","#nu_{#mu} CC - all","l");

   ci = TColor::GetColor("#000099");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(5);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("LogE_numuCC_COH","#nu_{#mu} CC - coh","l");

   ci = TColor::GetColor("#6600ff");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(4);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("LogE_numuCC_QEL","#nu_{#mu} CC - qel","l");

   ci = TColor::GetColor("#003366");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(4);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("LogE_numuCC_RES","#nu_{#mu} CC - res","l");

   ci = TColor::GetColor("#0066ff");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(4);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("LogE_numuCC_DIS","#nu_{#mu} CC - dis","l");

   ci = TColor::GetColor("#666699");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(4);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   c552a->Modified();
   c552a->cd();
   c552a->SetSelected(c552a);
}
