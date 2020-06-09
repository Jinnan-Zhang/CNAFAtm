void LOGDATA_NPE_LPMT_numuCC_SB_0-20GeV_16volcut_1m_over95nscut_withfidcut()
{
//=========Macro generated from canvas: c45/
//=========  (Tue Jul  9 15:59:18 2019) by ROOT version 6.12/06
   TCanvas *c45 = new TCanvas("c45", "",1120,480,800,600);
   gStyle->SetOptStat(0);
   c45->Range(5.5125,0.5690422,7.3875,0.8908812);
   c45->SetFillColor(0);
   c45->SetBorderMode(0);
   c45->SetBorderSize(2);
   c45->SetBottomMargin(0.12);
   c45->SetFrameBorderMode(0);
   c45->SetFrameBorderMode(0);
   
   TH1F *Lognpe_LPMT_numuCC_SB__16 = new TH1F("Lognpe_LPMT_numuCC_SB__16","",12,5.7,7.2);
   Lognpe_LPMT_numuCC_SB__16->SetBinContent(0,1);
   Lognpe_LPMT_numuCC_SB__16->SetBinContent(1,0.7666667);
   Lognpe_LPMT_numuCC_SB__16->SetBinContent(2,0.7917889);
   Lognpe_LPMT_numuCC_SB__16->SetBinContent(3,0.7605263);
   Lognpe_LPMT_numuCC_SB__16->SetBinContent(4,0.8278932);
   Lognpe_LPMT_numuCC_SB__16->SetBinContent(5,0.8411215);
   Lognpe_LPMT_numuCC_SB__16->SetBinContent(6,0.8467433);
   Lognpe_LPMT_numuCC_SB__16->SetBinContent(7,0.8080808);
   Lognpe_LPMT_numuCC_SB__16->SetBinContent(8,0.7939394);
   Lognpe_LPMT_numuCC_SB__16->SetBinContent(9,0.7272727);
   Lognpe_LPMT_numuCC_SB__16->SetBinContent(10,0.625);
   Lognpe_LPMT_numuCC_SB__16->SetBinContent(11,0.744186);
   Lognpe_LPMT_numuCC_SB__16->SetBinContent(12,0.6190476);
   Lognpe_LPMT_numuCC_SB__16->SetBinContent(13,0.5714286);
   Lognpe_LPMT_numuCC_SB__16->SetEntries(9.152266);
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
