#pragma once
#include <SFML/Graphics.hpp>
#include "Global.h"
#include "Button.h"
#include "Square.h"

class Board
{
private:
	sf::RectangleShape m_board;
public:
	Board();
	~Board();
	sf::RectangleShape getBoard();
	char checkButton(std::vector <Button* >, sf::Event);
	void switchButton(char, std::vector <Button* > &, std::vector <Button* >, std::vector <std::vector <char>> & vec, int i, int j);
	void insertButton(char, sf::RectangleShape, std::vector <std::vector <Square*>>, std::vector <std::vector <bool>> &,
	std::vector <std::vector <Node>>, std::vector <Button* > &, std::vector <Button* >, sf::Event, int &, std::vector <std::vector <char>> &);
};

