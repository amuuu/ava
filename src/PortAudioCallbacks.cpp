#include "PortAudioController.h"

// TODO: re-write + rename this callback.
int PortAudioController::paCallbackMethod(const void *inputBuffer, void *outputBuffer, unsigned long framesPerBuffer,
                            const PaStreamCallbackTimeInfo* timeInfo, PaStreamCallbackFlags statusFlags)
{
    float *out = (float*)outputBuffer;
    unsigned long i;

    (void) timeInfo; /* Prevent unused variable warnings. */
    (void) statusFlags;
    (void) inputBuffer;
    
    for( i=0; i<framesPerBuffer; i++ )
    {
        *out++=generatedOutputBuffer[leftPhase];
        *out++=generatedOutputBuffer[rightPhase];

        leftPhase += 1;
        if (leftPhase >= TABLE_SIZE) leftPhase -= TABLE_SIZE;
        rightPhase += 3; /* higher pitch so we can distinguish left and right. */
        if (rightPhase >= TABLE_SIZE) rightPhase -= TABLE_SIZE;
    }

    return paContinue;  
}
