#include "Kite.h"

Kite::Kite(const IsoscelesTriangle triangles[2])
	:m_triangle1(triangles[0]), m_triangle2(triangles[1])
{
	validateVertex(m_triangle2.getVertexRef(0), m_triangle2.getVertexRef(1), m_triangle2.getVertexRef(2)); //validate Vertex data from triangle2


	// check if first Vertex match third Vertex// check if first Vertex match second Vertex 
	if (!(m_triangle1.getVertex(0).isEqual(m_triangle2.getVertex(0))) || !(m_triangle1.getVertex(2).isEqual(m_triangle2.getVertex(2))) || compareTriangleVertex(m_triangle1, m_triangle2))

	{
		m_triangle1.getVertexRef(0) = { 20, 20 };
		m_triangle1.getVertexRef(1) = { 25, 25 };
		m_triangle1.getVertex(2) = { 20, 30 };

		m_triangle2.getVertexRef(0) = { 20, 20 };
		m_triangle2.getVertexRef(1) = { 25, 15 };
		m_triangle2.getVertexRef(2) = { 30, 20 };
	}
}


Kite::Kite(const Vertex & top, double width, double topHeight, double bottomHeight)
	:m_triangle1(top, width, topHeight), m_triangle2(top, width, bottomHeight)
{
	validateVertex(m_triangle2.getVertexRef(0), m_triangle2.getVertexRef(1), m_triangle2.getVertexRef(2)); //validate Vertex data from triangle2


	// check if first Vertex match third Vertex// check if first Vertex match second Vertex 
	if (!(m_triangle1.getVertex(0).isEqual(m_triangle2.getVertex(0))) || !(m_triangle1.getVertex(2).isEqual(m_triangle2.getVertex(2))) || compareTriangleVertex(m_triangle1, m_triangle2))

	{
		m_triangle1.getVertexRef(0) = { 20, 20 };
		m_triangle1.getVertexRef(1) = { 25, 25 };
		m_triangle1.getVertex(2) = { 20, 30 };

		m_triangle2.getVertexRef(0) = { 20, 20 };
		m_triangle2.getVertexRef(1) = { 25, 15 };
		m_triangle2.getVertexRef(2) = { 30, 20 };
	}
}


double Kite::getTotalHeight() const
{
	return (m_triangle1.getVertex(1).m_y - m_triangle2.getVertex(1).m_y);
}


bool Kite::validateVertex(Vertex & first, Vertex & second, Vertex & third)
{
	// check if Vertex is between 0 and MAX_X - 0 and MAX_Y 		                                                           
	if (!first.isValid() || !second.isValid() || !third.isValid())
	{
		first = { 20, 20 };
		second = { 25, 15 };
		third = { 30, 20 };
		return false;
	}

	//check:
	//a) m_first.m_x < m_third.m_x
	//b) m_first.m_y == m_third.m_y
	//c) m_second != m_first (check for m_x and m_y at the same time)
	//d) m_second != m_third (check for m_x and m_y at the same time)
	if (!third.isRighterThan(first) || !sameY(first, third) || second.isEqual(first) || second.isEqual(third))
	{
		first = { 20, 20 };
		second = { 25, 15 };
		third = { 30, 20 };
		return false;
	}

	//check if both sides (from m_first --> m_second and from m_third --> m_second) has the same Sceles
	if (!(doubleEqual(distance(first, second), distance(third, second))))
	{
		first = { 20, 20 };
		second = { 25, 15 };
		third = { 30, 20 };
		return false;
	}
	return true;
}


bool Kite::compareTriangleVertex(IsoscelesTriangle triangle1, IsoscelesTriangle triangle2)
{
	if (triangle1.getVertex(0).isEqual(triangle2.getVertex(0)) && triangle1.getVertex(1).isEqual(triangle2.getVertex(1)) && triangle1.getVertex(2).isEqual(triangle2.getVertex(2)))
		return true;
	return false;
}


void Kite::draw(Board & board) const
{
	m_triangle1.draw(board);
	m_triangle2.draw(board);
}

Rectangle Kite::getBoundingRectangle() const
{
	return { {m_triangle1.getVertex(0).m_x, m_triangle2.getVertex(1).m_y}, {m_triangle2.getVertex(2).m_x,m_triangle1.getVertex(1).m_y} };
}


double Kite::getArea() const
{
	return (m_triangle1.getArea() + m_triangle2.getArea());
}


double Kite::getPerimeter() const
{
	return (m_triangle1.getPerimeter() + m_triangle2.getPerimeter());
}


Vertex Kite::getCenter() const
{
	return { (m_triangle1.getVertex(2).m_x) / 2, m_triangle1.getVertex(2).m_y  };
}


bool Kite::scale(double factor)
{
	
	std::cout << std::endl;
	double x = getCenter().m_x;
	double y = getCenter().m_y;

	bool xx = scale(factor, m_triangle1, x, y);
	bool yy = scale(factor, m_triangle2, x, y);
	std::cout << std::endl;

	return xx + yy;
}

bool Kite::scale(double factor, IsoscelesTriangle & triangle, double x, double y)
{
	//define three test points of the IsoscelesTriangle
	Vertex m_first_test = { ((triangle.getVertex(0).m_x - x) * factor) + x, ((triangle.getVertex(0).m_y - y) * factor) + y };
	Vertex m_second_test = { ((triangle.getVertex(1).m_x - x) * factor) + x, ((triangle.getVertex(1).m_y - y) * factor) + y };
	Vertex m_third_test = { ((triangle.getVertex(2).m_x - x) * factor) + x, ((triangle.getVertex(2).m_y - y) * factor) + y };

	if (validateVertex(m_first_test, m_second_test, m_third_test))
	{
		triangle.getVertexRef(0) = m_first_test;

		triangle.getVertexRef(1) = m_second_test;

		triangle.getVertexRef(2) = m_third_test;
		return true;
	}
	return false;
}