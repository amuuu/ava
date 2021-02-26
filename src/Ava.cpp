#include "Ava.h"


Ava::Ava()
{
    printf("Project %s initialized.\n", project.GetProjectName().c_str());
}

bool Halt::PerformTransition(IOController io)
{
    if (io.pac.StopStream())
        if (io.pac.CloseStream()) /* TODO: probably these two shouldn't be together */
            return true;
    return false;
}

bool OutputPlayback::PerformTransition(IOController io)
{
    if (io.pac.OpenStream(Pa_GetDefaultOutputDevice())) /* TODO: it shouldn't always be the default device */
        if(io.pac.StartStream())
            return true;
    return false;
}

bool Starting::PerformTransition(IOController io)
{   
    if (io.pac.Initialize())
        return true;
    return false;
}

bool Ava::SetState(EngineState newState)
{        
    /* TODO: don't allow transition to the same state (or should it be allowed?) */
    currentState = statesMap[newState];
        
    if (currentState->PerformTransition(io))
        return true;
    
    return false;
}

bool Ava::UpdateMainOutputBuffer()
{
    OutputData* od = project.GetNextProjectSample();

    if(io.pac.SetOutputBuffer(od)) {
        printf("Output buffer updated. \n");
        return true;
    }
    return false;
}

