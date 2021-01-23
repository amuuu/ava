#pragma once

#include "SoundUnit.h"

class VirtualInstrument : public RawUnit
{
    public:
    // array: midi data stuff
        virtual float* FillData() {float* a; return a; };
};
