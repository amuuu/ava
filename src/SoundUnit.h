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
        SoundUnit() { }
        
        OutputData GetOutputBuffer() const { return outputData; }
    
    protected:
        OutputData outputData;
};


class RawUnit : public SoundUnit
{

};

