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
        
        void SetOutputBufferData(OutputData *newOutputData);
    
    private:
        void SetDelayAmount();
        int* amount; // to be changed

        int* tmpReadPtr;
};