#include "../src/AvaUserHeaders.h"

class AvaInterface
{
    public:
        AvaInterface();

        void Play(float numSeconds);

        void SetParameter(int trackIndex, std::string name, float value, int isEffect);
        void SetTrackActive(int trackIndex, bool isActive);
        /* TODO: audio device settings */

    private:
        Ava* ava;
};