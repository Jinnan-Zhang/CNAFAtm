#!/usr/bin/env python
# -*- coding: utf-8 -*-
from lib.PreImport import *
import sys
import os
sys.path.append("..")


#if neutrino energy in pgst
# https://arxiv.org/pdf/1510.05494.pdf told me it's true
# neutrino energy in GeV
def ViewNetrinoEnergy(NFiles, WhichEntry=0, SaveFileName="NeutrinoEnergy"):
    ROOT.ROOT.EnableImplicitMT()
    pgst = ROOT.TChain("pgst")
    AddUserFile2TChain(pgst, NFiles=NFiles)
    geninfo = ROOT.TChain("geninfo")
    AddUserFile2TChain(geninfo, NFiles)
    # .SetBranchStatus("*", 0)


def ViewNPE_LPMT(NFiles, WhichEntry=0, SaveFileName="NPE_LPMT"):
    ROOT.ROOT.EnableImplicitMT()
    evt = ROOT.TChain("evt")
    AddUserFile2TChain(evt, NFiles=NFiles)
    evt.SetBranchStatus("*", 0)
    evt.SetBranchStatus("nPE", 1)
    evt.SetBranchStatus("pmtID",1)
    c = ROOT.TCanvas("myCanvasName", "", 800, 600)
    evt.Draw("nPE>>+h_NPE", "pmtID<20000")
    ROOT.gStyle.SetOptStat("ne")
    c.SaveAs("./pics/" + SaveFileName + ".png")

def ViewFakeData():
    ROOT.ROOT.EnableImplicitMT()
    