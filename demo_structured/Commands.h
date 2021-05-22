#include <string>
#include <vector>
#include <sstream>


#define CMD_DELI '-'
#define EXIT__CMD "exit" // exit
#define PLAY__CMD "play" // play-2
#define SET_FREQ_PARAMS_CMD "setfreqparams" // setfreqparams-1-440-0.5


 
struct DeserializedCmd
{
    bool isValid;
};

struct DeserializedExitCmd :  public DeserializedCmd
{
    // empty
};

struct DeserializedPlayCmd :  public DeserializedCmd
{
    int numSeconds;
};

struct DeserializedSetFreqParamsCmd :  public DeserializedCmd
{
    int deviceNum;
    float freq;
    bool isFreqModified;
    float amp;
    bool isAmpModified;
};



static void tokenize(std::string const &str, const char delim,
            std::vector<std::string> &out)
{
    std::stringstream ss(str);
 
    std::string s;
    while (std::getline(ss, s, delim)) {
        out.push_back(s);
    }
}

static std::string GetCommandPart(std::string command, int index)
{
    std::vector<std::string> out;
    tokenize(command, CMD_DELI, out);

    if (out.size() < index)
        return "";

    else
        return out[index];

}


class ExitCommand
{
    public:
        static DeserializedExitCmd Check (std::string command)
        {

            DeserializedExitCmd result;
        
            std::string first = GetCommandPart(command, 0);
            if (first == EXIT__CMD)
                result.isValid = true;
            else
                result.isValid = false;

            return result;
        }
};

class PlayCommand
{
    public:
        static DeserializedPlayCmd Check (std::string command)
        {

            DeserializedPlayCmd result;

            std::string first = GetCommandPart(command, 0);
            if (first == PLAY__CMD)
            {
                result.isValid = true;
                
                std::string sec = GetCommandPart(command, 1);
                result.numSeconds = std::stoi(sec); 

            }
            else 
            {
                result.isValid = false;
            }

            return result;
        }
};


class SetFreqParamCommand
{
    public:
        static DeserializedSetFreqParamsCmd Check (std::string command)
        {

            DeserializedSetFreqParamsCmd result;

            std::string first = GetCommandPart(command, 0);
            if (first == SET_FREQ_PARAMS_CMD)
            {
                result.isValid = true;

                
                std::string sec = GetCommandPart(command, 1);
                result.deviceNum = std::stoi(sec);
                
                std::string third = GetCommandPart(command, 2);
                if (third != "n") 
                {
                    result.freq = std::stoi(sec); 
                    result.isFreqModified = true;
                }
                else
                    result.isFreqModified = false;
                
                std::string forth = GetCommandPart(command, 3);
                if (forth != "n") 
                {
                    result.freq = std::stoi(third); 
                    result.isAmpModified = true;
                }
                else
                    result.isAmpModified = false;
            }
            else 
            {
                result.isValid = false;
            }

            return result;
        }
};



