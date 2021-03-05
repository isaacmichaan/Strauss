#pragma once
#include <string>

class BaseField
{
public:
	BaseField();
	~BaseField();
	virtual std::string getMessage() const = 0;
	virtual void insertField() = 0;
	virtual bool isValid(std::string&) = 0;
};

