void NPE_LPMT_numuCC_SB_0-20GeV_16volcut_1m_less75nscut_withfidcut()
{
//=========Macro generated from canvas: c55/
//=========  (Sun Jan 13 11:35:58 2019) by ROOT version 6.13/08
   TCanvas *c55 = new TCanvas("c55", "",285,275,800,600);
   gStyle->SetOptStat(0);
   c55->Range(-3750000,-0.1615385,3.375e+07,1.184615);
   c55->SetFillColor(0);
   c55->SetBorderMode(0);
   c55->SetBorderSize(2);
   c55->SetBottomMargin(0.12);
   c55->SetFrameBorderMode(0);
   c55->SetFrameBorderMode(0);
   
   TH1F *Npe_LPMT_numuCC_SB__14 = new TH1F("Npe_LPMT_numuCC_SB__14","",35,0,3e+07);
   Npe_LPMT_numuCC_SB__14->SetBinContent(1,0.8410853);
   Npe_LPMT_numuCC_SB__14->SetBinContent(2,0.9534386);
   Npe_LPMT_numuCC_SB__14->SetBinContent(3,0.9672785);
   Npe_LPMT_numuCC_SB__14->SetBinContent(4,0.9725225);
   Npe_LPMT_numuCC_SB__14->SetBinContent(5,0.9543509);
   Npe_LPMT_numuCC_SB__14->SetBinContent(6,0.9619978);
   Npe_LPMT_numuCC_SB__14->SetBinContent(7,0.9655688);
   Npe_LPMT_numuCC_SB__14->SetBinContent(8,0.9575372);
   Npe_LPMT_numuCC_SB__14->SetBinContent(9,0.9642857);
   Npe_LPMT_numuCC_SB__14->SetBinContent(10,0.9615384);
   Npe_LPMT_numuCC_SB__14->SetBinContent(11,0.92891);
   Npe_LPMT_numuCC_SB__14->SetBinContent(12,0.9259259);
   Npe_LPMT_numuCC_SB__14->SetBinContent(13,0.9646018);
   Npe_LPMT_numuCC_SB__14->SetBinContent(14,0.9390244);
   Npe_LPMT_numuCC_SB__14->SetBinContent(15,0.9384615);
   Npe_LPMT_numuCC_SB__14->SetBinContent(16,1);
   Npe_LPMT_numuCC_SB__14->SetBinContent(17,0.8863636);
   Npe_LPMT_numuCC_SB__14->SetBinContent(18,0.9722222);
   Npe_LPMT_numuCC_SB__14->SetBinContent(19,0.9);
   Npe_LPMT_numuCC_SB__14->SetBinContent(20,0.7894737);
   Npe_LPMT_numuCC_SB__14->SetBinContent(21,0.8888889);
   Npe_LPMT_numuCC_SB__14->SetBinContent(22,0.8235294);
   Npe_LPMT_numuCC_SB__14->SetBinContent(23,0.7272727);
   Npe_LPMT_numuCC_SB__14->SetBinContent(24,0.6666667);
   Npe_LPMT_numuCC_SB__14->SetBinContent(25,0.6666667);
   Npe_LPMT_numuCC_SB__14->SetBinContent(26,1);
   Npe_LPMT_numuCC_SB__14->SetBinContent(30,1);
   Npe_LPMT_numuCC_SB__14->SetEntries(24.51761);
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
   Npe_LPMT_numuCC_SB__14->GetYaxis()->SetTitle("S/#sqrt{S+B}");
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
