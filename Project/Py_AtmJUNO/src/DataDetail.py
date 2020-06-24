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
    