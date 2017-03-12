//
//  Oscillator.hpp
//  additiveSynth
//
//  Created by Isabella Maund on 26/01/2017.
//
//

#ifndef Oscillator_hpp
#define Oscillator_hpp
#include "maximilian.h"


class Oscillator {
    
public:
    Oscillator()
    {
        state = 0;
    }
    
    void setOscillator(int waveForm);
    double getSample(double frequency);
    
private:
    int state;
    maxiOsc osc;
};




#endif /* Oscillator_hpp */
