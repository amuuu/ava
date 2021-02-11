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
         
        virtual OutputData* ApplyEffect(std::map<std::string, float> parameters) { return nullptr; }
    
    int m;

    protected:
        OutputData* outputData;
        
}; 