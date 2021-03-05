#include <SFML/Graphics.hpp>
#include <iostream>
#include "Board.h"
#include "Global.h"
#include "Button.h"
#include "Square.h"


void menu(std::vector <Button* > & button)
{
	button.push_back(new Button("robot.jpg", 0));
	button.push_back(new Button("guard.jpg", 50));
	button.push_back(new Button("rock.jpg", 100));
	button.push_back(new Button("#.jpg", 150));
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 800), "Bomberman");
	Board board;
	
	std::vector <std::vector <Square*>> square;
	square.resize(BOARD_SIZE);

	std::vector <std::vector <bool>> boolean;
	boolean.resize(BOARD_SIZE);

	std::vector <std::vector <Node>> positions;
	positions.resize(BOARD_SIZE);

	std::vector <std::vector <char>> vec;
	vec.resize(BOARD_SIZE);

	for (int i = 0; i < BOARD_SIZE; ++i)
	{
		square[i].resize(BOARD_SIZE);
		boolean[i].resize(BOARD_SIZE);
		positions[i].resize(BOARD_SIZE);
		vec[i].resize(BOARD_SIZE);
	}

	for (float i = 0, x = 0, y = 0; i < BOARD_SIZE; i++, x = 0, y += 50)
	{
		for (float j = 0; j < BOARD_SIZE; j++, x += 50)
		{
			square[i][j] = new Square(100 + x, 100 + y);
			boolean[i][j] = true;
			positions[i][j].x = (100 + x);
			positions[i][j].y = (100 + y);
			vec[i][j] = ' ';
		}
	}

	std::vector <Button* > button;
	menu(button);
	std::vector <Button*> shapes;
	
	int count = 0;
	char c = '0';

	while (window.isOpen())
	{ 
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
				case sf::Event::Closed :
				{
					window.close();
					break;
				}
				
				case sf::Event::MouseButtonPressed :
				{
					if (!board.getBoard().getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) c = board.checkButton(button, event);
					board.insertButton(c, board.getBoard(), square, boolean, positions, shapes, button, event, count, vec);
					break;
				}
			}
		}

		window.clear(sf::Color::Green);
		for (int i = 0; i < BOARD_SIZE; i++)
			for (int j = 0; j < BOARD_SIZE; j++)
		window.draw(square[i][j]->getSquare());
		window.draw(button[ROBOT]->getButton());
		window.draw(button[GUARD]->getButton());
		window.draw(button[STAR]->getButton());
		window.draw(button[BLOCK]->getButton());
		for (int i = 0; i < count; i++)
			window.draw(shapes[i]->getButton());
		window.display();
	}

	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
			std::cout << vec[i][j];
		std::cout << std::endl;
	}
	int a; std::cin >> a;
}