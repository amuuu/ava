/** @file Delay.h
	@brief Basic delay effect
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