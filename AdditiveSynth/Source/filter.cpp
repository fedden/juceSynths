//
//  filter.cpp
//  additiveSynth
//
//  Created by Isabella Maund on 30/01/2017.
//
//

#include "filter.hpp"

double Filter::getFilter(double input, double cutOffFreq, double resonance){

    switch(state){
    
        case 0 :
        return filter.lores(input,cutOffFreq, resonance);
        break;
        case 1 :
        return filter.bandpass(input, cutOffFreq, resonance);
        break;
        case 2 :
        return filter.hires(input, cutOffFreq, resonance);
        break;
            
            
        
            
            
            
            
            
    }




}

void Filter::setFilter(int desiredFilter){
    
    state = desiredFilter;
    
    
    
    
}
