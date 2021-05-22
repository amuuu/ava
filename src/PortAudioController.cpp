#include "PortAudioController.h"

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
    project = new ProjectController();  
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


bool PortAudioController::DisplayAudioDevicesSettings()
{
    printf( "PortAudio version: 0x%08X\n", Pa_GetVersion());
    printf( "Version text: '%s'\n", Pa_GetVersionInfo()->versionText );

    int numDevices = Pa_GetDeviceCount();

    if ( numDevices < 0)
    {
        printf( "ERROR: Pa_GetDeviceCount returned 0x%x\n", numDevices );
        return false;
    }
    
    printf( "Total number of devices: %d\n", numDevices);

    const PaDeviceInfo *deviceInfo;
    int defaultDisplayed;
    PaStreamParameters inputParameters, outputParameters;
    PaError err;

    for(int i=0; i < numDevices; i++ )
    {
        deviceInfo = Pa_GetDeviceInfo( i );
        printf( "Device #%d ~~~~~~~~~~~\n", i );

        /* Mark global and API specific default devices */
        defaultDisplayed = 0;
        if ( i == Pa_GetDefaultInputDevice() )
        {
            printf( "[ Default Input" );
            defaultDisplayed = 1;
        }
        else if ( i == Pa_GetHostApiInfo( deviceInfo->hostApi )->defaultInputDevice )
        {
            const PaHostApiInfo *hostInfo = Pa_GetHostApiInfo( deviceInfo->hostApi );
            printf( "[ Default %s Input", hostInfo->name );
            defaultDisplayed = 1;
        }
        
        if ( i == Pa_GetDefaultOutputDevice() )
        {
            printf( (defaultDisplayed ? "," : "[") );
            printf( " Default Output" );
            defaultDisplayed = 1;
        }
        else if ( i == Pa_GetHostApiInfo( deviceInfo->hostApi )->defaultOutputDevice )
        {
            const PaHostApiInfo *hostInfo = Pa_GetHostApiInfo( deviceInfo->hostApi );
            printf( (defaultDisplayed ? "," : "[") );                
            printf( " Default %s Output", hostInfo->name );
            defaultDisplayed = 1;
        }

        if ( defaultDisplayed )
            printf( " ]\n" );

        /* print device info fields */
        #ifdef WIN32
        {   /* Use wide char on windows, so we can show UTF-8 encoded device names */
            wchar_t wideName[MAX_PATH];
            MultiByteToWideChar(CP_UTF8, 0, deviceInfo->name, -1, wideName, MAX_PATH-1);
            wprintf( L"Name                        = %s\n", wideName );
        }
        #else
                printf( "Name = %s\n", deviceInfo->name );
        #endif
        printf( "Default sample rate = %8.2f\n", deviceInfo->defaultSampleRate );
    }

    return true;
}