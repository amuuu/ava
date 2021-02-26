#include "SimpleSineGenerator.h"

#include <stdio.h>
#include <cmath>

SimpleSineGenerator::SimpleSineGenerator() : VirtualInstrument()
{
    (*parameters).insert({"freq", 1});

    SetSoundUnitName("Simple Sine");
}

OutputData* SimpleSineGenerator::UpdateOutputBuffer()
{
    // TODO: Not all freqs can be heard. something's wrong with the formula.
    
    float freq = (*parameters)["freq"];
    float amp = (*parameters)["amp"];
    
    ModifyOutputDataStructBufferSize(outputData, 2*freq);
    
    int size = outputData->size;

    printf("size: %d\n", size);
    
    double timeUnit = (double) 1 / (double) (freq*size);

    printf("time unit: %f\n", timeUnit);
    float time = 0;

    for (int i=0; i < size; i++)
    {
        // *(outputData->outputBuffer+i) = sin ( freq * (M_PI * 2) * ((float) i / (float) size));
        *(outputData->outputBuffer+i) = amp * sin (freq * (M_PI * 2) * (time));
        // *(outputData->outputBuffer+i) = amp * sin (freq * (M_PI * 2) * (i * timeUnit));


        // printf("val %f\n", *(outputData->outputBuffer+i));
        // printf("val %f\n", time);
        time += timeUnit;    

    }

    return outputData;
}

