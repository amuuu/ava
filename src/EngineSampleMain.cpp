#include "IOController.h"
#include "include/portaudio.h"

#define NUM_SECONDS   (3)

int main(void)
{

    IOController io;
    
    io.pac.Initialize();

    if(io.pac.OpenStream(Pa_GetDefaultOutputDevice()))
    {
        if(io.pac.StartStream())
        {
            printf("Play for %d seconds.\n", NUM_SECONDS);

            Pa_Sleep( NUM_SECONDS * 1000);

            io.pac.StopStream();
        }
        io.pac.CloseStream();
    }

    printf("TEST DONE AND SEE YOU LATER.\n");
    return paNoError;
}