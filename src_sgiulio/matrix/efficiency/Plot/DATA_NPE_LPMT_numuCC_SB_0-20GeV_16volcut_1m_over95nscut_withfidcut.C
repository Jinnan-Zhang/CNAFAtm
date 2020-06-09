void DATA_NPE_LPMT_numuCC_SB_0-20GeV_16volcut_1m_over95nscut_withfidcut()
{
//=========Macro generated from canvas: c55/
//=========  (Tue Jul  9 15:59:16 2019) by ROOT version 6.12/06
   TCanvas *c55 = new TCanvas("c55", "",321,480,800,600);
   gStyle->SetOptStat(0);
   c55->Range(-3750000,-0.1302619,3.375e+07,0.9552537);
   c55->SetFillColor(0);
   c55->SetBorderMode(0);
   c55->SetBorderSize(2);
   c55->SetBottomMargin(0.12);
   c55->SetFrameBorderMode(0);
   c55->SetFrameBorderMode(0);
   
   TH1F *Npe_LPMT_numuCC_SB__14 = new TH1F("Npe_LPMT_numuCC_SB__14","",12,0,3e+07);
   Npe_LPMT_numuCC_SB__14->SetBinContent(1,0.8020386);
   Npe_LPMT_numuCC_SB__14->SetBinContent(2,0.806383);
   Npe_LPMT_numuCC_SB__14->SetBinContent(3,0.6902655);
   Npe_LPMT_numuCC_SB__14->SetBinContent(4,0.704918);
   Npe_LPMT_numuCC_SB__14->SetBinContent(5,0.6896552);
   Npe_LPMT_numuCC_SB__14->SetBinContent(6,0.6);
   Npe_LPMT_numuCC_SB__14->SetBinContent(7,0.6666667);
   Npe_LPMT_numuCC_SB__14->SetBinContent(8,0.4);
   Npe_LPMT_numuCC_SB__14->SetBinContent(9,0.75);
   Npe_LPMT_numuCC_SB__14->SetEntries(6.109927);
   Npe_LPMT_numuCC_SB__14->SetStats(0);
   Npe_LPMT_numuCC_SB__14->SetFillStyle(3002);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   Npe_LPMT_numuCC_SB__14->SetLineColor(ci);
   Npe_LPMT_numuCC_SB__14->SetLineWidth(5);
   Npe_LPMT_numuCC_SB__14->GetXaxis()->SetTitle("NPE_{LPMT}");
   Npe_LPMT_numuCC_SB__14->GetXaxis()->SetLabelFont(42);
   Npe_LPMT_numuCC_SB__14->GetXaxis()->SetLabelSize(0.05);
   Npe_LPMT_numuCC_SB__14->GetXaxis()->SetTitleSize(0.05);
   Npe_LPMT_numuCC_SB__14->GetXaxis()->SetTitleFont(42);
   Npe_LPMT_numuCC_SB__14->GetYaxis()->SetTitle("S/(S+B)");
   Npe_LPMT_numuCC_SB__14->GetYaxis()->SetLabelFont(42);
   Npe_LPMT_numuCC_SB__14->GetYaxis()->SetLabelSize(0.05);
   Npe_LPMT_numuCC_SB__14->GetYaxis()->SetTitleSize(0.035);
   Npe_LPMT_numuCC_SB__14->GetYaxis()->SetTitleOffset(1.2);
   Npe_LPMT_numuCC_SB__14->GetYaxis()->SetTitleFont(42);
   Npe_LPMT_numuCC_SB__14->GetZaxis()->SetLabelFont(42);
   Npe_LPMT_numuCC_SB__14->GetZaxis()->SetLabelSize(0.035);
   Npe_LPMT_numuCC_SB__14->GetZaxis()->SetTitleSize(0.035);
   Npe_LPMT_numuCC_SB__14->GetZaxis()->SetTitleFont(42);
   Npe_LPMT_numuCC_SB__14->Draw("");
   c55->Modified();
   c55->cd();
   c55->SetSelected(c55);
}
