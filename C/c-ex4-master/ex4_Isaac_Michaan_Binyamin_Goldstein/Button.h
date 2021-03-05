#pragma once
#include <SFML/Graphics.hpp>

class Button
{
private:
	sf::RectangleShape m_button;
	sf::Texture texture;
public:
	Button(const std::string fileName, const float startX);
	~Button();
	Button * clone() const { return new Button(*this); }
	void setSize(sf::RectangleShape &, const float, const float);
	void setPosition(sf::RectangleShape &, const float, const float);
	void setTexture(sf::RectangleShape &, const std::string);
	sf::RectangleShape& getButtonByRef() { return m_button; }
	sf::RectangleShape getButton() const { return m_button; }
};