#include "Triangle.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

//Triangle::Triangle()
//{
//}
//
//
//Triangle::~Triangle()
//{
//}

void Triangle::draw(double width, double height) const
{
	int i, j, k;
	cout << "Please enter number of rows you want to see: \n";
	
	for (k = 1; k <= width; k++)
	{
		for (j = 1; j <= width - k; j++)
			cout << ' ';
		for (i = 1; i <= 2 * k - 1; i++)
		{
			if (i == 1 || i == 2 * k - 1 || k == width)
				cout << '*';
			else
				cout << ' ';
		}
		cout << endl;
	}
}
