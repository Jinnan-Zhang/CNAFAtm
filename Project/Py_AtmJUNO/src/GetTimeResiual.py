#!/usr/bin/env python
# -*- coding: utf-8 -*-
from lib.PreImport import *
import sys
import os
sys.path.append("..")

def ViewHitTime(NFiles, WhichEntry=0, SaveFileName="hitTime"):
    evt = ROOT.TChain("evt")
    AddUserFile2TChain(evt,NFiles)
    c = ROOT.TCanvas("myCanvasName", "The Canvas Title", 800, 600)
    evt.Draw("hitTime>>h_hit","pmtID>300000","",1,WhichEntry)
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

#Same particles for geninfo and prmtrkdep
def ViewPDGID(NFiles, WhichEntry=0, SaveFileName="PDGID"):
    ROOT.ROOT.EnableImplicitMT()
    geninfo=ROOT.TChain("geninfo")
    AddUserFile2TChain(geninfo, NFiles)
    geninfo.SetBranchStatus("*", 0)
    geninfo.SetBranchStatus("InitPDGID",1)
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
        print("gen:",np.asarray(geninfo.InitPDGID))
        print("prm:",np.asarray(prmtrkdep.PDGID))
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
    evt.SetBranchStatus("*",0)
    evt.SetBranchStatus("pmtID",1)
    c = ROOT.TCanvas("myCanvasName", "The Canvas Title", 800, 600)
    evt.Draw("pmtID>>+h_pmtID","pmtID>30000 && pmtID<50000")
    ROOT.gStyle.SetOptStat("ne")
    c.SaveAs("./pics/"+SaveFileName + ".png")
    
#basicly relective index
def ViewOptPar(NFiles):
    opticalparam=ROOT.TChain("opticalparam")
    print(opticalparam.AsMatirx(columns=["LS_RI_idx"]))

#get smeared value for vertex position, default: sima_v=1m
def GetSmearedVertex(InitialX,InitialY,InitialZ,SmearSigma=1):
    SmearR = np.random.normal(np.zeros(InitialX.shape[0]),SmearSigma)
    SmearCosTheta = np.random.rand(InitialX.shape[0]) * 2. - 1
    SmearSinTheta = np.sqrt(1. - SmearCosTheta**2)
    SmearPhi = np.random.rand(InitialX.shape[0]) * np.pi * 2.
    dx, dy, dz = SmearR * SmearSinTheta * np.cos(
        SmearPhi), SmearR * SmearSinTheta * np.sin(
            SmearPhi), SmearR * SmearCosTheta
    X_new, Y_new, Z_new = InitialX + dx, InitialY + dy, InitialZ + dz
    return X_new,Y_new,Z_new

#get smeared value both hitTime,default: sigma_hittime=4ns
def GetSmearedHittime(InitialhitTime,SmearSigma):
    hitTime_new=np.random.normal(InitialhitTime,SmearSigma)
    return hitTime_new

#Get Distance from vertex to pmt
def GetDistanceR_Vi(V_x,V_y,V_z,Hit_x,Hit_y,Hit_z):
    R_Vi=np.sqrt((V_x-Hit_x)**2+(V_y-Hit_y)**2+(V_z-Hit_z)**2)
    return R_Vi

def SmearVertexAndGetDistance(InitialX,InitialY,InitialZ,Hit_x,Hit_y,Hit_z,SmearSigma=1):
    V_x,V_y,V_z=GetSmearedVertex(InitialX,InitialY,InitialZ,SmearSigma)
    R_Vi=np.sqrt((V_x-Hit_x)**2+(V_y-Hit_y)**2+(V_z-Hit_z)**2)
    return R_Vi

def ViewTimeProfile(NFiles,SaveFileName="TimeProfile"):
    ROOT.ROOT.EnableImplicitMT()
    h_muCC=ROOT.TH1D("muCC","muon Charge Current",NumofBins,TimeP_low,TimeP_up)
    h_eCC=ROOT.TH1D("eCC","electron Charge Current",NumofBins,TimeP_low,TimeP_up)
    h_NC=ROOT.TH1D("NC","Neutral Current",NumofBins,TimeP_low,TimeP_up)
    h_muCC_list=[h_muCC]
    h_eCC_list=[h_eCC]
    h_NC_list=[h_NC]
    for i in range(len(LPMT_NPE_steps)):
        h_muCC.append()
    evt = ROOT.TChain("evt")
    geninfo = ROOT.TChain("geninfo")
    AddUserFile2TChain(evt,NFiles=NFiles)
    AddUserFile2TChain(geninfo,NFiles=NFiles)
    evt.SetBranchStatus("*", 0)
    geninfo.SetBranchStatus("*", 0)
    geninfo.SetBranchStatus("InitX", 1)
    geninfo.SetBranchStatus("InitY", 1)
    geninfo.SetBranchStatus("InitZ", 1)
    geninfo.SetBranchStatus("InitPDGID",1)
    evt.SetBranchStatus("hitTime", 1)
    evt.SetBranchStatus("pmtID", 1)
    for entry in range(evt.GetEntries()):
        geninfo.GetEntry(entry)
        InitX,InitY,InitZ=np.asarray(geninfo.InitX)/1e3,np.asarray(geninfo.InitY)/1e3,np.asarray(geninfo.InitZ)/1e3
        if (np.sqrt(InitZ[0]**2+InitY[0]**2+InitZ[0]**2)<R_vertex_cut):
            evt.GetEntry(entry)
            pmtID=np.asarray(evt.pmtID)
            SPMTs=np.where((pmtID>=sPMTID_low)&(pmtID<=sPMTID_up))
            WPPMTs=np.where((pmtID>=WPPMTID_low)&(pmtID<=WPPMTID_up))
            LPMTs=np.where((pmtID>=LPMTID_low)&(pmtID<=LPMTID_up))
            if WPPMTs.shape[0]<WP_NPE_cut :
                hitTime=np.asarray(evt.hitTime)
                

                InitX,InitY,InitZ=np.asarray(geninfo.InitX)/1e3,np.asarray(geninfo.InitY)/1e3,np.asarray(geninfo.InitZ)/1e3
                Hit_x,Hit_y,Hit_z=np.asarray(evt.GlobalPosX)/1e3,np.asarray(evt.GlobalPosY)/1e3,np.asarray(evt.GlobalPosZ)/1e3
                R_Vi=SmearVertexAndGetDistance(InitX[0],InitY[0],InitZ[0],Hit_x[SPMTs],Hit_y[SPMTs],Hit_z[SPMTs],1.)
                InitPDGID=geninfo.InitPDGID
    


if __name__ == "__main__":
    pass
