#pragma once
#include "IsoscelesTriangle.h"
#include "Utilities.h"
#include "Board.h"

class Kite
{
private:
	//define three points of the IsoscelesTriangle
	IsoscelesTriangle m_triangle1;
	
    //define three points of the IsoscelesTriangle
	IsoscelesTriangle m_triangle2;
	
	//Checking if Vertexes are within the rules of an IsoscelesTriangle
		//otherwise change values to default
	bool validateVertex(Vertex&, Vertex&, Vertex&);
	
	//Check if both Triangles are equal
	bool compareTriangleVertex(IsoscelesTriangle, IsoscelesTriangle);

public:
	//Constructor that receives 2 triangles
	Kite(const IsoscelesTriangle triangles[2]);		//constructor
	
	//Constructor that receives 2 triangles
	Kite(const Vertex& top, double width, double topHeight, double bottomHeight);	//constructor
	
	//Return Height
	double getTotalHeight() const;		// get Height
	
	//Draw Kite
	void draw(Board& board) const;
	
	//Draw a Rectangle around the Triangle
	Rectangle getBoundingRectangle() const;

	//Return Area
	double getArea() const;//	get Area from both triangles
	
	//Return Perimeter
	double getPerimeter() const;	// get Perimeter
	
	//Return Center
	Vertex getCenter() const; // get Center
	
	//Add Scale to original Triangle
	bool scale(double);
	bool scale(double factor, IsoscelesTriangle & triangle, double x, double y);
};

