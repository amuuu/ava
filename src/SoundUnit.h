#include <math.h>

#define OUTPUT_BUFFER_SIZE   (200)

#ifndef M_PI
#define M_PI  (3.14159265)
#endif

class SoundUnit
{
    public:
        SoundUnit() { outputBuffer = new float [OUTPUT_BUFFER_SIZE]; }
        
        float* GetOutputBuffer() const { return outputBuffer; }
    
    protected:
        float* outputBuffer;
};


class RawUnit : public SoundUnit
{

};

class VirtualInstrument : public RawUnit
{
    public:
    // array: midi data stuff
        virtual float* FillData() {float* a; return a; };
};


class SimpleSineGenerator: public VirtualInstrument
{
    public:
        float* FillData();

};