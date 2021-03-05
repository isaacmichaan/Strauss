#pragma once
#include <vector>
#include <memory>
class BaseField;
class BaseValidator;

class Form
{
public:
	Form();
	~Form();
	void addField(BaseField* bF) { baseField.push_back(bF); }
	void addValidator(BaseValidator* bV) { baseValidator.push_back(bV); }
	void fillForm();
	bool validateForm();
	std::vector<BaseField*> getField() const { return baseField; }
	std::vector<std::string> getForm() const { return validForm; }
private:
	std::vector<BaseField*> baseField;
	std::vector<BaseValidator*> baseValidator;
	std::vector<std::string> validForm{ "error", "error", "error", "error", "error", "error" };
};

std::ostream& operator<<(std::ostream& ostr, const Form& form);