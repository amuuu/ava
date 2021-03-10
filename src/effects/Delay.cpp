#include "Delay.h"

Delay::Delay(): SoundEffectType()
{
    writePosition = new int;
    readPosition = new int;
    *writePosition = 0;
    *readPosition = 0;
    SetDelay();
    amount = -1;
    feedback = -1;
}


float Delay::ApplyEffect(std::map<std::string, float>* parameters, float inputSample)
{
    // TODO: add update param method like sine generator
    // double amount = (*parameters)["amount"];
    // double feedback = (*parameters)["feedback"];
    UpdateParams(parameters);

    // printf("   Applying delay effect...\n");
    static float out = 0;
    
    out = ((1-amount) * inputSample + amount * *(buffer + *readPosition)); //1-amount=dryMix, amount=wetMix
            
    *(buffer + *writePosition) = inputSample + (*(buffer + *readPosition) * feedback);
    
    (*readPosition)++;
    if (*readPosition >= bufferLength)
        *readPosition = 0;

    (*writePosition)++;
    
    if (*writePosition >= bufferLength)
        *writePosition = 0;
    
    // printf("read: %d, write: %d\n", *readPosition, *writePosition);
    return out;
}

void Delay::SetDelay()
{
    delayLength = 0.5; // make this a parameter?

    bufferLength  = (int) 2.0 * SAMPLE_RATE;
    // bufferLength  = 512;

    if (bufferLength < 1)
        bufferLength = 1;

    buffer = new double [bufferLength];
    for (int i=0; i<bufferLength; i++)
        *(buffer+i) = 0;

    *readPosition = (int) (*writePosition - (delayLength * SAMPLE_RATE) + bufferLength) % bufferLength;

}

void Delay::UpdateParams(std::map<std::string, float>* parameters)
{
    try {
        amount = (*parameters)["amount"];
        feedback = (*parameters)["feedback"];
        
        if (amount < 0 || feedback < 0)
            throw BadParam();
    }
    
    catch (BadParam& e) {
        printf("%s\n", e.Msg());
    }
}