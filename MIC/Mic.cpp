#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>
#include "goerzelfilter.h"
#include <string.h>
#include <sstream>
#include <string>
#include "CustomRecorder.h"


//
//float goertzel(int numSamples, int TARGET_FREQUENCY, int SAMPLING_RATE, float* data)
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
//    for (i = 0; i < numSamples; i++)
//    {
//        q0 = coeff * q1 - q2 + data[i];
//        q2 = q1;
//        q1 = q0;
//    }
//    real = (q1 - q2 * cosine)/scalingFactor;
//    imag = (q2 * sine)/scalingFactor;
//    result = sqrtf(real * real + imag * imag);
//    std::cout << result << std::endl;
//    return result;
//}

int main() {
    std::stringstream oss;
    sf::RenderWindow window(sf::VideoMode(800, 600), "recording Sounds", sf::Style::Default);
    window.setFramerateLimit(60);
    
    sf::Font font;

    if (!font.loadFromFile("arial.ttf")) {

    }


    sf::RectangleShape rectangle;
    rectangle.setFillColor(sf::Color::Green);
    rectangle.setSize(sf::Vector2f(100.f, 50.f));
    rectangle.setPosition(window.getSize().x / 2.f, window.getSize().y / 2.f);
    
    sf::Text SampleCountText;
    SampleCountText.setCharacterSize(24);
    SampleCountText.setFont(font);
    SampleCountText.setFillColor(sf::Color::Blue);
    SampleCountText.setString("123");
    SampleCountText.setPosition(300.f,550.f);

    sf::Text SampleCountTextS;
    SampleCountTextS.setCharacterSize(24);
    SampleCountTextS.setFont(font);
    SampleCountTextS.setFillColor(sf::Color::Blue);
    SampleCountTextS.setString("Sample Count:");
    SampleCountTextS.setPosition(10.f, 550.f);

 



    sf::Text SampleFreq;
    SampleFreq.setCharacterSize(24);
    SampleFreq.setFont(font);
    SampleFreq.setFillColor(sf::Color::Blue);
    SampleFreq.setString("123");
    SampleFreq.setPosition(370.f, 450.f);

    sf::Text SampleFreqS;
    SampleFreqS.setCharacterSize(24);
    SampleFreqS.setFont(font);
    SampleFreqS.setFillColor(sf::Color::Blue);
    SampleFreqS.setString("Sample freq (HZ):");
    SampleFreqS.setPosition(10.f, 450.f);

    sf::Text L1;
    L1.setCharacterSize(24);
    L1.setFont(font);
    L1.setFillColor(sf::Color::Blue);
    L1.setString("697 HZ:");
    L1.setPosition(10.f, 50.f);

    sf::Text L12;
    L12.setCharacterSize(24);
    L12.setFont(font);
    L12.setFillColor(sf::Color::Blue);
    L12.setString("770 HZ:");
    L12.setPosition(300.f, 50.f);

    sf::Text L2;
    L2.setCharacterSize(24);
    L2.setFont(font);
    L2.setFillColor(sf::Color::Blue);
    L2.setString("770 HZ:");
    L2.setPosition(10.f, 100.f);

    sf::Text L22;
    L22.setCharacterSize(24);
    L22.setFont(font);
    L22.setFillColor(sf::Color::Blue);
    L22.setString("941 HZ:");
    L22.setPosition(300.f, 100.f);

    sf::Text L3;
    L3.setCharacterSize(24);
    L3.setFont(font);
    L3.setFillColor(sf::Color::Blue);
    L3.setString("852 HZ:");
    L3.setPosition(10.f, 150.f);

    sf::Text L33;
    L33.setCharacterSize(24);
    L33.setFont(font);
    L33.setFillColor(sf::Color::Blue);
    L33.setString("Sample freq (HZ):");
    L33.setPosition(300.f, 150.f);

    sf::Text L4;
    L4.setCharacterSize(24);
    L4.setFont(font);
    L4.setFillColor(sf::Color::Blue);
    L4.setString("941 HZ:");
    L4.setPosition(10.f, 200.f);

    sf::Text L42;
    L42.setCharacterSize(24);
    L42.setFont(font);
    L42.setFillColor(sf::Color::Blue);
    L42.setString("Sample freq (HZ):");
    L42.setPosition(300.f, 200.f);


    sf::Text H1;
    H1.setCharacterSize(24);
    H1.setFont(font);
    H1.setFillColor(sf::Color::Blue);
    H1.setString("1209 HZ:");
    H1.setPosition(10.f, 250.f);

    sf::Text H12;
    H12.setCharacterSize(24);
    H12.setFont(font);
    H12.setFillColor(sf::Color::Blue);
    H12.setString("1336 HZ:");
    H12.setPosition(300.f, 250.f);

    sf::Text H2;
    H2.setCharacterSize(24);
    H2.setFont(font);
    H2.setFillColor(sf::Color::Blue);
    H2.setString("1336 HZ::");
    H2.setPosition(10.f, 300.f);

    sf::Text H22;
    H22.setCharacterSize(24);
    H22.setFont(font);
    H22.setFillColor(sf::Color::Blue);
    H22.setString("Sample freq (HZ):");
    H22.setPosition(300.f, 300.f);

    sf::Text H3;
    H3.setCharacterSize(24);
    H3.setFont(font);
    H3.setFillColor(sf::Color::Blue);
    H3.setString("1447 HZ:");
    H3.setPosition(10.f, 350.f);

    sf::Text H32;
    H32.setCharacterSize(24);
    H32.setFont(font);
    H32.setFillColor(sf::Color::Blue);
    H32.setString("Sample freq (HZ):");
    H32.setPosition(300.f, 350.f);

    sf::Text H4;
    H4.setCharacterSize(24);
    H4.setFont(font);
    H4.setFillColor(sf::Color::Blue);
    H4.setString("1663 HZ:");
    H4.setPosition(10.f, 400.f);

    sf::Text H42;
    H42.setCharacterSize(24);
    H42.setFont(font);
    H42.setFillColor(sf::Color::Blue);
    H42.setString("Sample freq (HZ):");
    H42.setPosition(300.f, 400.f);




    if (!sf::SoundRecorder::isAvailable()) {
        std::cout << "you need to install a mic " << std::endl;
    }

   // sf::SoundBufferRecorder recorder;
    SpeechRecorder recorder;
    sf::SoundBuffer buffer;
    sf::Sound sound;
    while (window.isOpen())
    {
        window.clear();
        window.draw(SampleCountText);
        window.draw(SampleCountTextS);
        window.draw(SampleFreqS);
        window.draw(SampleFreq);
        window.draw(L1);
        window.draw(L2);
        window.draw(L3);
        window.draw(L4);
        window.draw(H1);
        window.draw(H2);
        window.draw(H3);
        window.draw(H4);
        window.draw(L12);
        window.draw(L22);
        window.draw(L33);
        window.draw(L42);
        window.draw(H12);
        window.draw(H22);
        window.draw(H32);
        window.draw(H42);
        
       
       // window.draw(rectangle);

        window.display();

        sf::Event Event;
        while (window.pollEvent(Event))
        {
            window.clear();
            window.draw(rectangle);

            switch (Event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                if (Event.key.code == sf::Keyboard::A)
                    recorder.start();

                
                else if (Event.key.code == sf::Keyboard::B)
                {
                    recorder.stop();
                    buffer = recorder.getBuffer();


                   // std::ostringstream oss;
                    //oss << buffer.getSampleCount();
                    //SampleCountText.setString(oss.str());
                    //UINT oss2 = buffer.getSampleRate();
                    //std::string oss3 = std::to_string(oss2);
                    //SampleFreq.setString(oss3);
                    //float d = (int)buffer.getSamples();
                    //float k = goertzel2(buffer.getSampleCount()-2, 5000, buffer.getSampleRate(), &d);
                    //std::string power2 = std::to_string(k);
                    //power.setString(power2);
                    //sound.setBuffer(buffer);

                    sound.play();

                }
                    

                
            }
        }
    }
}


