#!/bin/bash
rm -rf ../effplots ./Data.o
g++ -I$ROOTSYS/include -fPIC -Wall -c Data.C -o ./Data.o
g++ -Wall -I$ROOTSYS/include -L$ROOTSYS/lib main.cpp -lCore -lHist -lCint -lRIO -lTree -lGpad Data.o -o ../effplots
