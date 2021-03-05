#pragma once
#include <iostream>
#include <string>
#include <vector>

class ClassNames
{
public:
	ClassNames();
	~ClassNames();
	void show(int num) { if (num < 3) std::cout << classNames[num + 1]; else std::cout << num; }
	std::string show(int num, int i) { return classNames[num]; }
private:
	std::vector<std::string> classNames{ "First Class", "Business Class", "Economy Class" };
};

