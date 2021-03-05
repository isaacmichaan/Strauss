#include "Circle.h"
#include <iostream>

using std::cout;

//Circle::Circle()
//{
//}
//
//
//Circle::~Circle()
//{
//}


void Circle::draw(double width, double height) const
{
	height = width * 1.5;
	for (double y = width; y >= -width; y -= 2) {
		for (double x = -height; x <= height; x++) {

			if ((int)sqrt(pow(x, 2) + pow(y, 2)) == width) cout << "*";
			else cout << " ";

		}
		cout << "\n";
	}
}
