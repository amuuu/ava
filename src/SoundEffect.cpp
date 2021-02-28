#include "SoundEffect.h"

SoundEffect::SoundEffect() : VirtualInstrument() 
{
    effectType = (SoundEffectType*) malloc(sizeof(SoundEffectType));
    effectCollection = new SoundEffectTypes();
}

float SoundEffect::ApplyEffect(float inputSample)
{
    return effectType->ApplyEffect(parameters, inputSample);
}

float SoundEffect::GetNextUnitSample()
{ 
    // ApplyEffect();
    return 0.0; 
}
