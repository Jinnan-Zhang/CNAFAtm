void Ev_nueCC_SB_0-20GeV_16volcut_1m_less75nscut_withfidcut()
{
//=========Macro generated from canvas: c67/
//=========  (Mon Jan 14 15:43:08 2019) by ROOT version 6.13/08
   TCanvas *c67 = new TCanvas("c67", "",269,259,800,600);
   gStyle->SetOptStat(0);
   c67->Range(-2.5,-0.1542876,22.5,1.131442);
   c67->SetFillColor(0);
   c67->SetBorderMode(0);
   c67->SetBorderSize(2);
   c67->SetBottomMargin(0.12);
   c67->SetFrameBorderMode(0);
   c67->SetFrameBorderMode(0);
   
   TH1F *Ev_LPMT_nueCC_SB__13 = new TH1F("Ev_LPMT_nueCC_SB__13","",35,0,20);
   Ev_LPMT_nueCC_SB__13->SetBinContent(1,0.9551135);
   Ev_LPMT_nueCC_SB__13->SetBinContent(2,0.8156028);
   Ev_LPMT_nueCC_SB__13->SetBinContent(3,0.7974783);
   Ev_LPMT_nueCC_SB__13->SetBinContent(4,0.7849873);
   Ev_LPMT_nueCC_SB__13->SetBinContent(5,0.7558348);
   Ev_LPMT_nueCC_SB__13->SetBinContent(6,0.7717391);
   Ev_LPMT_nueCC_SB__13->SetBinContent(7,0.7881944);
   Ev_LPMT_nueCC_SB__13->SetBinContent(8,0.7622951);
   Ev_LPMT_nueCC_SB__13->SetBinContent(9,0.7025316);
   Ev_LPMT_nueCC_SB__13->SetBinContent(10,0.78125);
   Ev_LPMT_nueCC_SB__13->SetBinContent(11,0.8131868);
   Ev_LPMT_nueCC_SB__13->SetBinContent(12,0.7411765);
   Ev_LPMT_nueCC_SB__13->SetBinContent(13,0.6875);
   Ev_LPMT_nueCC_SB__13->SetBinContent(14,0.6956522);
   Ev_LPMT_nueCC_SB__13->SetBinContent(15,0.7450981);
   Ev_LPMT_nueCC_SB__13->SetBinContent(16,0.755102);
   Ev_LPMT_nueCC_SB__13->SetBinContent(17,0.7714286);
   Ev_LPMT_nueCC_SB__13->SetBinContent(18,0.7142857);
   Ev_LPMT_nueCC_SB__13->SetBinContent(19,0.7);
   Ev_LPMT_nueCC_SB__13->SetBinContent(20,0.6666667);
   Ev_LPMT_nueCC_SB__13->SetBinContent(21,0.8421053);
   Ev_LPMT_nueCC_SB__13->SetBinContent(22,0.6);
   Ev_LPMT_nueCC_SB__13->SetBinContent(23,0.6470588);
   Ev_LPMT_nueCC_SB__13->SetBinContent(24,0.7894737);
   Ev_LPMT_nueCC_SB__13->SetBinContent(25,0.5);
   Ev_LPMT_nueCC_SB__13->SetBinContent(26,0.5294118);
   Ev_LPMT_nueCC_SB__13->SetBinContent(27,0.7692308);
   Ev_LPMT_nueCC_SB__13->SetBinContent(28,0.7692308);
   Ev_LPMT_nueCC_SB__13->SetBinContent(29,0.25);
   Ev_LPMT_nueCC_SB__13->SetEntries(20.90163);
   Ev_LPMT_nueCC_SB__13->SetStats(0);
   Ev_LPMT_nueCC_SB__13->SetFillStyle(3002);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#ff0000");
   Ev_LPMT_nueCC_SB__13->SetLineColor(ci);
   Ev_LPMT_nueCC_SB__13->SetLineWidth(5);
   Ev_LPMT_nueCC_SB__13->GetXaxis()->SetTitle("E_{#nu} [GeV]");
   Ev_LPMT_nueCC_SB__13->GetXaxis()->SetLabelFont(42);
   Ev_LPMT_nueCC_SB__13->GetXaxis()->SetLabelSize(0.05);
   Ev_LPMT_nueCC_SB__13->GetXaxis()->SetTitleSize(0.05);
   Ev_LPMT_nueCC_SB__13->GetXaxis()->SetTitleFont(42);
   Ev_LPMT_nueCC_SB__13->GetYaxis()->SetTitle("S/(S+B)");
   Ev_LPMT_nueCC_SB__13->GetYaxis()->SetLabelFont(42);
   Ev_LPMT_nueCC_SB__13->GetYaxis()->SetLabelSize(0.05);
   Ev_LPMT_nueCC_SB__13->GetYaxis()->SetTitleSize(0.035);
   Ev_LPMT_nueCC_SB__13->GetYaxis()->SetTitleOffset(1.2);
   Ev_LPMT_nueCC_SB__13->GetYaxis()->SetTitleFont(42);
   Ev_LPMT_nueCC_SB__13->GetZaxis()->SetLabelFont(42);
   Ev_LPMT_nueCC_SB__13->GetZaxis()->SetLabelSize(0.035);
   Ev_LPMT_nueCC_SB__13->GetZaxis()->SetTitleSize(0.035);
   Ev_LPMT_nueCC_SB__13->GetZaxis()->SetTitleFont(42);
   Ev_LPMT_nueCC_SB__13->Draw("");
   c67->Modified();
   c67->cd();
   c67->SetSelected(c67);
}
