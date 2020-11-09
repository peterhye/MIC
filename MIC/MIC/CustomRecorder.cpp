#include "CustomRecorder.h"
#include "Mic.h"



bool SpeechRecorder::onStart()
{
    // Initialize whatever has to be done before the capture starts
    setProcessingInterval(sf::milliseconds(15));
    

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
     a = goertzel2(samp.size(), 697, 44100, samp);
     b = goertzel2(samp.size(), 770, 44100, samp);
     c = goertzel2(samp.size(), 852, 44100, samp);
     d = goertzel2(samp.size(), 941, 44100, samp);
     e = goertzel2(samp.size(), 1209, 44100, samp);
     f = goertzel2(samp.size(), 1336, 44100, samp);
     g = goertzel2(samp.size(), 1447, 44100, samp);
     h = goertzel2(samp.size(), 1633, 44100, samp);
    //std::cout << "a: "<< a << std::endl;
    //std::cout << "b: " << b << std::endl;
    //std::cout << "c: "<< c << std::endl;
    //std::cout << "d: " << d << std::endl;

    int avg = (a + b + c + d + e + f + g + h) / 8;
    int sc = 20;
    Previousnumber = CurrentNumber;
    if (std::max({ a,b,c,d }) == a&& a>avg+(avg/sc)) {
        
        


        if (std::max({ e,f,g,h }) == e && e > avg + (avg / sc)) {
            std::cout << "1" << std::endl;
            CurrentNumber = '1';
        }
        if (std::max({ e,f,g,h }) == f && f > avg + (avg / sc)) {
            std::cout << "2" << std::endl;
            CurrentNumber = '2';
        }
        if (std::max({ e,f,g,h }) == g && g > avg + (avg / sc)) {
            std::cout << "3" << std::endl;
            CurrentNumber = '3';
        }
        if (std::max({ e,f,g,h }) == h && h > avg + (avg / sc)) {
            std::cout << "A" << std::endl;
            CurrentNumber = 'A';

        }
        
    };

    if (std::max({ a,b,c,d }) == b && b > avg + (avg / sc)) {
       // Previousnumber = CurrentNumber;

        if (std::max({ e,f,g,h }) == e && e > avg + (avg / sc)) {
            std::cout << "4" << std::endl;
            CurrentNumber = '4';
        }
        if (std::max({ e,f,g,h }) == f && f > avg + (avg / sc)) {
            std::cout << "5" << std::endl;
            CurrentNumber = '5';
        }
        if (std::max({ e,f,g,h }) == g && g > avg + (avg / sc)) {
            std::cout << "6" << std::endl;
            CurrentNumber = '6';
        }
        if (std::max({ e,f,g,h }) == h && h > avg + (avg / sc)) {
            std::cout << "B" << std::endl;
            CurrentNumber = 'B';
        }

    }

    if (std::max({ a,b,c,d }) == c && c > avg + (avg / sc)) {
       // Previousnumber = CurrentNumber;
        if (std::max({ e,f,g,h }) == e && e > avg + (avg / sc)) {
            std::cout << "7" << std::endl;
            CurrentNumber = '7';
        }
        if (std::max({ e,f,g,h }) == f && f > avg + (avg / sc)) {
            std::cout << "8" << std::endl;
            CurrentNumber = '8';
        }
        if (std::max({ e,f,g,h }) == g && g > avg + (avg / sc)) {
            std::cout << "9" << std::endl;
            CurrentNumber = '9';
        }
        if (std::max({ e,f,g,h }) == h && h > avg + (avg / sc)) {
            std::cout << "C" << std::endl;
            CurrentNumber = 'C';
        }

      
    }

    if (std::max({ a,b,c,d }) == d && d > avg + (avg / sc)) {
        //Previousnumber = CurrentNumber;
        if (std::max({ e,f,g,h }) == e && e > avg + (avg / sc)) {
            std::cout << "*" << std::endl;
            CurrentNumber = '*';
        }
        if (std::max({ e,f,g,h }) == f && f > avg + (avg / sc)) {
            std::cout << "0" << std::endl;
            CurrentNumber = '0';
        }
        if (std::max({ e,f,g,h }) == g && g > avg + (avg / sc)) {
            std::cout << "#" << std::endl;
            CurrentNumber = '#';
        }
        if (std::max({ e,f,g,h }) == h && h > avg + (avg / sc)) {
            std::cout << "D" << std::endl;
            CurrentNumber = 'D';
        }
      
    }


    if (CurrentNumber != Previousnumber && Previousnumber == '*') {
        RecievedNumbersString.push_back(CurrentNumber);
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
    float   scalingFactor = (numSamples-1) / 2;
   
    floatnumSamples = (float)numSamples-1;
    std::string number = std::to_string(floatnumSamples);
   // std::cout << number << std::endl;
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

string SpeechRecorder::currentnumber() {

    
    return string(1,CurrentNumber);
}

void SpeechRecorder::resetter() {
    CurrentNumber = 'x';
    Previousnumber = 'y';
    RecievedNumbersString = "x";


}

string SpeechRecorder::powerArray() {
    string a1,b1,c1,d1,e1,f1,g1,h1;

    a1 = std::to_string(a);
    b1 = std::to_string(b);
    c1 = std::to_string(c);
    d1 = std::to_string(d);
    e1 = std::to_string(e);
    f1 = std::to_string(f);
    g1 = std::to_string(g);
    h1 = std::to_string(h);
    return ("a: " + a1 + " b: " +b1 + " c: " + c1 + " d: "+d1 + " e: " +e1 + " f: " +f1 + " g: " +g1 + " h: " +h1 );
        


}