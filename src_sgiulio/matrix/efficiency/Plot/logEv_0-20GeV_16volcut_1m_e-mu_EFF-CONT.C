void logEv_0-20GeV_16volcut_1m_e-mu_EFF-CONT()
{
//=========Macro generated from canvas: c98/
//=========  (Tue Mar  5 16:07:19 2019) by ROOT version 6.12/06
   TCanvas *c98 = new TCanvas("c98", "",65,52,1500,1000);
   gStyle->SetOptStat(0);
   c98->Range(0,0,1,1);
   c98->SetFillColor(0);
   c98->SetBorderMode(0);
   c98->SetBorderSize(2);
   c98->SetLeftMargin(0.15);
   c98->SetRightMargin(0.12);
   c98->SetBottomMargin(0.15);
   c98->SetFrameBorderMode(0);
  
// ------------>Primitives in pad: c98_1
   TPad *c98_1 = new TPad("c98_1", "c98_1",0.01,0.51,0.49,0.99);
   c98_1->Draw();
   c98_1->cd();
   c98_1->Range(1.547945,0.3778875,4.561644,0.8505556);
   c98_1->SetFillColor(0);
   c98_1->SetBorderMode(0);
   c98_1->SetBorderSize(2);
   c98_1->SetLeftMargin(0.15);
   c98_1->SetRightMargin(0.12);
   c98_1->SetBottomMargin(0.15);
   c98_1->SetFrameBorderMode(0);
   c98_1->SetFrameBorderMode(0);
   
   TH1F *Ev_less75_nueCC_EFF = new TH1F("Ev_less75_nueCC_EFF","#nu_{e}^{CC} efficiency",12,2,4.2);
   Ev_less75_nueCC_EFF->SetBinContent(0,0.925);
   Ev_less75_nueCC_EFF->SetBinContent(1,0.7701864);
   Ev_less75_nueCC_EFF->SetBinContent(2,0.7864078);
   Ev_less75_nueCC_EFF->SetBinContent(3,0.7333748);
   Ev_less75_nueCC_EFF->SetBinContent(4,0.621968);
   Ev_less75_nueCC_EFF->SetBinContent(5,0.5057296);
   Ev_less75_nueCC_EFF->SetBinContent(6,0.4648649);
   Ev_less75_nueCC_EFF->SetBinContent(7,0.4681754);
   Ev_less75_nueCC_EFF->SetBinContent(8,0.5108359);
   Ev_less75_nueCC_EFF->SetBinContent(9,0.5411664);
   Ev_less75_nueCC_EFF->SetBinContent(10,0.5048011);
   Ev_less75_nueCC_EFF->SetBinContent(11,0.5355555);
   Ev_less75_nueCC_EFF->SetBinContent(12,0.4924242);
   Ev_less75_nueCC_EFF->SetBinContent(13,0.1538462);
   Ev_less75_nueCC_EFF->SetEntries(6.93549);
   Ev_less75_nueCC_EFF->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   Ev_less75_nueCC_EFF->SetLineColor(ci);
   Ev_less75_nueCC_EFF->SetLineWidth(3);
   Ev_less75_nueCC_EFF->GetXaxis()->SetTitle("log_{10}(E_{#nu} [MeV])");
   Ev_less75_nueCC_EFF->GetXaxis()->SetLabelFont(42);
   Ev_less75_nueCC_EFF->GetXaxis()->SetLabelSize(0.05);
   Ev_less75_nueCC_EFF->GetXaxis()->SetTitleSize(0.06);
   Ev_less75_nueCC_EFF->GetXaxis()->SetTitleFont(42);
   Ev_less75_nueCC_EFF->GetYaxis()->SetTitle("efficiency");
   Ev_less75_nueCC_EFF->GetYaxis()->SetLabelFont(42);
   Ev_less75_nueCC_EFF->GetYaxis()->SetLabelSize(0.05);
   Ev_less75_nueCC_EFF->GetYaxis()->SetTitleSize(0.06);
   Ev_less75_nueCC_EFF->GetYaxis()->SetTitleOffset(0);
   Ev_less75_nueCC_EFF->GetYaxis()->SetTitleFont(42);
   Ev_less75_nueCC_EFF->GetZaxis()->SetLabelFont(42);
   Ev_less75_nueCC_EFF->GetZaxis()->SetLabelSize(0.05);
   Ev_less75_nueCC_EFF->GetZaxis()->SetTitleSize(0.035);
   Ev_less75_nueCC_EFF->GetZaxis()->SetTitleFont(42);
   Ev_less75_nueCC_EFF->Draw("colz");
   
   TPaveText *pt = new TPaveText(-0.02499998,0.895,1.025,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *pt_LaTex = pt->AddText("#nu_{e}^{CC} efficiency");
   pt->Draw();
   c98_1->Modified();
   c98->cd();
  
// ------------>Primitives in pad: c98_2
   TPad *c98_2 = new TPad("c98_2", "c98_2",0.51,0.51,0.99,0.99);
   c98_2->Draw();
   c98_2->cd();
   c98_2->Range(2.126575,0.4714987,4.482739,1.014556);
   c98_2->SetFillColor(0);
   c98_2->SetBorderMode(0);
   c98_2->SetBorderSize(2);
   c98_2->SetLeftMargin(0.15);
   c98_2->SetRightMargin(0.12);
   c98_2->SetBottomMargin(0.15);
   c98_2->SetFrameBorderMode(0);
   c98_2->SetFrameBorderMode(0);
   
   TH1F *Ev_over95_numuCC_EFF = new TH1F("Ev_over95_numuCC_EFF","#nu_{#mu}^{CC} FC efficiency",10,2.48,4.2);
   Ev_over95_numuCC_EFF->SetBinContent(1,0.9384615);
   Ev_over95_numuCC_EFF->SetBinContent(2,0.9408553);
   Ev_over95_numuCC_EFF->SetBinContent(3,0.9329127);
   Ev_over95_numuCC_EFF->SetBinContent(4,0.8984428);
   Ev_over95_numuCC_EFF->SetBinContent(5,0.8574687);
   Ev_over95_numuCC_EFF->SetBinContent(6,0.8283244);
   Ev_over95_numuCC_EFF->SetBinContent(7,0.7713262);
   Ev_over95_numuCC_EFF->SetBinContent(8,0.6964809);
   Ev_over95_numuCC_EFF->SetBinContent(9,0.5868726);
   Ev_over95_numuCC_EFF->SetBinContent(10,0.5714286);
   Ev_over95_numuCC_EFF->SetBinContent(11,0.8181818);
   Ev_over95_numuCC_EFF->SetEntries(8.022574);
   Ev_over95_numuCC_EFF->SetStats(0);

   ci = TColor::GetColor("#000099");
   Ev_over95_numuCC_EFF->SetLineColor(ci);
   Ev_over95_numuCC_EFF->SetLineWidth(3);
   Ev_over95_numuCC_EFF->GetXaxis()->SetTitle("log_{10}(E_{#nu} [MeV])");
   Ev_over95_numuCC_EFF->GetXaxis()->SetLabelFont(42);
   Ev_over95_numuCC_EFF->GetXaxis()->SetLabelSize(0.05);
   Ev_over95_numuCC_EFF->GetXaxis()->SetTitleSize(0.06);
   Ev_over95_numuCC_EFF->GetXaxis()->SetTitleFont(42);
   Ev_over95_numuCC_EFF->GetYaxis()->SetTitle("efficiency");
   Ev_over95_numuCC_EFF->GetYaxis()->SetLabelFont(42);
   Ev_over95_numuCC_EFF->GetYaxis()->SetLabelSize(0.05);
   Ev_over95_numuCC_EFF->GetYaxis()->SetTitleSize(0.06);
   Ev_over95_numuCC_EFF->GetYaxis()->SetTitleOffset(0);
   Ev_over95_numuCC_EFF->GetYaxis()->SetTitleFont(42);
   Ev_over95_numuCC_EFF->GetZaxis()->SetLabelFont(42);
   Ev_over95_numuCC_EFF->GetZaxis()->SetLabelSize(0.05);
   Ev_over95_numuCC_EFF->GetZaxis()->SetTitleSize(0.035);
   Ev_over95_numuCC_EFF->GetZaxis()->SetTitleFont(42);
   Ev_over95_numuCC_EFF->Draw("colz");
   
   pt = new TPaveText(-0.02499998,0.895,1.025,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   pt_LaTex = pt->AddText("#nu_{#mu}^{CC} FC efficiency");
   pt->Draw();
   c98_2->Modified();
   c98->cd();
  
// ------------>Primitives in pad: c98_3
   TPad *c98_3 = new TPad("c98_3", "c98_3",0.01,0.01,0.49,0.49);
   c98_3->Draw();
   c98_3->cd();
   c98_3->Range(1.547945,-0.06322581,4.561644,0.3582796);
   c98_3->SetFillColor(0);
   c98_3->SetBorderMode(0);
   c98_3->SetBorderSize(2);
   c98_3->SetLeftMargin(0.15);
   c98_3->SetRightMargin(0.12);
   c98_3->SetBottomMargin(0.15);
   c98_3->SetFrameBorderMode(0);
   c98_3->SetFrameBorderMode(0);
   
   TH1F *Ev_less75_nueCC_CONT = new TH1F("Ev_less75_nueCC_CONT","#nu_{e}^{CC} contamination",12,2,4.2);
   Ev_less75_nueCC_CONT->SetBinContent(2,0.00273224);
   Ev_less75_nueCC_CONT->SetBinContent(3,0.01501251);
   Ev_less75_nueCC_CONT->SetBinContent(4,0.08835341);
   Ev_less75_nueCC_CONT->SetBinContent(5,0.1671904);
   Ev_less75_nueCC_CONT->SetBinContent(6,0.1911469);
   Ev_less75_nueCC_CONT->SetBinContent(7,0.2169811);
   Ev_less75_nueCC_CONT->SetBinContent(8,0.2202268);
   Ev_less75_nueCC_CONT->SetBinContent(9,0.2252142);
   Ev_less75_nueCC_CONT->SetBinContent(10,0.2525252);
   Ev_less75_nueCC_CONT->SetBinContent(11,0.2629969);
   Ev_less75_nueCC_CONT->SetBinContent(12,0.3010753);
   Ev_less75_nueCC_CONT->SetBinContent(13,0.8333333);
   Ev_less75_nueCC_CONT->SetEntries(1.943455);
   Ev_less75_nueCC_CONT->SetStats(0);

   ci = TColor::GetColor("#000099");
   Ev_less75_nueCC_CONT->SetLineColor(ci);
   Ev_less75_nueCC_CONT->SetLineWidth(3);
   Ev_less75_nueCC_CONT->GetXaxis()->SetTitle("log_{10}(E_{#nu} [MeV])");
   Ev_less75_nueCC_CONT->GetXaxis()->SetLabelFont(42);
   Ev_less75_nueCC_CONT->GetXaxis()->SetLabelSize(0.05);
   Ev_less75_nueCC_CONT->GetXaxis()->SetTitleSize(0.06);
   Ev_less75_nueCC_CONT->GetXaxis()->SetTitleFont(42);
   Ev_less75_nueCC_CONT->GetYaxis()->SetTitle("contamination");
   Ev_less75_nueCC_CONT->GetYaxis()->SetLabelFont(42);
   Ev_less75_nueCC_CONT->GetYaxis()->SetLabelSize(0.05);
   Ev_less75_nueCC_CONT->GetYaxis()->SetTitleSize(0.06);
   Ev_less75_nueCC_CONT->GetYaxis()->SetTitleOffset(0);
   Ev_less75_nueCC_CONT->GetYaxis()->SetTitleFont(42);
   Ev_less75_nueCC_CONT->GetZaxis()->SetLabelFont(42);
   Ev_less75_nueCC_CONT->GetZaxis()->SetLabelSize(0.05);
   Ev_less75_nueCC_CONT->GetZaxis()->SetTitleSize(0.035);
   Ev_less75_nueCC_CONT->GetZaxis()->SetTitleFont(42);
   Ev_less75_nueCC_CONT->Draw("colz");
   
   pt = new TPaveText(-0.02499998,0.895,1.025,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   pt_LaTex = pt->AddText("#nu_{e}^{CC} contamination");
   pt->Draw();
   c98_3->Modified();
   c98->cd();
  
// ------------>Primitives in pad: c98_4
   TPad *c98_4 = new TPad("c98_4", "c98_4",0.51,0.01,0.99,0.49);
   c98_4->Draw();
   c98_4->cd();
   c98_4->Range(2.126575,-0.1373693,4.482739,0.8638844);
   c98_4->SetFillColor(0);
   c98_4->SetBorderMode(0);
   c98_4->SetBorderSize(2);
   c98_4->SetLeftMargin(0.15);
   c98_4->SetRightMargin(0.12);
   c98_4->SetBottomMargin(0.15);
   c98_4->SetFrameBorderMode(0);
   c98_4->SetFrameBorderMode(0);
   
   TH1F *Ev_over95_numuCC_CONT = new TH1F("Ev_over95_numuCC_CONT","#nu_{#mu}^{CC} FC contamination",10,2.48,4.2);
   Ev_over95_numuCC_CONT->SetBinContent(0,0.75);
   Ev_over95_numuCC_CONT->SetBinContent(1,0.046875);
   Ev_over95_numuCC_CONT->SetBinContent(2,0.05137615);
   Ev_over95_numuCC_CONT->SetBinContent(3,0.09580106);
   Ev_over95_numuCC_CONT->SetBinContent(4,0.174409);
   Ev_over95_numuCC_CONT->SetBinContent(5,0.2209272);
   Ev_over95_numuCC_CONT->SetBinContent(6,0.265157);
   Ev_over95_numuCC_CONT->SetBinContent(7,0.3458967);
   Ev_over95_numuCC_CONT->SetBinContent(8,0.4774477);
   Ev_over95_numuCC_CONT->SetBinContent(9,0.6398104);
   Ev_over95_numuCC_CONT->SetBinContent(10,0.728);
   Ev_over95_numuCC_CONT->SetBinContent(11,0.8656716);
   Ev_over95_numuCC_CONT->SetEntries(3.0457);
   Ev_over95_numuCC_CONT->SetStats(0);

   ci = TColor::GetColor("#000099");
   Ev_over95_numuCC_CONT->SetLineColor(ci);
   Ev_over95_numuCC_CONT->SetLineWidth(3);
   Ev_over95_numuCC_CONT->GetXaxis()->SetTitle("log_{10}(E_{#nu} [MeV])");
   Ev_over95_numuCC_CONT->GetXaxis()->SetLabelFont(42);
   Ev_over95_numuCC_CONT->GetXaxis()->SetLabelSize(0.05);
   Ev_over95_numuCC_CONT->GetXaxis()->SetTitleSize(0.06);
   Ev_over95_numuCC_CONT->GetXaxis()->SetTitleFont(42);
   Ev_over95_numuCC_CONT->GetYaxis()->SetTitle("contamination");
   Ev_over95_numuCC_CONT->GetYaxis()->SetLabelFont(42);
   Ev_over95_numuCC_CONT->GetYaxis()->SetLabelSize(0.05);
   Ev_over95_numuCC_CONT->GetYaxis()->SetTitleSize(0.06);
   Ev_over95_numuCC_CONT->GetYaxis()->SetTitleOffset(0);
   Ev_over95_numuCC_CONT->GetYaxis()->SetTitleFont(42);
   Ev_over95_numuCC_CONT->GetZaxis()->SetLabelFont(42);
   Ev_over95_numuCC_CONT->GetZaxis()->SetLabelSize(0.05);
   Ev_over95_numuCC_CONT->GetZaxis()->SetTitleSize(0.035);
   Ev_over95_numuCC_CONT->GetZaxis()->SetTitleFont(42);
   Ev_over95_numuCC_CONT->Draw("colz");
   
   pt = new TPaveText(-0.02499998,0.895,1.025,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   pt_LaTex = pt->AddText("#nu_{#mu}^{CC} FC contamination");
   pt->Draw();
   c98_4->Modified();
   c98->cd();
   c98->Modified();
   c98->cd();
   c98->SetSelected(c98);
}
