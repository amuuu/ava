#include "AvaInterface.h"

AvaInterface::AvaInterface()
{
    ava = new Ava();
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