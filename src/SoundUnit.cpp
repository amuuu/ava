#include "SoundUnit.h"

#include <stdio.h>
SoundUnit::SoundUnit()
{
    outputData = (struct OutputData*) malloc (sizeof(struct OutputData));

    InitializeDefaultIOStructValues();
}

bool SoundUnit::InitializeDefaultIOStructValues()
{
    outputData->size = DEFAULT_SIZE;
    outputData->cursor = INIT_CURSOR_VAL;
    outputData->framesNo = DEFAULT_FRAMES_NO;
}
