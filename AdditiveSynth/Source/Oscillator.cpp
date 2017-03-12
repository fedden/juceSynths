//
//  Oscillator.cpp
//  additiveSynth
//
//  Created by Isabella Maund on 26/01/2017.
//
//

#include "Oscillator.hpp"



void Oscillator::setOscillator(int waveForm){
    
    state = waveForm;
  
}


double Oscillator::getSample(double frequency = 0){
    
    switch(state){
        case 0:
            return osc.sinewave(frequency);
            break;
        case 1:
            return osc.square(frequency);
            break;
        case 2:
            return osc.sawn(frequency);
            break;
        case 3:
            return osc.triangle(frequency);
            break;
        case 4:
            return osc.noise();
            break;
            
    
    }
    
    }
