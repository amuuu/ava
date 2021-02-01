/** @file Track.h
	@brief Manages individual tracks and the soundunits inside them.
*/
/*
*   This header contains methods for managing a single track and soundunits inside that track,
*   as well as providing ways to manage track settings such as its state (active, mute, deactivated.)
*/

#include "SoundUnit.h"
#include "SoundEffect.h"

#include <list>
#include <string>
#include <typeinfo>

enum TrackState {Mute, Deactivated, Active};
enum TrackOutputMode {Mono, Stereo};

class Track
{
    public:
        
        Track();
        Track(std::string name) : Track() { trackAudioSettings.trackName = name; };
        
        TrackState GetTrackState() { return state; }
        bool ChangeTrackState(TrackState newState) { state = newState; return true;};

        bool AppendNewSoundEffect(SoundEffect newSoundEffect); // TODO: doesn't obey SRP, should be inside a new class
        bool SetSoundSource(SoundUnit newSoundSource) { *soundSource = newSoundSource; return true; }
        
        SoundEffect GetEffect(int index);
        SoundUnit GetSoundSource();

        bool SetTrackName(std::string name) { trackAudioSettings.trackName = name; return true; }
        std::string GetTrackName() { return trackAudioSettings.trackName; }

        // std::list<SoundUnit>* GetAllSoundUnits() const { return soundUnits; }

        OutputData* GetTrackOutputBuffer();
    
    private:
        TrackState state;

        // std::list<SoundUnit>* soundUnits;
        std::list<SoundEffect>* effectChain;
        SoundUnit* soundSource;

        struct TrackAudioSettings_t
        {
            TrackOutputMode outputMode;
            float volume;
            float pan;
            std::string trackName; 

        } trackAudioSettings;
};
