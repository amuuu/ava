#pragma once

#include "AudioDataStructs.h"

#include <map>


class SoundEffectType
{
    public:
        SoundEffectType() { 
            outputData = (struct OutputData*) malloc (sizeof(struct OutputData));
            InitOutputDataStruct(outputData);
            m = 123;
        }
         
        virtual OutputData* ApplyEffect(std::map<std::string, float>* parameters) { return nullptr; }
        OutputData* test() { return outputData; }

        int m;
    protected:
        OutputData* outputData;
        
        
}; 