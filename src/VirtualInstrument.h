/** @file VirtualInstrument.h
	@brief Base class for instruments with real-time configurable parameters 
*/
/*
*   This header contains methods for the base class that's inherited to create virtual instruments.
*/

#pragma once

#include "SoundUnit.h"

#include <map>
#include <string>


struct VirtualInstrumentParameter
{
    std::string name;
    float value;
};

class VirtualInstrument : public RawUnit
{
    
    public:
        VirtualInstrument() : RawUnit() {}
        virtual bool SetParameter(VirtualInstrumentParameter targetParameter) { return false; }
        virtual bool SetParameter(std::string parameterName, float parameterValue) { return false; }

    
    protected:
        std::map<std::string, float> parameters;

        virtual OutputData* FillOutputData() { return outputData; };
        virtual bool AddParameter(VirtualInstrumentParameter targetParameter) { return false; }


};
