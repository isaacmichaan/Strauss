#pragma once
#include <string>
class BaseField;

class BaseValidator
{
public:
	BaseValidator();
	~BaseValidator();
	virtual bool isValid(BaseField&, std::string&) { return false; }
	virtual bool isValid(BaseField&, BaseField&, std::string, std::string&) { return false; }
};

