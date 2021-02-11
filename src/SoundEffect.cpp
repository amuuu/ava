#include "SoundEffect.h"

void SoundEffect::ApplyEffect()
{
    printf("zxczxc\n");
    printf("AMOUNT: %f\n", (*parameters)["amount"]);

    printf("NAME: %d\n",effectType->m);

    outputData = effectType->ApplyEffect(parameters);
    
    printf("AAAAAAAAAAAAAAA\n");
    
}

OutputData* SoundEffect::UpdateOutputBuffer()
{ 
    ApplyEffect();
    return outputData; 
}
