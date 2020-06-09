void Ev_numuCC_SB_0-20GeV_16volcut_1m_over95nscut_withfidcut()
{
//=========Macro generated from canvas: c55/
//=========  (Mon Jan 14 15:43:08 2019) by ROOT version 6.13/08
   TCanvas *c55 = new TCanvas("c55", "",307,297,800,600);
   gStyle->SetOptStat(0);
   c55->Range(-2.5,0.620233,22.5,1.010375);
   c55->SetFillColor(0);
   c55->SetBorderMode(0);
   c55->SetBorderSize(2);
   c55->SetBottomMargin(0.12);
   c55->SetFrameBorderMode(0);
   c55->SetFrameBorderMode(0);
   
   TH1F *Ev_LPMT_numuCC_SB__14 = new TH1F("Ev_LPMT_numuCC_SB__14","",35,0,20);
   Ev_LPMT_numuCC_SB__14->SetBinContent(1,0.95687);
   Ev_LPMT_numuCC_SB__14->SetBinContent(2,0.9006793);
   Ev_LPMT_numuCC_SB__14->SetBinContent(3,0.8185133);
   Ev_LPMT_numuCC_SB__14->SetBinContent(4,0.7895623);
   Ev_LPMT_numuCC_SB__14->SetBinContent(5,0.7887686);
   Ev_LPMT_numuCC_SB__14->SetBinContent(6,0.7835344);
   Ev_LPMT_numuCC_SB__14->SetBinContent(7,0.759204);
   Ev_LPMT_numuCC_SB__14->SetBinContent(8,0.7557355);
   Ev_LPMT_numuCC_SB__14->SetBinContent(9,0.7266667);
   Ev_LPMT_numuCC_SB__14->SetBinContent(10,0.7372709);
   Ev_LPMT_numuCC_SB__14->SetBinContent(11,0.751861);
   Ev_LPMT_numuCC_SB__14->SetBinContent(12,0.7588425);
   Ev_LPMT_numuCC_SB__14->SetBinContent(13,0.772);
   Ev_LPMT_numuCC_SB__14->SetBinContent(14,0.7172131);
   Ev_LPMT_numuCC_SB__14->SetBinContent(15,0.7365854);
   Ev_LPMT_numuCC_SB__14->SetBinContent(16,0.7919075);
   Ev_LPMT_numuCC_SB__14->SetBinContent(17,0.778481);
   Ev_LPMT_numuCC_SB__14->SetBinContent(18,0.6956522);
   Ev_LPMT_numuCC_SB__14->SetBinContent(19,0.7421875);
   Ev_LPMT_numuCC_SB__14->SetBinContent(20,0.7457627);
   Ev_LPMT_numuCC_SB__14->SetBinContent(21,0.7307692);
   Ev_LPMT_numuCC_SB__14->SetBinContent(22,0.7291667);
   Ev_LPMT_numuCC_SB__14->SetBinContent(23,0.7435898);
   Ev_LPMT_numuCC_SB__14->SetBinContent(24,0.6973684);
   Ev_LPMT_numuCC_SB__14->SetBinContent(25,0.8676471);
   Ev_LPMT_numuCC_SB__14->SetBinContent(26,0.7906977);
   Ev_LPMT_numuCC_SB__14->SetBinContent(27,0.7368421);
   Ev_LPMT_numuCC_SB__14->SetBinContent(28,0.680851);
   Ev_LPMT_numuCC_SB__14->SetBinContent(29,0.7837838);
   Ev_LPMT_numuCC_SB__14->SetBinContent(30,0.6904762);
   Ev_LPMT_numuCC_SB__14->SetBinContent(31,0.7804878);
   Ev_LPMT_numuCC_SB__14->SetBinContent(32,0.7272727);
   Ev_LPMT_numuCC_SB__14->SetBinContent(33,0.8157895);
   Ev_LPMT_numuCC_SB__14->SetBinContent(34,0.8518519);
   Ev_LPMT_numuCC_SB__14->SetBinContent(35,0.7307692);
   Ev_LPMT_numuCC_SB__14->SetEntries(26.86466);
   Ev_LPMT_numuCC_SB__14->SetStats(0);
   Ev_LPMT_numuCC_SB__14->SetFillStyle(3002);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   Ev_LPMT_numuCC_SB__14->SetLineColor(ci);
   Ev_LPMT_numuCC_SB__14->SetLineWidth(5);
   Ev_LPMT_numuCC_SB__14->GetXaxis()->SetTitle("E_{#nu} [GeV]");
   Ev_LPMT_numuCC_SB__14->GetXaxis()->SetLabelFont(42);
   Ev_LPMT_numuCC_SB__14->GetXaxis()->SetLabelSize(0.05);
   Ev_LPMT_numuCC_SB__14->GetXaxis()->SetTitleSize(0.05);
   Ev_LPMT_numuCC_SB__14->GetXaxis()->SetTitleFont(42);
   Ev_LPMT_numuCC_SB__14->GetYaxis()->SetTitle("S/(S+B)");
   Ev_LPMT_numuCC_SB__14->GetYaxis()->SetLabelFont(42);
   Ev_LPMT_numuCC_SB__14->GetYaxis()->SetLabelSize(0.05);
   Ev_LPMT_numuCC_SB__14->GetYaxis()->SetTitleSize(0.035);
   Ev_LPMT_numuCC_SB__14->GetYaxis()->SetTitleOffset(1.2);
   Ev_LPMT_numuCC_SB__14->GetYaxis()->SetTitleFont(42);
   Ev_LPMT_numuCC_SB__14->GetZaxis()->SetLabelFont(42);
   Ev_LPMT_numuCC_SB__14->GetZaxis()->SetLabelSize(0.035);
   Ev_LPMT_numuCC_SB__14->GetZaxis()->SetTitleSize(0.035);
   Ev_LPMT_numuCC_SB__14->GetZaxis()->SetTitleFont(42);
   Ev_LPMT_numuCC_SB__14->Draw("");
   c55->Modified();
   c55->cd();
   c55->SetSelected(c55);
}
