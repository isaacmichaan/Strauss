#include "Rectangle.h"
#include <iostream>

using std::cout;

//Rectangle::Rectangle()
//{
//}
//
//
//Rectangle::~Rectangle()
//{
//}

void Rectangle::draw(double width, double height) const
{
	cout << "*";
	for (int i = 0; i < width - 2; i++)
	{
		cout << "*";
	}
	cout << "*\n";

	for (int i = 0; i < height - 2; i++)
	{
		cout << "*";
		for (int j = 0; j < width - 2; j++)
		{
			cout << " ";
		}
		cout << "*\n";
	}

	cout << "*";
	for (int i = 0; i < width - 2; i++)
	{
		cout << "*";
	}
	cout << "*\n";
}
