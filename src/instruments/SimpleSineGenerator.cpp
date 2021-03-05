#include "SimpleSineGenerator.h"

#include <stdio.h>

SimpleSineGenerator::SimpleSineGenerator() : VirtualInstrument()
{
    (*parameters).insert({"freq", -1});
    (*parameters).insert({"amp", -1});

    SetSoundUnitName("Simple Sine");

    CreateWaveTable();

    currentSample = new float;
    currentIndex = 0;
}

float SimpleSineGenerator::GetNextUnitSample()
{
    static unsigned int index0 = 0;
    static unsigned int index1 = 0;
    static float frac = 0;
    static float value0 = 0, value1 = 0;
    if (pendingParamUpdate) UpdateParams();

    index0 = (unsigned int) currentIndex;
    index1 = index0 == (wavetableSize - 1) ? (unsigned int) 0 : index0 + 1;

    frac = currentIndex - (float) index0;

    value0 = *(wavetable+index0);
    value1 = *(wavetable+index1);

    *currentSample = value0 + frac * (value1 - value0);

    if ((currentIndex += wavetableDelta) > (float) wavetableSize)
        currentIndex -= (float) wavetableSize;
    
    printf("current %f\n", *currentSample);
    return *currentSample;
}


void SimpleSineGenerator::CreateWaveTable()
{
    wavetableSize = 1<<7;
    wavetable = new float [wavetableSize];

    double angleData = (2*M_PI)/(double)(wavetableSize-1);
    double currentAngle = 0 ;

    for (int i=0; i < wavetableSize; i++)
    {
        double value = std::sin(currentAngle);
        *(wavetable+i) = value;
        currentAngle += angleData;
    }

    printf("Simple Sine Wave Table Created.\n");
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