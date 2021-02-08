#pragma once

#include "effects/Delay.h"
#include <map>


class SoundEffectCollection // TODO: change the name
{
    public:
        Delay delayObject;
        
        std::map<std::string, SoundEffectType*> effectsMap;

        SoundEffectCollection() {

            effectsMap.insert ( std::pair<std::string,SoundEffectType*>("Delay", &delayObject) );
        }
        
};