#include "../src/Ava.h"
#include "../src/include/portaudio.h"

#include "../src/instruments/SimpleSineGenerator.h"
#include "../src/effects/Delay.h"


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
  
    VirtualInstrumentParameter p;
    p.name = "freq";
    p.value = 440.0;

    SimpleSineGenerator sine;
    sine.SetParameter(p);
    ava.project.GetTrack(0)->AppendNewUnit(sine);
    ava.project.GetTrack(0)->ChangeTrackState(Deactivated);
    

    Delay delay;
    delay.SetParameter("amount", 1);
    ava.project.GetTrack(0)->AppendNewUnit(delay);

    // SimpleSineGenerator sine2;
    // sine2.SetParameter("freq", 410);
    // ava.project.AppendTrack();
    // ava.project.GetTrack(1)->AppendNewUnit(sine2);
    
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