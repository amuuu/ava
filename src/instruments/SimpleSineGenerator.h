#include "../VirtualInstrument.h"


class SimpleSineGenerator: public VirtualInstrument
{
    public:
        SimpleSineGenerator();
        float* FillData();
        bool SetParameter(VirtualInstrumentParameter targetParameter) { return false; }

};