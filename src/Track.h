
#include "SoundUnit.h"

#include <list>

enum TrackState {Mute, Deactivated, Active};
enum TrackOutputMode {Mono, Stereo};

class Track
{
    public:
        TrackState GetTrackState() const { return state; }
        bool ChangeTrackState(TrackState newState) { return true; /* for now */ };

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
