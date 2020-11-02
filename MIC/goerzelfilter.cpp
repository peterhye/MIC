
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
# define M_PI           3.14159265358979323846  /* pi */
#include "goerzelfilter.h"
#include <complex.h>
#include <complex>
#include <iostream>
#include "Goertzel2.h"
#define LEN(a) (sizeof(a)/sizeof(a[0]))
#include <fstream>
GoertzelFilter goertzelSetup(double normalizedfreq)
{
    double w = 2 * M_PI * normalizedfreq;
    double wr, wi;

    GoertzelFilter g;

    wr = cos(w);
    wi = sin(w);
    g.coeff = 2 * wr;
    g.cosine = wr;
    g.sine = wi;

    return g;
};

std::complex<double>  goertzelFilterC(double* samples, int nsamples, GoertzelFilter* g)
{
    double sprev = 0.0;
    double sprev2 = 0.0;
    double s, imag, real;
    int n;

    for (n = 0; n < nsamples; n++) {
        s = samples[n] + g->coeff * sprev - sprev2;
        sprev2 = sprev;
        sprev = s;
    }

    real = sprev * g->cosine - sprev2;
    imag = -sprev * g->sine;

    return sqrt(real * real + imag * imag);
};



double* filtering2(double samples2[], unsigned int simprate, int numberofsamples) {

  
    // This will hold our input and output data
    double data[1024] = { 0. };
    std::complex<double> filtered[1024] = { 0. };

    // This will hold the filter constants
    GoertzelFilter g = { 0. };
    double sr = simprate;
    int n;
    int nwindow = 16;
    // Goertzel block size = (sampeling rate/ antallet af sampels)
    double f = 4. / LEN(data);

    // Generate data with noise
    //fileout.open("generated data");
    //for (n = 0; n < LEN(data); n++) {
    //    data[n] = sin(n * (2. * M_PI) * f) + 0.5 * ((float)rand() / RAND_MAX - 0.5);
    //    fileout << "{" << n << "," << data[n] << "}," << endl;
    //}


    // Set up the filter constants, note that we choose a frequency
    g = goertzelSetup(f);

    // Filter the data using a sliding window
    for (n = 0; n < LEN(data) - nwindow; n++) {
        filtered[n + nwindow / 2] = goertzelFilterC(&data[n], nwindow, &g) /= nwindow;
    }

    // Print the real Valued Data (1st column) and complex valued Goertzel output
    for (n = 0; n < LEN(data); n++) {
        printf("%g %g %g\n", data[n], creal(filtered[n]), cimag(filtered[n]));
    }
 
    return &data[1024];

}


