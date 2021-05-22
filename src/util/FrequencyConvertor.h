/** @file FrequencyConvertor.h
	@brief Frequency convertor functions
*/
/*
*   Used links:

    https://pages.mtu.edu/~suits/NoteFreqCalcs.html#:~:text=fn%20%3D%20the%20frequency%20of,equals%202%20%3D%201.059463094359...&text=where%20W%20is%20the%20wavelength,s%20at%20%22room%20temperature.%22

    http://techlib.com/reference/musical_note_frequencies.htm

    https://pages.mtu.edu/~suits/notefreqs.html
*/

#pragma once

#include <math.h>

// equal tempered scale
static float NoteNumberToFreq(int noteNumber)
{
    float baseFreq = 440.0; // A above the middle C / A4=57(midi)

    int distanceToBaseNote = noteNumber - 57; //middle C
    
    float result = baseFreq * pow(1.059463, distanceToBaseNote);

    return result;
}