#include "Form.h"
#include <iostream>
#include "BaseField.h"
#include "BaseValidator.h"



Form::Form()
{
}


Form::~Form()
{
}

void Form::fillForm()
{
	int i = 0;
	for (auto bS : baseField)
	{
		if (validForm[i] == "error")
		{
			std::cout << bS->getMessage() << std::endl;
			bS->insertField();
		} i++;
	}
}

bool Form::validateForm()
{
	bool is_valid = true;
	int i = 0;
	for (auto bS : baseField)
	{
		if (!bS->isValid(validForm[i]))
			is_valid = false;
		i++;
	}
	//if (is_valid) is_valid = baseValidator[0]->isValid(*baseField[3], *baseField[4], validForm[3], validForm[4]);
	//if (is_valid) is_valid = baseValidator[1]->isValid(*baseField[3], *baseField[5], validForm[3], validForm[5]);
	return is_valid;
}

std::ostream & operator<<(std::ostream & ostr, const Form & form)
{
	int i = 0;
	for (auto bS : form.getField())
	{
		std::cout << bS->getMessage() << std::endl;
		if (form.getForm()[i] != "error")
			std::cout << form.getForm()[i] << std::endl;
		else
			if (i == 0)
				std::cout << "Can't contain digits" << std::endl;
			else
				if (i == 1)
					std::cout << "Wrong control digit" << std::endl;
				else
					if (i == 2)
						std::cout << "Out of range" << std::endl;
					else
						if (i == 3)
							std::cout << "Out of range" << std::endl;
						else
							if (i == 4)
								std::cout << "Out of range" << std::endl;
							else
								if (i == 5)
									std::cout << "Out of range" << std::endl;
		i++;
	} return ostr;
}
