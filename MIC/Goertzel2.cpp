//#pragma once
//#include "Goertzel2.h"
//#include <string>
//#include<iostream>
//
//
//
//
//float Goertzel2::goertzel2(int numSamples, int TARGET_FREQUENCY, int SAMPLING_RATE, float* data)
//{
//    int     k, i;
//    float   floatnumSamples;
//    float   omega, sine, cosine, coeff, q0, q1, q2, result, real, imag;
//    float   scalingFactor = numSamples / 2.0;
//    floatnumSamples = (float)numSamples;
//    k = (int)(0.5 + ((floatnumSamples * TARGET_FREQUENCY) / SAMPLING_RATE));
//    omega = (2.0 * M_PI * k) / floatnumSamples;
//    sine = sin(omega);
//    cosine = cos(omega);
//    coeff = 2.0 * cosine;
//    q0 = 0;
//    q1 = 0;
//    q2 = 0;
//
//    for (i = 0; i <= numSamples-100; i++)
//    {
//        q0 = coeff * q1 - q2 + data[i];
//        q2 = q1;
//        q1 = q0;
//    }
//    real = (q1 - q2 * cosine) / scalingFactor;
//    imag = (q2 * sine) / scalingFactor;
//    result = sqrtf(real * real + imag * imag);
//    std::cout << result << std::endl;
//    return result;
//}