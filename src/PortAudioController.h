/** @file PortAudioController.h
	@brief Main controller for audio I/O that uses PortAudio sound API
*/
/*
*   This header contains methods for utilizing PortAudio API. 
*   Methods are implemented inside PortAudioController.cpp and PortAudioCallbacks.cpp
*/

#pragma once

#include <stdio.h>
#include <string.h> // for memcpy
#include <math.h>
#include "include/portaudio.h"
#include "ProjectController.h"

#include "AudioDataStructs.h"

#define FRAMES_PER_BUFFER  (64)
#define TABLE_SIZE   (200)

#ifndef M_PI
#define M_PI  (3.14159265)
#endif

enum CallbackType {OutputPlaybackOnly, RealTimeProcessing};

class PortAudioController
{
    public:
        PortAudioController();

        bool StartStream();
        bool StopStream();
        bool OpenStream(PaDeviceIndex index);
        bool CloseStream();
        bool Initialize();

        bool DisplayAudioDevicesSettings();
        // void SetAudioDevice(bool isOutput, int index);

        void SetProjectObject(ProjectController* projectController) { project = projectController; }

        // TODO: set audio device

    private:
        PaStream *stream;
        ProjectController* project;

        CallbackType callbackType;  // TODO: USE MAP INSIDE paCallback map_name[callbacktype] :
                                    // ((PortAudioController*)userData)->paCallbackMethod(inputBuffer, outputBuffer, framesPerBuffer, timeInfo, statusFlags);


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

        bool IsStreamEmpty();

        bool InitPaOutputDataStruct();

        void PrintSupportedStandardSampleRates(const PaStreamParameters *inputParameters, const PaStreamParameters *outputParameters);

};
