#include "Track.h"

bool Track::AppendNewUnit(SoundUnit newSoundUnit)
{
    soundUnits.push_back(newSoundUnit);
    return true;
}