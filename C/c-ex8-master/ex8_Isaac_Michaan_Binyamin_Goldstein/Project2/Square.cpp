#include "Square.h"



Square::Square(float x, float y)
{
	square.setSize(sf::Vector2f(SIZE, SIZE));
	square.setRotation(45);
	square.setFillColor(colorArray[rand() % 6]);
	square.setPosition(sf::Vector2f(x, y));
}


Square::~Square()
{
}
