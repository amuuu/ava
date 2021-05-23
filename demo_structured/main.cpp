#include "AvaInterface.h"
#include "Composer.h"
#include "Commands.h"

#include <iostream>


int main(void)
{
    AvaInterface* ava = new AvaInterface();
    
    std::string inputCommand;

    while (true)
    {

        std::cout << "\ncommands:\nplay - setfreqparams - addnew - setnote\nnumtracks - showaudiosettings - exit\n\n";
        std::cin >> inputCommand; 

        
        if (ExitCommand::Check(inputCommand).isValid)
        {
            printf("exiting...\n");
            break;
        }

        else if (PlayCommand::Check(inputCommand).isValid)
        {
            DeserializedPlayCmd res = PlayCommand::Check(inputCommand);
            ava->Play(res.numSeconds);
        }

        else if (SetFreqParamsCommand::Check(inputCommand).isValid)
        {
            DeserializedSetFreqParamsCmd res = SetFreqParamsCommand::Check(inputCommand);
            
            if (res.isFreqModified)
                ava->SetParameter(res.deviceNum,"freq", res.freq, false);

            if (res.isAmpModified)
                ava->SetParameter(res.deviceNum,"amp", res.amp, false);
        }

        else if (SetNoteParamsCommand::Check(inputCommand).isValid)
        {
            DeserializedSetNoteParamsCmd res = SetNoteParamsCommand::Check(inputCommand);
            float freq = NoteNumberToFreq(res.noteNum);
            ava->SetParameter(res.deviceNum,"freq", freq, false);
        }

        else if (ShowAudioSettingsCommand::Check(inputCommand).isValid)
        {
            ava->DisplayAudioDeviceSettings();
        }

        else if (AddNewCommand::Check(inputCommand).isValid)
        {
            DeserializedAddNewCmd res = AddNewCommand::Check(inputCommand);

            ava->AddNewSineGeneratorTrack(res.freq, res.amp);
        }

        else if (NumTracksCommand::Check(inputCommand).isValid)
        {
            printf("Num Tracks: %d\n", ava->GetNumTracks());
        }

        else if (ActivateTrackCommand::Check(inputCommand).isValid)
        {
            DeserializedActiveCmd res = ActivateTrackCommand::Check(inputCommand);

            ava->SetTrackActive(res.trackIndex, Active);
        }

        else if (DectivateTrackCommand::Check(inputCommand).isValid)
        {
            DeserializedActiveCmd res = DectivateTrackCommand::Check(inputCommand);

            ava->SetTrackActive(res.trackIndex, Deactivated);
        }

        else 
        {
            printf("Invalid Command.\n");
        }

    }

    printf("TEST DONE AND SEE YOU LATER.\n");
    return paNoError;
}

