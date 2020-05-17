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
    evt.ls()
def ViewPDGID(NFiles):
    ROOT.ROOT.EnableImplicitMT()


if __name__ == "__main__":
    pass
