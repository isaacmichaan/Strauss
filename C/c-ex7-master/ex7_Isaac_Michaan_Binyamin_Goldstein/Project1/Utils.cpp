#include "Utils.h"
#include <iostream>
#include <string>
#include <sstream>

int Utils::readInt(std::istream& is)
{
	std::string s;
	is >> s;
	std::stringstream ss(s);
	ss.exceptions(ss.failbit);

	int number;
	try 
	{ 
		ss >> number;
	}
	catch (const std::exception& e) {
		std::cout << "\nThe value you inserted is not an integer number\n";
		throw std::exception();
	}	
	return number;
}