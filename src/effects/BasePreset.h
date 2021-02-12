#pragma once

#include "../SoundEffect.h"


class BaseEffectPreset
{
    public:
        SoundEffect effect;
        
        BaseEffectPreset(std::string name)
        {
            effect.SetName(name);
        }

        SoundEffect GetEffect() { return effect; }
};