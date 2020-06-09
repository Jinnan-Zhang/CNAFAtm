void logEv_eff_0-20GeV_16volcut_1m_FLAV_less75nscut()
{
//=========Macro generated from canvas: c17/
//=========  (Mon May 27 10:29:25 2019) by ROOT version 6.12/06
   TCanvas *c17 = new TCanvas("c17", "",65,52,800,600);
   gStyle->SetOptStat(0);
   c17->Range(-1.275,-0.7229185,1.475,5.301402);
   c17->SetFillColor(0);
   c17->SetBorderMode(0);
   c17->SetBorderSize(2);
   c17->SetLogy();
   c17->SetBottomMargin(0.12);
   c17->SetFrameBorderMode(0);
   c17->SetFrameBorderMode(0);
   
   TH1F *logEv_Nue__1 = new TH1F("logEv_Nue__1","",10,-1,1.2);
   logEv_Nue__1->SetBinContent(0,2066);
   logEv_Nue__1->SetBinContent(1,6296);
   logEv_Nue__1->SetBinContent(2,14851);
   logEv_Nue__1->SetBinContent(3,23436);
   logEv_Nue__1->SetBinContent(4,29499);
   logEv_Nue__1->SetBinContent(5,29281);
   logEv_Nue__1->SetBinContent(6,23604);
   logEv_Nue__1->SetBinContent(7,16502);
   logEv_Nue__1->SetBinContent(8,9950);
   logEv_Nue__1->SetBinContent(9,5699);
   logEv_Nue__1->SetBinContent(10,3002);
   logEv_Nue__1->SetBinContent(11,768);
   logEv_Nue__1->SetMinimum(1);
   logEv_Nue__1->SetMaximum(50000);
   logEv_Nue__1->SetEntries(164954);
   logEv_Nue__1->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#ff9933");
   logEv_Nue__1->SetFillColor(ci);
   logEv_Nue__1->SetFillStyle(3002);

   ci = TColor::GetColor("#ff9933");
   logEv_Nue__1->SetLineColor(ci);
   logEv_Nue__1->SetLineWidth(5);
   logEv_Nue__1->GetXaxis()->SetTitle("log_{10}(E_{#nu} [GeV])");
   logEv_Nue__1->GetXaxis()->SetLabelFont(42);
   logEv_Nue__1->GetXaxis()->SetTitleSize(0.05);
   logEv_Nue__1->GetXaxis()->SetTitleFont(42);
   logEv_Nue__1->GetYaxis()->SetTitle("entries");
   logEv_Nue__1->GetYaxis()->SetLabelFont(42);
   logEv_Nue__1->GetYaxis()->SetLabelSize(0.05);
   logEv_Nue__1->GetYaxis()->SetTitleSize(0.035);
   logEv_Nue__1->GetYaxis()->SetTitleOffset(1.2);
   logEv_Nue__1->GetYaxis()->SetTitleFont(42);
   logEv_Nue__1->GetZaxis()->SetLabelFont(42);
   logEv_Nue__1->GetZaxis()->SetLabelSize(0.035);
   logEv_Nue__1->GetZaxis()->SetTitleSize(0.035);
   logEv_Nue__1->GetZaxis()->SetTitleFont(42);
   logEv_Nue__1->Draw("");
   
   TH1F *logEv_Nue_fidcut__2 = new TH1F("logEv_Nue_fidcut__2","",10,-1,1.2);
   logEv_Nue_fidcut__2->SetBinContent(0,1498);
   logEv_Nue_fidcut__2->SetBinContent(1,4601);
   logEv_Nue_fidcut__2->SetBinContent(2,10964);
   logEv_Nue_fidcut__2->SetBinContent(3,17166);
   logEv_Nue_fidcut__2->SetBinContent(4,21694);
   logEv_Nue_fidcut__2->SetBinContent(5,21500);
   logEv_Nue_fidcut__2->SetBinContent(6,17325);
   logEv_Nue_fidcut__2->SetBinContent(7,12226);
   logEv_Nue_fidcut__2->SetBinContent(8,7295);
   logEv_Nue_fidcut__2->SetBinContent(9,4106);
   logEv_Nue_fidcut__2->SetBinContent(10,2211);
   logEv_Nue_fidcut__2->SetBinContent(11,536);
   logEv_Nue_fidcut__2->SetEntries(121122);
   logEv_Nue_fidcut__2->SetStats(0);

   ci = TColor::GetColor("#3399ff");
   logEv_Nue_fidcut__2->SetFillColor(ci);
   logEv_Nue_fidcut__2->SetFillStyle(3002);

   ci = TColor::GetColor("#3399ff");
   logEv_Nue_fidcut__2->SetLineColor(ci);
   logEv_Nue_fidcut__2->SetLineWidth(5);
   logEv_Nue_fidcut__2->GetXaxis()->SetLabelFont(42);
   logEv_Nue_fidcut__2->GetXaxis()->SetLabelSize(0.035);
   logEv_Nue_fidcut__2->GetXaxis()->SetTitleSize(0.035);
   logEv_Nue_fidcut__2->GetXaxis()->SetTitleFont(42);
   logEv_Nue_fidcut__2->GetYaxis()->SetLabelFont(42);
   logEv_Nue_fidcut__2->GetYaxis()->SetLabelSize(0.035);
   logEv_Nue_fidcut__2->GetYaxis()->SetTitleSize(0.035);
   logEv_Nue_fidcut__2->GetYaxis()->SetTitleOffset(0);
   logEv_Nue_fidcut__2->GetYaxis()->SetTitleFont(42);
   logEv_Nue_fidcut__2->GetZaxis()->SetLabelFont(42);
   logEv_Nue_fidcut__2->GetZaxis()->SetLabelSize(0.035);
   logEv_Nue_fidcut__2->GetZaxis()->SetTitleSize(0.035);
   logEv_Nue_fidcut__2->GetZaxis()->SetTitleFont(42);
   logEv_Nue_fidcut__2->Draw("same");
   
   TH1F *logEv_Nue_timecut__3 = new TH1F("logEv_Nue_timecut__3","",10,-1,1.2);
   logEv_Nue_timecut__3->SetBinContent(0,152);
   logEv_Nue_timecut__3->SetBinContent(1,1731);
   logEv_Nue_timecut__3->SetBinContent(2,5228);
   logEv_Nue_timecut__3->SetBinContent(3,7813);
   logEv_Nue_timecut__3->SetBinContent(4,7964);
   logEv_Nue_timecut__3->SetBinContent(5,7159);
   logEv_Nue_timecut__3->SetBinContent(6,5670);
   logEv_Nue_timecut__3->SetBinContent(7,4170);
   logEv_Nue_timecut__3->SetBinContent(8,2448);
   logEv_Nue_timecut__3->SetBinContent(9,1212);
   logEv_Nue_timecut__3->SetBinContent(10,513);
   logEv_Nue_timecut__3->SetBinContent(11,60);
   logEv_Nue_timecut__3->SetEntries(44120);
   logEv_Nue_timecut__3->SetStats(0);

   ci = TColor::GetColor("#ff0000");
   logEv_Nue_timecut__3->SetFillColor(ci);
   logEv_Nue_timecut__3->SetFillStyle(3002);

   ci = TColor::GetColor("#ff0000");
   logEv_Nue_timecut__3->SetLineColor(ci);
   logEv_Nue_timecut__3->SetLineWidth(5);
   logEv_Nue_timecut__3->GetXaxis()->SetTitle("log_{10}(E_{#nu} [GeV])");
   logEv_Nue_timecut__3->GetXaxis()->SetLabelFont(42);
   logEv_Nue_timecut__3->GetXaxis()->SetLabelSize(0.035);
   logEv_Nue_timecut__3->GetXaxis()->SetTitleSize(0.035);
   logEv_Nue_timecut__3->GetXaxis()->SetTitleFont(42);
   logEv_Nue_timecut__3->GetYaxis()->SetLabelFont(42);
   logEv_Nue_timecut__3->GetYaxis()->SetLabelSize(0.035);
   logEv_Nue_timecut__3->GetYaxis()->SetTitleSize(0.035);
   logEv_Nue_timecut__3->GetYaxis()->SetTitleOffset(0);
   logEv_Nue_timecut__3->GetYaxis()->SetTitleFont(42);
   logEv_Nue_timecut__3->GetZaxis()->SetLabelFont(42);
   logEv_Nue_timecut__3->GetZaxis()->SetLabelSize(0.035);
   logEv_Nue_timecut__3->GetZaxis()->SetTitleSize(0.035);
   logEv_Nue_timecut__3->GetZaxis()->SetTitleFont(42);
   logEv_Nue_timecut__3->Draw("same");
   
   TH1F *logEv_bkg1__4 = new TH1F("logEv_bkg1__4","",10,-1,1.2);
   logEv_bkg1__4->SetBinContent(1,1);
   logEv_bkg1__4->SetBinContent(2,15);
   logEv_bkg1__4->SetBinContent(3,234);
   logEv_bkg1__4->SetBinContent(4,928);
   logEv_bkg1__4->SetBinContent(5,1204);
   logEv_bkg1__4->SetBinContent(6,1070);
   logEv_bkg1__4->SetBinContent(7,832);
   logEv_bkg1__4->SetBinContent(8,544);
   logEv_bkg1__4->SetBinContent(9,287);
   logEv_bkg1__4->SetBinContent(10,159);
   logEv_bkg1__4->SetBinContent(11,39);
   logEv_bkg1__4->SetEntries(5313);
   logEv_bkg1__4->SetStats(0);

   ci = TColor::GetColor("#006600");
   logEv_bkg1__4->SetFillColor(ci);
   logEv_bkg1__4->SetFillStyle(3002);

   ci = TColor::GetColor("#006600");
   logEv_bkg1__4->SetLineColor(ci);
   logEv_bkg1__4->SetLineWidth(5);
   logEv_bkg1__4->GetXaxis()->SetTitle("log_{10}(E_{#nu} [GeV])");
   logEv_bkg1__4->GetXaxis()->SetLabelFont(42);
   logEv_bkg1__4->GetXaxis()->SetLabelSize(0.035);
   logEv_bkg1__4->GetXaxis()->SetTitleSize(0.035);
   logEv_bkg1__4->GetXaxis()->SetTitleFont(42);
   logEv_bkg1__4->GetYaxis()->SetLabelFont(42);
   logEv_bkg1__4->GetYaxis()->SetLabelSize(0.035);
   logEv_bkg1__4->GetYaxis()->SetTitleSize(0.035);
   logEv_bkg1__4->GetYaxis()->SetTitleOffset(0);
   logEv_bkg1__4->GetYaxis()->SetTitleFont(42);
   logEv_bkg1__4->GetZaxis()->SetLabelFont(42);
   logEv_bkg1__4->GetZaxis()->SetLabelSize(0.035);
   logEv_bkg1__4->GetZaxis()->SetTitleSize(0.035);
   logEv_bkg1__4->GetZaxis()->SetTitleFont(42);
   logEv_bkg1__4->Draw("same");
   
   TLegend *leg = new TLegend(0.35,0.15,0.6,0.4,NULL,"brNDC");
   leg->SetBorderSize(1);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("logEv_Nue","#nu_{e} - inj.","l");

   ci = TColor::GetColor("#ff9933");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(5);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("logEv_Nue_fidcut","#nu_{e} - fid.","l");

   ci = TColor::GetColor("#3399ff");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(5);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("logEv_Nue_timecut","#nu_{e} - sel.","l");

   ci = TColor::GetColor("#ff0000");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(5);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("logEv_bkg1","Res. bkg","l");

   ci = TColor::GetColor("#006600");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(5);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   c17->Modified();
   c17->cd();
   c17->SetSelected(c17);
}
