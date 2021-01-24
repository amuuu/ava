#pragma once

#include "SoundUnit.h"

#include <map>
#include <string>


struct VirtualInstrumentParameter
{
    std::string propName;
    float propValue;
};

class VirtualInstrument : public RawUnit
{
    
    public:
        virtual float* FillData() {float* a; return a; };
        virtual bool SetParameter(VirtualInstrumentParameter targetParameter) { return false; }
    
    private:
        std::map<std::string, float> parameters;

};
