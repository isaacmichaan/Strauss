#include "CalculatorItem.h"
#include "Calculator.h"
#include "Add.h"
#include "Subtraction.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Multiply.h"
#include "Utils.h"
#include "InvalidArg.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>


using std::cout;
using std::cin;
using std::endl;
using std::string;

const std::vector<string> Calculator::m_vector_command = { "read", "exit" , "help", "cre", "area", "per",
		"mul", "add", "sub", "draw", "same", "del", "min", "max", "resize" };

string Calculator::getUserCommand()
{
	string act;
	cout << endl << "Please enter a command (\"help\" for command list):" << endl;
	int line = __LINE__ + 1;
	cin >> act;
	if (std::find(m_vector_command.cbegin(), m_vector_command.cend(), act) == m_vector_command.cend())
		throw InvalidArg(act, line);
	return act;
}

void Calculator::comm(std::string command)
{
	if (command == "exit")
	{
		exit();
		return;
	}

	//request for the list of option to action(-to requests)
	if (command == "help")
	{
		help();
		return;
	}

	//create a basic shape and put it in the calculator
	if (command == "cre")
	{
		createShape();
		return;
	}

	//calculate the area of a shape from the calculator, the shape is requested by number(-index)
	if (command == "area")
	{
		calculateArea();
		return;
	}

	//calculate the perimeter of a shape from the calculator, the shape is requested by number(-index)
	if (command == "per")
	{
		calculatePerimeter();
		return;
	}

	//create a new shape that consist of multiple of one shape, and put it in the calculator
	if (command == "mul")
	{
		m_calculatorItems.push_back(std::make_shared<Multiply>(std::cin, *this));
		return;
	}

	//create a new shape that consist of add of one shape and another shape, and put it in the calculator
	if (command == "add")
	{
		m_calculatorItems.push_back(std::make_shared<Add>(std::cin, *this));
		return;
	}

	//create a new shape that consist of subtraction of one shape from another shape, and put it in the calculator
	if (command == "sub")
	{
		m_calculatorItems.push_back(std::make_shared<Subtraction>(std::cin, *this));
		return;
	}

	//Draws the shape (regardless of its actual size)
	if (command == "draw")
	{
		drawItem();
		return;
	}

	//Prints all indexes of the shapes that are equal in their area and perimeter to the selected shape
	if (command == "same")
	{
		findAllSameShapes();
		return;
	}

	//Deletes the required shape from the calculator and arranges the indexes of the other shapes
	if (command == "del")
	{
		deleteItem();
		return;
	}

	//Finds and prints the largest of the shapes in the calculator, according to the user selection
	if (command == "min")
	{
		findMin();
		return;
	}
	//Finds and prints the smallest of the shapes in the calculator, according to the user selection
	if (command == "max")
	{
		findMax();
		return;
	}
	if (command == "resize")
	{
		resize();
		return;
	}
	throw std::exception();
}

void Calculator::exit()
{
	cout << "Goodbye.";
}

void Calculator::calculateArea()
{
	int line = __LINE__ + 1;
	const int index = insert("Area ", line);
	cout << "Area ";
	m_calculatorItems[index]->printDetails();
	cout << " = " << m_calculatorItems[index]->area() << endl;
}

void Calculator::calculatePerimeter()
{
	int line = __LINE__ + 1;
	const int index = insert("Perimeter ", line);
	cout << "Perimeter ";
	m_calculatorItems[index]->printDetails();
	cout << " = " << m_calculatorItems[index]->perimeter() << endl;
}

void Calculator::drawItem()
{
	int line = __LINE__ + 1;
	const int index = insert("drawItem ", line);
	m_calculatorItems[index]->draw();
}

void Calculator::findAllSameShapes() const
{
	int line = __LINE__ + 1;
	const int index = insert("findAllSameShapes ", line);
	same(index);
}

void Calculator::deleteItem()
{
	int line = __LINE__ + 1;
	const int index = insert("deleteItem ", line);
	m_calculatorItems.erase(m_calculatorItems.begin() + index);
}

void Calculator::findMin() const
{
	int line = __LINE__ + 1;
	const int amount = insert("findMin ammount ", line);
	//in first time (for Comparison)
	line = __LINE__ + 1;
	int index = insert("findMin index ", line); // maybe problem here since it returns a const int
	double min = m_calculatorItems[index]->area();

	for (int i = 0; i < amount - 1; i++)
	{
		index = insert("findMin index ", line);
		min = m_calculatorItems[index]->area() < min ? m_calculatorItems[index]->area() : min;
	}
	cout << "The minimum area is:" << min << endl;
}

void Calculator::findMax() const
{
	int line = __LINE__ + 1;
	const int amount = insert("findMax ammount ", line);
	//Calculates the largest area of all selected shapes, return the index of the maxim
	double max = 0;
	for (int i = 0; i < amount; i++)
	{
		const int index = Utils::readInt(std::cin);
		max = m_calculatorItems[index]->area() > max ? m_calculatorItems[index]->area() : max;
	}
	cout << "The maximum area is:" << max << endl;
}



//the main function in this class, performs actions at user request
void Calculator::run()
{
	bool y = true;
	while (y)
		try
	{
		std::cout << "Hello, please enter max shapes:" << std::endl;
		std::string s;
		std::cin >> s;
		std::stringstream ss(s);
		ss.exceptions(ss.failbit);
		ss >> m_max_shapes;
		y = false;
	}
	catch (const std::exception& e) {
		std::cout << "\nThe value you inserted is not an integer number\n"
			<< "\nPlease try again\n" << std::endl;
	}

	while (true)
	{
		printItemList();
		string command;
		try { command = getUserCommand(); }
		catch (const InvalidArg& e)
		{
			cout << e.what() << "\n";
		}
		//exit from the calculator
		try {
			if (command == "read")
			{
				read();
			}
			else comm(command);
		}
		catch (const InvalidArg& e) { cout << e.what() << "\n"; }
		catch (const std::exception&) {}
	}
}

std::shared_ptr<CalculatorItem> Calculator::operator[](int index) const
{
	return m_calculatorItems.at(index);
}

//--------------------------------------------------------
//Prints a help screen with a list of possible commands and a brief explanation of it
void Calculator::help()
{
	cout << "Following is the list of the calculator's available commands" << endl
		<< "cre(ate) #shape <R - rectangle | T-triangle | C- circle>" << endl
		<< "area num - Computes the area of shape #num" << endl
		<< "per(imeter) num - Computes the perimeter of shape #num" << endl
		<< "draw num - Draw the shape" << endl
		<< "#num mul(tiply) num x - Creates an item that is the multiplication of shape #num x times" << endl
		<< "add num1 num2 - Creates an item that is the sum of item #num1 and function #num2" << endl
		<< "sub num1 num2 - Creates an item that is the subtraction of item #num1 and function #num2" << endl
		<< "min n #num1-#numN - Returns the smallest area in the chosen shapes. n - the requested shapes: #num1..." << endl
		<< "max n #num1-#numN - Returns the biggest area in the chosen shapes. n - the requested shapes: #num1..." << endl
		<< "same num - Returns shapes with which have the same area and perimeter to the shape #num" << endl
		<< "del(ete) num - Deletes item #num from function list" << endl
		<< "help - Prints this help screen" << endl
		<< "exit - Exits the program." << endl;
}
//--------------------------------------------------------
//Prints all indices of the shapes that are equal in their area and scope to the selected shape
void Calculator::same(int index) const
{
	const double area = m_calculatorItems[index]->area();
	const double perimeter = m_calculatorItems[index]->perimeter();

	for (auto i = 0; i < m_calculatorItems.size(); ++i)
	{
		if (m_calculatorItems[i]->area() == area
			&& m_calculatorItems[i]->perimeter() == perimeter
			&& i != index)
		{
			cout << i << ": ";
			m_calculatorItems[i]->printDetails();
			cout << endl;
		}
	}
	cout << endl;
}


//-----------------------------------------------------------
//create new shape rectangle/circle/triangle and insert to the list of the shapes (to the vector)
void Calculator::createShape()
{
	char shape;
	int line = __LINE__ + 1;
	cin >> shape;
	shape = toupper(shape);

	if (m_calculatorItems.size() == m_max_shapes)
	{
		std::string s = std::to_string(m_max_shapes);
		throw InvalidArg(std::string("Sorry, you exceeded the maximum of ").append(s).append(" shapes"));
		return;
	}
	if (shape == 'R')
	{
		m_calculatorItems.push_back(std::make_shared<Rectangle>(std::cin));
		return;
	}
	else if (shape == 'C')
	{
		m_calculatorItems.push_back(std::make_shared<Circle>(std::cin));
		return;
	}
	else if (shape == 'T')
	{
		m_calculatorItems.push_back(std::make_shared<Triangle>(std::cin));
		return;
	}
	std::string s(1, shape);
	throw InvalidArg(std::string("cre ").append(s), line);
}
//-----------------------------------------------------------
//print the list of the shapes that in the vector
void Calculator::printItemList() const
{
	std::cout << "\nYour Max Shapes is: " << m_max_shapes << std::endl;
	int i = 0;
	cout << "\nThis is the shapes list:" << endl;
	for (auto& item : m_calculatorItems)
	{
		cout << i++ << ": ";
		item->printDetails();
		cout << endl;
	}
}

const int Calculator::insert(std::string str, int line) const
{
	const int index = Utils::readInt(std::cin);
	if (index >= m_calculatorItems.size())
	{
		std::string i = std::to_string(index);
		throw InvalidArg(std::string(str).append(i), line);
	}
	return index;
}

void Calculator::read()
{
	std::ifstream f("read.txt");
	if (!f.good())
		throw InvalidArg("Error during open the file comm.txt");
	std::string str;
	char c = 'y';
	while (std::getline(f, str))
	{
		std::cout << str << std::endl;
		try { comm(str); }
		catch (const InvalidArg& e)
		{
			cout << e.what() << "\n";
			std::cout << "command not valid, press Y to continue or N to finnish reading from file\n";
			std::cin >> c;
		}
		catch (const std::exception&)
		{
			std::cout << "command not valid, press Y to continue or N to finnish reading from file\n";
			std::cin >> c;
		}
		if (c == 'n') break;
	}
}

void Calculator::resize()
{
	int temp;
	std::cin >> temp;
	while (temp < m_max_shapes)
	{
		std::cout << "Oh, I am sorry! Your new max is less than the oldest,"
			<< "please choose another number (press N) or we will delete " << m_max_shapes - temp
			<< " shapes from the end(press D) only in case you excedded the old max";
		char c;
		std::cin >> c;
		if (c == 'd')
		{
			int num_to_delete = m_max_shapes - temp;
			if (m_calculatorItems.size() > temp)
				for (int i = 0; (i < m_calculatorItems.size() && i < num_to_delete); i++)
					m_calculatorItems.erase(m_calculatorItems.begin() + (--m_max_shapes));
			break;
		}
		std::cin >> temp;
	}
	m_max_shapes = temp;
}