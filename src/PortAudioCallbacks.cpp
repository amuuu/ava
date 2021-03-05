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
    static float sample = 0;

    for (i = 0; i<framesPerBuffer; i++)
    {
        sample = project->GetNextProjectSample();
        *out++ = sample;
        *out++ = sample;
    }  

    return paContinue;  
}