#include "../VirtualInstrument.h"


class SimpleSineGenerator: public VirtualInstrument
{
    public:
        SimpleSineGenerator();
        bool SetParameter(VirtualInstrumentParameter targetParameter);
        bool SetParameter(std::string parameterName, float parameterValue);
        
    private:    
        bool AddParameter(VirtualInstrumentParameter targetParameter);
        OutputData* FillOutputData();

};