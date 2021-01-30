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
        SoundEffect() : VirtualInstrument() { }

        float GetDryWetValue() { return *drywetValue; }
        bool IsBypassed() { return *isBypassed; }
        
        bool SetDryWetValue(float newVal) { *drywetValue = newVal; return true; }
        bool SetIsBypassed(bool newIsBypassed) { *isBypassed = newIsBypassed; return true; }

        virtual OutputData* ApplyEffect() { return 0; };
        OutputData* UpdateOutputBuffer() { return ApplyEffect(); }

        
        bool SetParameter(std::string parameterName, float parameterValue); // not a clean solution. should be changed
        

    private:
        float* drywetValue;
        bool* isBypassed;

};