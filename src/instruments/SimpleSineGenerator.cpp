#include "SimpleSineGenerator.h"

#include <stdio.h>

SimpleSineGenerator::SimpleSineGenerator() : VirtualInstrument()
{
    (*parameters).insert({"freq", -1});
    (*parameters).insert({"amp", -1});


    SetSoundUnitName("Simple Sine");

    CreateWaveTable();
}

float SimpleSineGenerator::GetNextUnitSample()
{
    // printf("bruhhhhhhhhhhhhhhhhhhhhh");
    
    if (pendingParamUpdate) UpdateParams();

    auto index0 = (unsigned int) currentIndex;
    auto index1 = index0 == (wavetableSize - 1) ? (unsigned int) 0 : index0 + 1;

    auto frac = currentIndex - (float) index0;

    // auto value0 = table[index0];
    auto value0 = *(outputData->outputBuffer+index0);
    auto value1 = *(outputData->outputBuffer+index1);

    auto currentSample = value0 + frac * (value1 - value0);

    if ((currentIndex += wavetableDelta) > (float) wavetableSize)
        currentIndex -= (float) wavetableSize;
    printf("current %f\n", currentSample);
    return currentSample;
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

void SimpleSineGenerator::UpdateParams()
{
    try {
        freq = (*parameters)["freq"];
        amp = (*parameters)["amp"];
        
        if (freq < 0 || amp < 0)
            throw BadParam();

        SetFrequency(freq, SAMPLE_RATE);
        
        pendingParamUpdate = false;
    }
    
    catch (BadParam& e) {
        printf("%s\n", e.Msg());
    }
}