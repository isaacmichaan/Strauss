#include "Rectangle.h"
#include "Vertex.h"
#include "Board.h"
#include "Utilities.h"
#include <iostream>
using namespace std;

Rectangle::Rectangle(const Vertex& bottomLeft, const Vertex& topRight)
	:m_bottomLeft(bottomLeft), m_topRight(topRight)
{
	validateVertex(m_bottomLeft, m_topRight);
}


Rectangle::Rectangle(const Vertex vertices[2])
	:Rectangle(vertices[0], vertices[1])
{}


Rectangle::Rectangle(double x0, double y0, double x1, double y1)
	: Rectangle({ x0, y0 }, { x1,y1 })
{}


Rectangle::Rectangle(const Vertex& start, double width, double height)
	: Rectangle(start, { start.m_x + width, start.m_y + height })
{}


Vertex Rectangle::getBottomLeft() const
{
	return m_bottomLeft;
}

Vertex & Rectangle::getBottomLeftRef()
{
	return m_bottomLeft;
}


Vertex Rectangle::getTopRight() const
{
	return m_topRight;
}

Vertex & Rectangle::getTopRightRef()
{
	return m_topRight;
}


Vertex Rectangle::getTopLeft() const
{
	return { m_bottomLeft.m_x, m_topRight.m_y };
}


Vertex Rectangle::getBottomRight() const
{
	return { m_topRight.m_x, m_bottomLeft.m_y };
}


double Rectangle::getWidth() const
{
	return distance(m_bottomLeft, m_topRight);
}


double Rectangle::getHeight() const
{
	return distance(m_bottomLeft, { m_bottomLeft.m_x, m_topRight.m_y });
}


double Rectangle::getPerimeter() const
{
	double length = getHeight();
	double width = getWidth();
	double perimeter = (2 * length) + (2 * width);

	return perimeter;
}


double Rectangle::getArea() const
{
	return  (getHeight()*getWidth());
}


Vertex Rectangle::getCenter() const
{
	double newX = (m_bottomLeft.m_x + m_topRight.m_x) / 2;
	double newY = (m_bottomLeft.m_y + m_topRight.m_y) / 2;

	return Vertex{ newX,newY };
}


bool Rectangle::scale(double factor)
{
	Vertex left, right;
	left = { ((m_bottomLeft.m_x - getCenter().m_x) * factor) + getCenter().m_x, ((m_bottomLeft.m_y - getCenter().m_y) * factor) + getCenter().m_y };
	right = { ((m_topRight.m_x - getCenter().m_x) * factor) + getCenter().m_x, ((m_topRight.m_y - getCenter().m_y) * factor) + getCenter().m_y };

	if (validateVertex(left, right))
	{
		m_bottomLeft = left;
		m_topRight = right;
		return true;
	}
	return false;
}


bool Rectangle::validateVertex(Vertex bottomLeft, Vertex topRight)
{
	if (!bottomLeft.isValid() || !topRight.isValid())
	{
		m_bottomLeft = { 20 ,10 };
		m_topRight = { 30 ,10 };
		return false;
	}

	if (!topRight.isHigherThan(bottomLeft) || !topRight.isRighterThan(bottomLeft))
	{
		m_bottomLeft = { 20 ,10 };
		m_topRight = { 30 ,20 };
		return false;
	}
	return true;
}


void Rectangle::draw(Board & board) const
{
	board.drawLine(m_bottomLeft, getTopLeft());
	board.drawLine(m_bottomLeft, getBottomRight());
	board.drawLine(m_topRight, getTopLeft());
	board.drawLine(m_topRight, getBottomRight());
}


Rectangle Rectangle::getBoundingRectangle() const
{
	return { m_bottomLeft , m_topRight };
}




