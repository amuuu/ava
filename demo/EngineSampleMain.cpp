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
    SimpleSineGenerator sine;

    
    VirtualInstrumentParameter p;
    p.name = "freq";
    p.value = 1;
    
    sine.SetParameter(p);
    sine.FillData();

    ava.project.GetTrack(0).AppendNewUnit(sine);
    
    ava.UpdateOutputBuffer(sine.GetOutputBuffer());

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