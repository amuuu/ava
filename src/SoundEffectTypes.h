/** @file SoundEffectTypes.h
	@brief contains a collection of SoundEffectType objects
*/
/**
 * This class holds a collection of SoundEffectType objects; it is used in runtime to fill a SoundEffect object's effectType property.
 */
 

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