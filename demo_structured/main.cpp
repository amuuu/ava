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

        std::cout << "commands: play, exit, setfreqparams, showaudiosettings, addnew, numtracks \n";
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

        if (SetFreqParamsCommand::Check(inputCommand).isValid)
        {
            DeserializedSetFreqParamsCmd res = SetFreqParamsCommand::Check(inputCommand);
            
            if (res.isFreqModified)
                ava->SetParameter(res.deviceNum,"freq", res.freq, false);

            if (res.isAmpModified)
                ava->SetParameter(res.deviceNum,"amp", res.amp, false);
        }

        if (ShowAudioSettingsCommand::Check(inputCommand).isValid)
        {
            ava->DisplayAudioDeviceSettings();
        }

        if (AddNewCommand::Check(inputCommand).isValid)
        {
            DeserializedAddNewCmd res = AddNewCommand::Check(inputCommand);

            ava->AddNewSineGeneratorTrack(res.freq, res.amp);
        }

        if (NumTracksCommand::Check(inputCommand).isValid)
        {
            printf("Num Tracks: %d\n", ava->GetNumTracks());
        }

        if (ActivateTrackCommand::Check(inputCommand).isValid)
        {
            DeserializedActiveCmd res = ActivateTrackCommand::Check(inputCommand);

            ava->SetTrackActive(res.trackIndex, Active);
        }

        if (DectivateTrackCommand::Check(inputCommand).isValid)
        {
            DeserializedActiveCmd res = DectivateTrackCommand::Check(inputCommand);

            ava->SetTrackActive(res.trackIndex, Deactivated);
        }

    }

    printf("TEST DONE AND SEE YOU LATER.\n");
    return paNoError;
}

