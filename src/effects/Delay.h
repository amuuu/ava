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
        Delay();
        float ApplyEffect(std::map<std::string, float>* parameters, float inputSample) override;
    
        void SetDelay();
    
    private:
        void UpdateParams(std::map<std::string, float>* parameters);
        
        int bufferLength;
        double* buffer;
        
        double delayLength;
        double amount;
        double feedback;
        
        int* writePosition;
        int* readPosition;
};

