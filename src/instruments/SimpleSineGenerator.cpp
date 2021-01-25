#include "SimpleSineGenerator.h"

#include <stdio.h>


SimpleSineGenerator::SimpleSineGenerator() : VirtualInstrument()
{
    parameters.insert({"freq", 1});
}

OutputData* SimpleSineGenerator::FillOutputData()
{
    printf("freq=%f\n", parameters["freq"]);
    
    int size = outputData->size;
    float freq = parameters["freq"];

    for(int i=0; i < size; i++)
    {
        outputData->outputBuffer[i] = (float) sin ( 440 * (M_PI * 2) * ((float) i / (float) size));
    }

    return outputData;
}

bool SimpleSineGenerator::SetParameter(VirtualInstrumentParameter targetParameter) 
{ 
    parameters[targetParameter.name] = targetParameter.value; // TODO: handle none-existent parameters in the map
    
    // printf("Parameter %p = %f\n", targetParameter.name, parameters[targetParameter.name]);
    return true;
}


bool SimpleSineGenerator::AddParameter(VirtualInstrumentParameter targetParameter) 
{ 
    parameters.insert({targetParameter.name, targetParameter.value});
    
    // printf("New parameter %p = %f was added.\n", targetParameter.name, parameters[targetParameter.name]);
    return true;
}