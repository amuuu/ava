#include "SimpleSineGenerator.h"

#include <stdio.h>


SimpleSineGenerator::SimpleSineGenerator() : VirtualInstrument()
{
    (*parameters).insert({"freq", 1});

    SetSoundUnitName("Simple Sine");
}

OutputData* SimpleSineGenerator::UpdateOutputBuffer()
{
    // TODO: Not all freqs can be heard. something's wrong with the formula.
    
    int size = outputData->size;
    float freq = (*parameters)["freq"];

    for(int i=0; i < size; i++)
    {
        *(outputData->outputBuffer+i) = sin ( freq * (M_PI * 2) * ((float) i / (float) size));
    }

    // float freq = (*parameters)["freq"];
    // outputData->size = 2*freq;
    // outputData->outputBuffer

    return outputData;
}

