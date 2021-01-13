#include "PortAudioController.h"

bool PortAudioController::StartStream()
{
    if (stream == 0)
        return false;
    
    PaError err = Pa_StartStream(stream);
    
    return (err == paNoError);
}

bool PortAudioController::StopStream()
{
    if (stream == 0)
        return false;
    
    PaError err = Pa_StopStream(stream);

    return (err == paNoError);
}