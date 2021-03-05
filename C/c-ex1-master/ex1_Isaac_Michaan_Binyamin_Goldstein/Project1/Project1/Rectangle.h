#pragma once
#include "Vertex.h"
#include "Board.h"
#include "Utilities.h"

class Rectangle
{
private:
	Vertex m_bottomLeft, m_topRight;
	// return the Top-left of the Rectangle
	Vertex getTopLeft() const;
	// return the Bottom-right of the Rectangle
	Vertex getBottomRight() const;
	//retrun bool if the vertex is on the scope
	bool validateVertex(Vertex, Vertex);


public:
	//4 constractor to biuld the Rectangle
	Rectangle(const Vertex&, const Vertex&);
	Rectangle(const Vertex vertices[2]);
	Rectangle(double, double, double, double);
	Rectangle(const Vertex&, double, double);
	// return the Bottom-left of the Rectangle
	Vertex getBottomLeft() const;
	Vertex& getBottomLeftRef();
	// return the Top-Right of the Rectangle
	Vertex getTopRight() const;
	Vertex& getTopRightRef();
	// retrun the widdth of the Rectnagle
	double getWidth() const;
	// retrun the higet of the Rectnagle
	double getHeight() const;
	// drow the Rectnagle on the board
	void draw(Board&) const;
	Rectangle getBoundingRectangle() const;
	// retrun the area of the Rectnagle
	double getArea() const;
	// retrun the perimeter of the Rectnagle
	double getPerimeter() const;
	// retrun the center of the Rectnagle
	Vertex getCenter() const;
	// retrun double size of the Rectnagle
	bool scale(double);
};

