#pragma once
#include "Rectangle.h"
#include "IsoscelesTriangle.h"


class House
{
private:
	Rectangle m_rectangle;
	IsoscelesTriangle m_triangle;
	

public:
	//2 constractor to biuld the House
	House(const Rectangle& rectangle, const IsoscelesTriangle& triangle);
	House(const Vertex& roofTop, double width, double roofHeight, double baseHeight);
	// if the roof is legeal && big from the Rectangle it's will change it 
	bool estendRoof(double width);
	// retrun the hight of the House
	double getHeight() const;
	// retrun the diffrene wight of the Rectangle and Triengle
	double getWidthDifference() const;
	// drow the House on the board
	void draw(Board & board) const;
	// retrun the bonding of the Rectnagle for the House
	Rectangle getBoundingRectangle() const;
	// retrun the area of the Rectnagle
	double getArea() const;
	// retrun the primer of the Rectnagle
	double getPerimeter() const;
	// retrun the center of the Rectnagle
	Vertex getCenter() const;
	// retrun double size of the House
	bool scale(double factor);
	
};

