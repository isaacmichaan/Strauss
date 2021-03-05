#pragma once
#include "BaseValidator.h"
#include "Field.h"
#include "ValuesToNames.h"
#include "DestinationNames.h"
#include "ClassNames.h"
#include "CurrencyNames.h"
class BaseField;

template <class T>
class RangeValidator : public BaseValidator
{
public:
	RangeValidator(const int& min, const int& max) : m_min(min), m_max(max) { if (m_min > m_max) { int t = m_min; m_min = m_max; m_max = m_min; } }
	~RangeValidator() {}
	virtual bool isValid(BaseField&, std::string&);
	bool operator<(const int& other) const;
	bool operator>(const int& other) const;
private:
	int m_min, m_max;
};

template<class T>
inline bool RangeValidator<T>::isValid(BaseField & number, std::string& str)
{
	auto num = dynamic_cast<Field<T>&>(number).getField();
	if (typeid(num) == typeid(int))
	{
		int n = dynamic_cast<Field<int>&>(number).getField();
		if (n >= m_min && n <= m_max) {
			str = std::to_string(n);
			return true;
		}
	}
	else if (typeid(num) == typeid(ValuesToNames<DestinationNames>))
	{
		ValuesToNames<DestinationNames> n = dynamic_cast<Field<ValuesToNames<DestinationNames>>&>(number).getField();
		if (n.getValue() >= m_min && n.getValue() <= m_max) {
			str = n.getValueS();
			return true;
		}
	}
	else if (typeid(num) == typeid(ValuesToNames<ClassNames>))
	{
		ValuesToNames<ClassNames> n = dynamic_cast<Field<ValuesToNames<ClassNames>>&>(number).getField();
		if (n.getValue() >= m_min && n.getValue() <= m_max) {
			str = n.getValueS();
			return true;
		}
	}
	else if (typeid(num) == typeid(ValuesToNames<CurrencyNames>))
	{
		ValuesToNames<CurrencyNames> n = dynamic_cast<Field<ValuesToNames<CurrencyNames>>&>(number).getField();
		if (n.getValue() >= m_min && n.getValue() <= m_max) {
			str = n.getValueS();
			return true;
		}
	}
	return false;
}

template<class T>
inline bool RangeValidator<T>::operator<(const int & other) const
{
	return 0;
}

template<class T>
inline bool RangeValidator<T>::operator>(const int & other) const
{
	return 0;
}
