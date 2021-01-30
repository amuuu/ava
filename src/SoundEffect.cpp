#include "SoundEffect.h"

bool SoundEffect::SetParameter(std::string parameterName, float parameterValue)
{
    (*parameters)[parameterName] = parameterValue; // TODO: handle none-existent parameters in the map
    return true;
}