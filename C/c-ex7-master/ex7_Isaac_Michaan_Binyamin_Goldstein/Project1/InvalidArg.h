#pragma once
#include <iostream>
#include <string>
class InvalidArg : public std::invalid_argument
{
public:
	InvalidArg(std::string);
	InvalidArg(std::string, int line);
	~InvalidArg();
};

