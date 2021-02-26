#include "VirtualInstrument.h"

bool VirtualInstrument::SetParameter(VirtualInstrumentParameter targetParameter) 
{ 
    (*parameters)[targetParameter.name] = targetParameter.value; // TODO: handle none-existent parameters in the map

    printf("Parameter %s = %f\n", targetParameter.name.c_str(), (*parameters)[targetParameter.name]);
    
    // UpdateOutputBuffer();

    return true;
}

bool VirtualInstrument::SetParameter(std::string parameterName, float parameterValue)
{
    (*parameters)[parameterName] = parameterValue; // TODO: handle none-existent parameters in the map
    
    // UpdateOutputBuffer(); // TODO: causes seg. fault for sound effect units.
                            // but still it's too much work to call this each time manually when a parameter changes for instrument
    
    return true;
}



bool VirtualInstrument::AddParameter(VirtualInstrumentParameter targetParameter) 
{ 
    (*parameters).insert({targetParameter.name, targetParameter.value});
    
    // printf("New parameter %p = %f was added.\n", targetParameter.name, parameters[targetParameter.name]);
    return true;
}
