#include "AvaInterface.h"
#include "Composer.h"
#include "Commands.h"

#include <iostream>


void CheckExitCmd()
{

}

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

        std::cout << "commands: play, exit, setfreqparams \n";
        std::cin >> inputCommand;

        
        if (ExitCommand::Check(inputCommand).isValid)
        {
            printf("exiting...\n");
            break;
        }

        if (PlayCommand::Check(inputCommand).isValid)
        {
            DeserializedPlayCmd res = PlayCommand::Check(inputCommand);

            if (res.numSeconds != -1)
            {
                ava->Play(res.numSeconds);
            }
        }

        if (SetFreqParamCommand::Check(inputCommand).isValid)
        {
            DeserializedSetFreqParamsCmd res = SetFreqParamCommand::Check(inputCommand);
            
            if(res.isFreqModified)
                ava->SetParameter(res.deviceNum,"freq", res.freq, false);

            if(res.isAmpModified)
                ava->SetParameter(res.deviceNum,"amp", res.amp, false);
        }



        if (inputCommand == "addnew")
        {
            std::cout << "init freq? ";
            std::cin >> newFreq;
            std::cout << "init amp? ";
            std::cin >> newAmp;

            if (newFreq = -1) newFreq = 440;
            if (newAmp = -1) newAmp = 1;

            ava->AddNewSineGeneratorTrack(newFreq, newAmp);
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

