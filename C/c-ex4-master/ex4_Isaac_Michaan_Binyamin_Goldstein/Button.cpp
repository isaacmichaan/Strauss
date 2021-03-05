#include "Button.h"
#include "Global.h"


Button::Button(const std::string fileName, const float startX)
{
	setSize(m_button, SIZE_X, SIZE_Y);
	setPosition(m_button, startX, 0);
	setTexture(m_button, fileName);
}


Button::~Button()
{
}


void Button::setSize(sf::RectangleShape & button, const float startX, const float startY)
{
	button.setSize(sf::Vector2f(startX, startY));
}


void Button::setPosition(sf::RectangleShape & button, const float startX, const float startY)
{
	button.setPosition(startX, startY);
}


void Button::setTexture(sf::RectangleShape & button, const std::string fileName)
{
	if (texture.loadFromFile(fileName, sf::IntRect(0, 0, 0, 0)))
		button.setTexture(&texture);
}