#!/usr/bin/env python
# -*- coding: utf-8 -*-
from lib.PreImport import *
import sys
import os
sys.path.append("..")


def ViewHitTime(NFiles, WhichEntry=0, SaveFileName="hitTime"):
    evt = ROOT.TChain("evt")
    AddUserFile2TChain(evt, NFiles)
    c = ROOT.TCanvas("myCanvasName", "The Canvas Title", 800, 600)
    evt.Draw("hitTime>>+h_hit", "pmtID>300000", "")  # ,1,WhichEntry)
    ROOT.gStyle.SetOptStat("ne")
    c.SaveAs("./pics/"+SaveFileName + ".png")


def ViewGlobalPos(NFiles, WhichEntry=0, SaveFileName="GlobalPos"):
    ROOT.ROOT.EnableImplicitMT()
    evt = ROOT.TChain("evt")
    AddUserFile2TChain(evt, NFiles=NFiles)
    c = ROOT.TCanvas("myCanvasName", "The Canvas Title", 800, 600)
    evt.Draw(
        "sqrt(GlobalPosX*GlobalPosX+GlobalPosY*GlobalPosY+GlobalPosZ*GlobalPosZ)/1000>>+h_GPos",
        "pmtID>300000",
        "", 1, WhichEntry)
    h_GPos = ROOT.gDirectory.Get("h_GPos")
    h_GPos.SetXTitle("m")
    ROOT.gStyle.SetOptStat("ne")
    c.SaveAs("./pics/"+SaveFileName + ".png")

# Same particles for geninfo and prmtrkdep


def ViewPDGID(NFiles, WhichEntry=0, SaveFileName="PDGID"):
    ROOT.ROOT.EnableImplicitMT()
    geninfo = ROOT.TChain("geninfo")
    AddUserFile2TChain(geninfo, NFiles)
    geninfo.SetBranchStatus("*", 0)
    geninfo.SetBranchStatus("InitPDGID", 1)
    # geninfo.GetEntry(WhichEntry)
    # InitPDGID=np.asarray(geninfo.InitPDGID)
    # print("geninfo:\t",InitPDGID)
    prmtrkdep = ROOT.TChain("prmtrkdep")
    AddUserFile2TChain(prmtrkdep, NFiles=NFiles)
    prmtrkdep.SetBranchStatus("*", 0)
    prmtrkdep.SetBranchStatus("PDGID", 1)
    for entry in range(prmtrkdep.GetEntries()):
        geninfo.GetEntry(entry)
        prmtrkdep.GetEntry(entry)
        print("gen:", np.asarray(geninfo.InitPDGID))
        print("prm:", np.asarray(prmtrkdep.PDGID))
    # prmtrkdep.GetEntry(WhichEntry)
    # PDGID=np.asarray(prmtrkdep.PDGID)
    # print("prmtrkdep:\t",PDGID)
    # c = ROOT.TCanvas("myCanvasName", "The Canvas Title", 800, 600)
    # prmtrkdep.Draw("PDGID>>+h_PDGID")
    # # h_PDGID=(ROOT.TH1F)ROOT.gDirectory.Get("h_PDGID")
    # ROOT.gStyle.SetOptStat("ne")
    # c.SaveAs("./pics/"+SaveFileName + ".png")


def ViewWaterPoolPEs(NFiles, WhichEntry=0, SaveFileName="WPnpe"):
    SimEvent = ROOT.TChain("/Event/Sim/SimEvent")
    AddDetsimFile2TChain(SimEvent, NFiles=NFiles)
    c = ROOT.TCanvas("myCanvasName", "The Canvas Title", 800, 600)
    SimEvent.Draw("SimEvent.m_wp_hits>>+h_wp_npe")
    ROOT.gStyle.SetOptStat("ne")
    c.SaveAs("./pics/"+SaveFileName + ".png")
    # SimEvent.GetEntry(WhichEntry)
    # npe=np.asarray(SimEvent.SimEvent.m_wp_hits.npe)
    # print(npe)


def ViewPMTID(NFiles, WhichEntry=0, SaveFileName="PMTid"):
    ROOT.ROOT.EnableImplicitMT()
    evt = ROOT.TChain("evt")
    AddUserFile2TChain(evt, NFiles=NFiles)
    evt.SetBranchStatus("*", 0)
    evt.SetBranchStatus("pmtID", 1)
    c = ROOT.TCanvas("myCanvasName", "The Canvas Title", 800, 600)
    evt.Draw("pmtID>>+h_pmtID", "pmtID>30000 && pmtID<50000")
    ROOT.gStyle.SetOptStat("ne")
    c.SaveAs("./pics/"+SaveFileName + ".png")

# basicly relective index


def ViewOptPar(NFiles):
    opticalparam = ROOT.TChain("opticalparam")
    print(opticalparam.AsMatirx(columns=["LS_RI_idx"]))

# get smeared value for vertex position, default: sima_v=1m


def GetSmearedVertex(InitialX, InitialY, InitialZ, SmearSigma=1):
    SmearR = np.random.normal(0, SmearSigma)
    SmearCosTheta = np.random.rand(1) * 2. - 1
    SmearSinTheta = np.sqrt(1. - SmearCosTheta**2)
    SmearPhi = np.random.rand(1) * np.pi * 2.
    dx, dy, dz = SmearR * SmearSinTheta * np.cos(
        SmearPhi), SmearR * SmearSinTheta * np.sin(
            SmearPhi), SmearR * SmearCosTheta
    X_new, Y_new, Z_new = InitialX + dx, InitialY + dy, InitialZ + dz
    return X_new, Y_new, Z_new

# get smeared value both hitTime,default: sigma_hittime=4ns


def GetSmearedHittime(InitialhitTime, SmearSigma=4):
    hitTime_new = np.random.normal(InitialhitTime, SmearSigma)
    return hitTime_new

# Get Distance from vertex to pmt


def GetDistanceR_Vi(V_x, V_y, V_z, Hit_x, Hit_y, Hit_z):
    R_Vi = np.sqrt((V_x-Hit_x)**2+(V_y-Hit_y)**2+(V_z-Hit_z)**2)
    return R_Vi


def SmearVertexAndGetDistance(InitialX, InitialY, InitialZ, Hit_x, Hit_y, Hit_z, SmearSigma=1):
    V_x, V_y, V_z = GetSmearedVertex(InitialX, InitialY, InitialZ, SmearSigma)
    R_Vi = np.sqrt((V_x-Hit_x)**2+(V_y-Hit_y)**2+(V_z-Hit_z)**2)
    return R_Vi


def ViewTimeProfile(NFiles, StartFile=1, SaveFileName="TimeProfile"):
    ROOT.ROOT.EnableImplicitMT()
    h_muCC = ROOT.TH1D("muCC0", "muon Charge Current",
                       NumofBins, TimeP_low, TimeP_up)
    h_eCC = ROOT.TH1D("eCC0", "electron Charge Current",
                      NumofBins, TimeP_low, TimeP_up)
    h_NC = ROOT.TH1D("NC0", "Neutral Current", NumofBins, TimeP_low, TimeP_up)
    h_muCC_list = [h_muCC]
    h_eCC_list = [h_eCC]
    h_NC_list = [h_NC]
    for i in range(len(LPMT_NPE_steps)-1):
        h_muCC_t = h_muCC.Clone("muCC"+str(i+1))
        h_muCC_list.append(h_muCC_t)
        h_eCC_t = h_eCC.Clone("eCC"+str(i+1))
        h_eCC_list.append(h_eCC_t)
        h_NC_t = h_NC.Clone("NC"+str(i+1))
        h_NC_list.append(h_NC_t)

    evt = ROOT.TChain("evt")
    geninfo = ROOT.TChain("geninfo")
    AddUserFile2TChain(evt, NFiles=NFiles, StartFile=StartFile)
    AddUserFile2TChain(geninfo, NFiles=NFiles, StartFile=StartFile)
    evt.SetBranchStatus("*", 0)
    geninfo.SetBranchStatus("*", 0)
    geninfo.SetBranchStatus("InitX", 1)
    geninfo.SetBranchStatus("InitY", 1)
    geninfo.SetBranchStatus("InitZ", 1)
    geninfo.SetBranchStatus("InitPDGID", 1)
    evt.SetBranchStatus("hitTime", 1)
    evt.SetBranchStatus("pmtID", 1)
    evt.SetBranchStatus("GlobalPosX", 1)
    evt.SetBranchStatus("GlobalPosY", 1)
    evt.SetBranchStatus("GlobalPosZ", 1)
    for entry in range(evt.GetEntries()):
        geninfo.GetEntry(entry)
        # one vertex, use first one
        InitX, InitY, InitZ = np.asarray(geninfo.InitX)[
            0]/1e3, np.asarray(geninfo.InitY)[0]/1e3, np.asarray(geninfo.InitZ)[0]/1e3
        Smear_X, Smear_Y, Smear_Z = GetSmearedVertex(
            InitX, InitY, InitZ, sigma_vertex)
        # print(np.sqrt(Smear_Z**2+Smear_Y**2+Smear_X**2))
        if (np.sqrt(Smear_X**2+Smear_Y**2+Smear_Z**2) < R_vertex_cut):
            evt.GetEntry(entry)
            pmtID = np.asarray(evt.pmtID)
            # index for different kind of pmts
            SPMTs = np.where((pmtID >= sPMTID_low) & (pmtID <= sPMTID_up))[0]
            WPPMTs = np.where((pmtID >= WPPMTID_low) &
                              (pmtID <= WPPMTID_up))[0]
            LPMTs = np.where((pmtID >= LPMTID_low) & (pmtID <= LPMTID_up))[0]
            if (WPPMTs.shape[0] < WP_NPE_cut) & (LPMTs.shape[0] > LPMT_NPE_cut) & (LPMTs.shape[0] < LPMT_NPE_cut_up):
                # hit position only for sPMT
                Hit_x, Hit_y, Hit_z = np.asarray(evt.GlobalPosX)[SPMTs]/1e3, np.asarray(
                    evt.GlobalPosY)[SPMTs]/1e3, np.asarray(evt.GlobalPosZ)[SPMTs]/1e3
                R_Vi = np.sqrt((Smear_X-Hit_x)**2+(Smear_Y-Hit_y)
                               ** 2+(Smear_Z-Hit_z)**2)

                hitTime = np.asarray(evt.hitTime)[SPMTs]
                # smear hitTime
                Smear_t = np.random.normal(hitTime, sigma_hitTime)
                # prompt time cut less than 3 times of meadian value
                # this cut is not valid, even though better
                # hit_pr_idx=np.where(Smear_t<np.median(hitTime)*10)[0]
                hit_pr_idx = np.where(Smear_t < HitTimeCut_up)[
                    0]  # <np.median(hitTime)*10)[0]
                t_res_i = Smear_t[hit_pr_idx] - \
                    (R_Vi[hit_pr_idx]*LS_RI_idx/LightSpeed_c)
                # t_res_i=Smear_t-(R_Vi*LS_RI_idx/LightSpeed_c)
                # print(t_res_i)
                # print(R_Vi)

                # takes RMS not standar devation?
                RMS_t_res = np.sqrt(np.mean(t_res_i**2))

                # lepton at first place
                InitPDGID = np.asarray(geninfo.InitPDGID)[0]

                # for value, find 0 means under the LPMT cut,
                # which will not happen, find 1 means first stage, thus need -1
                # to the histgram list
                At_Which_NPE_LPMT = np.searchsorted(
                    LPMT_NPE_steps, LPMTs.shape[0])-1
                # e-CC
                if (InitPDGID == 11) | (InitPDGID == -11):
                    h_eCC_list[At_Which_NPE_LPMT].Fill(RMS_t_res)
                # mu-CC
                elif (InitPDGID == 13) | (InitPDGID == -13):
                    h_muCC_list[At_Which_NPE_LPMT].Fill(RMS_t_res)
                else:
                    h_NC_list[At_Which_NPE_LPMT].Fill(RMS_t_res)
    ff_TimeP = ROOT.TFile("./results/"+SaveFileName +
                          str(StartFile)+".root", "RECREATE")
    ff_TimeP.cd()
    for i in range(len(LPMT_NPE_steps)):
        h_muCC_list[i].Write()
        h_eCC_list[i].Write()
        h_NC_list[i].Write()
        h_muCC_list[i].SetXTitle("#sigma(t_{res}) [ns]")
        h_muCC_list[i].SetYTitle("entries")
        h_eCC_list[i].SetXTitle("#sigma(t_{res}) [ns]")
        h_eCC_list[i].SetYTitle("entries")
        h_NC_list[i].SetXTitle("#sigma(t_{res}) [ns]")
        h_NC_list[i].SetYTitle("entries")
    ff_TimeP.Close()


if __name__ == "__main__":
    pass
