#include "Controller.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
#include "Add.h"
#include "Sub.h"
#include "Multiple.h"
#include <iostream>
#include <string>
#include <algorithm>

using std::string;
using std::cout;
using std::cin;

Controller::Controller()
{
}


Controller::~Controller()
{
}

void Controller::run()
{
	std::vector<std::shared_ptr<Shape>> v;
	//v.push_back(std::make_shared<Circle>());
	//v.push_back(std::make_shared<Rectangle>());
	//v.push_back(std::make_shared<Triangle>());
	string command;
	do
	{
		int i = 0;
		cout << "This is the shapes list:\n";
		for (auto &e : v)
		{
			cout << i++ << ": " << e->getName() << " (" << e->getDimensions() << ")\n";
		}
		cout << "\n" << "Please enter a command ('help' for command list):\n";

		if (getline(std::cin, command))		
		//std::transform(command.begin(), command.end(), command.begin(), ::toupper);
		if (command == "help")
		{
			cout << "\n" << R"(Following is the list of the calculator's available commands:
cre(ate) #shape <R - rectangle | T-triangle | C- circle>
area num - Computes the area of shape #num
per(imeter) num - Computes the perimeter of shape #num
draw num - Draw the shape #num
mul(tiply) num x - Creates a function that is the multiplication
of shape #num x times
add num1 num2 - Creates a function that is the sum of function
#num1 and function #num2
sub num1 num2 - Creates a function that is the subtraction of
function #num1 and function #num2
min n #num1-#numN - Returns the smallest area in the chosen
shapes. n - the requested shapes: #num1...
max n #num1-#numN - Returns the biggest area in the chosen shapes.
n - the requested shapes: #num1...
same num - Returns shapes with which have the same area and
perimeter to the shape #num
del(ete) num - Deletes function #num from function list
help - Prints this help screen
exit - Exits the program)";
		}
		if (command == "cre r")
		{
			double h, w;
			cout << "Enter height then width\n";
			cin >> h >> w;
			v.push_back(std::make_shared<Rectangle>(h, w));
		}
		if (command == "cre t")
		{
			double h, w;
			cout << "Enter height then width\n";
			cin >> h >> w;
			v.push_back(std::make_shared<Triangle>(h, w));
		}
		if (command == "cre c")
		{
			double r;
			cout << "Enter raduis\n";
			cin >> r;
			v.push_back(std::make_shared<Circle>(r));
		}
		if (command == "area")
		{
			int num;
			cin >> num;
			cout << v[num]->getName() << " (" << v[num]->getDimensions() << ") = " << v[num]->getArea() << "\n";
		}
		if (command == "per")
		{
			int num;
			cin >> num;
			cout << v[num]->getName() << " (" << v[num]->getDimensions() << ") = " << v[num]->getPerimeter() << "\n";
		}
		if (command == "draw")
		{
			int num;
			cin >> num;
			cout << v[num]->getName() << " (" << v[num]->getDimensions() << ")\n"; 
			v[num]->draw(v[num]->getHeight(), v[num]->getWidth());
			cout << "\n";
		}
		if (command == "max")
		{
			int n;
			cin >> n;
			int i = 0, j;
			double max = v[0]->getArea();
			for (auto &e : v)
			{
				if (e->getArea() > max && i < n)
				{
					max = e->getArea();
					j = i;
				}
				i++;
			}
			cout << v[j]->getName() << " (" << v[j]->getDimensions() << ") = " << v[j]->getArea() << "\n";
		}
		if (command == "min")
		{
			int n;
			cin >> n;
			int i = 0, j;
			double min = v[0]->getArea();
			for (auto &e : v)
			{
				if (e->getArea() < min && i < n)
				{
					min = e->getArea();
					j = i;
				}
				i++;
			}
			cout << v[j]->getName() << " (" << v[j]->getDimensions() << ") = " << v[j]->getArea() << "\n";
		}
		if (command == "add")
		{
			int arg1, arg2;
			cout << "Enter indexes of two shapes\n";
			cin >> arg1 >> arg2;
			v.push_back(std::make_shared<Add>(v[arg1], v[arg2]));
		}
		if (command == "sub")
		{
			int arg1, arg2;
			cout << "Enter indexes of two shapes\n";
			cin >> arg1 >> arg2;
			v.push_back(std::make_shared<Sub>(v[arg1], v[arg2]));
		}
		if (command == "mul")
		{
			int arg1, arg2;
			cout << "Enter indexes of shape and mun to mul\n";
			cin >> arg1 >> arg2;
			v.push_back(std::make_shared<Multiple>(v[arg1], arg2));
		}
		if (command == "del")
		{
			int index;
			cout << "Enter the number of the shape from the list:\n";
			cin >> index;
			v.erase(v.begin() + index);
		}
		

	} while (command != "exit");
}
