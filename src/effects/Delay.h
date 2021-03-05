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
        Delay() : SoundEffectType() { tmpReadPtr = new int; *tmpReadPtr = 0;}

        float ApplyEffect(std::map<std::string, float>* parameters, float inputSample) override;
    
    private:
        int* tmpReadPtr;

};

