#include "SoundUnit.h"

float* SimpleSineGenerator::FillData()
{
    for(int i=0; i < OUTPUT_BUFFER_SIZE; i++)
    {
        *(outputBuffer+i) = (float) sin(((double) i/(double) OUTPUT_BUFFER_SIZE) * M_PI * 2.);
    }

    return outputBuffer;
}