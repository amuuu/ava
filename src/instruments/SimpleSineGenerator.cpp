#include "SimpleSineGenerator.h"

#include <stdio.h>


SimpleSineGenerator::SimpleSineGenerator()
{
    parameters.insert({"freq", 1});
}

float* SimpleSineGenerator::FillData()
{
    for(int i=0; i < OUTPUT_BUFFER_SIZE; i++)
    {
        *(outputBuffer+i) = (float) sin ( parameters["freq"] * (M_PI * 2) * ((double) i / (double) OUTPUT_BUFFER_SIZE));
    }
    return outputBuffer;
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

