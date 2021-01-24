#include "SimpleSineGenerator.h"

SimpleSineGenerator::SimpleSineGenerator()
{
    parameters.insert({"freq", 1});
}

float* SimpleSineGenerator::FillData()
{
    for(int i=0; i < OUTPUT_BUFFER_SIZE; i++)
    {
        *(outputBuffer+i) = (float) sin (((double)i / (double) OUTPUT_BUFFER_SIZE) * M_PI * 2.);
    }
    return outputBuffer;
}

bool SimpleSineGenerator::SetParameter(VirtualInstrumentParameter targetParameter) 
{ 
    parameters[targetParameter.name] = targetParameter.value;
    return true;
}
