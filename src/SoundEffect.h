/** @file SoundEffect.h
	@brief Base class for sound effect units
*/
/*
*   
*/

#pragma once

#include "VirtualInstrument.h"

#include <map>
#include <string>

class SoundEffect : public VirtualInstrument
{
    public:
        SoundEffect();

        float GetDryWetValue() { return *drywetValue; }
        bool IsBypassed() { return *isBypassed; }
        
        bool SetDryWetValue(float newVal) { *drywetValue = newVal; return true; }
        bool SetIsBypassed(bool newIsBypassed) { *isBypassed = newIsBypassed; }

        virtual bool ApplyEffect();


    private:
        float* drywetValue;
        bool* isBypassed;

}