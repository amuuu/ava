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

// TODO: Input must be a list/array of output data; one for each track in the project.
bool Ava::UpdateOutputBufferData()
{
    
    OutputData* tmpOutputData = (struct OutputData*) malloc (sizeof(struct OutputData));
    InitOutputDataStruct(tmpOutputData);    
    
    std::list<Track>* tracks = project.GetAllTracks();

    float bufferDivisionValue = GetDivisionValue((int) project.GetNumActiveTracks()); // divide the buffer and sum up the data on all tracks using this value
    
    for (std::list<Track>::iterator trackIt = tracks->begin(); trackIt != tracks->end(); ++trackIt) { // for each track
        
        printf("Track: %s\n", trackIt->GetTrackName().c_str());
        
        if (trackIt->GetTrackState() == Active) // only calculate the buffer based on active tracks
        {
            
            std::list<SoundUnit>* soundUnits = trackIt->GetAllSoundUnits();
            std::list<SoundUnit>::iterator soundUnitIt = soundUnits->begin();
            OutputData* od;
            
            for (soundUnitIt = soundUnits->begin(); soundUnitIt != soundUnits->end(); ++soundUnitIt) { // for each sound unit inside the track
                od = soundUnitIt->GetOutputBufferData();
                ++soundUnitIt;
                soundUnitIt->SetOutputBufferData(od);  /* buffer of list[1] = list[0] <-(which is the source of sound) (list[1] is an effect)              
                                                        * then buffer of list[2] = list[1]
                                                        *  ...
                                                        *
                                                        * Inside SetOutputBufferData for effects, their effect will be applied and outputdata will be updated.
                                                        */
            }
            
            od = soundUnitIt->GetOutputBufferData(); // the final soundunit will now have the effects of itself + all previous units combined.
            
            for (int i=0; i< tmpOutputData->size; i++) {
                tmpOutputData->outputBuffer[i] += bufferDivisionValue * od->outputBuffer[i]; // update the buffer value based on the division value
            }
        }
        else
        {
            printf("^^^^ Track was not active.\n");
        }
    }

    if(io.pac.SetOutputBuffer(tmpOutputData)) {
        printf("Output buffer updated. \n");
        return true;
    }
    return false;
}
