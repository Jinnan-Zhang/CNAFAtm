#!/bin/bash
rm -rf ../makematrix ./Data.o
g++ -I$ROOTSYS/include -fPIC -Wall -fpermissive -std=c++11 -c Data.C -o ./Data.o
g++ -Wall -I$ROOTSYS/include -L$ROOTSYS/lib main.cpp -std=c++11 -lCore -lHist -lRIO -lTree -lGpad Data.o -o ../makematrix
