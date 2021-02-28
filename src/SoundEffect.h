/** @file SoundEffect.h
	@brief defines a sound effect and its properties.
*/
/**
 * This class defines the sound effect and its properties. However the SOUND ALGORITHM of the sound effect is not defined here. 
 * Sound Effect's algorithm works with Strategy design pattern;
 * SoundEffect has an object called effectType which is filled with an effect algorithm, such as Delay (on runtime).
 * The effectType object has a method (ApplyEffect) that applies the effect based on the effect's sound algorithm and passes it back to the outputData object of the SoundEffect class.
 * Then the outputData object of the SoundEffect will contain the applied effect results.
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
        
        SoundEffect();
        SoundEffect(std::string name) : SoundEffect() { SetName(name); }
        
        float ApplyEffect(float inputSample);
        float GetNextUnitSample() override;

        float GetDryWetValue() { return *drywetValue; }
        bool IsBypassed() { return *isBypassed; }
        
        bool SetDryWetValue(float newVal) { *drywetValue = newVal; return true; }
        bool SetIsBypassed(bool newIsBypassed) { *isBypassed = newIsBypassed; return true; }

        void SetName(std::string name) { SetSoundUnitName(name); SetSoundEffectType(name); }


    private:
        SoundEffectType* effectType;
        SoundEffectTypes* effectCollection;

        float* drywetValue;
        bool* isBypassed;

        void SetSoundEffectType(std::string typeName) { effectType = effectCollection->GetType(typeName); }

};