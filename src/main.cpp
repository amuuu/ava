#include "PortAudioController.h"
#include "include/portaudio.h"

#define NUM_SECONDS   (5)

int main()
{

    PortAudioController pac;
    
    pac.Initialize();

    if(pac.OpenStream(Pa_GetDefaultOutputDevice()))
    {
        if(pac.StartStream())
        {
            printf("Play for %d seconds.\n", NUM_SECONDS);
            Pa_Sleep( NUM_SECONDS * 1000);
            pac.StopStream();
        }
        pac.CloseStream();
    }

    printf("TEST DONE");
    return paNoError;
}