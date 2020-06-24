#!/usr/bin/env python
# -*- coding: utf-8 -*-
import ROOT
try:
    import numpy as np
except:
    print("Failed to import numpy.")
    exit()
# detector simulation path
SGD = "/storage/gpfs_data/juno/junofs/production/public/users/sgiulio/J18v1r1-Pre1/Atmospheric/0-20GeV/detsim/user-detsim-"
SGD1 = "/storage/gpfs_data/juno/junofs/production/public/users/sgiulio/J18v1r1-Pre1/Atmospheric/0-20GeV/detsim/detsim-"
StartFile = 1


def AddUserFile2TChain(tree, NFiles=2, StartFile=1):
    for nn in range(StartFile, StartFile+NFiles):
        tree.Add(SGD + str(nn) + ".root")


def AddDetsimFile2TChain(tree, NFiles=1):
    for nn in range(StartFile, StartFile+NFiles):
        tree.Add(SGD1+str(nn)+".root")


# pmt id range for different pmts
LPMTID_low = 0
LPMTID_up = 20000
sPMTID_low = 300000
sPMTID_up = 500000
WPPMTID_low = 30000
WPPMTID_up = 50000
# merters per nano-sec
LightSpeed_c = 0.299792458
# liquid reflexive index, use average
# LS_RI_idx=1.55
LS_RI_idx = 1.5
# 16 m vertex position cut
R_vertex_cut = 16.
# water pool NPE cut
# WP_NPE_cut = 60
WP_NPE_cut = 50 # Giulio newest cuts
# Large PMT NPE cut
LPMT_NPE_cut = 1e5
LPMT_NPE_cut_up = 10**7.2
# Large PMT slection steps, Get all in one try
LPMT_NPE_steps = [1e5, 4.73e5, 1.01e6, 2.32e6,10**7.2]

sigma_vertex = 1.  # 1m
sigma_hitTime = 4  # 4ns
# HitTimeCut_up = 1500  # 1500 ns
HitTimeCut_up = 1200  # 1200 ns (1.2 mus) according to Giulio

# 1 ns binwidth
BinWidth = 1
TimeP_low = 20
TimeP_up = 520
# number of bins
NumofBins = (TimeP_up-TimeP_low)/BinWidth

PDG_ID = {11: 'electron',
          12: 'nu_e',
          -11: 'positron',
          -12: 'nu_e_bar',
          13: 'muon',
          -13: 'anti_muon'}

# class SimPMTHit(ROOT.TObject):
#     def __init__(self):
#         self.pmtid = -1
#         self.npe = -1
#         self.hittime = -1.
#         self.timewindow = 0.
#         self.trackid = -1
#     def getPMTID(self):
#         return self.pmtid
#     def getNPE(self):
#         return self.npe
#     def getHitTime(self):
#         return self.hittime
#     def getTimeWindow(self):
#         return self.timewindow
#     def getTrackID(self):
#         return self.trackid
#     def setPMTID(self,val):
#         self.pmtid=val
#     def setNPE(self,val):
#         self.npe=val
#     def setHitTime(self,val):
#         self.hittime = val
#     def setTimeWindow(self,val):
#         self.timewindow=val
#     def setTrackID(self,val):
#         self.trackid=val
