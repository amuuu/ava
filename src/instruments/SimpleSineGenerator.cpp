#include "SimpleSineGenerator.h"

#include <stdio.h>

SimpleSineGenerator::SimpleSineGenerator() : VirtualInstrument()
{
    (*parameters).insert({"freq", -1});
    (*parameters).insert({"amp", -1});


    SetSoundUnitName("Simple Sine");

    CreateWaveTable();
}

OutputData* SimpleSineGenerator::GetNextUnitSample()
{
    printf("bruh");
    float freq, amp;
    
    try {
        freq = (*parameters)["freq"];
        amp = (*parameters)["amp"];
        
        if (freq < 0 || amp < 0)
            throw BadParam();
    }
    
    catch (BadParam& e) {
        printf("%s\n", e.Msg());
    }
    
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

