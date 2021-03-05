#pragma once
#include <cstdint>
#include "BaseValidator.h"

class IdValidator : public BaseValidator
{
public:
	IdValidator();
	~IdValidator();
	virtual bool isValid(BaseField&, std::string&);
};

