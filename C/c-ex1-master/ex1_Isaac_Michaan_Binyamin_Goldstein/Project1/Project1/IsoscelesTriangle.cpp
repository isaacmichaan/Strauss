#include "IsoscelesTriangle.h"

IsoscelesTriangle::IsoscelesTriangle(const Vertex vertices[3])
	:m_first(vertices[0]), m_second(vertices[1]), m_third(vertices[2])
{
	validateVertex(m_first, m_second, m_third);
}


IsoscelesTriangle::IsoscelesTriangle(const Vertex& center, double width, double height)	:m_second(center)
{
	m_first.m_x = (m_second.m_x - (width / 2));
	m_first.m_y = m_second.m_y - height;

	m_third.m_x = (m_second.m_x + (width / 2));
	m_third.m_y = m_second.m_y - height;

	validateVertex(m_first, m_second, m_third);
}


Vertex IsoscelesTriangle::getVertex(int index) const
{
	if (index == 0)
		return m_first;

	if (index == 1)
		return m_second;

	return m_third;
}


Vertex& IsoscelesTriangle::getVertexRef(int index)
{
	if (index == 0)
		return m_first;

	if (index == 1)
		return m_second;

	return m_third;
}


double IsoscelesTriangle::getLength() const
{
	return (m_third.m_x - m_first.m_x);
}


double IsoscelesTriangle::getScelesLength() const
{
	return distance(m_second, m_first);
}


double IsoscelesTriangle::getHeight() const
{
	return (m_second.m_y - m_first.m_y);
}


bool IsoscelesTriangle::validateVertex(Vertex & first, Vertex & second, Vertex & third)
{
	// check if Vertex is between 0 and MAX_X - 0 and MAX_Y 		                                                           
	if (!first.isValid() || !second.isValid() || !third.isValid())
	{
		first = { 20, 20 };
		second = { 25, 25 };
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
		second = { 25, 25};
		third = { 30, 20 };
		return false;
	}

	//check if both sides (from m_first --> m_second and from m_third --> m_second) has the same Sceles
	if (!(doubleEqual(distance(first, second), distance(third, second))))
	{
		first = { 20, 20 };
		second = { 25, 25 };
		third = { 30, 20 };
		return false;
	}
	return true;
}


void IsoscelesTriangle::buildTriangle(Vertex center, double width, double height)
{
	m_second = center;	m_first.m_x = (m_second.m_x - (width / 2));	m_first.m_x = m_second.m_y - height;	m_third.m_x = (m_second.m_x + (width / 2));	m_first.m_y = m_second.m_y - height;	validateVertex(m_first, m_second, m_third);
}


void IsoscelesTriangle::draw(Board & board) const
{
	board.drawLine(m_first, m_third);
	board.drawLine(m_first, m_second);
	board.drawLine(m_third, m_second);
}

Rectangle IsoscelesTriangle::getBoundingRectangle() const
{
	return { m_first, {m_third.m_x,m_second.m_y} };
}

double IsoscelesTriangle::getArea() const
{
	return std::sqrt((std::pow(getHeight(), 2)) + ((std::pow(getLength(), 2)) / 4));
}


double IsoscelesTriangle::getPerimeter() const
{
	return (2 * getScelesLength() + getLength());
}

Vertex IsoscelesTriangle::getCenter() const
{
	return { (m_first.m_x + m_second.m_x + m_third.m_x) / 3 , (m_first.m_y + m_second.m_y + m_third.m_y) / 3 };
}

bool IsoscelesTriangle::scale(double factor)
{
	//define three test points of the IsoscelesTriangle
	Vertex m_first_test = { ((m_first.m_x - getCenter().m_x) * factor) + getCenter().m_x, ((m_first.m_y - getCenter().m_y) * factor) + getCenter().m_y };
	Vertex m_second_test = { ((m_second.m_x - getCenter().m_x) * factor) + getCenter().m_x, ((m_second.m_y - getCenter().m_y) * factor) + getCenter().m_y };
	Vertex m_third_test = { ((m_third.m_x - getCenter().m_x) * factor) + getCenter().m_x, ((m_third.m_y - getCenter().m_y) * factor) + getCenter().m_y };

	if (validateVertex(m_first_test, m_second_test, m_third_test))
	{
		m_first = m_first_test;

		m_second = m_second_test;

		m_third = m_third_test;
		return true;
	}
	return false;
}
