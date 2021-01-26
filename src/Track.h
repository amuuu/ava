
#include "SoundUnit.h"

#include <list>
#include <string>

enum TrackState {Mute, Deactivated, Active};
enum TrackOutputMode {Mono, Stereo};

class Track
{
    public:
        
        Track() { soundUnits = new std::list<SoundUnit>; ChangeTrackState(Active); };
        Track(std::string name) : Track() { trackAudioSettings.trackName = name; };
        
        TrackState GetTrackState() const { return state; }
        bool ChangeTrackState(TrackState newState) { state = newState; return true;};

        bool AppendNewUnit(SoundUnit newSoundUnit); // TODO: doesn't obey SRP, should be inside a new class
        SoundUnit GetSoundUnit(int index);

        bool SetTrackName(std::string name) { trackAudioSettings.trackName = name; return true; }
        std::string GetTrackName() { return trackAudioSettings.trackName; }

    
    private:
        TrackState state;

        std::list<SoundUnit>* soundUnits;

        struct TrackAudioSettings_t
        {
            TrackOutputMode outputMode;
            float volume;
            float pan;
            std::string trackName; 

        } trackAudioSettings;
};
