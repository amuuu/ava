#include "Track.h"

bool Track::AppendNewUnit(SoundUnit newSoundUnit)
{
    soundUnits.push_back(newSoundUnit);
    return true;
}

SoundUnit Track::GetSoundUnit(int index)
{
    std::list<SoundUnit>::iterator it = soundUnits.begin();
    std::advance(it, index);
    return *it;
}
    