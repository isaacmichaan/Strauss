#include "Square.h"
#include "Global.h"

Square::Square(const float startX, const float startY)
{
	board.setSize(sf::Vector2f(SIZE_X, SIZE_Y));
	board.setPosition(startX, startY);
}


Square::~Square()
{
}
