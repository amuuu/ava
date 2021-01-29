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
        bool SetIsBypassed(bool newIsBypassed) { *isBypassed = newIsBypassed; return true; }

        virtual OutputData* ApplyEffect();

        OutputData* UpdateOutputBuffer() { return ApplyEffect(); }

    private:
        float* drywetValue;
        bool* isBypassed;

    protected:
        OutputData* processed;
        OutputData* preProcessed;

};