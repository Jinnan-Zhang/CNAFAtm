void GENIE_logtrueEnergy()
{
//=========Macro generated from canvas: c81/
//=========  (Fri May 24 17:46:14 2019) by ROOT version 6.12/06
   TCanvas *c81 = new TCanvas("c81", "",81,52,1000,600);
   gStyle->SetOptStat(0);
   c81->Range(1.71875,3.11121,4.53125,5.279003);
   c81->SetFillColor(0);
   c81->SetBorderMode(0);
   c81->SetBorderSize(2);
   c81->SetLogy();
   c81->SetBottomMargin(0.12);
   c81->SetFrameBorderMode(0);
   c81->SetFrameBorderMode(0);
   
   TH1F *LogTrueE_numu__1 = new TH1F("LogTrueE_numu__1","",20,2,4.25);
   LogTrueE_numu__1->SetBinContent(0,4376);
   LogTrueE_numu__1->SetBinContent(1,4703);
   LogTrueE_numu__1->SetBinContent(2,10060);
   LogTrueE_numu__1->SetBinContent(3,20400);
   LogTrueE_numu__1->SetBinContent(4,32430);
   LogTrueE_numu__1->SetBinContent(5,41920);
   LogTrueE_numu__1->SetBinContent(6,48189);
   LogTrueE_numu__1->SetBinContent(7,56107);
   LogTrueE_numu__1->SetBinContent(8,60908);
   LogTrueE_numu__1->SetBinContent(9,60109);
   LogTrueE_numu__1->SetBinContent(10,57763);
   LogTrueE_numu__1->SetBinContent(11,53992);
   LogTrueE_numu__1->SetBinContent(12,47006);
   LogTrueE_numu__1->SetBinContent(13,39521);
   LogTrueE_numu__1->SetBinContent(14,32876);
   LogTrueE_numu__1->SetBinContent(15,26417);
   LogTrueE_numu__1->SetBinContent(16,21884);
   LogTrueE_numu__1->SetBinContent(17,16686);
   LogTrueE_numu__1->SetBinContent(18,13239);
   LogTrueE_numu__1->SetBinContent(19,10542);
   LogTrueE_numu__1->SetBinContent(20,8156);
   LogTrueE_numu__1->SetBinContent(21,2984);
   LogTrueE_numu__1->SetEntries(670268);
   LogTrueE_numu__1->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   LogTrueE_numu__1->SetLineColor(ci);
   LogTrueE_numu__1->SetLineWidth(5);
   LogTrueE_numu__1->GetXaxis()->SetTitle("log_{10} (True Energy [MeV])");
   LogTrueE_numu__1->GetXaxis()->SetLabelFont(42);
   LogTrueE_numu__1->GetXaxis()->SetLabelSize(0.05);
   LogTrueE_numu__1->GetXaxis()->SetTitleSize(0.05);
   LogTrueE_numu__1->GetXaxis()->SetTitleFont(42);
   LogTrueE_numu__1->GetYaxis()->SetTitle("entries");
   LogTrueE_numu__1->GetYaxis()->SetLabelFont(42);
   LogTrueE_numu__1->GetYaxis()->SetLabelSize(0.05);
   LogTrueE_numu__1->GetYaxis()->SetTitleSize(0.035);
   LogTrueE_numu__1->GetYaxis()->SetTitleOffset(1.2);
   LogTrueE_numu__1->GetYaxis()->SetTitleFont(42);
   LogTrueE_numu__1->GetZaxis()->SetLabelFont(42);
   LogTrueE_numu__1->GetZaxis()->SetLabelSize(0.035);
   LogTrueE_numu__1->GetZaxis()->SetTitleSize(0.035);
   LogTrueE_numu__1->GetZaxis()->SetTitleFont(42);
   LogTrueE_numu__1->Draw("");
   
   TH1F *LogTrueE_nue__2 = new TH1F("LogTrueE_nue__2","",20,2,4.25);
   LogTrueE_nue__2->SetBinContent(0,4309);
   LogTrueE_nue__2->SetBinContent(1,4833);
   LogTrueE_nue__2->SetBinContent(2,8308);
   LogTrueE_nue__2->SetBinContent(3,12922);
   LogTrueE_nue__2->SetBinContent(4,18371);
   LogTrueE_nue__2->SetBinContent(5,22676);
   LogTrueE_nue__2->SetBinContent(6,26142);
   LogTrueE_nue__2->SetBinContent(7,29877);
   LogTrueE_nue__2->SetBinContent(8,31248);
   LogTrueE_nue__2->SetBinContent(9,29909);
   LogTrueE_nue__2->SetBinContent(10,28137);
   LogTrueE_nue__2->SetBinContent(11,25432);
   LogTrueE_nue__2->SetBinContent(12,21495);
   LogTrueE_nue__2->SetBinContent(13,17180);
   LogTrueE_nue__2->SetBinContent(14,13778);
   LogTrueE_nue__2->SetBinContent(15,10672);
   LogTrueE_nue__2->SetBinContent(16,8151);
   LogTrueE_nue__2->SetBinContent(17,5901);
   LogTrueE_nue__2->SetBinContent(18,4342);
   LogTrueE_nue__2->SetBinContent(19,3129);
   LogTrueE_nue__2->SetBinContent(20,2189);
   LogTrueE_nue__2->SetBinContent(21,731);
   LogTrueE_nue__2->SetEntries(329732);
   LogTrueE_nue__2->SetStats(0);

   ci = TColor::GetColor("#ff0000");
   LogTrueE_nue__2->SetLineColor(ci);
   LogTrueE_nue__2->SetLineWidth(5);
   LogTrueE_nue__2->GetXaxis()->SetTitle("log_{10} (True Energy [MeV])");
   LogTrueE_nue__2->GetXaxis()->SetLabelFont(42);
   LogTrueE_nue__2->GetXaxis()->SetLabelSize(0.05);
   LogTrueE_nue__2->GetXaxis()->SetTitleSize(0.05);
   LogTrueE_nue__2->GetXaxis()->SetTitleFont(42);
   LogTrueE_nue__2->GetYaxis()->SetTitle("entries");
   LogTrueE_nue__2->GetYaxis()->SetLabelFont(42);
   LogTrueE_nue__2->GetYaxis()->SetLabelSize(0.05);
   LogTrueE_nue__2->GetYaxis()->SetTitleSize(0.035);
   LogTrueE_nue__2->GetYaxis()->SetTitleOffset(1.2);
   LogTrueE_nue__2->GetYaxis()->SetTitleFont(42);
   LogTrueE_nue__2->GetZaxis()->SetLabelFont(42);
   LogTrueE_nue__2->GetZaxis()->SetLabelSize(0.035);
   LogTrueE_nue__2->GetZaxis()->SetTitleSize(0.035);
   LogTrueE_nue__2->GetZaxis()->SetTitleFont(42);
   LogTrueE_nue__2->Draw("same");
   
   TLegend *leg = new TLegend(0.5,0.15,0.6,0.3,NULL,"brNDC");
   leg->SetBorderSize(1);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("LogTrueE_numu","#nu_{#mu}","l");

   ci = TColor::GetColor("#000099");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(5);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("LogTrueE_nue","#nu_{e}","l");

   ci = TColor::GetColor("#ff0000");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(5);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   c81->Modified();
   c81->cd();
   c81->SetSelected(c81);
}
