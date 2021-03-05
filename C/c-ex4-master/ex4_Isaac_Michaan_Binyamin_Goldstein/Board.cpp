#include "Board.h"

Board::Board()
{
	m_board.setSize(sf::Vector2f(400, 400));
	m_board.setPosition(100, 100);
}


Board::~Board()
{
}


sf::RectangleShape Board::getBoard()
{
	return m_board;
}


char Board::checkButton(std::vector <Button* > button, sf::Event event)
{
	if (button[ROBOT]->getButton().getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) return '1';

	if (button[GUARD]->getButton().getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) return '2';

	if (button[STAR]->getButton().getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) return '3';

	if (button[BLOCK]->getButton().getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) return '4';

	return '0';
}


void Board::insertButton(char c, sf::RectangleShape board, std::vector <std::vector <Square*>> square, std::vector <std::vector <bool>> & boolean,
	std::vector <std::vector <Node>> positions, std::vector <Button* > & shapes, std::vector <Button* > button, sf::Event event, int & count,
	std::vector <std::vector <char>> & vec)
{
	if (board.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
	{
		if (c != '0')
			for (int i = 0; i < BOARD_SIZE; i++)
				for (int j = 0; j < BOARD_SIZE; j++)
					if (boolean[i][j] && square[i][j]->getSquare().getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
					{
						boolean[i][j] = false;
						switchButton(c, shapes, button, vec, i, j);
						count++;
						shapes[count - 1]->getButtonByRef().setPosition(positions[i][j].x, positions[i][j].y);
					}
	}
}


void Board::switchButton(char c, std::vector <Button* > & shapes, std::vector <Button* > button, std::vector <std::vector <char>> & vec, int i, int j)
{
	switch (c)
	{
	case '1':
	{
		shapes.push_back(button[ROBOT]->clone());
		vec[i][j] = '/';
		break;
	}
	case '2':
	{
		shapes.push_back(button[GUARD]->clone());
		vec[i][j] = '!';
		break;
	}
	case '3':
	{
		shapes.push_back(button[STAR]->clone());
		vec[i][j] = '@';
		break;
	}
	case '4':
	{
		shapes.push_back(button[BLOCK]->clone());
		vec[i][j] = '#';
		break;
	}
	}
}