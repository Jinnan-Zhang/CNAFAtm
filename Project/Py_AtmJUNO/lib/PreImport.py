#!/usr/bin/env python
# -*- coding: utf-8 -*-
import ROOT
try:
    import numpy as np
except:
    print("Failed to import numpy.")
    exit()
#detector simulation path 
SGD="/storage/gpfs_data/juno/junofs/production/public/users/sgiulio/J18v1r1-Pre1/Atmospheric/0-20GeV/detsim/user-detsim-"

def AddFile2TChain(tree, NFiles=1):
    for nn in range(1,1+NFiles):
        tree.Add(SGD + str(nn) + ".root")