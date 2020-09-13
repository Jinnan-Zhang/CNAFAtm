#!/usr/bin/env python
# -*- coding: utf-8 -*-
import numpy as np
import matplotlib.pyplot as plt
from ROOT import TH1D, TFile, TGraph


def ViewXsec(filename="guowl/spectrum.dat", skiprows=6):
    data = np.loadtxt(fname=filename, skiprows=skiprows)
    x = data[:, 0]
    muCC = data[:, 1]
    muCCbar = data[:, 2]  #mu+mubar
    eCC = data[:, 3]
    eCCbar = data[:, 4]
    x_low = 0
    x_up = 20
    ff_outXsec = TFile.Open("./CCXsecFlux.root", "recreate")
    h_muCC = TH1D("muCCXsec", "Cross Section of (#nu_{#mu}) charged current",
                  muCC.size, x_low, x_up)
    h_muCCbar = TH1D("muCCXsecbar",
                     "Cross Section of (#bar{#nu_{#mu}}) charged current",
                     muCC.size, x_low, x_up)
    h_eCC = TH1D("eCCXsec", "Cross Section of (#nu_{e}) charged current",
                 eCC.size, x_low, x_up)
    h_eCCbar = TH1D("eCCXsecbar",
                    "Cross Section of (#bar{#nu_{e}}) charged current",
                    eCC.size, x_low, x_up)
    for i in range(muCC.size):
        h_eCC.SetBinContent(i + 1, eCC[i])
        h_muCC.SetBinContent(i + 1, muCC[i])
        h_eCCbar.SetBinContent(i + 1, eCCbar[i])
        h_muCCbar.SetBinContent(i + 1, muCCbar[i])
    h_eCC.SetXTitle("Neutrino Energy[GeV]")
    h_eCC.SetYTitle("#sigma_{tot} [10^{-38}cm^{2}GeV^{-1}]")
    h_muCC.SetXTitle("Neutrino Energy[GeV]")
    h_muCC.SetYTitle("#sigma_{tot} [10^{-38}cm^{2}GeV^{-1}]")
    h_eCCbar.SetXTitle("Neutrino Energy[GeV]")
    h_eCCbar.SetYTitle("#sigma_{tot} [10^{-38}cm^{2}GeV^{-1}]")
    h_muCCbar.SetXTitle("Neutrino Energy[GeV]")
    h_muCCbar.SetYTitle("#sigma_{tot} [10^{-38}cm^{2}GeV^{-1}]")
    # h_eCC.Draw("hist")
    # h_muCC.Draw("hist")
    h_eCC.Write()
    h_muCC.Write()
    h_eCCbar.Write()
    h_muCCbar.Write()

    data_flux = np.loadtxt("../Flux/JUNOFlux_Honda_HKKM2014.txt", skiprows=2)
    Ev = np.array(data_flux[:, 0])
    muCCflux = np.array(data_flux[:, 1])
    muCCbarflux = np.array(data_flux[:, 2])
    eCCflux = np.array(data_flux[:, 3])
    eCCbarflux = np.array(data_flux[:, 4])
    g_muCCflux = TGraph(Ev.size, Ev, muCCflux)
    g_muCCbarflux = TGraph(Ev.size, Ev, muCCbarflux)
    g_eCCflux = TGraph(Ev.size, Ev, eCCflux)
    g_eCCbarflux = TGraph(Ev.size, Ev, eCCbarflux)
    g_eCCbarflux.Draw()
    g_muCCflux.Write("muCCflux")
    g_muCCbarflux.Write("muCCbarfluc")
    g_eCCflux.Write("eCCflux")
    g_eCCbarflux.Write("eCCbarFlux")
    
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
