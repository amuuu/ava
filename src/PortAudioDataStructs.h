#pragma once

#define SIZE (200)

struct OutputData
{
    float outputBuffer [SIZE];
    unsigned long cursor;
    unsigned long num_frames;
};