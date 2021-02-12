/** @file Presets.h
	@brief Contains a set of ready to go SoundEffect objects wrapped in preset classes.
*/
/**
 * This header contains a set of preset classes which are used in runtime to make new effects and append them to projects!
 */

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


