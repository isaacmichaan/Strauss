#pragma once
#include "BaseValidator.h"
class BaseField;

template <class T, class TT>
class DestinationToClassValidator : public BaseValidator
{
public:
	DestinationToClassValidator(BaseField*, BaseField*) {}
	~DestinationToClassValidator() {}
	virtual bool isValid(BaseField&, BaseField&, std::string, std::string&);
};

template<class T, class TT>
inline bool DestinationToClassValidator<T, TT>::isValid(BaseField & baseF_1, BaseField & baseF_2, std::string str_1, std::string & str_2)
{
	ValuesToNames<DestinationNames> bF_1 = dynamic_cast<Field<ValuesToNames<DestinationNames>>&>(baseF_1).getField();
	ValuesToNames<ClassNames> bF_2 = dynamic_cast<Field<ValuesToNames<ClassNames>>&>(baseF_2).getField();
	str_1 = std::to_string(bF_1.getValue());
	str_2 = std::to_string(bF_2.getValue());
	if (((str_1 == "1" || str_1 == "2") && str_2 == "3") || ((str_1 == "4" || str_1 == "5") && str_2 == "1"))
	{
		str_2 = "error";
		return false;
	} return true;
}
