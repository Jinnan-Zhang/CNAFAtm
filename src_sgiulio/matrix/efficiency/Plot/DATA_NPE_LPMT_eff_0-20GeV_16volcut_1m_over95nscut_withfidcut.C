void DATA_NPE_LPMT_eff_0-20GeV_16volcut_1m_over95nscut_withfidcut()
{
//=========Macro generated from canvas: c25/
//=========  (Tue Jul  9 16:34:52 2019) by ROOT version 6.12/06
   TCanvas *c25 = new TCanvas("c25", "",865,52,800,600);
   gStyle->SetOptStat(0);
   c25->Range(-3750000,-0.3315341,3.375e+07,3.898677);
   c25->SetFillColor(0);
   c25->SetBorderMode(0);
   c25->SetBorderSize(2);
   c25->SetLogy();
   c25->SetBottomMargin(0.12);
   c25->SetFrameBorderMode(0);
   c25->SetFrameBorderMode(0);
   
   TH1F *Npe_LPMT_numuCC__4 = new TH1F("Npe_LPMT_numuCC__4","",12,0,3e+07);
   Npe_LPMT_numuCC__4->SetBinContent(1,1578);
   Npe_LPMT_numuCC__4->SetBinContent(2,424);
   Npe_LPMT_numuCC__4->SetBinContent(3,85);
   Npe_LPMT_numuCC__4->SetBinContent(4,51);
   Npe_LPMT_numuCC__4->SetBinContent(5,23);
   Npe_LPMT_numuCC__4->SetBinContent(6,9);
   Npe_LPMT_numuCC__4->SetBinContent(7,10);
   Npe_LPMT_numuCC__4->SetBinContent(8,3);
   Npe_LPMT_numuCC__4->SetBinContent(9,3);
   Npe_LPMT_numuCC__4->SetEntries(2186);
   Npe_LPMT_numuCC__4->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#3399ff");
   Npe_LPMT_numuCC__4->SetFillColor(ci);
   Npe_LPMT_numuCC__4->SetFillStyle(3002);

   ci = TColor::GetColor("#3399ff");
   Npe_LPMT_numuCC__4->SetLineColor(ci);
   Npe_LPMT_numuCC__4->SetLineWidth(5);
   Npe_LPMT_numuCC__4->GetXaxis()->SetTitle("NPE_{LPMT}");
   Npe_LPMT_numuCC__4->GetXaxis()->SetLabelFont(42);
   Npe_LPMT_numuCC__4->GetXaxis()->SetLabelSize(0.05);
   Npe_LPMT_numuCC__4->GetXaxis()->SetTitleSize(0.05);
   Npe_LPMT_numuCC__4->GetXaxis()->SetTitleFont(42);
   Npe_LPMT_numuCC__4->GetYaxis()->SetTitle("entries");
   Npe_LPMT_numuCC__4->GetYaxis()->SetLabelFont(42);
   Npe_LPMT_numuCC__4->GetYaxis()->SetLabelSize(0.05);
   Npe_LPMT_numuCC__4->GetYaxis()->SetTitleSize(0.035);
   Npe_LPMT_numuCC__4->GetYaxis()->SetTitleOffset(1.2);
   Npe_LPMT_numuCC__4->GetYaxis()->SetTitleFont(42);
   Npe_LPMT_numuCC__4->GetZaxis()->SetLabelFont(42);
   Npe_LPMT_numuCC__4->GetZaxis()->SetLabelSize(0.035);
   Npe_LPMT_numuCC__4->GetZaxis()->SetTitleSize(0.035);
   Npe_LPMT_numuCC__4->GetZaxis()->SetTitleFont(42);
   Npe_LPMT_numuCC__4->Draw("");
   
   TH1F *Npe_LPMT_numuCC_cut__5 = new TH1F("Npe_LPMT_numuCC_cut__5","",12,0,3e+07);
   Npe_LPMT_numuCC_cut__5->SetBinContent(1,1495);
   Npe_LPMT_numuCC_cut__5->SetBinContent(2,379);
   Npe_LPMT_numuCC_cut__5->SetBinContent(3,78);
   Npe_LPMT_numuCC_cut__5->SetBinContent(4,43);
   Npe_LPMT_numuCC_cut__5->SetBinContent(5,20);
   Npe_LPMT_numuCC_cut__5->SetBinContent(6,6);
   Npe_LPMT_numuCC_cut__5->SetBinContent(7,6);
   Npe_LPMT_numuCC_cut__5->SetBinContent(8,2);
   Npe_LPMT_numuCC_cut__5->SetBinContent(9,3);
   Npe_LPMT_numuCC_cut__5->SetEntries(2032);
   Npe_LPMT_numuCC_cut__5->SetStats(0);

   ci = TColor::GetColor("#ff0000");
   Npe_LPMT_numuCC_cut__5->SetFillColor(ci);
   Npe_LPMT_numuCC_cut__5->SetFillStyle(3002);

   ci = TColor::GetColor("#ff0000");
   Npe_LPMT_numuCC_cut__5->SetLineColor(ci);
   Npe_LPMT_numuCC_cut__5->SetLineWidth(5);
   Npe_LPMT_numuCC_cut__5->GetXaxis()->SetTitle("NPE_{LPMT}");
   Npe_LPMT_numuCC_cut__5->GetXaxis()->SetLabelFont(42);
   Npe_LPMT_numuCC_cut__5->GetXaxis()->SetLabelSize(0.035);
   Npe_LPMT_numuCC_cut__5->GetXaxis()->SetTitleSize(0.035);
   Npe_LPMT_numuCC_cut__5->GetXaxis()->SetTitleFont(42);
   Npe_LPMT_numuCC_cut__5->GetYaxis()->SetLabelFont(42);
   Npe_LPMT_numuCC_cut__5->GetYaxis()->SetLabelSize(0.035);
   Npe_LPMT_numuCC_cut__5->GetYaxis()->SetTitleSize(0.035);
   Npe_LPMT_numuCC_cut__5->GetYaxis()->SetTitleOffset(0);
   Npe_LPMT_numuCC_cut__5->GetYaxis()->SetTitleFont(42);
   Npe_LPMT_numuCC_cut__5->GetZaxis()->SetLabelFont(42);
   Npe_LPMT_numuCC_cut__5->GetZaxis()->SetLabelSize(0.035);
   Npe_LPMT_numuCC_cut__5->GetZaxis()->SetTitleSize(0.035);
   Npe_LPMT_numuCC_cut__5->GetZaxis()->SetTitleFont(42);
   Npe_LPMT_numuCC_cut__5->Draw("same");
   
   TH1F *Npe_LPMT_bkg2__6 = new TH1F("Npe_LPMT_bkg2__6","",12,0,3e+07);
   Npe_LPMT_bkg2__6->SetBinContent(1,369);
   Npe_LPMT_bkg2__6->SetBinContent(2,91);
   Npe_LPMT_bkg2__6->SetBinContent(3,35);
   Npe_LPMT_bkg2__6->SetBinContent(4,18);
   Npe_LPMT_bkg2__6->SetBinContent(5,9);
   Npe_LPMT_bkg2__6->SetBinContent(6,4);
   Npe_LPMT_bkg2__6->SetBinContent(7,3);
   Npe_LPMT_bkg2__6->SetBinContent(8,3);
   Npe_LPMT_bkg2__6->SetBinContent(9,1);
   Npe_LPMT_bkg2__6->SetEntries(533);
   Npe_LPMT_bkg2__6->SetStats(0);

   ci = TColor::GetColor("#006600");
   Npe_LPMT_bkg2__6->SetFillColor(ci);
   Npe_LPMT_bkg2__6->SetFillStyle(3002);

   ci = TColor::GetColor("#006600");
   Npe_LPMT_bkg2__6->SetLineColor(ci);
   Npe_LPMT_bkg2__6->SetLineWidth(5);
   Npe_LPMT_bkg2__6->GetXaxis()->SetTitle("NPE_{LPMT}");
   Npe_LPMT_bkg2__6->GetXaxis()->SetLabelFont(42);
   Npe_LPMT_bkg2__6->GetXaxis()->SetLabelSize(0.035);
   Npe_LPMT_bkg2__6->GetXaxis()->SetTitleSize(0.035);
   Npe_LPMT_bkg2__6->GetXaxis()->SetTitleFont(42);
   Npe_LPMT_bkg2__6->GetYaxis()->SetLabelFont(42);
   Npe_LPMT_bkg2__6->GetYaxis()->SetLabelSize(0.035);
   Npe_LPMT_bkg2__6->GetYaxis()->SetTitleSize(0.035);
   Npe_LPMT_bkg2__6->GetYaxis()->SetTitleOffset(0);
   Npe_LPMT_bkg2__6->GetYaxis()->SetTitleFont(42);
   Npe_LPMT_bkg2__6->GetZaxis()->SetLabelFont(42);
   Npe_LPMT_bkg2__6->GetZaxis()->SetLabelSize(0.035);
   Npe_LPMT_bkg2__6->GetZaxis()->SetTitleSize(0.035);
   Npe_LPMT_bkg2__6->GetZaxis()->SetTitleFont(42);
   Npe_LPMT_bkg2__6->Draw("same");
   
   TLegend *leg = new TLegend(0.65,0.6,0.9,0.9,NULL,"brNDC");
   leg->SetBorderSize(1);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("Npe_LPMT_numuCC","#nu_{#mu} CC","l");

   ci = TColor::GetColor("#3399ff");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(5);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Npe_LPMT_numuCC_cut","#nu_{#mu} CC sel.","l");

   ci = TColor::GetColor("#ff0000");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(5);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Npe_LPMT_bkg2","res. bkg","l");

   ci = TColor::GetColor("#006600");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(5);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   c25->Modified();
   c25->cd();
   c25->SetSelected(c25);
}
