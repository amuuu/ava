#include "PortAudioController.h"

bool PortAudioController::SetOutputBuffer(float* newBuffer)
{
    for(int i=0;i<TABLE_SIZE; i++) {
        generatedOutputBuffer[i] = *(newBuffer+i);
    }
    return true;
}

int PortAudioController::paCallback(const void *inputBuffer, void *outputBuffer, unsigned long framesPerBuffer,
                            const PaStreamCallbackTimeInfo* timeInfo, PaStreamCallbackFlags statusFlags,
                            void *userData)
{
    return ((PortAudioController*)userData)->paCallbackMethod(inputBuffer, outputBuffer,
            framesPerBuffer,
            timeInfo,
            statusFlags);
}
        

bool PortAudioController::OpenStream(PaDeviceIndex index)
{
    PaStreamParameters outputParameters;

    outputParameters.device = index;
    if (outputParameters.device == paNoDevice) {
        return false;
    }

    const PaDeviceInfo* pInfo = Pa_GetDeviceInfo(index);
    if (pInfo != 0)
    {
        printf("Output device name: '%s'\r", pInfo->name);
    }

    outputParameters.channelCount = 2;       /* stereo output */
    outputParameters.sampleFormat = paFloat32; /* 32 bit floating point output */
    outputParameters.suggestedLatency = Pa_GetDeviceInfo( outputParameters.device )->defaultLowOutputLatency;
    outputParameters.hostApiSpecificStreamInfo = NULL;

    PaError err = Pa_OpenStream(
        &stream,
        NULL, /* no input */
        &outputParameters,
        SAMPLE_RATE,
        paFramesPerBufferUnspecified,
        paClipOff,      /* we won't output out of range samples so don't bother clipping them */
        &PortAudioController::paCallback,
        this            /* Using 'this' for userData so we can cast to Sine* in paCallback method */
        );

    if (err != paNoError)
    {
        /* Failed to open stream to device !!! */
        return false;
    }

    err = Pa_SetStreamFinishedCallback(stream, &PortAudioController::paStreamFinished);

    if (err != paNoError)
    {
        Pa_CloseStream(stream);
        stream = 0;

        return false;
    }

    return true;
}

PortAudioController::PortAudioController()
    :stream(0), leftPhase(0), rightPhase(0)
{
}

bool PortAudioController::Initialize()
{
    PaError err = Pa_Initialize();
    
    if (err != paNoError) {
        Pa_Terminate();
    
        printf("ERROR ON INITIALIZE\n");
        printf("Error number: %d\n Error Message: %s\n", err, Pa_GetErrorText(err));
        exit(0);
    }
    else {
        return true;
    }
}

bool PortAudioController::StartStream()
{
    if (IsStreamEmpty())
        return false;
    
    PaError err = Pa_StartStream(stream);    
    return (err == paNoError);
}

bool PortAudioController::StopStream()
{
    if (IsStreamEmpty())
        return false;
    
    PaError err = Pa_StopStream(stream);
    // PaError err = Pa_AbortStream(stream);

    return (err == paNoError);
}

bool PortAudioController::CloseStream()
{   
    if (IsStreamEmpty())
        return false;

    PaError err = Pa_CloseStream(stream);
    stream = 0;

    return (err == paNoError);
}

void PortAudioController::paStreamFinishedMethod()
{
    printf("Stream Completed.\n");
}

void PortAudioController::paStreamFinished(void* userData)
{
    return ((PortAudioController*)userData)->paStreamFinishedMethod();
}

bool PortAudioController::IsStreamEmpty()
{
    if (stream == 0)
        return true;
    return false;
}
