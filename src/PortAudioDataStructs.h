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