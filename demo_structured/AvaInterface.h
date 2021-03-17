#include "../src/AvaUserHeaders.h"

enum TrackState {Mute, Deactivated, Active};

class AvaInterface
{
    public:
        AvaInterface();

        void Play(float numSeconds);

        /* TODO: Set parameter for effects */
        void SetParameter(int trackIndex, std::string name, float value, int isEffect);
        void SetTrackActive(int trackIndex, TrackState state);

        void AddNewSineGeneratorTrack();
        /* TODO: audio device settings */

    private:
        Ava* ava;

        std::map<int, SimpleSineGenerator*>* instruments; 

        void InitInstruments();
};