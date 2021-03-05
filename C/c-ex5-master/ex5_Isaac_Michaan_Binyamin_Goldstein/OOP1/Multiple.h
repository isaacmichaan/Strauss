#pragma once
#include "Shape.h"

class Multiple : public Shape
{
public:
	Multiple(std::shared_ptr<Shape> s1, unsigned int x /*std::shared_ptr<Shape> s2*/) :
		m_s1(s1), /*m_s2(s2)*/x(x),
		Shape(string("Multiple ("+s1->getName()+" * "+std::to_string(x)+")"))
	{}
	const double getArea()
	{
		return m_s1->getArea() * x/*m_s2->getArea()*/;
	}
	const double getPerimeter()
	{
		return m_s1->getPerimeter() * x/*m_s2->getPerimeter()*/;
	}
	const string getDimensions() {
		std::ostringstream oss;
		oss << m_s1->getDimensions() /*<< " - " << m_s2->getDimensions()*/;
		return oss.str();
	}
	virtual void draw(double width, double height = 0) const 
	{ 
		m_s1->draw(m_s1->getHeight(), m_s1->getWidth());
		//m_s2->draw(m_s2->getHeight(), m_s2->getWidth());
	}
private:
	std::shared_ptr<Shape> m_s1;
	//std::shared_ptr<Shape> m_s2;
	unsigned int x;
};

