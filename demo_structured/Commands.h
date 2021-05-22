#include <string>
#include <vector>
#include <sstream>


#define CMD_DELI '-'
#define EXIT_CMD "exit"
#define PLAY_CMD "playbruh"

 
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



class PlayCommand
{
    public:
        static DeserializedPlayCmd Check (std::string command)
        {

            DeserializedPlayCmd result;

            std::string first = GetCommandPart(command, 0);
            if (first == PLAY_CMD)
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


class ExitCommand
{
    public:
        static DeserializedExitCmd Check (std::string command)
        {

            DeserializedExitCmd result;
        
            std::string first = GetCommandPart(command, 0);
            if (first == EXIT_CMD)
                result.isValid = true;
            else
                result.isValid = false;

            return result;
        }
};