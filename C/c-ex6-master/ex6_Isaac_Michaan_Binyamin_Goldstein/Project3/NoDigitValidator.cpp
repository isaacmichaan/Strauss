#include "NoDigitValidator.h"
#include "Field.h"
#include <algorithm>


NoDigitValidator::NoDigitValidator()
{
}


NoDigitValidator::~NoDigitValidator()
{
}

bool NoDigitValidator::isValid(BaseField& string, std::string& str)
{
	auto str_ = dynamic_cast<Field<std::string>&>(string).getField();

	for (int i = 0; i < str_.size(); i++)
		if (isdigit(str_[i]))
			return false;

	str = str_;
	return true;
}
