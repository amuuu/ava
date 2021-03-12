#include "../src/AvaUserHeaders.h"

#include <iostream>

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

    Ava* ava = new Ava();
    SimpleSineGenerator* sine = new SimpleSineGenerator();
    SimpleSineGenerator* sine2 = new SimpleSineGenerator();
    DelayEffect* delay = new DelayEffect();
    
    ava->project->GetTrack(0)->SetSoundSource(sine);
    // ava->project->GetTrack(0)->AppendNewSoundEffect(delay);
    ava->project->AppendTrack();
    ava->project->GetTrack(1)->SetSoundSource(sine2);


    sine->SetParameter("freq", 510);
    sine->SetParameter("amp", 1);

    // ava->project->GetTrack(0)->ChangeTrackState(Deactivated);


    // int targetInstrument = 1;
    float newFreq = 440, newAmp = 1;
    float numSeconds = 0.5; 
    while (true)
    {
        // std::cin >> targetInstrument;
        std::cin >> newFreq;
        std::cin >> newAmp;
        std::cin >> numSeconds;

        if (newFreq != -1)
        {
            sine->SetParameter("freq", newFreq);
        }
        
        if (newAmp != -1)
        {
            sine->SetParameter("amp", newAmp);
        }
        
        if (numSeconds != -1)
        {
            if (ava->SetState(StartingState))
            {
                if (ava->SetState(OutputPlaybackState))
                {
                    printf("Play for %d seconds.\n", NUM_SECONDS);

                    Pa_Sleep( numSeconds * 1000);
            
                    ava->SetState(HaltState);
                }
            }
        }

    }

    // printf("TEST DONE AND SEE YOU LATER.\n");
    return paNoError;
}

