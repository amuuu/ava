/** @file PortAudioCallbacks.cpp
	@brief Different Port Audio callback functions
*/
/*
*   This header contains different pa callbacks. The only reason that it's not combined with PortAudioController.cpp
*   is because it'd make the other file too crowded :)
*/

#include "PortAudioController.h"

// TODO: re-write + rename this callback.
int PortAudioController::paCallbackMethod(const void *inputBuffer, void *outputBuffer, unsigned long framesPerBuffer,
                            const PaStreamCallbackTimeInfo* timeInfo, PaStreamCallbackFlags statusFlags)
{
    float *out = (float*) outputBuffer;
    
    (void) timeInfo;
    (void) statusFlags;
    (void) inputBuffer;
    
    // accessing paOutputData pointer values inside the loop causes segementation faults.
    static int* cursor = &paOutputData->cursor;
    static int* size = &paOutputData->size;
    static unsigned long* framesNo = &paOutputData->framesNo;
    static float* buffer = paOutputData->outputBuffer;

    for (int i=0; i<framesPerBuffer; i++)
    {
        *out++ = *(buffer + *cursor);
        *out++ = *(buffer + *cursor);
        
        *cursor += 1;        
        if (*cursor >= *size) *cursor -= *size;
        
        /* if (*cursor < *framesNo) {
            }        
        else {
        } */
    }  

    return paContinue;  
}