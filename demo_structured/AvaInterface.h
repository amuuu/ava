#include "../src/AvaUserHeaders.h"

class AvaInterface
{
    public:
        AvaInterface();

        void Play(float numSeconds);

        void SetParameter(int trackIndex, std::string name, float value, int isEffect);
        void SetTrackActive(int trackIndex, bool isActive);

        void AddNewSineGeneratorTrack();
        /* TODO: audio device settings */

    private:
        Ava* ava;

        std::map<int, SimpleSineGenerator*>* instruments; 

        void InitInstruments();
};