#include <exception>

struct BadParam : public std::exception
{
	const char* Msg() const throw ()
    {
    	return "Selected parameter hasn't been set for the target sound unit.\n";
    }
}