#pragma once

#include "effects/Delay.h"
#include <map>


class SoundEffectTypes
{
    public:
        Delay delayObject;
        
        std::map<std::string, SoundEffectType*> effectsMap;

        SoundEffectTypes()
        {
            effectsMap.insert(std::pair<std::string,SoundEffectType*>("Delay", &delayObject));
            
        }

        
        
};