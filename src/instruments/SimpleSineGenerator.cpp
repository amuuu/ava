#include "SimpleSineGenerator.h"

#include <stdio.h>
#include <cmath>

SimpleSineGenerator::SimpleSineGenerator() : VirtualInstrument()
{
    (*parameters).insert({"freq", 1});

    SetSoundUnitName("Simple Sine");

    CreateWaveTable();
}

OutputData* SimpleSineGenerator::UpdateOutputBuffer()
{
    // TODO: Not all freqs can be heard. something's wrong with the formula.
    
    float freq = (*parameters)["freq"];
    float amp = (*parameters)["amp"];
    
    

    return outputData;
}


void SimpleSineGenerator::CreateWaveTable()
{
    int size = 1<<7;
    ModifyOutputDataStructBufferSize(outputData, size);
    double angleData = (2*M_PI)/(double)(size-1);
    double currentAngle = 0 ;

    printf("size: %d\n", size);

    for (int i=0; i < size; i++)
    {
        double value = std::sin(currentAngle);
        *(outputData->outputBuffer+i) = value;
        currentAngle += angleData;
    }

}
