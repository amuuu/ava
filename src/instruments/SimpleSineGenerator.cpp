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
    
    SetFrequency(freq, SAMPLE_RATE);

    return outputData;
}


void SimpleSineGenerator::CreateWaveTable()
{
    wavetableSize = 1<<7;
    ModifyOutputDataStructBufferSize(outputData, wavetableSize);
    double angleData = (2*M_PI)/(double)(wavetableSize-1);
    double currentAngle = 0 ;

    printf("size: %d\n", wavetableSize);

    for (int i=0; i < wavetableSize; i++)
    {
        double value = std::sin(currentAngle);
        *(outputData->outputBuffer+i) = value;
        currentAngle += angleData;
    }
}

void SimpleSineGenerator::SetFrequency(float freq, float sampleRate)
{
    auto tableSizeOverSampleRate = (float) wavetableSize / sampleRate;
    wavetableDelta = freq * tableSizeOverSampleRate;
}

