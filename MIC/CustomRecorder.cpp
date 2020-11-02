#include "CustomRecorder.h"
#include "Mic.h"


bool SpeechRecorder::onStart()
{
    // Initialize whatever has to be done before the capture starts
    setProcessingInterval(sf::milliseconds(20));

    // Return true to start playing
    return true;
}


bool SpeechRecorder::onProcessSamples(const Int16* samples, size_t sampleCount)
{
    // Do something with the new chunk of samples (store them, send them, ...)



    vector<float> samp;
    for (int i = 0; i <= sampleCount; i++)
    {
        samp.push_back(samples[i]);
    }


    //int maxSample = 4500;
    //for (int i(0); i < sampleCount; i++)
    //{
    //    if (abs(samples[i]) > maxSample)
    //        maxSample = abs(samples[i]);
    //        
    //        
    //  


  /*  }*/
    //float d = (int)samples;
    int a = goertzel2(samp.size(), 697, 48000, samp);
    int b = goertzel2(samp.size(), 770, 48000, samp);
    int c = goertzel2(samp.size(), 852, 48000, samp);
    int d = goertzel2(samp.size(), 941, 48000, samp);

    if (std::max({ a,b,c,d }) == a) {
        std::cout << "697" << std::endl;
    };

    if (std::max({ a,b,c,d }) == b) {
        std::cout << "770" << std::endl;
    }

    if (std::max({ a,b,c,d }) == c) {
        std::cout << "852" << std::endl;
    }

    if (std::max({ a,b,c,d }) == d) {
        std::cout << "941" << std::endl;
    }


    

    samp.clear();
   
   

 /*   std::cout << "Max sample: " << maxSample << std::endl;*/


    // Return true to continue playing
    return true;
}


float SpeechRecorder::goertzel2(int numSamples, int TARGET_FREQUENCY, int SAMPLING_RATE, vector<float> &data)
{
    int     k, i;
    float   floatnumSamples;
    float   omega, sine, cosine, coeff, q0, q1, q2, result, real, imag;
    float   scalingFactor = numSamples / 2.0;
    floatnumSamples = (float)numSamples;
    k = (int)(0.5 + ((floatnumSamples * TARGET_FREQUENCY) / SAMPLING_RATE));
    omega = (2.0 * M_PI * k) / floatnumSamples;
    sine = sin(omega);
    cosine = cos(omega);
    coeff = 2.0 * cosine;
    q0 = 0;
    q1 = 0;
    q2 = 0;

    for (i = 0; i <= numSamples-1 ; i++)
    {
        q0 = coeff * q1 - q2 + data[i];
        q2 = q1;
        q1 = q0;
    }
    real = (q1 - q2 * cosine) / scalingFactor;
    imag = (q2 * sine) / scalingFactor;
    result = sqrtf(real * real + imag * imag);
    //std::cout << result << std::endl;
    return result;
};