void logNPE_eff_0-20GeV_16volcut_1m_FLAV_less75nscut()
{
//=========Macro generated from canvas: c117/
//=========  (Mon May 27 10:29:29 2019) by ROOT version 6.12/06
   TCanvas *c117 = new TCanvas("c117", "",1120,480,800,600);
   gStyle->SetOptStat(0);
   c117->Range(4.725,-0.7229185,7.475,5.301402);
   c117->SetFillColor(0);
   c117->SetBorderMode(0);
   c117->SetBorderSize(2);
   c117->SetLogy();
   c117->SetBottomMargin(0.12);
   c117->SetFrameBorderMode(0);
   c117->SetFrameBorderMode(0);
   
   TH1F *logNPE_Nue__9 = new TH1F("logNPE_Nue__9","",10,5,7.2);
   logNPE_Nue__9->SetBinContent(0,24777);
   logNPE_Nue__9->SetBinContent(1,7427);
   logNPE_Nue__9->SetBinContent(2,11213);
   logNPE_Nue__9->SetBinContent(3,18078);
   logNPE_Nue__9->SetBinContent(4,23958);
   logNPE_Nue__9->SetBinContent(5,24287);
   logNPE_Nue__9->SetBinContent(6,20672);
   logNPE_Nue__9->SetBinContent(7,14761);
   logNPE_Nue__9->SetBinContent(8,9566);
   logNPE_Nue__9->SetBinContent(9,5627);
   logNPE_Nue__9->SetBinContent(10,3134);
   logNPE_Nue__9->SetBinContent(11,1454);
   logNPE_Nue__9->SetMinimum(1);
   logNPE_Nue__9->SetMaximum(50000);
   logNPE_Nue__9->SetEntries(164954);
   logNPE_Nue__9->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#ff9933");
   logNPE_Nue__9->SetFillColor(ci);
   logNPE_Nue__9->SetFillStyle(3002);

   ci = TColor::GetColor("#ff9933");
   logNPE_Nue__9->SetLineColor(ci);
   logNPE_Nue__9->SetLineWidth(5);
   logNPE_Nue__9->GetXaxis()->SetTitle("log_{10}(NPE_{LPMT})");
   logNPE_Nue__9->GetXaxis()->SetLabelFont(42);
   logNPE_Nue__9->GetXaxis()->SetTitleSize(0.05);
   logNPE_Nue__9->GetXaxis()->SetTitleFont(42);
   logNPE_Nue__9->GetYaxis()->SetTitle("entries");
   logNPE_Nue__9->GetYaxis()->SetLabelFont(42);
   logNPE_Nue__9->GetYaxis()->SetLabelSize(0.05);
   logNPE_Nue__9->GetYaxis()->SetTitleSize(0.035);
   logNPE_Nue__9->GetYaxis()->SetTitleOffset(1.2);
   logNPE_Nue__9->GetYaxis()->SetTitleFont(42);
   logNPE_Nue__9->GetZaxis()->SetLabelFont(42);
   logNPE_Nue__9->GetZaxis()->SetLabelSize(0.035);
   logNPE_Nue__9->GetZaxis()->SetTitleSize(0.035);
   logNPE_Nue__9->GetZaxis()->SetTitleFont(42);
   logNPE_Nue__9->Draw("");
   
   TH1F *logNPE_Nue_fidcut__10 = new TH1F("logNPE_Nue_fidcut__10","",10,5,7.2);
   logNPE_Nue_fidcut__10->SetBinContent(1,5000);
   logNPE_Nue_fidcut__10->SetBinContent(2,7684);
   logNPE_Nue_fidcut__10->SetBinContent(3,12741);
   logNPE_Nue_fidcut__10->SetBinContent(4,17484);
   logNPE_Nue_fidcut__10->SetBinContent(5,17949);
   logNPE_Nue_fidcut__10->SetBinContent(6,15674);
   logNPE_Nue_fidcut__10->SetBinContent(7,11435);
   logNPE_Nue_fidcut__10->SetBinContent(8,7539);
   logNPE_Nue_fidcut__10->SetBinContent(9,4398);
   logNPE_Nue_fidcut__10->SetBinContent(10,2501);
   logNPE_Nue_fidcut__10->SetBinContent(11,1198);
   logNPE_Nue_fidcut__10->SetEntries(103603);
   logNPE_Nue_fidcut__10->SetStats(0);

   ci = TColor::GetColor("#3399ff");
   logNPE_Nue_fidcut__10->SetFillColor(ci);
   logNPE_Nue_fidcut__10->SetFillStyle(3002);

   ci = TColor::GetColor("#3399ff");
   logNPE_Nue_fidcut__10->SetLineColor(ci);
   logNPE_Nue_fidcut__10->SetLineWidth(5);
   logNPE_Nue_fidcut__10->GetXaxis()->SetLabelFont(42);
   logNPE_Nue_fidcut__10->GetXaxis()->SetLabelSize(0.035);
   logNPE_Nue_fidcut__10->GetXaxis()->SetTitleSize(0.035);
   logNPE_Nue_fidcut__10->GetXaxis()->SetTitleFont(42);
   logNPE_Nue_fidcut__10->GetYaxis()->SetLabelFont(42);
   logNPE_Nue_fidcut__10->GetYaxis()->SetLabelSize(0.035);
   logNPE_Nue_fidcut__10->GetYaxis()->SetTitleSize(0.035);
   logNPE_Nue_fidcut__10->GetYaxis()->SetTitleOffset(0);
   logNPE_Nue_fidcut__10->GetYaxis()->SetTitleFont(42);
   logNPE_Nue_fidcut__10->GetZaxis()->SetLabelFont(42);
   logNPE_Nue_fidcut__10->GetZaxis()->SetLabelSize(0.035);
   logNPE_Nue_fidcut__10->GetZaxis()->SetTitleSize(0.035);
   logNPE_Nue_fidcut__10->GetZaxis()->SetTitleFont(42);
   logNPE_Nue_fidcut__10->Draw("same");
   
   TH1F *logNPE_Nue_timecut__11 = new TH1F("logNPE_Nue_timecut__11","",10,5,7.2);
   logNPE_Nue_timecut__11->SetBinContent(1,1609);
   logNPE_Nue_timecut__11->SetBinContent(2,3743);
   logNPE_Nue_timecut__11->SetBinContent(3,6644);
   logNPE_Nue_timecut__11->SetBinContent(4,7933);
   logNPE_Nue_timecut__11->SetBinContent(5,7123);
   logNPE_Nue_timecut__11->SetBinContent(6,6194);
   logNPE_Nue_timecut__11->SetBinContent(7,4696);
   logNPE_Nue_timecut__11->SetBinContent(8,3223);
   logNPE_Nue_timecut__11->SetBinContent(9,1774);
   logNPE_Nue_timecut__11->SetBinContent(10,882);
   logNPE_Nue_timecut__11->SetBinContent(11,299);
   logNPE_Nue_timecut__11->SetEntries(44120);
   logNPE_Nue_timecut__11->SetStats(0);

   ci = TColor::GetColor("#ff0000");
   logNPE_Nue_timecut__11->SetFillColor(ci);
   logNPE_Nue_timecut__11->SetFillStyle(3002);

   ci = TColor::GetColor("#ff0000");
   logNPE_Nue_timecut__11->SetLineColor(ci);
   logNPE_Nue_timecut__11->SetLineWidth(5);
   logNPE_Nue_timecut__11->GetXaxis()->SetTitle("log_{10}(NPE_{LPMT})");
   logNPE_Nue_timecut__11->GetXaxis()->SetLabelFont(42);
   logNPE_Nue_timecut__11->GetXaxis()->SetLabelSize(0.035);
   logNPE_Nue_timecut__11->GetXaxis()->SetTitleSize(0.035);
   logNPE_Nue_timecut__11->GetXaxis()->SetTitleFont(42);
   logNPE_Nue_timecut__11->GetYaxis()->SetLabelFont(42);
   logNPE_Nue_timecut__11->GetYaxis()->SetLabelSize(0.035);
   logNPE_Nue_timecut__11->GetYaxis()->SetTitleSize(0.035);
   logNPE_Nue_timecut__11->GetYaxis()->SetTitleOffset(0);
   logNPE_Nue_timecut__11->GetYaxis()->SetTitleFont(42);
   logNPE_Nue_timecut__11->GetZaxis()->SetLabelFont(42);
   logNPE_Nue_timecut__11->GetZaxis()->SetLabelSize(0.035);
   logNPE_Nue_timecut__11->GetZaxis()->SetTitleSize(0.035);
   logNPE_Nue_timecut__11->GetZaxis()->SetTitleFont(42);
   logNPE_Nue_timecut__11->Draw("same");
   
   TH1F *logNPE_bkg1__12 = new TH1F("logNPE_bkg1__12","",10,5,7.2);
   logNPE_bkg1__12->SetBinContent(1,8);
   logNPE_bkg1__12->SetBinContent(2,25);
   logNPE_bkg1__12->SetBinContent(3,1003);
   logNPE_bkg1__12->SetBinContent(4,1894);
   logNPE_bkg1__12->SetBinContent(5,915);
   logNPE_bkg1__12->SetBinContent(6,676);
   logNPE_bkg1__12->SetBinContent(7,360);
   logNPE_bkg1__12->SetBinContent(8,256);
   logNPE_bkg1__12->SetBinContent(9,105);
   logNPE_bkg1__12->SetBinContent(10,38);
   logNPE_bkg1__12->SetBinContent(11,33);
   logNPE_bkg1__12->SetEntries(5313);
   logNPE_bkg1__12->SetStats(0);

   ci = TColor::GetColor("#006600");
   logNPE_bkg1__12->SetFillColor(ci);
   logNPE_bkg1__12->SetFillStyle(3002);

   ci = TColor::GetColor("#006600");
   logNPE_bkg1__12->SetLineColor(ci);
   logNPE_bkg1__12->SetLineWidth(5);
   logNPE_bkg1__12->GetXaxis()->SetTitle("log_{10}(NPE_{LPMT})");
   logNPE_bkg1__12->GetXaxis()->SetLabelFont(42);
   logNPE_bkg1__12->GetXaxis()->SetLabelSize(0.035);
   logNPE_bkg1__12->GetXaxis()->SetTitleSize(0.035);
   logNPE_bkg1__12->GetXaxis()->SetTitleFont(42);
   logNPE_bkg1__12->GetYaxis()->SetLabelFont(42);
   logNPE_bkg1__12->GetYaxis()->SetLabelSize(0.035);
   logNPE_bkg1__12->GetYaxis()->SetTitleSize(0.035);
   logNPE_bkg1__12->GetYaxis()->SetTitleOffset(0);
   logNPE_bkg1__12->GetYaxis()->SetTitleFont(42);
   logNPE_bkg1__12->GetZaxis()->SetLabelFont(42);
   logNPE_bkg1__12->GetZaxis()->SetLabelSize(0.035);
   logNPE_bkg1__12->GetZaxis()->SetTitleSize(0.035);
   logNPE_bkg1__12->GetZaxis()->SetTitleFont(42);
   logNPE_bkg1__12->Draw("same");
   
   TLegend *leg = new TLegend(0.15,0.15,0.4,0.45,NULL,"brNDC");
   leg->SetBorderSize(1);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("logNPE_Nue","#nu_{e}","l");

   ci = TColor::GetColor("#ff9933");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(5);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("logNPE_Nue_fidcut","#nu_{e} fid.","l");

   ci = TColor::GetColor("#3399ff");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(5);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("logNPE_Nue_timecut","#nu_{e} sel.","l");

   ci = TColor::GetColor("#ff0000");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(5);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("logNPE_bkg1","res. bkg","l");

   ci = TColor::GetColor("#006600");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(5);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   c117->Modified();
   c117->cd();
   c117->SetSelected(c117);
}
