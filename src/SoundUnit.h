/** @file SoundUnit.h
	@brief Base class that can make a sound in the engine
*/
/*
*   This header contains definitions for the base units that can make sound. SoundUnit is abstract but
*   other sound type classes inherit from it. RawUnit is the basic class that can play sound files.
*/

#pragma once

#include <math.h>
#include <string>

#include "AudioDataStructs.h"
#include "AvaExceptions.h"

#define OUTPUT_BUFFER_SIZE   (200)

#ifndef M_PI
#define M_PI  (3.14159265)
#endif

class SoundUnit
{
    public:
        SoundUnit();
        
        virtual float GetNextUnitSample() { return 0.0; }
        void SetOutputBufferData(OutputData *newOutputData) { *outputData = *newOutputData; }

        std::string GetSoundUnitName() { return soundUnitProps.name; }
        void SetSoundUnitName(std::string name) { soundUnitProps.name = name; }
    

    protected:
        OutputData* outputData;
    
    private:
        bool InitializeDefaultIOStructValues();
        
        struct SoundUnitProps_t
        {
            std::string name; 

        } soundUnitProps;

};


class RawUnit : public SoundUnit
{
    public:
        RawUnit() : SoundUnit() {}
};

