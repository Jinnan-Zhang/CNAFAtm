void NPE_LPMT_numuCC_SB_0-20GeV_16volcut_1m_over95nscut_withfidcut()
{
//=========Macro generated from canvas: c55/
//=========  (Thu Aug 29 17:02:16 2019) by ROOT version 6.12/06
   TCanvas *c55 = new TCanvas("c55", "",321,480,800,600);
   gStyle->SetOptStat(0);
   c55->Range(-3750000,0.08528846,3.375e+07,1.145385);
   c55->SetFillColor(0);
   c55->SetBorderMode(0);
   c55->SetBorderSize(2);
   c55->SetBottomMargin(0.12);
   c55->SetFrameBorderMode(0);
   c55->SetFrameBorderMode(0);
   
   TH1F *Npe_LPMT_numuCC_SB__14 = new TH1F("Npe_LPMT_numuCC_SB__14","",35,0,3e+07);
   Npe_LPMT_numuCC_SB__14->SetBinContent(1,0.759912);
   Npe_LPMT_numuCC_SB__14->SetBinContent(2,0.8030572);
   Npe_LPMT_numuCC_SB__14->SetBinContent(3,0.8352658);
   Npe_LPMT_numuCC_SB__14->SetBinContent(4,0.8420911);
   Npe_LPMT_numuCC_SB__14->SetBinContent(5,0.8321357);
   Npe_LPMT_numuCC_SB__14->SetBinContent(6,0.804828);
   Npe_LPMT_numuCC_SB__14->SetBinContent(7,0.7868853);
   Npe_LPMT_numuCC_SB__14->SetBinContent(8,0.7797798);
   Npe_LPMT_numuCC_SB__14->SetBinContent(9,0.7652646);
   Npe_LPMT_numuCC_SB__14->SetBinContent(10,0.7303059);
   Npe_LPMT_numuCC_SB__14->SetBinContent(11,0.697644);
   Npe_LPMT_numuCC_SB__14->SetBinContent(12,0.6649395);
   Npe_LPMT_numuCC_SB__14->SetBinContent(13,0.5829493);
   Npe_LPMT_numuCC_SB__14->SetBinContent(14,0.5790754);
   Npe_LPMT_numuCC_SB__14->SetBinContent(15,0.6187291);
   Npe_LPMT_numuCC_SB__14->SetBinContent(16,0.5823755);
   Npe_LPMT_numuCC_SB__14->SetBinContent(17,0.5927835);
   Npe_LPMT_numuCC_SB__14->SetBinContent(18,0.5581396);
   Npe_LPMT_numuCC_SB__14->SetBinContent(19,0.4265734);
   Npe_LPMT_numuCC_SB__14->SetBinContent(20,0.488);
   Npe_LPMT_numuCC_SB__14->SetBinContent(21,0.6034483);
   Npe_LPMT_numuCC_SB__14->SetBinContent(22,0.5555556);
   Npe_LPMT_numuCC_SB__14->SetBinContent(23,0.5421687);
   Npe_LPMT_numuCC_SB__14->SetBinContent(24,0.5238096);
   Npe_LPMT_numuCC_SB__14->SetBinContent(25,0.5423729);
   Npe_LPMT_numuCC_SB__14->SetBinContent(26,0.4782609);
   Npe_LPMT_numuCC_SB__14->SetBinContent(27,0.6571429);
   Npe_LPMT_numuCC_SB__14->SetBinContent(28,0.4827586);
   Npe_LPMT_numuCC_SB__14->SetBinContent(29,0.5217391);
   Npe_LPMT_numuCC_SB__14->SetBinContent(30,0.5);
   Npe_LPMT_numuCC_SB__14->SetBinContent(31,0.4444444);
   Npe_LPMT_numuCC_SB__14->SetBinContent(32,0.5);
   Npe_LPMT_numuCC_SB__14->SetBinContent(33,0.25);
   Npe_LPMT_numuCC_SB__14->SetBinContent(34,0.4);
   Npe_LPMT_numuCC_SB__14->SetBinContent(35,1);
   Npe_LPMT_numuCC_SB__14->SetBinContent(36,0.25);
   Npe_LPMT_numuCC_SB__14->SetEntries(21.73244);
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
