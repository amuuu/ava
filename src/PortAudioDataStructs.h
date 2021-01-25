#pragma once

#define SIZE (200)

struct OutputData
{
    int size = SIZE;
    float outputBuffer [SIZE];
    unsigned long cursor = 0; // add left and right cursors?
    unsigned long framesNo = SIZE; //?
};