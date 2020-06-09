void LOGNPE_LPMT_nueCC_SB_0-20GeV_16volcut_1m_less75nscut_withfidcut()
{
//=========Macro generated from canvas: c89/
//=========  (Thu Aug 29 17:02:17 2019) by ROOT version 6.12/06
   TCanvas *c89 = new TCanvas("c89", "",65,52,800,600);
   gStyle->SetOptStat(0);
   c89->Range(4.65625,-0.1615385,8.09375,1.184615);
   c89->SetFillColor(0);
   c89->SetBorderMode(0);
   c89->SetBorderSize(2);
   c89->SetBottomMargin(0.12);
   c89->SetFrameBorderMode(0);
   c89->SetFrameBorderMode(0);
   
   TH1F *Lognpe_LPMT_nueCC_SB__15 = new TH1F("Lognpe_LPMT_nueCC_SB__15","",35,5,7.75);
   Lognpe_LPMT_nueCC_SB__15->SetBinContent(1,0.9821883);
   Lognpe_LPMT_nueCC_SB__15->SetBinContent(2,0.9982079);
   Lognpe_LPMT_nueCC_SB__15->SetBinContent(3,0.9963548);
   Lognpe_LPMT_nueCC_SB__15->SetBinContent(4,0.9963437);
   Lognpe_LPMT_nueCC_SB__15->SetBinContent(5,0.9979036);
   Lognpe_LPMT_nueCC_SB__15->SetBinContent(6,0.9606174);
   Lognpe_LPMT_nueCC_SB__15->SetBinContent(7,0.880726);
   Lognpe_LPMT_nueCC_SB__15->SetBinContent(8,0.7710295);
   Lognpe_LPMT_nueCC_SB__15->SetBinContent(9,0.7045908);
   Lognpe_LPMT_nueCC_SB__15->SetBinContent(10,0.6951018);
   Lognpe_LPMT_nueCC_SB__15->SetBinContent(11,0.7607527);
   Lognpe_LPMT_nueCC_SB__15->SetBinContent(12,0.7984952);
   Lognpe_LPMT_nueCC_SB__15->SetBinContent(13,0.8398162);
   Lognpe_LPMT_nueCC_SB__15->SetBinContent(14,0.8479792);
   Lognpe_LPMT_nueCC_SB__15->SetBinContent(15,0.8443272);
   Lognpe_LPMT_nueCC_SB__15->SetBinContent(16,0.8745263);
   Lognpe_LPMT_nueCC_SB__15->SetBinContent(17,0.9002481);
   Lognpe_LPMT_nueCC_SB__15->SetBinContent(18,0.9029649);
   Lognpe_LPMT_nueCC_SB__15->SetBinContent(19,0.8954683);
   Lognpe_LPMT_nueCC_SB__15->SetBinContent(20,0.9106648);
   Lognpe_LPMT_nueCC_SB__15->SetBinContent(21,0.897518);
   Lognpe_LPMT_nueCC_SB__15->SetBinContent(22,0.9078695);
   Lognpe_LPMT_nueCC_SB__15->SetBinContent(23,0.9209581);
   Lognpe_LPMT_nueCC_SB__15->SetBinContent(24,0.937299);
   Lognpe_LPMT_nueCC_SB__15->SetBinContent(25,0.9394572);
   Lognpe_LPMT_nueCC_SB__15->SetBinContent(26,0.9659686);
   Lognpe_LPMT_nueCC_SB__15->SetBinContent(27,0.9698113);
   Lognpe_LPMT_nueCC_SB__15->SetBinContent(28,0.9710145);
   Lognpe_LPMT_nueCC_SB__15->SetBinContent(29,1);
   Lognpe_LPMT_nueCC_SB__15->SetBinContent(30,1);
   Lognpe_LPMT_nueCC_SB__15->SetBinContent(31,0.974359);
   Lognpe_LPMT_nueCC_SB__15->SetBinContent(32,1);
   Lognpe_LPMT_nueCC_SB__15->SetEntries(29.04256);
   Lognpe_LPMT_nueCC_SB__15->SetStats(0);
   Lognpe_LPMT_nueCC_SB__15->SetFillStyle(3002);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#ff0000");
   Lognpe_LPMT_nueCC_SB__15->SetLineColor(ci);
   Lognpe_LPMT_nueCC_SB__15->SetLineWidth(5);
   Lognpe_LPMT_nueCC_SB__15->GetXaxis()->SetTitle("log_{10} (NPE_{LPMT})");
   Lognpe_LPMT_nueCC_SB__15->GetXaxis()->SetLabelFont(42);
   Lognpe_LPMT_nueCC_SB__15->GetXaxis()->SetLabelSize(0.05);
   Lognpe_LPMT_nueCC_SB__15->GetXaxis()->SetTitleSize(0.05);
   Lognpe_LPMT_nueCC_SB__15->GetXaxis()->SetTitleFont(42);
   Lognpe_LPMT_nueCC_SB__15->GetYaxis()->SetTitle("S/(S+B)");
   Lognpe_LPMT_nueCC_SB__15->GetYaxis()->SetLabelFont(42);
   Lognpe_LPMT_nueCC_SB__15->GetYaxis()->SetLabelSize(0.05);
   Lognpe_LPMT_nueCC_SB__15->GetYaxis()->SetTitleSize(0.035);
   Lognpe_LPMT_nueCC_SB__15->GetYaxis()->SetTitleOffset(1.2);
   Lognpe_LPMT_nueCC_SB__15->GetYaxis()->SetTitleFont(42);
   Lognpe_LPMT_nueCC_SB__15->GetZaxis()->SetLabelFont(42);
   Lognpe_LPMT_nueCC_SB__15->GetZaxis()->SetLabelSize(0.035);
   Lognpe_LPMT_nueCC_SB__15->GetZaxis()->SetTitleSize(0.035);
   Lognpe_LPMT_nueCC_SB__15->GetZaxis()->SetTitleFont(42);
   Lognpe_LPMT_nueCC_SB__15->Draw("");
   c89->Modified();
   c89->cd();
   c89->SetSelected(c89);
}
