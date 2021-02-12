#include "SoundEffect.h"

SoundEffect::SoundEffect() : VirtualInstrument() 
{
    effectType = (SoundEffectType*) malloc(sizeof(SoundEffectType));
    effectCollection = new SoundEffectTypes();
}

void SoundEffect::ApplyEffect()
{
    *outputData = *(effectType->ApplyEffect(parameters));
}

OutputData* SoundEffect::UpdateOutputBuffer()
{ 
    ApplyEffect();
    return outputData; 
}
