#include "PortAudioController.h"

bool PortAudioController::SetOutputBuffer(OutputData* newPaOutputData)
{
    printf("ff %f\n", newPaOutputData->outputBuffer[12]);

    *paOutputData = *newPaOutputData;

    printf("TEMEEEEEEEEEEEEE\n");

    // memcpy(paOutputData, newPaOutputData, sizeof(OutputData*));
    
    printf("f %f\n", paOutputData->outputBuffer[12]);

    // printf("Updated Buffer:\n");
    // for (int i=0; i<paOutputData->size; i++)
    //     printf("f %f", paOutputData->outputBuffer[i]);
    
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
    :stream(0)
{
    paOutputData = (struct OutputData*) malloc (sizeof(struct OutputData));
    
    // TODO: remove the below duplication using a helper class maybe with the soundunit.cpp file
    paOutputData->size = DEFAULT_SIZE;
    paOutputData->cursor = INIT_CURSOR_VAL;
    paOutputData->framesNo = DEFAULT_FRAMES_NO;
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
