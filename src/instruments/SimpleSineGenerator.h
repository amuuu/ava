#include "../VirtualInstrument.h"


class SimpleSineGenerator: public VirtualInstrument
{
    public:
        SimpleSineGenerator();
        bool SetParameter(VirtualInstrumentParameter targetParameter);
        
    private:    
        bool AddParameter(VirtualInstrumentParameter targetParameter);
        OutputData* FillOutputData();

};