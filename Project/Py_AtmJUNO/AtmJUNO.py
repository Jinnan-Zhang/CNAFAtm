#!/usr/bin/env python
# -*- coding: utf-8 -*-
from src.GetTimeResiual import *
from lib.PreImport import *
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

    if (len(sys.argv) == 4):
        ViewTimeProfile(NFiles=int(sys.argv[1]),
                        StartFile=int(sys.argv[2]),
                        SaveFileName=sys.argv[3])
    else:
        ViewTimeProfile(NFiles=int(sys.argv[1]), StartFile=int(sys.argv[2]))
