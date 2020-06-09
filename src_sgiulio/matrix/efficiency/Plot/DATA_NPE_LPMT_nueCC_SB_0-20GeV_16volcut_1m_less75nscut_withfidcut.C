void DATA_NPE_LPMT_nueCC_SB_0-20GeV_16volcut_1m_less75nscut_withfidcut()
{
//=========Macro generated from canvas: c67/
//=========  (Tue Jul  9 15:59:16 2019) by ROOT version 6.12/06
   TCanvas *c67 = new TCanvas("c67", "",1120,52,800,600);
   gStyle->SetOptStat(0);
   c67->Range(-3750000,-0.1615385,3.375e+07,1.184615);
   c67->SetFillColor(0);
   c67->SetBorderMode(0);
   c67->SetBorderSize(2);
   c67->SetBottomMargin(0.12);
   c67->SetFrameBorderMode(0);
   c67->SetFrameBorderMode(0);
   
   TH1F *Npe_LPMT_nueCC_SB__13 = new TH1F("Npe_LPMT_nueCC_SB__13","",12,0,3e+07);
   Npe_LPMT_nueCC_SB__13->SetBinContent(1,0.827791);
   Npe_LPMT_nueCC_SB__13->SetBinContent(2,0.9181818);
   Npe_LPMT_nueCC_SB__13->SetBinContent(3,0.9354839);
   Npe_LPMT_nueCC_SB__13->SetBinContent(4,1);
   Npe_LPMT_nueCC_SB__13->SetBinContent(5,1);
   Npe_LPMT_nueCC_SB__13->SetBinContent(6,1);
   Npe_LPMT_nueCC_SB__13->SetBinContent(7,1);
   Npe_LPMT_nueCC_SB__13->SetBinContent(11,1);
   Npe_LPMT_nueCC_SB__13->SetEntries(7.681457);
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
