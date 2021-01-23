#include "VirtualInstrument.h"


class SimpleSineGenerator: public VirtualInstrument
{
    public:
        float* FillData();

};