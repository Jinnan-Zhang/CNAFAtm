void LOGDATA_NPE_LPMT_nueCC_SB_0-20GeV_16volcut_1m_less75nscut_withfidcut()
{
//=========Macro generated from canvas: c89/
//=========  (Tue Jul  9 15:59:17 2019) by ROOT version 6.12/06
   TCanvas *c89 = new TCanvas("c89", "",65,52,800,600);
   gStyle->SetOptStat(0);
   c89->Range(4.725,0.5907331,7.475,1.065049);
   c89->SetFillColor(0);
   c89->SetBorderMode(0);
   c89->SetBorderSize(2);
   c89->SetBottomMargin(0.12);
   c89->SetFrameBorderMode(0);
   c89->SetFrameBorderMode(0);
   
   TH1F *Lognpe_LPMT_nueCC_SB__15 = new TH1F("Lognpe_LPMT_nueCC_SB__15","",12,5,7.2);
   Lognpe_LPMT_nueCC_SB__15->SetBinContent(1,1);
   Lognpe_LPMT_nueCC_SB__15->SetBinContent(2,1);
   Lognpe_LPMT_nueCC_SB__15->SetBinContent(3,0.91);
   Lognpe_LPMT_nueCC_SB__15->SetBinContent(4,0.6644295);
   Lognpe_LPMT_nueCC_SB__15->SetBinContent(5,0.7922078);
   Lognpe_LPMT_nueCC_SB__15->SetBinContent(6,0.8322148);
   Lognpe_LPMT_nueCC_SB__15->SetBinContent(7,0.8650793);
   Lognpe_LPMT_nueCC_SB__15->SetBinContent(8,0.8672566);
   Lognpe_LPMT_nueCC_SB__15->SetBinContent(9,0.9242424);
   Lognpe_LPMT_nueCC_SB__15->SetBinContent(10,0.9393939);
   Lognpe_LPMT_nueCC_SB__15->SetBinContent(11,0.9615384);
   Lognpe_LPMT_nueCC_SB__15->SetBinContent(12,1);
   Lognpe_LPMT_nueCC_SB__15->SetBinContent(13,0.6666667);
   Lognpe_LPMT_nueCC_SB__15->SetEntries(10.75636);
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
