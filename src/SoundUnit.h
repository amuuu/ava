/** @file SoundUnit.h
	@brief Base class that can make a sound in the engine
*/
/*
*   This header contains definitions for the base units that can make sound. SoundUnit is abstract but
*   other sound type classes inherit from it. RawUnit is the basic class that can play sound files.
*/

#pragma once

#include <math.h>

#include "PortAudioDataStructs.h"

#define OUTPUT_BUFFER_SIZE   (200)

#ifndef M_PI
#define M_PI  (3.14159265)
#endif

class SoundUnit
{
    public:
        SoundUnit();
        
        OutputData* GetOutputBufferData() { return outputData; }
        void SetOutputBufferData(OutputData *newOutputData) { *outputData = *newOutputData; }
    
    protected:
        OutputData* outputData;
    
    private:
        bool InitializeDefaultIOStructValues();

};


class RawUnit : public SoundUnit
{
    public:
        RawUnit() : SoundUnit() {}
};

