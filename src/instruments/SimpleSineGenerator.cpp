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
    
    float freq = (*parameters)["freq"];
    ModifyOutputDataStructBufferSize(outputData, 2*freq);
    int size = outputData->size;

    printf("size: %d\n", size);

    for(int i=0; i < size; i++)
    {
        *(outputData->outputBuffer+i) = sin ( freq * (M_PI * 2) * ((float) i / (float) size));
        printf("val %f\n", *(outputData->outputBuffer+i));
    }

    // float freq = (*parameters)["freq"];
    // outputData->size = 2*freq;
    // outputData->outputBuffer

    return outputData;
}

