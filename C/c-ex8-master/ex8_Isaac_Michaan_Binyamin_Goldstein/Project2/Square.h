#pragma once
#include "GameObject.h"

class Square : public GameObject
{
private:
	const sf::Color colorArray[6] = { sf::Color::Cyan, sf::Color::Blue, sf::Color::Green, sf::Color::Red, sf::Color::Yellow, sf::Color::Magenta };
	sf::RectangleShape square;
public:
	Square(float x, float y);
	~Square();
	virtual sf::Color getColor() const { return square.getFillColor(); }
	virtual void setColor(sf::Color c) { square.setFillColor(c); }
	virtual sf::RectangleShape getShape() const { return square; }
};

