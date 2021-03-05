#pragma once
#include <string>
template <class T>
class ValuesToNames
{
public:
	ValuesToNames() {}
	~ValuesToNames() {}
	int & getValue() { return m_value; }
	std::string getValueS() {
		T type;
		std::string os = type.show(m_value - 1, 0);
		return os;
	}
	friend std::ostream& operator<<(std::ostream& os, ValuesToNames& valuesToNames)
	{
		T type;
		type.show(valuesToNames.getValue());
		return os;
	}
	friend std::istream& operator>>(std::istream& is, ValuesToNames& valuesToNames)
	{
		is >> valuesToNames.getValue();
		return is;
	}
private:
	int m_value;
};

