#include "SimpleSineGenerator.h"

#include <stdio.h>


SimpleSineGenerator::SimpleSineGenerator() : VirtualInstrument()
{
    (*parameters).insert({"freq", 1});
}

OutputData* SimpleSineGenerator::UpdateOutputBuffer()
{
    // TODO: Not all freqs can be heard. something's wrong with the formula.
    
    int size = outputData->size;
    float freq = (*parameters)["freq"];

    for(int i=0; i < size; i++)
    {
        outputData->outputBuffer[i] = sin ( freq * (M_PI * 2) * ((float) i / (float) size));
    }

    return outputData;
}

