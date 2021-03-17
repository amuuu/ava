#include "AvaInterface.h"

AvaInterface::AvaInterface()
{
    ava = new Ava();
    instruments = new std::map<int, SimpleSineGenerator*>;

    InitInstruments();

}

void AvaInterface::Play(float numSeconds)
{
    if (ava->SetState(StartingState))
    {
        if (ava->SetState(OutputPlaybackState))
        {
            printf("Play for %f seconds.\n", numSeconds);

            Pa_Sleep( numSeconds * 1000);
    
            ava->SetState(HaltState);
        }
    }
}

void AvaInterface::InitInstruments()
{
    instruments->insert(std::pair<int, SimpleSineGenerator*>(0, new SimpleSineGenerator()));
    
    (*instruments)[0]->SetParameter("freq", 440);
    (*instruments)[0]->SetParameter("amp", 1);

    ava->project->GetTrack(0)->SetSoundSource((*instruments)[0]);
}

void AvaInterface::AddNewSineGeneratorTrack()
{
    int newIndex = ava->project->GetTracksSize();
    instruments->insert(std::pair<int, SimpleSineGenerator*>(newIndex, new SimpleSineGenerator()));
    (*instruments)[newIndex]->SetParameter("freq", 440);
    (*instruments)[newIndex]->SetParameter("amp", 1);

    ava->project->AppendTrack();
    ava->project->GetTrack(newIndex)->SetSoundSource((*instruments)[newIndex]);
}

void AvaInterface::SetTrackActive(int trackIndex, TrackState state)
{
    ava->project->GetTrack(trackIndex)->ChangeTrackState(state);
}

void AvaInterface::SetParameter(int trackIndex, std::string name, float value, bool isEffect=false)
{
    (*instruments)[trackIndex]->SetParameter(name, value);
}
