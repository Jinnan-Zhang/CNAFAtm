#!/usr/bin/env python
# -*- coding: utf-8 -*-
from lib.PreImport import *
from GetTimeResiual import GetSmearedVertex
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
    evt.SetBranchStatus("pmtID", 1)
    c = ROOT.TCanvas("myCanvasName", "", 800, 600)
    evt.Draw("nPE>>+h_NPE", "pmtID<20000")
    ROOT.gStyle.SetOptStat("ne")
    c.SaveAs("./pics/" + SaveFileName + ".png")


def ViewFakeData():
    ROOT.ROOT.EnableImplicitMT()


# get the efficiency of fiducial cut: WP and r<16m effciency of FC and PC events
def GetFiducialCutEff():
    evt = ROOT.TChain("evt")
    prmtrkdep = ROOT.TChain("prmtrkdep")
    geninfo = ROOT.TChain("geninfo")

    evt.Add(
        "/junofs/users/zhangjn/CNAF_Atm/Project/Py_AtmJUNO/user-detsim-2185.root"
    )
    prmtrkdep.Add(
        "/junofs/users/zhangjn/CNAF_Atm/Project/Py_AtmJUNO/user-detsim-2185.root"
    )
    geninfo.Add(
        "/junofs/users/zhangjn/CNAF_Atm/Project/Py_AtmJUNO/user-detsim-2185.root"
    )
    total_selected = 0
    FC_selected = 0
    PC_selected = 0
    for entry in evt:
        evt.GetEntry(entry)
        pmtID = np.asarray(evt.pmtID)
        nPE = np.asarray(evt.nPE)
        WPPMTs = np.where((pmtID >= WPPMTID_low) & (pmtID <= WPPMTID_up))[0]
        NPE_WPPMTs = np.sum(nPE[WPPMTs])

        geninfo.GetEntry(entry)
        InitX, InitY, InitZ = np.asarray(geninfo.InitX)[0] / 1e3, np.asarray(
            geninfo.InitY)[0] / 1e3, np.asarray(geninfo.InitZ)[0] / 1e3
