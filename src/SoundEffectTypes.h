#pragma once

#include "effects/Delay.h"
#include <map>


class SoundEffectTypes
{
    public:
        Delay delayObject;
        
        std::map<std::string, SoundEffectType*>* effectsMap;

        SoundEffectTypes()
        {
            effectsMap = new std::map<std::string, SoundEffectType*>;
            effectsMap->insert(std::pair<std::string,SoundEffectType*>("Delay", &delayObject));
            
        }

        SoundEffectType* GetType(std::string name)
        {
            return (*effectsMap)[name];
        }

        
        
};