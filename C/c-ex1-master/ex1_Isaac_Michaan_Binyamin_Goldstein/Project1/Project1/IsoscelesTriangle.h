#pragma once
#include "Vertex.h"
#include "Utilities.h"
#include "Board.h"
#include "Rectangle.h"
#include <iostream>

class IsoscelesTriangle
{
private :
	//define three points of the IsoscelesTriangle
	Vertex m_first, m_second, m_third; 
	
	//Check if Vertexes are within the rules of an IsoscelesTriangle
		//otherwise change values to default
	bool validateVertex(Vertex&, Vertex&, Vertex&);

	//Receive Vertex, width and height and build a Triangle
	void buildTriangle(Vertex, double, double);

public:
	//User gives 3 Vertex points
	IsoscelesTriangle(const Vertex vertices[3]);	//Constructor
	
	//User gives only the center point in a IsoscelesTriangle the width and height than we build the other 2 points and check if it is within the rules of an IsoscelesTriangle
	IsoscelesTriangle(const Vertex& center, double width, double height);	// Constructor
	
	//Return Vertex of the searched index
	Vertex getVertex(int index) const;	// find Vertex[index]
	
	//Return Vertex of the searched index by reference
	Vertex& getVertexRef(int index);
	
	//Return Lenght
	double getLength() const;	// get Length

	//Return Sceles
	double getScelesLength() const; 	// get Sceles Length

	//Return Height
	double getHeight() const;	// get Height

	//Draw Triangle
	void draw(Board& board) const;	

	//Draw a Rectangle around the Triangle
	Rectangle getBoundingRectangle() const;

	//Return Area
	double getArea() const;		// get Area

	//Return Perimeter
	double getPerimeter() const;	// get Perimeter

	//Return Center
	Vertex getCenter() const;

	//Add Scale to original Triangle
	bool scale(double);

	//Function that helps the use of the scale
	bool scale(double, bool);
};