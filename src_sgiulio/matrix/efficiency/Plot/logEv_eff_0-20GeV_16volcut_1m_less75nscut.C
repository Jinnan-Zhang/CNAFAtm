void logEv_eff_0-20GeV_16volcut_1m_less75nscut()
{
//=========Macro generated from canvas: c17/
//=========  (Thu Jun 20 17:54:18 2019) by ROOT version 6.12/06
   TCanvas *c17 = new TCanvas("c17", "",193,183,800,600);
   gStyle->SetOptStat(0);
   c17->Range(1.725,-0.5283228,4.475,3.874367);
   c17->SetFillColor(0);
   c17->SetBorderMode(0);
   c17->SetBorderSize(2);
   c17->SetLogy();
   c17->SetBottomMargin(0.12);
   c17->SetFrameBorderMode(0);
   c17->SetFrameBorderMode(0);
   
   TH1F *logEv_bkg1__9 = new TH1F("logEv_bkg1__9","",12,2,4.2);
   logEv_bkg1__9->SetBinContent(1,2);
   logEv_bkg1__9->SetBinContent(2,7);
   logEv_bkg1__9->SetBinContent(3,76);
   logEv_bkg1__9->SetBinContent(4,623);
   logEv_bkg1__9->SetBinContent(5,1226);
   logEv_bkg1__9->SetBinContent(6,1434);
   logEv_bkg1__9->SetBinContent(7,1284);
   logEv_bkg1__9->SetBinContent(8,1047);
   logEv_bkg1__9->SetBinContent(9,720);
   logEv_bkg1__9->SetBinContent(10,454);
   logEv_bkg1__9->SetBinContent(11,245);
   logEv_bkg1__9->SetBinContent(12,125);
   logEv_bkg1__9->SetBinContent(13,34);
   logEv_bkg1__9->SetEntries(7277);
   logEv_bkg1__9->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#006600");
   logEv_bkg1__9->SetFillColor(ci);
   logEv_bkg1__9->SetFillStyle(3002);

   ci = TColor::GetColor("#006600");
   logEv_bkg1__9->SetLineColor(ci);
   logEv_bkg1__9->SetLineWidth(5);
   logEv_bkg1__9->GetXaxis()->SetTitle("log_{10}(E_{#nu} [MeV])");
   logEv_bkg1__9->GetXaxis()->SetLabelFont(42);
   logEv_bkg1__9->GetXaxis()->SetLabelSize(0.035);
   logEv_bkg1__9->GetXaxis()->SetTitleSize(0.035);
   logEv_bkg1__9->GetXaxis()->SetTitleFont(42);
   logEv_bkg1__9->GetYaxis()->SetLabelFont(42);
   logEv_bkg1__9->GetYaxis()->SetLabelSize(0.035);
   logEv_bkg1__9->GetYaxis()->SetTitleSize(0.035);
   logEv_bkg1__9->GetYaxis()->SetTitleOffset(0);
   logEv_bkg1__9->GetYaxis()->SetTitleFont(42);
   logEv_bkg1__9->GetZaxis()->SetLabelFont(42);
   logEv_bkg1__9->GetZaxis()->SetLabelSize(0.035);
   logEv_bkg1__9->GetZaxis()->SetTitleSize(0.035);
   logEv_bkg1__9->GetZaxis()->SetTitleFont(42);
   logEv_bkg1__9->Draw("text");
   
   TLegend *leg = new TLegend(0.68,0.6,0.9,0.9,NULL,"brNDC");
   leg->SetBorderSize(1);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("logEv_nueCC","#nu_{e}^{CC}","l");

   ci = TColor::GetColor("#ffcc00");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(5);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("logEv_nueCC_fidcut","#nu_{e}^{CC} fid.","l");

   ci = TColor::GetColor("#3399ff");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(5);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("logEv_nueCC_timecut","#nu_{e}^{CC} sel.","l");

   ci = TColor::GetColor("#ff0000");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(5);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("logEv_bkg1","res. bkg","l");

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
