#include "IdValidator.h"
#include "Field.h"


IdValidator::IdValidator()
{
}


IdValidator::~IdValidator()
{
}

bool IdValidator::isValid(BaseField& value, std::string& str)
{
	auto ID = dynamic_cast<Field<uint32_t>&>(value).getField();
	auto cID = ID;
	int last = (ID % 10);
	int sum = 0;
	{
		while (ID > 0)
		{
			int i = (ID % 10);
			ID = ID / 10;
			int j = (ID % 10) * 2;
			int x = j % 10;
			int y = j / 10;
			sum = sum + i + x + y;
			ID = ID / 10;
		}
		if (sum % 10 == 0 && (sum - last) % 10 != 0)
		{
			str = std::to_string(cID);
			return true;
		}

	}
	return false;
}