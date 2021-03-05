#pragma once
#include <iostream>
#include <string>
#include <vector>

class DestinationNames
{
public:
	DestinationNames();
	~DestinationNames();
	void show(int num) { if (num < 3) std::cout << destinationNames[num + 1]; else std::cout << num; }
	std::string show(int num, int i) { return destinationNames[num]; }
private:
	std::vector<std::string> destinationNames{ "Rome", "Prague", "New York", "India", "Thailand" };
};

