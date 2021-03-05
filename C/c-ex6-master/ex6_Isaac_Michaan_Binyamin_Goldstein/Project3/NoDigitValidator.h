#pragma once
#include <string>
#include "BaseValidator.h"

class NoDigitValidator : public BaseValidator
{
public:
	NoDigitValidator();
	~NoDigitValidator();
	virtual bool isValid(BaseField&, std::string&);
};

