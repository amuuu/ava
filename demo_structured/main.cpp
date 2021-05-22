#include "AvaInterface.h"
#include "Composer.h"

#include <iostream>


int main(void)
{
    AvaInterface* ava = new AvaInterface();
    
    float newFreq = 440, newAmp = 1;
    float numSeconds = 0.5; 
    int deviceNumber = 1;
    bool shouldExit = false;
    
    std::string inputCommand;
    while (true)
    {

        std::cout << "commands: addnew/setparams/play/showdevices/deactivate/activate/exit\n";
        std::cin >> inputCommand;
        
        if (inputCommand == "exit")
        {
            break;
        }

        else if (inputCommand == "addnew")
        {
            std::cout << "init freq? ";
            std::cin >> newFreq;
            std::cout << "init amp? ";
            std::cin >> newAmp;

            if (newFreq = -1) newFreq = 440;
            if (newAmp = -1) newAmp = 1;

            ava->AddNewSineGeneratorTrack(newFreq, newAmp);
        }

        else if (inputCommand == "setparams")
        {
            std::cout << "(index starts from 0)\nwhich device? ";
            std::cin >> deviceNumber;

            std::cout << "new freq: ";
            std::cin >> newFreq;
            
            std::cout << "new amp: ";
            std::cin >> newAmp;

            if (newFreq != -1)
            {
                ava->SetParameter(deviceNumber,"freq", newFreq, false);
            }
            
            if (newAmp != -1)
            {
                ava->SetParameter(deviceNumber,"amp", newAmp, false);
            }
        }

        else if (inputCommand == "play")
        {

            std::cout << "secs: ";
            std::cin >> numSeconds;

            if (numSeconds != -1)
            {
                ava->Play(numSeconds);
            }
        }
        
        else if (inputCommand == "deactivate")
        {
            std::cout << "(index starts from 0)\nwhich device? ";
            std::cin >> deviceNumber;

            ava->SetTrackActive(deviceNumber, Deactivated);
        }

        else if (inputCommand == "activate")
        {
            std::cout << "(index starts from 0)\nwhich device? ";
            std::cin >> deviceNumber;

            ava->SetTrackActive(deviceNumber, Active);
        }

        else if (inputCommand == "showdevices")
        {
            ava->DisplayAudioDeviceSettings();
        }

        else
        {
            std::cout << "invalid command.\n";
        }

    }

    printf("TEST DONE AND SEE YOU LATER.\n");
    return paNoError;
}

