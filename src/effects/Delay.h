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
        Delay() : SoundEffectType() { tmpReadPtr = 0; }

        OutputData* ApplyEffect(std::map<std::string, float> parameters);
    
    private:
        int* tmpReadPtr;

};