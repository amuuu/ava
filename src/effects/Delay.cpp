#include "Delay.h"


float Delay::ApplyEffect(std::map<std::string, float>* parameters, float inputSample)
{
    // TODO: add update param method like sine generator
    int amount = (*parameters)["amount"];
    double feedback = (*parameters)["feedback"];

    printf("   Applying delay effect...\n");
    static float out = 0;
    
    out = ((1-amount) * inputSample + amount * *(buffer + *readPosition)); //1-amount=dryMix, amount=wetMix
            
    *(buffer + *writePosition) = inputSample + (*(buffer + *readPosition) * feedback);
    
    *readPosition++;
    if (*readPosition >= bufferLength)
        *readPosition = 0;

    *writePosition++;
    
    if (*writePosition >= bufferLength)
        *writePosition = 0;
    
    return out;
}

void Delay::SetDelay()
{
    delayLength = 0.5;

    bufferLength  = (int) 2.0 * SAMPLE_RATE;
    if (bufferLength < 1)
        bufferLength = 1;

    buffer = new double [bufferLength];
    for (int i=0; i<bufferLength; i++)
        *(buffer+i) = 0;

    *readPosition = (int) (*writePosition - (delayLength * SAMPLE_RATE) + bufferLength) % bufferLength;

}
