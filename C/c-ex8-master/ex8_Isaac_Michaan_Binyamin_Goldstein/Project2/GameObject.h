#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#define M 10
#define N 12
#define SIZE 50

class GameObject
{
public:
	GameObject();
	~GameObject();
	void buildMatrix(std::vector<std::vector<std::unique_ptr<GameObject>>>&);
	void buildPartofMatrix(std::vector<std::vector<std::unique_ptr<GameObject>>>&, int, int);
	virtual sf::Color getColor() const = 0;
	virtual void setColor(sf::Color) = 0;
	virtual sf::RectangleShape getShape() const = 0;
};

