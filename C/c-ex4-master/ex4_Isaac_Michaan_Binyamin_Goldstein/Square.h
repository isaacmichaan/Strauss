#pragma once
#include <SFML/Graphics.hpp>

class Square
{
private:
	sf::RectangleShape board;
public:
	Square(const float, const float);
	~Square();
	sf::RectangleShape getSquare() const { return board; }
};

