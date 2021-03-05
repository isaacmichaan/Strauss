#pragma once
#include "GameObject.h"

class Convex : public GameObject
{
public:
	Convex();
	~Convex();
	virtual sf::Color getColor() const = 0;
	virtual void setColor(sf::Color) = 0;
	virtual sf::RectangleShape getShape() const = 0;
};

