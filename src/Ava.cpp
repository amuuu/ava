#include "Ava.h"


bool Halt::PerformTransition(IOController io)
{
    io.pac.StopStream();
    io.pac.CloseStream(); /* TODO: probably these two shouldn't be together */
}

bool OutputPlayback::PerformTransition(IOController io)
{
    if(io.pac.StartStream())
        return true;
    
    return false;
}

bool Starting::PerformTransition(IOController io)
{   
    if (io.pac.Initialize()) {
        if (io.pac.OpenStream(Pa_GetDefaultOutputDevice())) /* TODO: it shouldn't always be the default device */
            return true;
        return false;
    }
    else 
        return false;
}

bool Ava::SetState(EngineState newState) {
    switch (newState)
    {
        case StartingState:
            Starting startingObj;
            currentState = startingObj;
            break;
        case OutputPlaybackState:
            OutputPlayback outputPlaybackObj;
            currentState = outputPlaybackObj;
            break;
        case HaltState:
            Halt haltObj;
            currentState = haltObj;
            break;
        default:
            break;
    }
    currentState.PerformTransition(io);
}