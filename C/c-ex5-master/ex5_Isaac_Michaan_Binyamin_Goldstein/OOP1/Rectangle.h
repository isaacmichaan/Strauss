#pragma once
#include <string>
#include <sstream>
#include "Shape.h"

class Rectangle : public Shape
{
public:
	Rectangle(double height = 0, double width = 0)
		:m_height(height), m_width(width), Shape("Rectangle")
	{}
	const double getArea()
	{
		return m_width * m_height;
	}
	const double getPerimeter()
	{
		return (2 * m_width + 2 * m_height);
	}
	const string getDimensions() {
		std::ostringstream oss;
		oss << "(" << m_height << "," << m_width << ")";
		return oss.str();
	}
	virtual double getHeight() const { return m_height; };
	virtual double getWidth() const { return m_width; };
	virtual void draw(double width, double height = 0) const;
private:
	double m_height;
	double m_width;
};

