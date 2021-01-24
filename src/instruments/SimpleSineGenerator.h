#include "../VirtualInstrument.h"


class SimpleSineGenerator: public VirtualInstrument
{
    public:
        float* FillData();
        bool SetParameter(VirtualInstrumentParameter targetParameter) { return false; }

};