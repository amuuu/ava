#include "include/PortAudio/portaudio.h"

typedef struct
{
    float left_phase;
    float right_phase;
}   
paTestData;

class Test {
    
    public:
        
        Test();
        void Terminate();

};