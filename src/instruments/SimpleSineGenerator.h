/** @file SimpleSineGenerator.h
	@brief A simple and basic virtual instrument for Ava
*/
/*
*   This header contains the implementation for a simple sine wave generator. The main method is UpdateOutputBuffer.
*/

#include "../VirtualInstrument.h"


class SimpleSineGenerator: public VirtualInstrument
{
    public:
        SimpleSineGenerator();
        float GetNextUnitSample() override;
    
    private:
        void CreateWaveTable();
        void SetFrequency(float freq, float sampleRate);
        float GetNextSample();
        void UpdateParams();
        
        float freq;
        float amp;

        int wavetableSize;
        double wavetableDelta;
        float currentIndex;        
};