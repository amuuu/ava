#pragma once

#include "BasePreset.h"

class DelayEffect : public BaseEffectPreset
{
    public:
        DelayEffect() : BaseEffectPreset("Delay")
        {
            effect.SetParameter("amount", 1.0); 
        }
};


