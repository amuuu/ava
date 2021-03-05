#include "../src/AvaUserHeaders.h"


///////// This is only to use the sleep function to demonstrate the example.
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
//////////////

#define NUM_SECONDS   (3)


int main(void)
{

    Ava ava;
    
    SimpleSineGenerator sine;
    sine.SetParameter("freq", 410);
    sine.SetParameter("amp", 1);
    ava.project->GetTrack(0)->SetSoundSource(&sine);

    // DelayEffect delay;
    // ava.project->GetTrack(0)->AppendNewSoundEffect(delay);

    // ava.project.GetTrack(0)->ChangeTrackState(Deactivated);

    // SimpleSineGenerator sine2;
    // sine2.SetParameter("freq", 200);
    // sine2.SetParameter("amp", 0.5);
    // ava.project->AppendTrack();
    // ava.project->GetTrack(1)->SetSoundSource(&sine2);

    

    if (ava.SetState(StartingState))
    {
        if (ava.SetState(OutputPlaybackState))
        {
            printf("Play for %d seconds.\n", NUM_SECONDS);

            Pa_Sleep( NUM_SECONDS * 1000);
    
            ava.SetState(HaltState);
        }
    }
    printf("TEST DONE AND SEE YOU LATER.\n");
    return paNoError;
}