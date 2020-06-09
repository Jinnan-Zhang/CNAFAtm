void LOGNPE_LPMT_numuCC_SB_0-20GeV_16volcut_1m_over95nscut_withfidcut()
{
//=========Macro generated from canvas: c45/
//=========  (Thu Aug 29 17:02:17 2019) by ROOT version 6.12/06
   TCanvas *c45 = new TCanvas("c45", "",1120,480,800,600);
   gStyle->SetOptStat(0);
   c45->Range(5.44375,-0.1368503,8.00625,1.003568);
   c45->SetFillColor(0);
   c45->SetBorderMode(0);
   c45->SetBorderSize(2);
   c45->SetBottomMargin(0.12);
   c45->SetFrameBorderMode(0);
   c45->SetFrameBorderMode(0);
   
   TH1F *Lognpe_LPMT_numuCC_SB__16 = new TH1F("Lognpe_LPMT_numuCC_SB__16","",35,5.7,7.75);
   Lognpe_LPMT_numuCC_SB__16->SetBinContent(0,0.7288136);
   Lognpe_LPMT_numuCC_SB__16->SetBinContent(1,0.7307899);
   Lognpe_LPMT_numuCC_SB__16->SetBinContent(2,0.757553);
   Lognpe_LPMT_numuCC_SB__16->SetBinContent(3,0.7691089);
   Lognpe_LPMT_numuCC_SB__16->SetBinContent(4,0.7812082);
   Lognpe_LPMT_numuCC_SB__16->SetBinContent(5,0.7908362);
   Lognpe_LPMT_numuCC_SB__16->SetBinContent(6,0.7897877);
   Lognpe_LPMT_numuCC_SB__16->SetBinContent(7,0.8022085);
   Lognpe_LPMT_numuCC_SB__16->SetBinContent(8,0.806906);
   Lognpe_LPMT_numuCC_SB__16->SetBinContent(9,0.8223001);
   Lognpe_LPMT_numuCC_SB__16->SetBinContent(10,0.8359544);
   Lognpe_LPMT_numuCC_SB__16->SetBinContent(11,0.837967);
   Lognpe_LPMT_numuCC_SB__16->SetBinContent(12,0.8324833);
   Lognpe_LPMT_numuCC_SB__16->SetBinContent(13,0.836578);
   Lognpe_LPMT_numuCC_SB__16->SetBinContent(14,0.8437126);
   Lognpe_LPMT_numuCC_SB__16->SetBinContent(15,0.8471682);
   Lognpe_LPMT_numuCC_SB__16->SetBinContent(16,0.8180668);
   Lognpe_LPMT_numuCC_SB__16->SetBinContent(17,0.8107208);
   Lognpe_LPMT_numuCC_SB__16->SetBinContent(18,0.7956829);
   Lognpe_LPMT_numuCC_SB__16->SetBinContent(19,0.7846434);
   Lognpe_LPMT_numuCC_SB__16->SetBinContent(20,0.7547374);
   Lognpe_LPMT_numuCC_SB__16->SetBinContent(21,0.7429775);
   Lognpe_LPMT_numuCC_SB__16->SetBinContent(22,0.6921624);
   Lognpe_LPMT_numuCC_SB__16->SetBinContent(23,0.6227848);
   Lognpe_LPMT_numuCC_SB__16->SetBinContent(24,0.5952733);
   Lognpe_LPMT_numuCC_SB__16->SetBinContent(25,0.586);
   Lognpe_LPMT_numuCC_SB__16->SetBinContent(26,0.4959128);
   Lognpe_LPMT_numuCC_SB__16->SetBinContent(27,0.5555556);
   Lognpe_LPMT_numuCC_SB__16->SetBinContent(28,0.5589744);
   Lognpe_LPMT_numuCC_SB__16->SetBinContent(29,0.5042017);
   Lognpe_LPMT_numuCC_SB__16->SetBinContent(30,0.4385965);
   Lognpe_LPMT_numuCC_SB__16->SetBinContent(31,0.375);
   Lognpe_LPMT_numuCC_SB__16->SetBinContent(32,0.5);
   Lognpe_LPMT_numuCC_SB__16->SetEntries(22.71585);
   Lognpe_LPMT_numuCC_SB__16->SetStats(0);
   Lognpe_LPMT_numuCC_SB__16->SetFillStyle(3002);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   Lognpe_LPMT_numuCC_SB__16->SetLineColor(ci);
   Lognpe_LPMT_numuCC_SB__16->SetLineWidth(5);
   Lognpe_LPMT_numuCC_SB__16->GetXaxis()->SetTitle("log_{10} (NPE_{LPMT})");
   Lognpe_LPMT_numuCC_SB__16->GetXaxis()->SetLabelFont(42);
   Lognpe_LPMT_numuCC_SB__16->GetXaxis()->SetLabelSize(0.05);
   Lognpe_LPMT_numuCC_SB__16->GetXaxis()->SetTitleSize(0.05);
   Lognpe_LPMT_numuCC_SB__16->GetXaxis()->SetTitleFont(42);
   Lognpe_LPMT_numuCC_SB__16->GetYaxis()->SetTitle("S/(S+B)");
   Lognpe_LPMT_numuCC_SB__16->GetYaxis()->SetLabelFont(42);
   Lognpe_LPMT_numuCC_SB__16->GetYaxis()->SetLabelSize(0.05);
   Lognpe_LPMT_numuCC_SB__16->GetYaxis()->SetTitleSize(0.035);
   Lognpe_LPMT_numuCC_SB__16->GetYaxis()->SetTitleOffset(1.2);
   Lognpe_LPMT_numuCC_SB__16->GetYaxis()->SetTitleFont(42);
   Lognpe_LPMT_numuCC_SB__16->GetZaxis()->SetLabelFont(42);
   Lognpe_LPMT_numuCC_SB__16->GetZaxis()->SetLabelSize(0.035);
   Lognpe_LPMT_numuCC_SB__16->GetZaxis()->SetTitleSize(0.035);
   Lognpe_LPMT_numuCC_SB__16->GetZaxis()->SetTitleFont(42);
   Lognpe_LPMT_numuCC_SB__16->Draw("");
   c45->Modified();
   c45->cd();
   c45->SetSelected(c45);
}
