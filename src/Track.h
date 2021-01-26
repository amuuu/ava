
#include "SoundUnit.h"

#include <list>

enum TrackState {Mute, Deactivated, Active};
enum TrackOutputMode {Mono, Stereo};

class Track
{
    public:
        TrackState GetTrackState() const { return state; }
        bool ChangeTrackState(TrackState newState) { return true; /* for now */ };

        bool AppendNewUnit(SoundUnit newSoundUnit); // TODO: doesn't obey SRP, should be inside a new class
        
        SoundUnit GetSoundUnit(int index);
    
    private:
        TrackState state;

        std::list<SoundUnit> soundUnits;

        struct TrackAudioSettings_t
        {
            TrackOutputMode outputMode;
            float volume;
            float pan;
            char* trackName; 
        } trackAudioSettings;
};
