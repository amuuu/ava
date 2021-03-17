#include "AvaInterface.h"

#include <iostream>
#include <map>

int main(void)
{
    AvaInterface* ava = new AvaInterface();
    
    // ava->project->GetTrack(0)->ChangeTrackState(Deactivated);


    float newFreq = 440, newAmp = 1;
    float numSeconds = 0.5; 
    int deviceNumber = 1;
    int shouldExit = -1;

    while (true)
    {

        std::cout << "exit? ";
        std::cin >> shouldExit;
        
        if (shouldExit != 1)
        {
            // std::cin >> targetInstrument;
            std::cout << "which device? ";
            std::cin >> deviceNumber;

            std::cout << "new freq: ";
            std::cin >> newFreq;
            
            std::cout << "new amp: ";
            std::cin >> newAmp;
            
            std::cout << "secs: ";
            std::cin >> numSeconds;

            if (newFreq != -1)
            {
                (*devices)[deviceNumber]->SetParameter("freq", newFreq);
            }
            
            if (newAmp != -1)
            {
                (*devices)[deviceNumber]->SetParameter("amp", newAmp);
            }
            
            if (numSeconds != -1)
            {
                ava->Play(numSeconds);
            }
        }
        else {
            break;
        }
    }

    printf("TEST DONE AND SEE YOU LATER.\n");
    return paNoError;
}

