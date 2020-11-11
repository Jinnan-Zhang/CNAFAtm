#!/usr/bin/env python
# -*- coding: utf-8 -*-
from lib.PreImport import *
from src.GetTimeResiual import GetSmearedVertex
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
def GetFiducialCutEff(NFile=1, StartFile=1):
    ROOT.ROOT.EnableImplicitMT()
    # evt = ROOT.TChain("evt")
    # prmtrkdep = ROOT.TChain("prmtrkdep")
    geninfo = ROOT.TChain("geninfo")

    # AddUserFile2TChain(evt, NFiles=NFile)
    AddUserFile2TChain(geninfo, NFiles=NFile)

    # evt.SetBranchStatus("*", 0)
    geninfo.SetBranchStatus("*", 0)
    geninfo.SetBranchStatus("InitPDGID", 1)

    muCC_total = 0
    eCC_total = 0
    NC_total = 0
    for entry in geninfo:
        # evt.GetEntry(entry)
        geninfo.GetEntry(entry)
        InitPDGID = np.asarray(geninfo.InitPDGID)[0]
        if (InitPDGID == 11) | (InitPDGID == -11):  #e CC
            eCC_total += 1
        elif (InitPDGID == 13) | (InitPDGID == -13):
            muCC_total += 1
        else:
            NC_total += 1
    print("muCC: ", muCC_total)
    print("eCC: ", eCC_total)
    print("NC: ", NC_total)


# show simple time residual profile
def ShowSimpletres(WhichEntry=0):
    ROOT.ROOT.EnableImplicitMT()
    evt = ROOT.TChain("evt")
    geninfo = ROOT.TChain("geninfo")
    pgst = ROOT.TChain("pgst")
    evt.Add("/mnt/f/user-detsim-2185.root")
    geninfo.Add("/mnt/f/user-detsim-2185.root")
    pgst.Add("/mnt/f/user-detsim-2185.root")

    geninfo.GetEntry(WhichEntry)
    InitX, InitY, InitZ = np.asarray(geninfo.InitX)[0] / 1e3, np.asarray(
        geninfo.InitY)[0] / 1e3, np.asarray(geninfo.InitZ)[0] / 1e3
    Smear_X, Smear_Y, Smear_Z = GetSmearedVertex(InitX, InitY, InitZ,
                                                 sigma_vertex)
    if (np.sqrt(Smear_X**2 + Smear_Y**2 + Smear_Z**2) < R_vertex_cut):
        evt.GetEntry(WhichEntry)
        nPE = np.asarray(evt.nPE)
        pmtID = np.asarray(evt.pmtID)
        SPMTs = np.where((pmtID >= sPMTID_low) & (pmtID <= sPMTID_up))[0]
        WPPMTs = np.where((pmtID >= WPPMTID_low) & (pmtID <= WPPMTID_up))[0]
        NPE_WPPMTs = np.sum(nPE[WPPMTs])
        LPMTs = np.where((pmtID >= LPMTID_low) & (pmtID <= LPMTID_up))[0]
        LPMTs_badTime = np.where(
            np.asarray(evt.hitTime)[LPMTs] > HitTimeCut_up)[0]
        if (NPE_WPPMTs < WP_NPE_cut):  #only WP cut
            Hit_x, Hit_y, Hit_z = np.asarray(
                evt.GlobalPosX)[SPMTs] / 1e3, np.asarray(
                    evt.GlobalPosY)[SPMTs] / 1e3, np.asarray(
                        evt.GlobalPosZ)[SPMTs] / 1e3
            R_Vi = np.sqrt((Smear_X - Hit_x)**2 + (Smear_Y - Hit_y)**2 +
                           (Smear_Z - Hit_z)**2)
            hitTime = np.asarray(evt.hitTime)[SPMTs]
            # smear hitTime
            Smear_t = np.random.normal(hitTime, sigma_hitTime)
            hit_pr_idx = np.where(Smear_t < HitTimeCut_up)[0]
            t_res_i = Smear_t - (R_Vi * LS_RI_idx / LightSpeed_c)
            # t_res_i = t_res_i[hit_pr_idx]
            t_res_i = t_res_i[t_res_i < HitTimeCut_up]
            sigma_tres = np.sqrt(np.mean(t_res_i**2))
            print(sigma_tres)
            print("pdg id:", (np.asarray(geninfo.InitPDGID)))

            import matplotlib.pyplot as plt
            fig, ax = plt.subplots()
            plt.hist(t_res_i, 100)
            # ax.set_yscale("log")
            plt.show()
