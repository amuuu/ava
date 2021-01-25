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
        printf("%cursor d\n", paOutputData->cursor);
        if (paOutputData->cursor < paOutputData->framesNo) {
            *out++ = paOutputData->outputBuffer[paOutputData->cursor];
            paOutputData->cursor+= 1;
            // printf("a %f, ", *(paOutputData->outputBuffer[paOutputData->cursor]));
        }
        else 
        {
            *out++ = 0;
            // printf("b\n");
        }
    }

    return paContinue;  
}
