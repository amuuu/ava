#pragma once

#include "AudioDataStructs.h"

#include <map>


class SoundEffectType
{
    public:
        SoundEffectType() { 
            outputData = (struct OutputData*) malloc (sizeof(struct OutputData));
            InitOutputDataStruct(outputData);
        }
         
        OutputData* ApplyEffect(std::map<std::string, float> parameters) {return nullptr;}
        
    protected:
        OutputData* outputData;
}; 