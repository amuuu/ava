#include "Delay.h"


float Delay::ApplyEffect(std::map<std::string, float>* parameters, float inputSample)
{
    int amount = (*parameters)["amount"];

    printf("   Applying delay effect...\n");
    // for(int i=0; i<outputData->size; i++) outputData->outputBuffer[i] = 0.0;
    // for (int i=0; i<outputData->size; i++) {
    //     double y = outputData->outputBuffer[*tmpReadPtr];
        
    //     outputData->outputBuffer[*tmpReadPtr++] = amount;
        
    //     if (*tmpReadPtr >= amount) { *tmpReadPtr -= amount; }
    // }
    return 0.0;
    
}