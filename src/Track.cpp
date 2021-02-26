#include "Track.h"

Track::Track()
{
    // soundUnits = new std::list<SoundUnit>;
    effectChain = new std::list<SoundEffect>;
    soundSource = (SoundUnit*) malloc (sizeof(SoundUnit));

    ChangeTrackState(Active);
}

bool Track::AppendNewSoundEffect(BaseEffectPreset effect)
{
    effectChain->push_back(effect.GetEffect());
    
    printf("New effect appended to: %s\n", GetTrackName().c_str());

    return true;
}

SoundEffect Track::GetEffect(int index)
{
    std::list<SoundEffect>::iterator it = effectChain->begin();
    std::advance(it, index);
    return *it;
}

SoundUnit Track::GetSoundSource()
{
    return *soundSource;
}


/* buffer of list[1] = list[0] <- (list[0] is the source of sound and list[1] is an effect)              
* then buffer of list[2] = list[1]
* then buffer of list[3] = list[2]
*  ...
*
* Inside SetOutputBufferData for effects, their effect will be applied and outputdata will be updated.
*/

OutputData* Track::GetNextTrackSample()
{
    OutputData* outputData = (struct OutputData*) malloc (sizeof(struct OutputData));
    InitOutputDataStruct(outputData);

    printf("::::UNIT CHAIN::::\n");
    printf("Generator: %s\n", soundSource->GetSoundUnitName().c_str());
    
    *outputData = *(soundSource->GetNextUnitSample()); // first sound unit that generates sounds

    std::list<SoundEffect>::iterator effectIt = effectChain->begin();

    // for each sound effect inside the track that comes after the sound generator
    for (effectIt = effectChain->begin(); effectIt != effectChain->end(); ++effectIt) {   

        printf("   Effect: %s\n", effectIt->GetSoundUnitName().c_str());
        
        effectIt->SetOutputBufferData(outputData);
        effectIt->ApplyEffect();
        *outputData = *(effectIt->GetNextUnitSample());
    }
    
    printf("::::::::::::::::::\n");

    return outputData;
}
