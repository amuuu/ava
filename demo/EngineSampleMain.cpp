#include "../src/AvaUserHeaders.h"

#include <iostream>
#include <map>

int main(void)
{

    Ava* ava = new Ava();
    
    SimpleSineGenerator* sine = new SimpleSineGenerator();
    SimpleSineGenerator* sine2 = new SimpleSineGenerator();
    
    std::map<int, SimpleSineGenerator*>* devices = new std::map<int, SimpleSineGenerator*>;
    devices->insert(std::pair<int, SimpleSineGenerator*>(1, sine));
    devices->insert(std::pair<int, SimpleSineGenerator*>(2, sine2));

    ava->project->GetTrack(0)->SetSoundSource(sine);
    ava->project->AppendTrack();
    ava->project->GetTrack(1)->SetSoundSource(sine2);

    // DelayEffect* delay = new DelayEffect();    
    // ava->project->GetTrack(0)->AppendNewSoundEffect(delay);

    sine->SetParameter("freq", 440);
    sine->SetParameter("amp", 1);
    // ava->project->GetTrack(0)->ChangeTrackState(Deactivated);


    float newFreq = 440, newAmp = 1;
    float numSeconds = 0.5; 

    while (true)
    {
        // std::cin >> targetInstrument;

        std::cout << "new freq: ";
        std::cin >> newFreq;
        
        std::cout << "new amp: ";
        std::cin >> newAmp;
        
        std::cout << "secs: ";
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

