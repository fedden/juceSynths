//
//  filter.hpp
//  additiveSynth
//
//  Created by Isabella Maund on 30/01/2017.
//
//

#ifndef filter_hpp
#define filter_hpp
#include "maximilian.h"


class Filter {
    
public:
    Filter()
    {
        state = 0;
        
    
    }
    void setFilter(int desiredFilter);
    double getFilter(double input, double cutOffFreq, double resonance);


private:
    
    int state;
    maxiFilter filter;
};




#endif /* filter_hpp */
