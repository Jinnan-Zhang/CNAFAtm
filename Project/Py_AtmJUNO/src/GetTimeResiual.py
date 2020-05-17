#!/usr/bin/env python
# -*- coding: utf-8 -*-
from lib.PreImport import *
import sys
import os
sys.path.append("..")


def ViewGlobalPos(NFiles, WhichEntry=0, SaveFileName="GlobalPos"):
    ROOT.ROOT.EnableImplicitMT()
    evt = ROOT.TChain("evt")
    AddUserFile2TChain(evt, NFiles=NFiles)
    c = ROOT.TCanvas("myCanvasName", "The Canvas Title", 800, 600)
    evt.Draw(
        "sqrt(GlobalPosX*GlobalPosX+GlobalPosY*GlobalPosY+GlobalPosZ*GlobalPosZ)/1000>>+h_GPos",
        "pmtID>150e3",
        "", 1, WhichEntry)
   # h_GPos = ROOT.gDirectory.Get("h_GPos")
   # h_GPos.SetXTitle("m")
    ROOT.gStyle.SetOptStat("ne")
    c.SaveAs("./pics/"+SaveFileName + ".png")


def ViewPDGID(NFiles, WhichEntry=0, SaveFileName="PDGID"):
    ROOT.ROOT.EnableImplicitMT()
    # geninfo=ROOT.TChain("geninfo")
    # AddUserFile2TChain(geninfo, NFiles)
    # geninfo.SetBranchStatus("*", 0)
    # geninfo.SetBranchStatus("InitPDGID",1)
    # geninfo.GetEntry(WhichEntry)
    # InitPDGID=np.asarray(geninfo.InitPDGID)
    # print("geninfo:\t",InitPDGID)
    prmtrkdep = ROOT.TChain("prmtrkdep")
    AddUserFile2TChain(prmtrkdep, NFiles=NFiles)
    prmtrkdep.SetBranchStatus("*", 0)
    prmtrkdep.SetBranchStatus("PDGID", 1)
    # prmtrkdep.GetEntry(WhichEntry)
    # PDGID=np.asarray(prmtrkdep.PDGID)
    # print("prmtrkdep:\t",PDGID)
    c = ROOT.TCanvas("myCanvasName", "The Canvas Title", 800, 600)
    prmtrkdep.Draw("PDGID>>+h_PDGID")
    # h_PDGID=(ROOT.TH1F)ROOT.gDirectory.Get("h_PDGID")
    ROOT.gStyle.SetOptStat("ne")
    c.SaveAs("./pics/"+SaveFileName + ".png")


def ViewWaterPoolPEs(NFiles, WhichEntry=0, SaveFileName="WPnpe"):
    SimEvent = ROOT.TChain("/Event/Sim/SimEvent")
    AddDetsimFile2TChain(SimEvent, NFiles=NFiles)
    # c = ROOT.TCanvas("myCanvasName", "The Canvas Title", 800, 600)
    # SimEvent.Draw("SimEvent.m_wp_hits.npe>>+h_wp_npe")
    # ROOT.gStyle.SetOptStat("ne")
    # c.SaveAs("./pics/"+SaveFileName + ".png")
    SimEvent.GetEntry(WhichEntry)
    npe=np.asarray(SimEvent.SimEvent.m_wp_hits.npe)
    print(npe)

if __name__ == "__main__":
    pass
