#!/usr/bin/env python
# -*- coding: utf-8 -*-
import numpy as np
import matplotlib.pyplot as plt
from ROOT import TH1D, TFile, TGraph


def ViewXsec(filename="guowl/spectrum.dat", skiprows=6):
    data = np.loadtxt(fname=filename, skiprows=skiprows)
    x = data[:, 0]
    muCC = data[:, 1] + data[:, 2]  #mu+mubar
    eCC = data[:, 3] + data[:, 4]
    x_low = 0
    x_up = 20
    ff_outXsec = TFile.Open("./guowl/CCXsec.root", "recreate")
    h_muCC = TH1D(
        "muCCXsec",
        "Cross Section of (#nu_{#mu}+#bar{#nu_{#mu}}) charged current",
        muCC.size, x_low, x_up)
    h_eCC = TH1D("eCCXsec",
                 "Cross Section of (#nu_{e}+#bar{#nu_{e}}) charged current",
                 eCC.size, x_low, x_up)
    for i in range(muCC.size):
        h_eCC.SetBinContent(i + 1, eCC[i])
        h_muCC.SetBinContent(i + 1, muCC[i])
    h_eCC.SetXTitle("Neutrino Energy[GeV]")
    h_eCC.SetYTitle("#sigma_{tot} [10^{-38}cm^{2}GeV^{-1}]")
    h_muCC.SetXTitle("Neutrino Energy[GeV]")
    h_muCC.SetYTitle("#sigma_{tot} [10^{-38}cm^{2}GeV^{-1}]")
    h_eCC.Draw("hist")
    h_muCC.Draw("hist")
    h_eCC.Write()
    h_muCC.Write()
    ff_outXsec.Close()

    fig, ax = plt.subplots()
    plt.plot(x, muCC * x**2)
    ax.set_yscale("log")
    plt.xlim(0, 20)
    plt.show()


if __name__ == "__main__":
    with plt.style.context("../../lib/Style/Paper.mplstyle"):
        # ViewXsec()
        ViewXsec(filename="guowl/CC.dat", skiprows=1)
        # ViewXsec(filename="../Flux/JUNOFlux_Honda_HKKM2014.txt", skiprows=2)
