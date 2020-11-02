#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <math.h>
#include <vector>
#define M_PI           3.14159265358979323846  /* pi */
using namespace std;
using namespace sf;

class SpeechRecorder : public sf::SoundBufferRecorder
{
public:
    bool onStart() override;
    bool onProcessSamples(const Int16* samples, size_t sampleCount) override;
    float goertzel2(int numSamples, int TARGET_FREQUENCY, int SAMPLING_RATE, vector<float> &data);

};
