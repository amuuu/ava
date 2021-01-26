#include "../src/Ava.h"
#include "../src/include/portaudio.h"

#include "../src/instruments/SimpleSineGenerator.h"

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
  
    VirtualInstrumentParameter p; //= {.name = "freq", .value = 500.0 };
    p.name = "freq";
    p.value = 440.0;

    SimpleSineGenerator sine;
    sine.SetParameter(p);
    ava.project.GetTrack(0).AppendNewUnit(sine);
    
    // SimpleSineGenerator sine2;
    // p.value = 410.0;
    // sine.SetParameter(p);
    // ava.project.AppendTrack();
    // ava.project.GetTrack(1).AppendNewUnit(sine2);
    
    ava.UpdateOutputBufferData();

    if (ava.SetState(StartingState)) {
        
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