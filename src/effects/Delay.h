/** @file Delay.h
	@brief Basic delay effect
*/
/*
*   
*/

#pragma once

#include "../SoundEffectType.h"

class Delay : public SoundEffectType
{
    public:
        Delay() : SoundEffectType() { writePosition = new int; readPosition = new int; *writePosition = 0; *readPosition = 0; SetDelay(); }

        float ApplyEffect(std::map<std::string, float>* parameters, float inputSample) override;
    
        void SetDelay();
    
    private:
        
        int bufferLength;
        double* buffer;
        
        double delayLength;
        
        int* writePosition;
        int* readPosition;
};

