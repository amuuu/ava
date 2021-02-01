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
        SoundEffect() : VirtualInstrument() { isEffect = true; }

        float GetDryWetValue() { return *drywetValue; }
        bool IsBypassed() { return *isBypassed; }
        
        bool SetDryWetValue(float newVal) { *drywetValue = newVal; return true; }
        bool SetIsBypassed(bool newIsBypassed) { *isBypassed = newIsBypassed; return true; }

        virtual OutputData* ApplyEffect() { printf("ssssssss"); return 0; };
        OutputData* UpdateOutputBuffer() { return ApplyEffect(); }

        int GetId() { return *id; }
        void SetId(int givenId) { *id = givenId; }


    private:
        float* drywetValue;
        bool* isBypassed;
        int* id;

};