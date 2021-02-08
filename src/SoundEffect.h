/** @file SoundEffect.h
	@brief Base class for sound effect units
*/
/*
*   
*/

#pragma once

#include "VirtualInstrument.h"
#include "SoundEffectType.h"
#include "SoundEffectCollection.h"

#include <map>
#include <string>

class SoundEffect : public VirtualInstrument
{
    public:
        SoundEffect() : VirtualInstrument() {}

        
        OutputData* ApplyEffect() { printf("hereaaaaaaaaaaaaa\n"); return effectType->ApplyEffect(*GetParameters()); };
        OutputData* UpdateOutputBuffer() { return ApplyEffect(); }
        

        float GetDryWetValue() { return *drywetValue; }
        bool IsBypassed() { return *isBypassed; }
        
        bool SetDryWetValue(float newVal) { *drywetValue = newVal; return true; }
        bool SetIsBypassed(bool newIsBypassed) { *isBypassed = newIsBypassed; return true; }

        void SetSoundEffectType(std::string typeName) { effectType = effectCollection.effectsMap[typeName]; printf(effectType->GetEffectName().c_str());}

        
    private:
        SoundEffectType* effectType;
        SoundEffectCollection effectCollection;
        
        float* drywetValue;
        bool* isBypassed;

};