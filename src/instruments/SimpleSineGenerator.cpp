#include "SimpleSineGenerator.h"

#include <stdio.h>


SimpleSineGenerator::SimpleSineGenerator() : VirtualInstrument()
{
    parameters.insert({"freq", 1});
}

OutputData* SimpleSineGenerator::FillOutputData()
{
    printf("x %d\n", outputData->size);

    for(int i=0; i < outputData->size; i++)
    {
        printf("b %f\n", (float) sin ( parameters["freq"] * (M_PI * 2) * ((double) i / (double) 200)));
        outputData->outputBuffer[i] = (float) sin ( parameters["freq"] * (M_PI * 2) * ((double) i / (double) outputData->size));
        printf("a %f\n", outputData->outputBuffer[i]);

    }

    printf("fff %f\n", outputData->outputBuffer[12]);
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