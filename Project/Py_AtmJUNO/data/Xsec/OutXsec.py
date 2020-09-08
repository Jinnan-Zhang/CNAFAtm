#!/usr/bin/env python
# -*- coding: utf-8 -*-
import numpy as np
import matplotlib.pyplot as plt


def ViewXsec(filename="guowl/spectrum.dat", skiprows=6):
    data = np.loadtxt(fname=filename, skiprows=skiprows)
    x = data[:, 0]
    muCC = data[:, 1]
    plt.plot(x, muCC)
    plt.show()


if __name__ == "__main__":
    with plt.style.context("../../lib/Style/Paper.mplstyle"):
        ViewXsec()