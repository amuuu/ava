/** @file SoundEffect.h
	@brief Base class for sound effect units
*/
/*
*   
*/

#pragma once

#include "VirtualInstrument.h"
#include "SoundEffectType.h"
#include "SoundEffectTypes.h"

#include <map>
#include <string>

class SoundEffect : public VirtualInstrument
{
    public:
        SoundEffect(std::string name) : SoundEffect() { SetName(name); SetParameter("amount", 1.0); printf("PA %f", (*parameters)["amount"]); }
        
        void ApplyEffect() { outputData = effectType->ApplyEffect(*parameters); printf("AAAAAAAAAAAAAAA\n"); };
        OutputData* UpdateOutputBuffer() { ApplyEffect(); return outputData; }
        

        float GetDryWetValue() { return *drywetValue; }
        bool IsBypassed() { return *isBypassed; }
        
        bool SetDryWetValue(float newVal) { *drywetValue = newVal; return true; }
        bool SetIsBypassed(bool newIsBypassed) { *isBypassed = newIsBypassed; return true; }


    private:
        SoundEffectType* effectType;
        SoundEffectTypes effectCollection;

        // Delay delay;
        
        float* drywetValue;
        bool* isBypassed;

        void SetSoundEffectType(std::string typeName) { printf("TYPE NAME: %s\n", typeName.c_str()); effectType = effectCollection.effectsMap[typeName];  printf("BNAME %d\n", effectType->m); }
        void SetName(std::string name) {SetSoundUnitName(name); SetSoundEffectType(name); }
        SoundEffect() : VirtualInstrument() { effectType = (SoundEffectType*) malloc(sizeof(SoundEffectType)); }

};