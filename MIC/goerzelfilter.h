#pragma once

#define M_PI           3.14159265358979323846  
#ifndef GOERTZELFILTER_H_
#define GOERTZELFILTER_H_
#include <complex.h>
#include <complex>
#include <array>
#include<cstdio>
typedef struct goertzelfilterstruct {
    double coeff;
    double sine;
    double cosine;
}

GoertzelFilter;

GoertzelFilter goertzelSetup(double normalizedfreq);

std::complex<double> goertzelFilterC(double* sample, int nsamples, GoertzelFilter* g);



 double* filtering2(double samples2[], unsigned int simprate, int numberofsamples);





#endif