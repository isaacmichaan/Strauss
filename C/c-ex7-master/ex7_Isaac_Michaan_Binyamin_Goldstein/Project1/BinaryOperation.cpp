#include "BinaryOperation.h"
#include "Utils.h"
#include "Calculator.h"
#include "InvalidArg.h"

BinaryOperation::BinaryOperation(std::istream& is, const Calculator& calculator)
{
	try 
	{ 
		m_item1 = calculator[Utils::readInt(is)];
		m_item2 = calculator[Utils::readInt(is)];
	}
	catch (const std::exception&) { throw InvalidArg("Out of range"); }
}
