
/** @file PortAudioController.h
	@brief Main controller for audio I/O that uses PortAudio sound API
	@author AMU <a@b.c>
*/
/*
*
*
*
*
*
*/

#include <stdio.h>
#include <math.h>
#include "include/portaudio.h"

#define NUM_SECONDS   (5)
#define SAMPLE_RATE   (44100)
#define FRAMES_PER_BUFFER  (64)


class PortAudioController
{
    public:
        bool StartStream();
        bool StopStream();
        bool OpenStream();
        bool CloseStream();

        
    private:
        PaStream *stream;


        /* This routine will be called by the PortAudio engine when audio is needed */
        static int paCallback(const void *inputBuffer, void *outputBuffer, unsigned long framesPerBuffer,
                            const PaStreamCallbackTimeInfo* timeInfo, PaStreamCallbackFlags statusFlags,
                            void *userData);

        /* The instance callback passed to the paCallback */
        int paCallbackMethod(const void *inputBuffer, void *outputBuffer, unsigned long framesPerBuffer,
                            const PaStreamCallbackTimeInfo* timeInfo, PaStreamCallbackFlags statusFlags);
                
        /* This routine is called by portaudio when playback is done. */
        static void paStreamFinished(void* userData);

        /* The instance finished method passed to paStreamFinished */
        void paStreamFinishedMethod();

};


class ScopedPortAudioHandler
{
    public:
        ScopedPortAudioHandler();
        ~ScopedPortAudioHandler();

        PaError result() const { return _result; }
    
    private: 
        PaError _result;

};



