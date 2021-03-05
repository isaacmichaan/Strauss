#include "House.h"

House::House(const Rectangle & rectangle, const IsoscelesTriangle & triangle)
	:m_rectangle(rectangle), m_triangle(triangle)
{
	if (!(m_rectangle.getTopRight().m_x == m_triangle.getVertexRef(2).m_x)
		&& !(m_rectangle.getTopRight().m_y == m_triangle.getVertexRef(2).m_y))
	{
		m_rectangle.getBottomLeftRef() = { 20, 10 };
		m_rectangle.getTopRightRef() = { 30, 20 };
		m_triangle.getVertexRef(0) = { 20,20 };
		m_triangle.getVertexRef(1) = { 25, 25 };
		m_triangle.getVertexRef(2) = { 30,20 };
	}
}

House::House(const Vertex & roofTop, double width, double roofHeight, double baseHeight)
	:m_rectangle(roofTop, width, baseHeight), m_triangle(roofTop, width, roofHeight)
{}

bool House::estendRoof(double width)
{
	if (!(width >= 0) || !(width <= 50) || (m_triangle.getLength() > width))
	{
		return false;
	}
	else
	{
		m_triangle.getVertexRef(1).m_x = m_triangle.getVertexRef(1).m_x - width / 2;
		m_triangle.getVertexRef(2).m_y = m_triangle.getVertexRef(2).m_y + width / 2;
		m_triangle.getVertexRef(3).m_x = m_triangle.getVertexRef(3).m_x + width / 2;
		return true;
	}
}

double House::getHeight() const
{
	Vertex middleRectangle = { m_rectangle.getBottomLeft().m_x + (m_rectangle.getBottomLeft().m_x / 2), m_rectangle.getBottomLeft().m_y };
	return (distance(middleRectangle, m_triangle.getVertex(1)));
}


double House::getWidthDifference() const
{
	double x;
	if (x = distance({ m_rectangle.getBottomLeft().m_x,m_rectangle.getTopRight().m_y }, m_rectangle.getTopRight()) - distance({ m_rectangle.getTopRight().m_x,m_rectangle.getBottomLeft().m_y }, m_rectangle.getBottomLeft()) < 0)
		return	x = -x;
	return x;
}


void House::draw(Board & board) const
{
	m_rectangle.draw(board);
	m_triangle.draw(board);
}


Rectangle House::getBoundingRectangle() const
{
	return { m_rectangle.getBottomLeft() , {m_triangle.getVertex(2).m_x, m_triangle.getVertex(1).m_y} };
}


double House::getArea() const
{
	return (m_rectangle.getArea() + m_triangle.getArea());
}


double House::getPerimeter() const
{
	return (m_rectangle.getPerimeter() + (m_triangle.getScelesLength() * 2));
}


Vertex House::getCenter() const
{
	Vertex middleRectangle = { m_triangle.getVertex(1).m_x,  m_triangle.getVertex(0).m_y };
	return middleRectangle;
}



bool House::scale(double factor)
{
	Vertex leftB, rightT, vertex1, vertex2, vertex3;
	leftB = { getCenter().m_x - (m_rectangle.getTopRight().m_x - getCenter().m_x) * factor ,getCenter().m_y + ((m_rectangle.getBottomLeft().m_y - getCenter().m_y) * factor) };
	rightT = { getCenter().m_x + (m_rectangle.getTopRight().m_x - getCenter().m_x) * factor,getCenter().m_y };
	vertex1 = { getCenter().m_x - (m_triangle.getVertex(2).m_x - getCenter().m_x) * factor,  getCenter().m_y };
	vertex3 = { getCenter().m_x + (m_triangle.getVertex(2).m_x - getCenter().m_x) * factor, getCenter().m_y };
	vertex2 = { getCenter().m_x, getCenter().m_y + ((m_triangle.getVertex(1).m_y - getCenter().m_y) * factor) };
	if (leftB.isValid() && rightT.isValid() && vertex1.isValid() && vertex2.isValid() && vertex3.isValid())
	{
		Rectangle rec(leftB, rightT);
		Vertex tri[3] = { vertex1, vertex2, vertex3 };
		m_rectangle = rec;
		m_triangle = tri;
		return true;
	}
	return false;
}


