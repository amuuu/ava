/** @file PortAudioCallbacks.h
	@brief Shared structs between Port Audio and other classes
*/
/*
*   This header contains shared structs that both PortAudioController and other classes such as VirtualInstrument use.
*   It also has some static functions to use with those structs.
*/

#pragma once

#define DEFAULT_SIZE (200)
#define DEFAULT_FRAMES_NO (200)
#define INIT_CURSOR_VAL (0)


struct OutputData
{
    int size;
    float outputBuffer [DEFAULT_SIZE];
    int cursor; // add left and right cursors?
    unsigned long framesNo; //?
};

static void InitOutputDataStruct(OutputData* od)
{
    // od = (struct OutputData*) malloc (sizeof(struct OutputData)); // segmentation fault potential
    od->size = DEFAULT_SIZE;
    od->cursor = INIT_CURSOR_VAL;
    od->framesNo = DEFAULT_FRAMES_NO;

    for(int i=0; i<od->size; i++) od->outputBuffer[i] = 0.0;
}