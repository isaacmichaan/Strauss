#pragma once
#include <iostream>
#include <string>
#include <vector>

class CurrencyNames
{
public:
	CurrencyNames();
	~CurrencyNames();
	void show(int num) { if (num < 3) std::cout << currencyNames[num + 1]; else std::cout << num; }
	std::string show(int num, int i) { return currencyNames[num]; }
private:
	std::vector<std::string> currencyNames{ "NIS", "Euro", "Dollar" };
};

