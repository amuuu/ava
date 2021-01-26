#include "SoundUnit.h"

#include <stdio.h>
SoundUnit::SoundUnit()
{
    outputData = (struct OutputData*) malloc (sizeof(struct OutputData));

    InitializeDefaultIOStructValues();
}

bool SoundUnit::InitializeDefaultIOStructValues()
{
    InitOutputDataStruct(outputData);
    return true;
}
