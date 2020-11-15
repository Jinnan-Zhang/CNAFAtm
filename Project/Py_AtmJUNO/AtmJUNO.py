#!/usr/bin/env python
# -*- coding: utf-8 -*-

from lib.PreImport import *
from src.GetTimeResiual import *
from src.DataDetail import *
import sys
import os
o_path = os.getcwd()
sys.path.append(o_path)

if __name__ == "__main__":
    # print(SGD)
    # ViewGlobalPos(NFiles=int(sys.argv[1]),WhichEntry=int(sys.argv[2]))
    # ViewHitTime(NFiles=int(sys.argv[1]),WhichEntry=int(sys.argv[2]))
    # ViewPDGID(NFiles=int(sys.argv[1]),WhichEntry=int(sys.argv[2]))
    # ViewWaterPoolPEs(NFiles=int(sys.argv[1]), WhichEntry=int(sys.argv[2]))
    # ViewPMTID(NFiles=int(sys.argv[1]), WhichEntry=int(sys.argv[2]))
    if (sys.argv[1] == "TPro"):
        if (len(sys.argv) == 4):
            ViewTimeProfile(NFiles=int(sys.argv[1 + 1]),
                            StartFile=int(sys.argv[2 + 1]),
                            SaveFileName=sys.argv[3 + 1])
        else:
            ViewTimeProfile(NFiles=int(sys.argv[1]),
                            StartFile=int(sys.argv[2]))
    elif (sys.argv[1] == "NcapT"):  # view nCatureTime
        ViewnCaptureT(int(sys.argv[2]))
    elif (sys.argv[1] == "NPETE"):  # all information
        GetNPE_Tres_Energy_Profile(NFiles=int(sys.argv[2]),
                                   StartFile=int(sys.argv[3]),
                                   SaveFileName="result_NPETE")
    elif (sys.argv[1] == "E_v"):  #view if neutrino energy right
        ViewNetrinoEnergy(int(sys.argv[2]))
    elif (sys.argv[1] == "NPE"):
        ViewNPE_LPMT(int(sys.argv[2]))
    elif (sys.argv[1] == "FVCut"):
        GetFiducialCutEff(int(sys.argv[2]),int(sys.argv[3]))
    elif (sys.argv[1] == "SimTres"):
        ShowSimpletres(int(sys.argv[2]))