void logEv_0-20GeV_16volcut_1m_e-mu_SGN-BKG()
{
//=========Macro generated from canvas: c95/
//=========  (Tue Mar  5 16:07:22 2019) by ROOT version 6.12/06
   TCanvas *c95 = new TCanvas("c95", "",420,52,1500,1000);
   gStyle->SetOptStat(0);
   c95->Range(0,0,1,1);
   c95->SetFillColor(0);
   c95->SetBorderMode(0);
   c95->SetBorderSize(2);
   c95->SetLeftMargin(0.15);
   c95->SetRightMargin(0.12);
   c95->SetBottomMargin(0.15);
   c95->SetFrameBorderMode(0);
  
// ------------>Primitives in pad: c95_1
   TPad *c95_1 = new TPad("c95_1", "c95_1",0.01,0.51,0.49,0.99);
   c95_1->Draw();
   c95_1->cd();
   c95_1->Range(1.547945,-202.4445,4.561644,1604.186);
   c95_1->SetFillColor(0);
   c95_1->SetBorderMode(0);
   c95_1->SetBorderSize(2);
   c95_1->SetLeftMargin(0.15);
   c95_1->SetRightMargin(0.12);
   c95_1->SetBottomMargin(0.15);
   c95_1->SetFrameBorderMode(0);
   c95_1->SetFrameBorderMode(0);
   
   TH1F *Ev_less75_nueCC_SGN = new TH1F("Ev_less75_nueCC_SGN","#nu_{e}^{CC} signal",12,2,4.2);
   Ev_less75_nueCC_SGN->SetBinContent(0,37);
   Ev_less75_nueCC_SGN->SetBinContent(1,248);
   Ev_less75_nueCC_SGN->SetBinContent(2,729);
   Ev_less75_nueCC_SGN->SetBinContent(3,1180);
   Ev_less75_nueCC_SGN->SetBinContent(4,1359);
   Ev_less75_nueCC_SGN->SetBinContent(5,1324);
   Ev_less75_nueCC_SGN->SetBinContent(6,1204);
   Ev_less75_nueCC_SGN->SetBinContent(7,993);
   Ev_less75_nueCC_SGN->SetBinContent(8,825);
   Ev_less75_nueCC_SGN->SetBinContent(9,631);
   Ev_less75_nueCC_SGN->SetBinContent(10,368);
   Ev_less75_nueCC_SGN->SetBinContent(11,241);
   Ev_less75_nueCC_SGN->SetBinContent(12,130);
   Ev_less75_nueCC_SGN->SetBinContent(13,4);
   Ev_less75_nueCC_SGN->SetEntries(9273);
   Ev_less75_nueCC_SGN->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   Ev_less75_nueCC_SGN->SetLineColor(ci);
   Ev_less75_nueCC_SGN->SetLineWidth(3);
   Ev_less75_nueCC_SGN->GetXaxis()->SetTitle("log_{10}(E_{#nu} [MeV])");
   Ev_less75_nueCC_SGN->GetXaxis()->SetLabelFont(42);
   Ev_less75_nueCC_SGN->GetXaxis()->SetLabelSize(0.05);
   Ev_less75_nueCC_SGN->GetXaxis()->SetTitleSize(0.06);
   Ev_less75_nueCC_SGN->GetXaxis()->SetTitleFont(42);
   Ev_less75_nueCC_SGN->GetYaxis()->SetTitle("entries");
   Ev_less75_nueCC_SGN->GetYaxis()->SetLabelFont(42);
   Ev_less75_nueCC_SGN->GetYaxis()->SetLabelSize(0.05);
   Ev_less75_nueCC_SGN->GetYaxis()->SetTitleSize(0.06);
   Ev_less75_nueCC_SGN->GetYaxis()->SetTitleOffset(0);
   Ev_less75_nueCC_SGN->GetYaxis()->SetTitleFont(42);
   Ev_less75_nueCC_SGN->GetZaxis()->SetLabelFont(42);
   Ev_less75_nueCC_SGN->GetZaxis()->SetLabelSize(0.05);
   Ev_less75_nueCC_SGN->GetZaxis()->SetTitleSize(0.035);
   Ev_less75_nueCC_SGN->GetZaxis()->SetTitleFont(42);
   Ev_less75_nueCC_SGN->Draw("colz");
   
   TPaveText *pt = new TPaveText(-0.02499998,0.895,1.025,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *pt_LaTex = pt->AddText("#nu_{e}^{CC} signal");
   pt->Draw();
   c95_1->Modified();
   c95->cd();
  
// ------------>Primitives in pad: c95_2
   TPad *c95_2 = new TPad("c95_2", "c95_2",0.51,0.51,0.99,0.99);
   c95_2->Draw();
   c95_2->cd();
   c95_2->Range(2.126575,-931.56,4.482739,5278.84);
   c95_2->SetFillColor(0);
   c95_2->SetBorderMode(0);
   c95_2->SetBorderSize(2);
   c95_2->SetLeftMargin(0.15);
   c95_2->SetRightMargin(0.12);
   c95_2->SetBottomMargin(0.15);
   c95_2->SetFrameBorderMode(0);
   c95_2->SetFrameBorderMode(0);
   
   TH1F *Ev_over95_numuCC_SGN = new TH1F("Ev_over95_numuCC_SGN","#nu_{#mu}^{CC} FC signal",10,2.48,4.2);
   Ev_over95_numuCC_SGN->SetBinContent(1,61);
   Ev_over95_numuCC_SGN->SetBinContent(2,3102);
   Ev_over95_numuCC_SGN->SetBinContent(3,4436);
   Ev_over95_numuCC_SGN->SetBinContent(4,3981);
   Ev_over95_numuCC_SGN->SetBinContent(5,3008);
   Ev_over95_numuCC_SGN->SetBinContent(6,2012);
   Ev_over95_numuCC_SGN->SetBinContent(7,1076);
   Ev_over95_numuCC_SGN->SetBinContent(8,475);
   Ev_over95_numuCC_SGN->SetBinContent(9,152);
   Ev_over95_numuCC_SGN->SetBinContent(10,68);
   Ev_over95_numuCC_SGN->SetBinContent(11,9);
   Ev_over95_numuCC_SGN->SetEntries(18380);
   Ev_over95_numuCC_SGN->SetStats(0);

   ci = TColor::GetColor("#000099");
   Ev_over95_numuCC_SGN->SetLineColor(ci);
   Ev_over95_numuCC_SGN->SetLineWidth(3);
   Ev_over95_numuCC_SGN->GetXaxis()->SetTitle("log_{10}(E_{#nu} [MeV])");
   Ev_over95_numuCC_SGN->GetXaxis()->SetLabelFont(42);
   Ev_over95_numuCC_SGN->GetXaxis()->SetLabelSize(0.05);
   Ev_over95_numuCC_SGN->GetXaxis()->SetTitleSize(0.06);
   Ev_over95_numuCC_SGN->GetXaxis()->SetTitleFont(42);
   Ev_over95_numuCC_SGN->GetYaxis()->SetTitle("entries");
   Ev_over95_numuCC_SGN->GetYaxis()->SetLabelFont(42);
   Ev_over95_numuCC_SGN->GetYaxis()->SetLabelSize(0.05);
   Ev_over95_numuCC_SGN->GetYaxis()->SetTitleSize(0.06);
   Ev_over95_numuCC_SGN->GetYaxis()->SetTitleOffset(0);
   Ev_over95_numuCC_SGN->GetYaxis()->SetTitleFont(42);
   Ev_over95_numuCC_SGN->GetZaxis()->SetLabelFont(42);
   Ev_over95_numuCC_SGN->GetZaxis()->SetLabelSize(0.05);
   Ev_over95_numuCC_SGN->GetZaxis()->SetTitleSize(0.035);
   Ev_over95_numuCC_SGN->GetZaxis()->SetTitleFont(42);
   Ev_over95_numuCC_SGN->Draw("colz");
   
   pt = new TPaveText(-0.02499998,0.895,1.025,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   pt_LaTex = pt->AddText("#nu_{#mu}^{CC} FC signal");
   pt->Draw();
   c95_2->Modified();
   c95->cd();
  
// ------------>Primitives in pad: c95_3
   TPad *c95_3 = new TPad("c95_3", "c95_3",0.01,0.01,0.49,0.49);
   c95_3->Draw();
   c95_3->cd();
   c95_3->Range(1.547945,-59.85,4.561644,339.15);
   c95_3->SetFillColor(0);
   c95_3->SetBorderMode(0);
   c95_3->SetBorderSize(2);
   c95_3->SetLeftMargin(0.15);
   c95_3->SetRightMargin(0.12);
   c95_3->SetBottomMargin(0.15);
   c95_3->SetFrameBorderMode(0);
   c95_3->SetFrameBorderMode(0);
   
   TH1F *Ev_less75_nueCC_BKG = new TH1F("Ev_less75_nueCC_BKG","#nu_{e}^{CC} background",12,2,4.2);
   Ev_less75_nueCC_BKG->SetBinContent(2,2);
   Ev_less75_nueCC_BKG->SetBinContent(3,18);
   Ev_less75_nueCC_BKG->SetBinContent(4,132);
   Ev_less75_nueCC_BKG->SetBinContent(5,266);
   Ev_less75_nueCC_BKG->SetBinContent(6,285);
   Ev_less75_nueCC_BKG->SetBinContent(7,276);
   Ev_less75_nueCC_BKG->SetBinContent(8,233);
   Ev_less75_nueCC_BKG->SetBinContent(9,184);
   Ev_less75_nueCC_BKG->SetBinContent(10,125);
   Ev_less75_nueCC_BKG->SetBinContent(11,86);
   Ev_less75_nueCC_BKG->SetBinContent(12,56);
   Ev_less75_nueCC_BKG->SetBinContent(13,25);
   Ev_less75_nueCC_BKG->SetEntries(1688);
   Ev_less75_nueCC_BKG->SetStats(0);

   ci = TColor::GetColor("#000099");
   Ev_less75_nueCC_BKG->SetLineColor(ci);
   Ev_less75_nueCC_BKG->SetLineWidth(3);
   Ev_less75_nueCC_BKG->GetXaxis()->SetTitle("log_{10}(E_{#nu} [MeV])");
   Ev_less75_nueCC_BKG->GetXaxis()->SetLabelFont(42);
   Ev_less75_nueCC_BKG->GetXaxis()->SetLabelSize(0.05);
   Ev_less75_nueCC_BKG->GetXaxis()->SetTitleSize(0.06);
   Ev_less75_nueCC_BKG->GetXaxis()->SetTitleFont(42);
   Ev_less75_nueCC_BKG->GetYaxis()->SetTitle("entries");
   Ev_less75_nueCC_BKG->GetYaxis()->SetLabelFont(42);
   Ev_less75_nueCC_BKG->GetYaxis()->SetLabelSize(0.05);
   Ev_less75_nueCC_BKG->GetYaxis()->SetTitleSize(0.06);
   Ev_less75_nueCC_BKG->GetYaxis()->SetTitleOffset(0);
   Ev_less75_nueCC_BKG->GetYaxis()->SetTitleFont(42);
   Ev_less75_nueCC_BKG->GetZaxis()->SetLabelFont(42);
   Ev_less75_nueCC_BKG->GetZaxis()->SetLabelSize(0.05);
   Ev_less75_nueCC_BKG->GetZaxis()->SetTitleSize(0.035);
   Ev_less75_nueCC_BKG->GetZaxis()->SetTitleFont(42);
   Ev_less75_nueCC_BKG->Draw("colz");
   
   pt = new TPaveText(-0.02499998,0.895,1.025,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   pt_LaTex = pt->AddText("#nu_{e}^{CC} background");
   pt->Draw();
   c95_3->Modified();
   c95->cd();
  
// ------------>Primitives in pad: c95_4
   TPad *c95_4 = new TPad("c95_4", "c95_4",0.51,0.01,0.99,0.49);
   c95_4->Draw();
   c95_4->cd();
   c95_4->Range(2.126575,-179.13,4.482739,1015.07);
   c95_4->SetFillColor(0);
   c95_4->SetBorderMode(0);
   c95_4->SetBorderSize(2);
   c95_4->SetLeftMargin(0.15);
   c95_4->SetRightMargin(0.12);
   c95_4->SetBottomMargin(0.15);
   c95_4->SetFrameBorderMode(0);
   c95_4->SetFrameBorderMode(0);
   
   TH1F *Ev_over95_numuCC_BKG = new TH1F("Ev_over95_numuCC_BKG","#nu_{#mu}^{CC} FC background",10,2.48,4.2);
   Ev_over95_numuCC_BKG->SetBinContent(0,3);
   Ev_over95_numuCC_BKG->SetBinContent(1,3);
   Ev_over95_numuCC_BKG->SetBinContent(2,168);
   Ev_over95_numuCC_BKG->SetBinContent(3,470);
   Ev_over95_numuCC_BKG->SetBinContent(4,841);
   Ev_over95_numuCC_BKG->SetBinContent(5,853);
   Ev_over95_numuCC_BKG->SetBinContent(6,726);
   Ev_over95_numuCC_BKG->SetBinContent(7,569);
   Ev_over95_numuCC_BKG->SetBinContent(8,434);
   Ev_over95_numuCC_BKG->SetBinContent(9,270);
   Ev_over95_numuCC_BKG->SetBinContent(10,182);
   Ev_over95_numuCC_BKG->SetBinContent(11,58);
   Ev_over95_numuCC_BKG->SetEntries(4577);
   Ev_over95_numuCC_BKG->SetStats(0);

   ci = TColor::GetColor("#000099");
   Ev_over95_numuCC_BKG->SetLineColor(ci);
   Ev_over95_numuCC_BKG->SetLineWidth(3);
   Ev_over95_numuCC_BKG->GetXaxis()->SetTitle("log_{10}(E_{#nu} [MeV])");
   Ev_over95_numuCC_BKG->GetXaxis()->SetLabelFont(42);
   Ev_over95_numuCC_BKG->GetXaxis()->SetLabelSize(0.05);
   Ev_over95_numuCC_BKG->GetXaxis()->SetTitleSize(0.06);
   Ev_over95_numuCC_BKG->GetXaxis()->SetTitleFont(42);
   Ev_over95_numuCC_BKG->GetYaxis()->SetTitle("entries");
   Ev_over95_numuCC_BKG->GetYaxis()->SetLabelFont(42);
   Ev_over95_numuCC_BKG->GetYaxis()->SetLabelSize(0.05);
   Ev_over95_numuCC_BKG->GetYaxis()->SetTitleSize(0.06);
   Ev_over95_numuCC_BKG->GetYaxis()->SetTitleOffset(0);
   Ev_over95_numuCC_BKG->GetYaxis()->SetTitleFont(42);
   Ev_over95_numuCC_BKG->GetZaxis()->SetLabelFont(42);
   Ev_over95_numuCC_BKG->GetZaxis()->SetLabelSize(0.05);
   Ev_over95_numuCC_BKG->GetZaxis()->SetTitleSize(0.035);
   Ev_over95_numuCC_BKG->GetZaxis()->SetTitleFont(42);
   Ev_over95_numuCC_BKG->Draw("colz");
   
   pt = new TPaveText(-0.02499998,0.895,1.025,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   pt_LaTex = pt->AddText("#nu_{#mu}^{CC} FC background");
   pt->Draw();
   c95_4->Modified();
   c95->cd();
   c95->Modified();
   c95->cd();
   c95->SetSelected(c95);
}
