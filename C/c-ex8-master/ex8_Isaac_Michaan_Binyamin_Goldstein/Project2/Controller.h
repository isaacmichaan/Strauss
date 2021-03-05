#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <queue>
class GameObject;

class Controller
{
private:
	int m_row = 10;
	int m_col = 12;
	int m_size = 50;
	const sf::Color colorArray[6] = { sf::Color::Cyan, sf::Color::Blue, sf::Color::Green, sf::Color::Red, sf::Color::Yellow, sf::Color::Magenta };
public:
	Controller();
	~Controller();
	void run();
	double floodFillArea(std::vector< std::vector<std::unique_ptr<GameObject> >>&, int, int, sf::Color);
	int floodFillCount(const std::vector< std::vector<std::unique_ptr<GameObject> >>&, int, int, sf::Color);
};

