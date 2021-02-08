#include "Track.h"

Track::Track()
{
    // soundUnits = new std::list<SoundUnit>;
    effectChain = new std::list<SoundEffect>;
    soundSource = (SoundUnit*) malloc (sizeof(SoundUnit));

    ChangeTrackState(Active);
}

bool Track::AppendNewSoundEffect(std::string effectName)
{
    SoundEffect newEffect;
    newEffect.SetSoundEffectType(effectName);

    effectChain->push_back(newEffect);
    
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

OutputData* Track::GetTrackOutputBuffer()
{
    OutputData* outputData = (struct OutputData*) malloc (sizeof(struct OutputData));
    InitOutputDataStruct(outputData);
    

    printf("::::UNIT CHAIN::::\n");
    printf("Generator: %s\n", soundSource->GetSoundUnitName().c_str());
    
    *outputData = *(soundSource->GetOutputBufferData()); // first sound unit that generates sounds

    printf("before f=%f\n", outputData->outputBuffer[12]);

    std::list<SoundEffect>::iterator effectIt = effectChain->begin();


    // for each sound effect inside the track that comes after the sound generator
    for (effectIt = effectChain->begin(); effectIt != effectChain->end(); ++effectIt) {   

        printf("   Effect: %s\n", effectIt->GetSoundUnitName().c_str());
        
        
        printf("1\n");
        effectIt->SetOutputBufferData(outputData);

        // printf("fffffffffff %f\n", effectStrategy.soundEffect->GetOutputBufferData()->outputBuffer[12]);
        printf("2\n");

        effectIt->ApplyEffect();

        printf("3\n");
        
        outputData = effectIt->GetOutputBufferData();
    }
    
    printf("after f=%f\n", outputData->outputBuffer[12]);
    
    printf("::::::::::::::::::\n");

    return outputData;
}
