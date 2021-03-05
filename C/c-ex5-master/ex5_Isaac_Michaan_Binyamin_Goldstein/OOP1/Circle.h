#pragma once
#include <string>
#include <sstream>
#include "Shape.h"

class Circle : public Shape
{
public:
	Circle(double raduis = 0)
		:m_raduis(raduis), Shape("Circle")
	{}
	const double getArea()
	{
		return m_raduis * 3.14;
	}
	const double getPerimeter()
	{
		return (2 * m_raduis * 3.14);
	}
	const string getDimensions() {
		std::ostringstream oss;
		oss << m_raduis;
		return oss.str();
	}
	virtual double getHeight() const { return m_raduis; };
	virtual double getWidth() const { return 0.0; };
	virtual void draw(double width, double height = 0) const;
private:
	double m_raduis;
};

