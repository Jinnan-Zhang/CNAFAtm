
#include "TObject.h"
#include <vector>
#include <iostream>
namespace JM
{
    class SimPMTHit : public TObject
    {
    private:
        int pmtid;
        int npe;
        double hittime;
        double timewindow;
        int trackid; // ref to Track ID. but if hits are merged, unknown.
    public:
        SimPMTHit()
        {
            pmtid = -1;
            npe = -1;
            hittime = -1;
            timewindow = 0;
            trackid = -1;
        }

        virtual ~SimPMTHit() {}

    public:
        int getPMTID() { return pmtid; }
        int getNPE() { return npe; }
        double getHitTime() { return hittime; }
        double getTimeWindow() { return timewindow; }
        int getTrackID() { return trackid; }

        void setPMTID(int val) { pmtid = val; }
        void setNPE(int val) { npe = val; }
        void setHitTime(double val) { hittime = val; }
        void setTimeWindow(double val) { timewindow = val; }
        void setTrackID(int val) { trackid = val; }

        ClassDef(SimPMTHit, 6)
    };
} // namespace JM
ClassImp(JM::SimPMTHit);

#define SGD1 "/storage/gpfs_data/juno/junofs/production/public/users/sgiulio/J18v1r1-Pre1/Atmospheric/0-20GeV/detsim/detsim-"
#include <TFile.h>
#include <TChain.h>

void AddDetsimFile2TChain(TChain &tree, int NFiles = 1, int startFile = 1)
{
    for (int i = startFile; i < startFile + NFiles; i++)
    {
        tree.Add(Form("%s%d.root", SGD1, i));
    }
}
int Wphits()
{
    TChain SimEvent("Event/Sim/SimEvent");
    AddDetsimFile2TChain(SimEvent);

    std::vector<SimPMTHit *> m_wp_hits = {0};
    TBranch *brWp = 0;
    SimEvent.SetBranchAddress("SimEvent.m_wp_hits", &m_wp_hits, &brWp);
    SimEvent.SetCacheSize(10000000);
    SimEvent.AddBranchToCache("SimEvent.m_wp_hits");
    brWp->GetEntry(1);
    printf("wpPe:%d\n", m_wp_hits[0]->getNPE());

    return 0;
}
