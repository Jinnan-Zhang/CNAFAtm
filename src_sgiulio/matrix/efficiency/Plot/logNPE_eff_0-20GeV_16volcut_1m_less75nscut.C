void logNPE_eff_0-20GeV_16volcut_1m_less75nscut()
{
//=========Macro generated from canvas: c117/
//=========  (Thu Jun 20 17:55:46 2019) by ROOT version 6.12/06
   TCanvas *c117 = new TCanvas("c117", "",269,259,800,600);
   gStyle->SetOptStat(0);
   c117->Range(4.725,2.936926,7.475,4.768383);
   c117->SetFillColor(0);
   c117->SetBorderMode(0);
   c117->SetBorderSize(2);
   c117->SetLogy();
   c117->SetBottomMargin(0.12);
   c117->SetFrameBorderMode(0);
   c117->SetFrameBorderMode(0);
   
   TH1F *logNPE_nueCC__14 = new TH1F("logNPE_nueCC__14","",10,5,7.2);
   logNPE_nueCC__14->SetBinContent(0,2155);
   logNPE_nueCC__14->SetBinContent(1,3414);
   logNPE_nueCC__14->SetBinContent(2,7503);
   logNPE_nueCC__14->SetBinContent(3,13427);
   logNPE_nueCC__14->SetBinContent(4,18741);
   logNPE_nueCC__14->SetBinContent(5,20309);
   logNPE_nueCC__14->SetBinContent(6,18145);
   logNPE_nueCC__14->SetBinContent(7,13268);
   logNPE_nueCC__14->SetBinContent(8,8716);
   logNPE_nueCC__14->SetBinContent(9,5174);
   logNPE_nueCC__14->SetBinContent(10,2869);
   logNPE_nueCC__14->SetBinContent(11,1453);
   logNPE_nueCC__14->SetEntries(115174);
   logNPE_nueCC__14->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#ffcc00");
   logNPE_nueCC__14->SetFillColor(ci);
   logNPE_nueCC__14->SetFillStyle(3002);

   ci = TColor::GetColor("#ffcc00");
   logNPE_nueCC__14->SetLineColor(ci);
   logNPE_nueCC__14->SetLineWidth(5);
   logNPE_nueCC__14->GetXaxis()->SetTitle("log_{10}(NPE_{LPMT})");
   logNPE_nueCC__14->GetXaxis()->SetLabelFont(42);
   logNPE_nueCC__14->GetXaxis()->SetTitleSize(0.05);
   logNPE_nueCC__14->GetXaxis()->SetTitleFont(42);
   logNPE_nueCC__14->GetYaxis()->SetTitle("entries");
   logNPE_nueCC__14->GetYaxis()->SetLabelFont(42);
   logNPE_nueCC__14->GetYaxis()->SetLabelSize(0.05);
   logNPE_nueCC__14->GetYaxis()->SetTitleSize(0.035);
   logNPE_nueCC__14->GetYaxis()->SetTitleOffset(1.2);
   logNPE_nueCC__14->GetYaxis()->SetTitleFont(42);
   logNPE_nueCC__14->GetZaxis()->SetLabelFont(42);
   logNPE_nueCC__14->GetZaxis()->SetLabelSize(0.035);
   logNPE_nueCC__14->GetZaxis()->SetTitleSize(0.035);
   logNPE_nueCC__14->GetZaxis()->SetTitleFont(42);
   logNPE_nueCC__14->Draw("");
   
   TH1F *logNPE_nueCC_fidcut__15 = new TH1F("logNPE_nueCC_fidcut__15","",10,5,7.2);
   logNPE_nueCC_fidcut__15->SetBinContent(1,2111);
   logNPE_nueCC_fidcut__15->SetBinContent(2,5044);
   logNPE_nueCC_fidcut__15->SetBinContent(3,9373);
   logNPE_nueCC_fidcut__15->SetBinContent(4,13545);
   logNPE_nueCC_fidcut__15->SetBinContent(5,14964);
   logNPE_nueCC_fidcut__15->SetBinContent(6,13646);
   logNPE_nueCC_fidcut__15->SetBinContent(7,10227);
   logNPE_nueCC_fidcut__15->SetBinContent(8,6797);
   logNPE_nueCC_fidcut__15->SetBinContent(9,3961);
   logNPE_nueCC_fidcut__15->SetBinContent(10,2270);
   logNPE_nueCC_fidcut__15->SetBinContent(11,1186);
   logNPE_nueCC_fidcut__15->SetEntries(83124);
   logNPE_nueCC_fidcut__15->SetStats(0);

   ci = TColor::GetColor("#3399ff");
   logNPE_nueCC_fidcut__15->SetFillColor(ci);
   logNPE_nueCC_fidcut__15->SetFillStyle(3002);

   ci = TColor::GetColor("#3399ff");
   logNPE_nueCC_fidcut__15->SetLineColor(ci);
   logNPE_nueCC_fidcut__15->SetLineWidth(5);
   logNPE_nueCC_fidcut__15->GetXaxis()->SetLabelFont(42);
   logNPE_nueCC_fidcut__15->GetXaxis()->SetLabelSize(0.035);
   logNPE_nueCC_fidcut__15->GetXaxis()->SetTitleSize(0.035);
   logNPE_nueCC_fidcut__15->GetXaxis()->SetTitleFont(42);
   logNPE_nueCC_fidcut__15->GetYaxis()->SetLabelFont(42);
   logNPE_nueCC_fidcut__15->GetYaxis()->SetLabelSize(0.035);
   logNPE_nueCC_fidcut__15->GetYaxis()->SetTitleSize(0.035);
   logNPE_nueCC_fidcut__15->GetYaxis()->SetTitleOffset(0);
   logNPE_nueCC_fidcut__15->GetYaxis()->SetTitleFont(42);
   logNPE_nueCC_fidcut__15->GetZaxis()->SetLabelFont(42);
   logNPE_nueCC_fidcut__15->GetZaxis()->SetLabelSize(0.035);
   logNPE_nueCC_fidcut__15->GetZaxis()->SetTitleSize(0.035);
   logNPE_nueCC_fidcut__15->GetZaxis()->SetTitleFont(42);
   logNPE_nueCC_fidcut__15->Draw("same");
   
   TH1F *logNPE_all_timecut__16 = new TH1F("logNPE_all_timecut__16","",10,5,7.2);
   logNPE_all_timecut__16->SetBinContent(1,1616);
   logNPE_all_timecut__16->SetBinContent(2,3772);
   logNPE_all_timecut__16->SetBinContent(3,7615);
   logNPE_all_timecut__16->SetBinContent(4,9720);
   logNPE_all_timecut__16->SetBinContent(5,7902);
   logNPE_all_timecut__16->SetBinContent(6,6643);
   logNPE_all_timecut__16->SetBinContent(7,4793);
   logNPE_all_timecut__16->SetBinContent(8,3204);
   logNPE_all_timecut__16->SetBinContent(9,1676);
   logNPE_all_timecut__16->SetBinContent(10,769);
   logNPE_all_timecut__16->SetBinContent(11,237);
   logNPE_all_timecut__16->SetEntries(47947);
   logNPE_all_timecut__16->SetStats(0);

   ci = TColor::GetColor("#333333");
   logNPE_all_timecut__16->SetFillColor(ci);
   logNPE_all_timecut__16->SetFillStyle(3002);

   ci = TColor::GetColor("#333333");
   logNPE_all_timecut__16->SetLineColor(ci);
   logNPE_all_timecut__16->SetLineWidth(5);
   logNPE_all_timecut__16->GetXaxis()->SetTitle("log_{10}(NPE_{LPMT})");
   logNPE_all_timecut__16->GetXaxis()->SetLabelFont(42);
   logNPE_all_timecut__16->GetXaxis()->SetLabelSize(0.035);
   logNPE_all_timecut__16->GetXaxis()->SetTitleSize(0.035);
   logNPE_all_timecut__16->GetXaxis()->SetTitleFont(42);
   logNPE_all_timecut__16->GetYaxis()->SetLabelFont(42);
   logNPE_all_timecut__16->GetYaxis()->SetLabelSize(0.035);
   logNPE_all_timecut__16->GetYaxis()->SetTitleSize(0.035);
   logNPE_all_timecut__16->GetYaxis()->SetTitleOffset(0);
   logNPE_all_timecut__16->GetYaxis()->SetTitleFont(42);
   logNPE_all_timecut__16->GetZaxis()->SetLabelFont(42);
   logNPE_all_timecut__16->GetZaxis()->SetLabelSize(0.035);
   logNPE_all_timecut__16->GetZaxis()->SetTitleSize(0.035);
   logNPE_all_timecut__16->GetZaxis()->SetTitleFont(42);
   logNPE_all_timecut__16->Draw("same");
   
   TH1F *logNPE_nueCC_timecut__17 = new TH1F("logNPE_nueCC_timecut__17","",10,5,7.2);
   logNPE_nueCC_timecut__17->SetBinContent(1,1597);
   logNPE_nueCC_timecut__17->SetBinContent(2,3726);
   logNPE_nueCC_timecut__17->SetBinContent(3,6188);
   logNPE_nueCC_timecut__17->SetBinContent(4,7017);
   logNPE_nueCC_timecut__17->SetBinContent(5,6560);
   logNPE_nueCC_timecut__17->SetBinContent(6,5742);
   logNPE_nueCC_timecut__17->SetBinContent(7,4324);
   logNPE_nueCC_timecut__17->SetBinContent(8,2899);
   logNPE_nueCC_timecut__17->SetBinContent(9,1569);
   logNPE_nueCC_timecut__17->SetBinContent(10,743);
   logNPE_nueCC_timecut__17->SetBinContent(11,236);
   logNPE_nueCC_timecut__17->SetEntries(40601);
   logNPE_nueCC_timecut__17->SetStats(0);

   ci = TColor::GetColor("#ff0000");
   logNPE_nueCC_timecut__17->SetFillColor(ci);
   logNPE_nueCC_timecut__17->SetFillStyle(3002);

   ci = TColor::GetColor("#ff0000");
   logNPE_nueCC_timecut__17->SetLineColor(ci);
   logNPE_nueCC_timecut__17->SetLineWidth(5);
   logNPE_nueCC_timecut__17->GetXaxis()->SetTitle("log_{10}(NPE_{LPMT})");
   logNPE_nueCC_timecut__17->GetXaxis()->SetLabelFont(42);
   logNPE_nueCC_timecut__17->GetXaxis()->SetLabelSize(0.035);
   logNPE_nueCC_timecut__17->GetXaxis()->SetTitleSize(0.035);
   logNPE_nueCC_timecut__17->GetXaxis()->SetTitleFont(42);
   logNPE_nueCC_timecut__17->GetYaxis()->SetLabelFont(42);
   logNPE_nueCC_timecut__17->GetYaxis()->SetLabelSize(0.035);
   logNPE_nueCC_timecut__17->GetYaxis()->SetTitleSize(0.035);
   logNPE_nueCC_timecut__17->GetYaxis()->SetTitleOffset(0);
   logNPE_nueCC_timecut__17->GetYaxis()->SetTitleFont(42);
   logNPE_nueCC_timecut__17->GetZaxis()->SetLabelFont(42);
   logNPE_nueCC_timecut__17->GetZaxis()->SetLabelSize(0.035);
   logNPE_nueCC_timecut__17->GetZaxis()->SetTitleSize(0.035);
   logNPE_nueCC_timecut__17->GetZaxis()->SetTitleFont(42);
   logNPE_nueCC_timecut__17->Draw("same");
   
   TH1F *logNPE_bkg1__18 = new TH1F("logNPE_bkg1__18","",10,5,7.2);
   logNPE_bkg1__18->SetBinContent(1,13);
   logNPE_bkg1__18->SetBinContent(2,31);
   logNPE_bkg1__18->SetBinContent(3,1416);
   logNPE_bkg1__18->SetBinContent(4,2697);
   logNPE_bkg1__18->SetBinContent(5,1332);
   logNPE_bkg1__18->SetBinContent(6,892);
   logNPE_bkg1__18->SetBinContent(7,464);
   logNPE_bkg1__18->SetBinContent(8,301);
   logNPE_bkg1__18->SetBinContent(9,105);
   logNPE_bkg1__18->SetBinContent(10,25);
   logNPE_bkg1__18->SetBinContent(11,1);
   logNPE_bkg1__18->SetEntries(7277);
   logNPE_bkg1__18->SetStats(0);

   ci = TColor::GetColor("#006600");
   logNPE_bkg1__18->SetFillColor(ci);
   logNPE_bkg1__18->SetFillStyle(3002);

   ci = TColor::GetColor("#006600");
   logNPE_bkg1__18->SetLineColor(ci);
   logNPE_bkg1__18->SetLineWidth(5);
   logNPE_bkg1__18->GetXaxis()->SetTitle("log_{10}(NPE_{LPMT})");
   logNPE_bkg1__18->GetXaxis()->SetLabelFont(42);
   logNPE_bkg1__18->GetXaxis()->SetLabelSize(0.035);
   logNPE_bkg1__18->GetXaxis()->SetTitleSize(0.035);
   logNPE_bkg1__18->GetXaxis()->SetTitleFont(42);
   logNPE_bkg1__18->GetYaxis()->SetLabelFont(42);
   logNPE_bkg1__18->GetYaxis()->SetLabelSize(0.035);
   logNPE_bkg1__18->GetYaxis()->SetTitleSize(0.035);
   logNPE_bkg1__18->GetYaxis()->SetTitleOffset(0);
   logNPE_bkg1__18->GetYaxis()->SetTitleFont(42);
   logNPE_bkg1__18->GetZaxis()->SetLabelFont(42);
   logNPE_bkg1__18->GetZaxis()->SetLabelSize(0.035);
   logNPE_bkg1__18->GetZaxis()->SetTitleSize(0.035);
   logNPE_bkg1__18->GetZaxis()->SetTitleFont(42);
   logNPE_bkg1__18->Draw("same");
   
   TLegend *leg = new TLegend(0.68,0.6,0.9,0.9,NULL,"brNDC");
   leg->SetBorderSize(1);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("logNPE_nueCC","#nu_{e}^{CC}","l");

   ci = TColor::GetColor("#ffcc00");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(5);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("logNPE_nueCC_fidcut","#nu_{e}^{CC} fid.","l");

   ci = TColor::GetColor("#3399ff");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(5);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("logNPE_all_timecut","#All sel.","l");

   ci = TColor::GetColor("#333333");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(5);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("logNPE_nueCC_timecut","#nu_{e}^{CC} sel.","l");

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
