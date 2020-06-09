void NPE_LPMT_nueCC_SB_0-20GeV_16volcut_1m_less75nscut_withfidcut()
{
//=========Macro generated from canvas: c67/
//=========  (Thu Aug 29 17:02:16 2019) by ROOT version 6.12/06
   TCanvas *c67 = new TCanvas("c67", "",1120,52,800,600);
   gStyle->SetOptStat(0);
   c67->Range(-3750000,-0.1615385,3.375e+07,1.184615);
   c67->SetFillColor(0);
   c67->SetBorderMode(0);
   c67->SetBorderSize(2);
   c67->SetBottomMargin(0.12);
   c67->SetFrameBorderMode(0);
   c67->SetFrameBorderMode(0);
   
   TH1F *Npe_LPMT_nueCC_SB__13 = new TH1F("Npe_LPMT_nueCC_SB__13","",35,0,3e+07);
   Npe_LPMT_nueCC_SB__13->SetBinContent(1,0.8157257);
   Npe_LPMT_nueCC_SB__13->SetBinContent(2,0.8490769);
   Npe_LPMT_nueCC_SB__13->SetBinContent(3,0.8939224);
   Npe_LPMT_nueCC_SB__13->SetBinContent(4,0.9005503);
   Npe_LPMT_nueCC_SB__13->SetBinContent(5,0.9010448);
   Npe_LPMT_nueCC_SB__13->SetBinContent(6,0.9054178);
   Npe_LPMT_nueCC_SB__13->SetBinContent(7,0.9125168);
   Npe_LPMT_nueCC_SB__13->SetBinContent(8,0.9381818);
   Npe_LPMT_nueCC_SB__13->SetBinContent(9,0.9384615);
   Npe_LPMT_nueCC_SB__13->SetBinContent(10,0.9438596);
   Npe_LPMT_nueCC_SB__13->SetBinContent(11,0.9414226);
   Npe_LPMT_nueCC_SB__13->SetBinContent(12,0.9701493);
   Npe_LPMT_nueCC_SB__13->SetBinContent(13,0.9621212);
   Npe_LPMT_nueCC_SB__13->SetBinContent(14,0.990566);
   Npe_LPMT_nueCC_SB__13->SetBinContent(15,0.9469026);
   Npe_LPMT_nueCC_SB__13->SetBinContent(16,0.9876543);
   Npe_LPMT_nueCC_SB__13->SetBinContent(17,0.9714286);
   Npe_LPMT_nueCC_SB__13->SetBinContent(18,0.9558824);
   Npe_LPMT_nueCC_SB__13->SetBinContent(19,0.9777778);
   Npe_LPMT_nueCC_SB__13->SetBinContent(20,1);
   Npe_LPMT_nueCC_SB__13->SetBinContent(21,1);
   Npe_LPMT_nueCC_SB__13->SetBinContent(22,1);
   Npe_LPMT_nueCC_SB__13->SetBinContent(23,1);
   Npe_LPMT_nueCC_SB__13->SetBinContent(24,1);
   Npe_LPMT_nueCC_SB__13->SetBinContent(25,1);
   Npe_LPMT_nueCC_SB__13->SetBinContent(26,1);
   Npe_LPMT_nueCC_SB__13->SetBinContent(27,0.9166667);
   Npe_LPMT_nueCC_SB__13->SetBinContent(28,1);
   Npe_LPMT_nueCC_SB__13->SetBinContent(29,1);
   Npe_LPMT_nueCC_SB__13->SetBinContent(30,1);
   Npe_LPMT_nueCC_SB__13->SetBinContent(31,1);
   Npe_LPMT_nueCC_SB__13->SetBinContent(32,1);
   Npe_LPMT_nueCC_SB__13->SetBinContent(33,1);
   Npe_LPMT_nueCC_SB__13->SetEntries(31.61933);
   Npe_LPMT_nueCC_SB__13->SetStats(0);
   Npe_LPMT_nueCC_SB__13->SetFillStyle(3002);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#ff0000");
   Npe_LPMT_nueCC_SB__13->SetLineColor(ci);
   Npe_LPMT_nueCC_SB__13->SetLineWidth(5);
   Npe_LPMT_nueCC_SB__13->GetXaxis()->SetTitle("NPE_{LPMT}");
   Npe_LPMT_nueCC_SB__13->GetXaxis()->SetLabelFont(42);
   Npe_LPMT_nueCC_SB__13->GetXaxis()->SetLabelSize(0.05);
   Npe_LPMT_nueCC_SB__13->GetXaxis()->SetTitleSize(0.05);
   Npe_LPMT_nueCC_SB__13->GetXaxis()->SetTitleFont(42);
   Npe_LPMT_nueCC_SB__13->GetYaxis()->SetTitle("S/(S+B)");
   Npe_LPMT_nueCC_SB__13->GetYaxis()->SetLabelFont(42);
   Npe_LPMT_nueCC_SB__13->GetYaxis()->SetLabelSize(0.05);
   Npe_LPMT_nueCC_SB__13->GetYaxis()->SetTitleSize(0.035);
   Npe_LPMT_nueCC_SB__13->GetYaxis()->SetTitleOffset(1.2);
   Npe_LPMT_nueCC_SB__13->GetYaxis()->SetTitleFont(42);
   Npe_LPMT_nueCC_SB__13->GetZaxis()->SetLabelFont(42);
   Npe_LPMT_nueCC_SB__13->GetZaxis()->SetLabelSize(0.035);
   Npe_LPMT_nueCC_SB__13->GetZaxis()->SetTitleSize(0.035);
   Npe_LPMT_nueCC_SB__13->GetZaxis()->SetTitleFont(42);
   Npe_LPMT_nueCC_SB__13->Draw("");
   c67->Modified();
   c67->cd();
   c67->SetSelected(c67);
}
