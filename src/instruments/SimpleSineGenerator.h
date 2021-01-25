#include "../VirtualInstrument.h"


class SimpleSineGenerator: public VirtualInstrument
{
    public:
        SimpleSineGenerator();
        OutputData* FillOutputData();
        bool SetParameter(VirtualInstrumentParameter targetParameter);
        
    private:    
        bool AddParameter(VirtualInstrumentParameter targetParameter);
};