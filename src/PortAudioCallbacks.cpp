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
    
    static unsigned long i = 0;
    
    // accessing paOutputData pointer values inside the loop causes segementation faults.
    // static int* cursor = paOutputData->cursor;
    static int cursor = 0;
    
    printf("NAME %s\n", project->GetTrack(0)->GetTrackName().c_str());

    for (i = 0; i<framesPerBuffer; i++)
    {
        // printf("out %f\n", *(buffer+*cursor));
        // *out++ = *(buffer + *cursor);
        // *out++ = *(buffer + *cursor);
        float sample = project->GetNextProjectSample();
        *out++ = sample;
        *out++ = sample;
    }  

    return paContinue;  
}