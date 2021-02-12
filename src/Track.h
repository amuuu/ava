/** @file Track.h
	@brief Manages individual tracks and the soundunits inside them.
*/
/*
*   This header contains methods for managing a single track and soundunits inside that track,
*   as well as providing ways to manage track settings such as its state (active, mute, deactivated.)
*/

#include "SoundUnit.h"

#include "SoundEffect.h"
#include "SoundEffectTypes.h"
#include "effects/Presets.h"

#include <list>
#include <string>

enum TrackState {Mute, Deactivated, Active};
enum TrackOutputMode {Mono, Stereo};

class Track
{
    public:
        
        Track();
        Track(std::string name) : Track() { trackAudioSettings.trackName = name; };
        
        /* Track state management */
        TrackState GetTrackState() { return state; }
        bool ChangeTrackState(TrackState newState) { state = newState; return true;};


        /* Sound source and effects */
        bool SetSoundSource(SoundUnit newSoundSource) { *soundSource = newSoundSource; return true; }
        SoundUnit GetSoundSource();

        bool AppendNewSoundEffect(BaseEffectPreset effect);
        SoundEffect GetEffect(int index);


        /* Track minor settings */
        bool SetTrackName(std::string name) { trackAudioSettings.trackName = name; return true; }
        std::string GetTrackName() { return trackAudioSettings.trackName; }


        /* Main function */
        OutputData* GetTrackOutputBuffer();

    
    private:
        TrackState state;

        SoundUnit* soundSource;
        std::list<SoundEffect>* effectChain;
        

        struct TrackAudioSettings_t
        {
            TrackOutputMode outputMode;
            float volume;
            float pan;
            std::string trackName; 

        } trackAudioSettings;
};
