void LOGEv_nueCC_SB_0-20GeV_16volcut_1m_less75nscut_withfidcut()
{
//=========Macro generated from canvas: c89/
//=========  (Mon Jan 14 15:43:08 2019) by ROOT version 6.13/08
   TCanvas *c89 = new TCanvas("c89", "",117,57,800,600);
   gStyle->SetOptStat(0);
   c89->Range(-1.28875,-0.1299273,1.59875,0.9528001);
   c89->SetFillColor(0);
   c89->SetBorderMode(0);
   c89->SetBorderSize(2);
   c89->SetBottomMargin(0.12);
   c89->SetFrameBorderMode(0);
   c89->SetFrameBorderMode(0);
   
   TH1F *Lognpe_LPMT_nueCC_SB__15 = new TH1F("Lognpe_LPMT_nueCC_SB__15","",35,-1,1.31);
   Lognpe_LPMT_nueCC_SB__15->SetBinContent(0,0.3878327);
   Lognpe_LPMT_nueCC_SB__15->SetBinContent(1,0.5060976);
   Lognpe_LPMT_nueCC_SB__15->SetBinContent(2,0.5534884);
   Lognpe_LPMT_nueCC_SB__15->SetBinContent(3,0.5266904);
   Lognpe_LPMT_nueCC_SB__15->SetBinContent(4,0.5404699);
   Lognpe_LPMT_nueCC_SB__15->SetBinContent(5,0.6497797);
   Lognpe_LPMT_nueCC_SB__15->SetBinContent(6,0.6862004);
   Lognpe_LPMT_nueCC_SB__15->SetBinContent(7,0.728223);
   Lognpe_LPMT_nueCC_SB__15->SetBinContent(8,0.7259136);
   Lognpe_LPMT_nueCC_SB__15->SetBinContent(9,0.7777778);
   Lognpe_LPMT_nueCC_SB__15->SetBinContent(10,0.8043118);
   Lognpe_LPMT_nueCC_SB__15->SetBinContent(11,0.7428998);
   Lognpe_LPMT_nueCC_SB__15->SetBinContent(12,0.7848297);
   Lognpe_LPMT_nueCC_SB__15->SetBinContent(13,0.7625202);
   Lognpe_LPMT_nueCC_SB__15->SetBinContent(14,0.7106918);
   Lognpe_LPMT_nueCC_SB__15->SetBinContent(15,0.744863);
   Lognpe_LPMT_nueCC_SB__15->SetBinContent(16,0.7551724);
   Lognpe_LPMT_nueCC_SB__15->SetBinContent(17,0.756917);
   Lognpe_LPMT_nueCC_SB__15->SetBinContent(18,0.740519);
   Lognpe_LPMT_nueCC_SB__15->SetBinContent(19,0.7616162);
   Lognpe_LPMT_nueCC_SB__15->SetBinContent(20,0.7692308);
   Lognpe_LPMT_nueCC_SB__15->SetBinContent(21,0.7648402);
   Lognpe_LPMT_nueCC_SB__15->SetBinContent(22,0.7286822);
   Lognpe_LPMT_nueCC_SB__15->SetBinContent(23,0.7459807);
   Lognpe_LPMT_nueCC_SB__15->SetBinContent(24,0.7569444);
   Lognpe_LPMT_nueCC_SB__15->SetBinContent(25,0.7736486);
   Lognpe_LPMT_nueCC_SB__15->SetBinContent(26,0.6851852);
   Lognpe_LPMT_nueCC_SB__15->SetBinContent(27,0.7848837);
   Lognpe_LPMT_nueCC_SB__15->SetBinContent(28,0.738255);
   Lognpe_LPMT_nueCC_SB__15->SetBinContent(29,0.6861314);
   Lognpe_LPMT_nueCC_SB__15->SetBinContent(30,0.7410714);
   Lognpe_LPMT_nueCC_SB__15->SetBinContent(31,0.72);
   Lognpe_LPMT_nueCC_SB__15->SetBinContent(32,0.6666667);
   Lognpe_LPMT_nueCC_SB__15->SetBinContent(33,0.6229508);
   Lognpe_LPMT_nueCC_SB__15->SetBinContent(34,0.5675676);
   Lognpe_LPMT_nueCC_SB__15->SetEntries(24.01102);
   Lognpe_LPMT_nueCC_SB__15->SetStats(0);
   Lognpe_LPMT_nueCC_SB__15->SetFillStyle(3002);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#ff0000");
   Lognpe_LPMT_nueCC_SB__15->SetLineColor(ci);
   Lognpe_LPMT_nueCC_SB__15->SetLineWidth(5);
   Lognpe_LPMT_nueCC_SB__15->GetXaxis()->SetTitle("log_{10} (E_{#nu} [GeV])");
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
