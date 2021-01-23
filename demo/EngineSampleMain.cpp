#include "../src/Ava.h"
#include "../src/include/portaudio.h"

#include "../src/instruments/SimpleSineGenerator.h"

#define NUM_SECONDS   (3)

int main(void)
{

    Ava ava;
    SimpleSineGenerator sine;

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