// there are better ways to implement this whole commands stuff. will refactor later.

#include <string>
#include <vector>
#include <sstream>


#define CMD_DELI '-'

#define EXIT__CMD "exit" // exit
#define PLAY__CMD "play" // play or play-2 (seconds)
#define SET_FREQ_PARAMS_CMD "setfreqparams" // setfreqparams-1-440-0.5 or setfreqparams-1-n-0.5 (device number - freq - amp)
#define SHOW_AUDIO_SETTINGS__CMD "showaudiosettings" // showdevices
#define ADD_NEW_DEVICE__CMD "addnew" // addnew or addnew-440-1 or addnew-440
#define NUM_TRACKS__CMD "numtracks" // numtracks
#define ACTIVATE_TRACK__CMD "activate" //activate-1
#define DEACTIVATE_TRACK__CMD "deactivate" //deactivate-1

 
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

struct DeserializedShowAudioSettingsCmd :  public DeserializedCmd
{
    // empty
};

struct DeserializedAddNewCmd :  public DeserializedCmd
{
    float freq;
    float amp;
};

struct DeserializedNumTracksCmd :  public DeserializedCmd
{
    // empty
};

struct DeserializedActiveCmd :  public DeserializedCmd
{
    int trackIndex;
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

    if (out.size() <= index)
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
                
                if (sec != "")
                    result.numSeconds = std::stoi(sec); 
                else
                    result.numSeconds = 1; 

            }
            else 
            {
                result.isValid = false;
            }

            return result;
        }
};

class SetFreqParamsCommand
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
                    result.amp = std::stoi(third); 
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

class ShowAudioSettingsCommand
{
    public:
        static DeserializedShowAudioSettingsCmd Check (std::string command)
        {

            DeserializedShowAudioSettingsCmd result;
        
            std::string first = GetCommandPart(command, 0);
            if (first == SHOW_AUDIO_SETTINGS__CMD)
                result.isValid = true;
            else
                result.isValid = false;

            return result;
        }
};

class AddNewCommand
{
    public:
        static DeserializedAddNewCmd Check (std::string command)
        {

            DeserializedAddNewCmd result;

            std::string first = GetCommandPart(command, 0);
            if (first == ADD_NEW_DEVICE__CMD)
            {
                result.isValid = true;
                
                result.freq = 440.0;
                result.amp = 1;
                

                std::string sec = GetCommandPart(command, 1);
                if (sec != "") 
                {
                    result.freq = std::stoi(sec); 
                
                    std::string third = GetCommandPart(command, 2);
                    if (third != "") 
                    {
                        result.amp = std::stoi(third); 
                    }
                }
            }
            else 
            {
                result.isValid = false;
            }

            return result;
        }
};

class NumTracksCommand
{
    public:
        static DeserializedNumTracksCmd Check (std::string command)
        {

            DeserializedNumTracksCmd result;
        
            std::string first = GetCommandPart(command, 0);
            if (first == NUM_TRACKS__CMD)
                result.isValid = true;
            else
                result.isValid = false;

            return result;
        }
};

class ActivateTrackCommand
{
    public:
        static DeserializedActiveCmd Check (std::string command)
        {

            DeserializedActiveCmd result;

            std::string first = GetCommandPart(command, 0);
            if (first == ACTIVATE_TRACK__CMD)
            {
                result.isValid = true;
                
                std::string sec = GetCommandPart(command, 1);
                if (sec != "")
                    result.trackIndex = std::stoi(sec); 
                else
                    result.isValid = false;
            }
            else 
            {
                result.isValid = false;
            }

            return result;
        }
};

class DectivateTrackCommand
{
    public:
        static DeserializedActiveCmd Check (std::string command)
        {

            DeserializedActiveCmd result;

            std::string first = GetCommandPart(command, 0);
            if (first == DEACTIVATE_TRACK__CMD)
            {
                result.isValid = true;
                
                std::string sec = GetCommandPart(command, 1);
                if (sec != "")
                    result.trackIndex = std::stoi(sec); 
                else
                    result.isValid = false;
            }
            else 
            {
                result.isValid = false;
            }

            return result;
        }
};


