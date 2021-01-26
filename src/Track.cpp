#include "Track.h"

bool Track::AppendNewUnit(SoundUnit newSoundUnit)
{
    soundUnits->push_back(newSoundUnit);
    
    printf("New sound unit appended to: %s\n", GetTrackName().c_str());

    return true;
}

SoundUnit Track::GetSoundUnit(int index)
{
    std::list<SoundUnit>::iterator it = soundUnits->begin();
    std::advance(it, index);
    return *it;
}
    