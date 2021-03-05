#include "InvalidArg.h"



InvalidArg::InvalidArg(std::string s) : invalid_argument(std::string(s))
{
}

InvalidArg::InvalidArg(std::string s, int line) :
	invalid_argument(std::string("Wrong command: ").append(s).append(" is not a valid command!"))
{
	std::cout << "\nLine: " << line << " --> ";
}


InvalidArg::~InvalidArg()
{
}
