#pragma once
#include <string>
//#include<stdlib.h>
//#include<stdio.h>
#include <sstream>

using std::string;

class Shape
{
public:
	Shape(string name) :m_name(std::move(name)) {}
	virtual const double getArea() = 0;
	virtual const double getPerimeter() = 0;
	virtual const string getDimensions() = 0;
	const string & getName()const { return m_name; }
	virtual double getHeight() const { return 0.0; }
	virtual double getWidth() const { return 0.0; }
	virtual void draw(double width, double height = 0) const {};
private:
	string m_name;
};

