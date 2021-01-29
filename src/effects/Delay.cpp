#include "Delay.h"

Delay::Delay()
{
    SetParameter("amount", 1.0);

    tmpReadPtr = 0;
}

void Delay::SetDelayAmount()
{
    *amount = (int) parameters["amount"];

}

OutputData* Delay::ApplyEffect()
{
    SetDelayAmount();

    for (int i=0; i<outputData->size; i++) {
        double y = outputData->outputBuffer[*tmpReadPtr];
        
        outputData->outputBuffer[*tmpReadPtr++] = *amount;
        
        if (*tmpReadPtr >= *amount) { *tmpReadPtr -= *amount; }
    }

    return outputData;

}
