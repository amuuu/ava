#pragma once

#include "math.h"

static float GetDivisionValue(int input)
{
    switch(input)
    {
        case 1: return 1;
        case 2: return 0.5;
        case 3: return 0.33;
        case 4: return 0.25;
        default: return -1;
    }
}