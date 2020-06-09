void LOGEv_numuCC_SB_0-20GeV_16volcut_1m_over95nscut_withfidcut()
{
//=========Macro generated from canvas: c45/
//=========  (Mon Jan 14 15:43:09 2019) by ROOT version 6.13/08
   TCanvas *c45 = new TCanvas("c45", "",155,95,800,600);
   gStyle->SetOptStat(0);
   c45->Range(-0.7825,-0.1615385,1.5425,1.184615);
   c45->SetFillColor(0);
   c45->SetBorderMode(0);
   c45->SetBorderSize(2);
   c45->SetBottomMargin(0.12);
   c45->SetFrameBorderMode(0);
   c45->SetFrameBorderMode(0);
   
   TH1F *Lognpe_LPMT_numuCC_SB__16 = new TH1F("Lognpe_LPMT_numuCC_SB__16","",35,-0.55,1.31);
   Lognpe_LPMT_numuCC_SB__16->SetBinContent(3,1);
   Lognpe_LPMT_numuCC_SB__16->SetBinContent(4,0.9626168);
   Lognpe_LPMT_numuCC_SB__16->SetBinContent(5,0.9705426);
   Lognpe_LPMT_numuCC_SB__16->SetBinContent(6,0.9499121);
   Lognpe_LPMT_numuCC_SB__16->SetBinContent(7,0.9367816);
   Lognpe_LPMT_numuCC_SB__16->SetBinContent(8,0.9226027);
   Lognpe_LPMT_numuCC_SB__16->SetBinContent(9,0.913669);
   Lognpe_LPMT_numuCC_SB__16->SetBinContent(10,0.8918054);
   Lognpe_LPMT_numuCC_SB__16->SetBinContent(11,0.8592777);
   Lognpe_LPMT_numuCC_SB__16->SetBinContent(12,0.8525226);
   Lognpe_LPMT_numuCC_SB__16->SetBinContent(13,0.814578);
   Lognpe_LPMT_numuCC_SB__16->SetBinContent(14,0.8209636);
   Lognpe_LPMT_numuCC_SB__16->SetBinContent(15,0.7931287);
   Lognpe_LPMT_numuCC_SB__16->SetBinContent(16,0.7944359);
   Lognpe_LPMT_numuCC_SB__16->SetBinContent(17,0.7838948);
   Lognpe_LPMT_numuCC_SB__16->SetBinContent(18,0.7943585);
   Lognpe_LPMT_numuCC_SB__16->SetBinContent(19,0.7820513);
   Lognpe_LPMT_numuCC_SB__16->SetBinContent(20,0.7785788);
   Lognpe_LPMT_numuCC_SB__16->SetBinContent(21,0.7764843);
   Lognpe_LPMT_numuCC_SB__16->SetBinContent(22,0.7636612);
   Lognpe_LPMT_numuCC_SB__16->SetBinContent(23,0.734472);
   Lognpe_LPMT_numuCC_SB__16->SetBinContent(24,0.7313195);
   Lognpe_LPMT_numuCC_SB__16->SetBinContent(25,0.7612782);
   Lognpe_LPMT_numuCC_SB__16->SetBinContent(26,0.7515658);
   Lognpe_LPMT_numuCC_SB__16->SetBinContent(27,0.7254408);
   Lognpe_LPMT_numuCC_SB__16->SetBinContent(28,0.7553192);
   Lognpe_LPMT_numuCC_SB__16->SetBinContent(29,0.7632399);
   Lognpe_LPMT_numuCC_SB__16->SetBinContent(30,0.7266436);
   Lognpe_LPMT_numuCC_SB__16->SetBinContent(31,0.75);
   Lognpe_LPMT_numuCC_SB__16->SetBinContent(32,0.7488789);
   Lognpe_LPMT_numuCC_SB__16->SetBinContent(33,0.7468355);
   Lognpe_LPMT_numuCC_SB__16->SetBinContent(34,0.7445256);
   Lognpe_LPMT_numuCC_SB__16->SetBinContent(35,0.7943925);
   Lognpe_LPMT_numuCC_SB__16->SetEntries(26.89578);
   Lognpe_LPMT_numuCC_SB__16->SetStats(0);
   Lognpe_LPMT_numuCC_SB__16->SetFillStyle(3002);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   Lognpe_LPMT_numuCC_SB__16->SetLineColor(ci);
   Lognpe_LPMT_numuCC_SB__16->SetLineWidth(5);
   Lognpe_LPMT_numuCC_SB__16->GetXaxis()->SetTitle("log_{10} (E_{#nu} [GeV])");
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
