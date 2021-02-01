#pragma once

#include <typeinfo>

#include "effects/Delay.h"


class SoundEffectComposite // TODO: change the name
{
    private:

        Delay* delayInstance;
    
    public:

        SoundEffect* soundEffect;

        SoundEffectComposite()
        { 
            soundEffect = (SoundEffect*) malloc (sizeof(SoundEffect));

            delayInstance = (Delay*) malloc (sizeof(Delay));

        }

        void SetEffect(SoundEffect effect)
        {
            if (effect.GetId()== 1 ) { // delay
                soundEffect = delayInstance;
                soundEffect->BulkSetParameters(effect.GetParameters());
            }

        }
};