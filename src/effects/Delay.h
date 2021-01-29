/** @file SoundEffect.h
	@brief Base class for sound effect units
*/
/*
*   
*/

#pragma once

#include "../SoundEffect.h"

class Delay : public SoundEffect
{
    public:
        Delay();
        OutputData* ApplyEffect();
    
    private:
        void SetDelayAmount();
        int* amount; // to be changed

        int* tmpReadPtr;
};