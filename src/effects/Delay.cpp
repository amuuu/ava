#include "Delay.h"


OutputData* Delay::ApplyEffect(std::map<std::string, float>* parameters)
{
    int amount = (*parameters)["amount"];
    printf("amount====%d\n", amount);
    
    // for(int i=0; i<outputData->size; i++) outputData->outputBuffer[i] = 0.0;
    // for (int i=0; i<outputData->size; i++) {
    //     double y = outputData->outputBuffer[*tmpReadPtr];
        
    //     outputData->outputBuffer[*tmpReadPtr++] = amount;
        
    //     if (*tmpReadPtr >= amount) { *tmpReadPtr -= amount; }
    // }
    return outputData;
    
}