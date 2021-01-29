#include "SimpleSineGenerator.h"

#include <stdio.h>


SimpleSineGenerator::SimpleSineGenerator() : VirtualInstrument()
{
    parameters.insert({"freq", 1});
}

OutputData* SimpleSineGenerator::UpdateOutputBuffer()
{
    // TODO: Not all freqs can be heard. something's wrong with the formula.
    
    int size = outputData->size;
    float freq = parameters["freq"];

    for(int i=0; i < size; i++)
    {
        outputData->outputBuffer[i] = sin ( freq * (M_PI * 2) * ((float) i / (float) size));
    }

    return outputData;
}

bool SimpleSineGenerator::SetParameter(VirtualInstrumentParameter targetParameter) 
{ 
    parameters[targetParameter.name] = targetParameter.value; // TODO: handle none-existent parameters in the map

    printf("Parameter %s = %f\n", targetParameter.name.c_str(), parameters[targetParameter.name]);
    
    UpdateOutputBuffer();

    return true;
}

bool SimpleSineGenerator::SetParameter(std::string parameterName, float parameterValue)
{
    parameters[parameterName] = parameterValue; // TODO: handle none-existent parameters in the map

    UpdateOutputBuffer();

    return true;
}



bool SimpleSineGenerator::AddParameter(VirtualInstrumentParameter targetParameter) 
{ 
    parameters.insert({targetParameter.name, targetParameter.value});
    
    // printf("New parameter %p = %f was added.\n", targetParameter.name, parameters[targetParameter.name]);
    return true;
}