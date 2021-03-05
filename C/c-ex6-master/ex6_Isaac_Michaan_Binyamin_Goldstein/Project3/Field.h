#pragma once
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include "BaseField.h"
class BaseValidator;

template <class T>
class Field : public BaseField
{
public:
	Field(std::string message) : m_message(message) {}
	~Field() {}
	void addValidator(BaseValidator* validator) { m_validator.push_back(validator); }
	virtual std::string getMessage() const { return m_message; }
	virtual void insertField() { std::cin >> m_data; }
	virtual bool isValid(std::string&);
	T getField() { return m_data; }
private:
	std::string m_message;
	std::vector<BaseValidator*> m_validator;
	T m_data;
};

template<class T>
inline bool Field<T>::isValid(std::string& str)
{
	for (auto bV : m_validator)
	{
		if (!bV->isValid(*this, str))
			return false;
	} return true;
}

//std::cout << typeid(str).name() << std::endl;
