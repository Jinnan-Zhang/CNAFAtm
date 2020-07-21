/*
transtale flux to be appliable
author: Jinnan Zhang
*/
#include "Math/InterpolationTypes.h"
#include "Math/Interpolator.h"
void LoadFile(std::string filename, std::vector<std::vector<double>> &v, int Length = 2, int SkipLines = 0);
void GetFluxHist();

using namespace std;
int OutFlux()
{
    GetFluxHist();
    return 0;
}

void GetFluxHist()
{
    vector<vector<double>> Data_vec;
    LoadFile("JUNOFlux_Honda_HKKM2014.txt", Data_vec, 4, 2);
    // printf("size:%d\tValue:%f\n",Data_vec.size(),Data_vec[0][2]);
    const int N_data_pts = (int)Data_vec.size();
    double E_nu_pts[N_data_pts];
    double Nu_e_pts[N_data_pts];
    double NU_mu_pts[N_data_pts];
    for (int i = 0; i < N_data_pts; i++)
    {
        
    }
    // Interpolator linearInt(N_data_pts, Interpolation::kLINEAR);
    // linearInt.SetData(N_data_pts, E_pts, U235Spec);
}

//may load data inte vector from txt file
void LoadFile(std::string filename,
              std::vector<std::vector<double>> &v,
              int Length,
              int SkipLines)
{
    std::ifstream infile;
    infile.open(filename, std::ios::in);
    if (!infile)
    {
        printf("Fail to open file:%s.", filename.c_str());
    }
    double t1;
    int CountSkip = 0;
    while (!infile.eof())
    {
        if (CountSkip < SkipLines)
        {
            if (infile.get() == '\n')
                CountSkip++;
        }
        else
        {
            std::vector<double> t(Length);
            for (int i = 0; i < Length; i++)
            {
                infile >> t1;
                t[i] = t1;
            }
            v.push_back(t);
        }
    }
    infile.close();
}
