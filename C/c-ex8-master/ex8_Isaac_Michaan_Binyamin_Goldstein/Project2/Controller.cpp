#include "Controller.h"
#include "GameObject.h"


Controller::Controller()
{
}


Controller::~Controller()
{
}


void Controller::run()
{
	sf::RenderWindow window(sf::VideoMode(1000, 900), "SFML works!");

	std::vector <sf::RectangleShape> colors;
	colors.resize(6);

	sf::RectangleShape rectangle;
	rectangle.setSize(sf::Vector2f(m_size, m_size));

	int x = 250, y = 0, k = 0;
	for (auto& col : colors)
	{
		col = rectangle;
		col.setFillColor(colorArray[k++]);
		col.setPosition(sf::Vector2f((x += m_size), y));
	}

	std::vector< std::vector<std::unique_ptr<GameObject> >> matrix;

	std::unique_ptr<GameObject> g;
	g->buildMatrix(matrix);

	sf::Color c = colorArray[rand() % 6];
	bool in = false;
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::MouseButtonPressed)
				for (int i = 0; i < 6; i++)
					if (colors[i].getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
					{
						c = colors[i].getFillColor();
						in = true;
					}
		}

		if (in)
		{
			floodFillArea(matrix, (m_row + m_row) - 1, 0, c);
			int times, x = 0;
			for (int i = 0; i < 6; i++)
			{
				times = floodFillCount(matrix, 0, m_col - 1, colorArray[i]);
				if (times > x)
				{
					x = times;
					c = colorArray[i];
					
				}
			}
			floodFillArea(matrix, 0, m_col - 1, c);
			in = false;
		}

		window.clear(sf::Color(245, 245, 220));
		for (auto& col : colors)
			window.draw(col);
		for (int i = 0; i < m_row + m_row; i++)
			for (int j = 0; j < m_col; j++)
				window.draw(matrix[i][j]->getShape());
		window.display();
	}
}

double Controller::floodFillArea(std::vector< std::vector<std::unique_ptr<GameObject> >>& image, int sr, int sc, sf::Color newColor)
{
	int height = image.size();
	if (height == 0) return 0;
	int width = image[0].size();
	if (width == 0) return 0;
	sf::Color color = image[sr][sc]->getColor();
	if (color == newColor) return 0;
	std::queue<std::pair<int, int>> Q;
	Q.push(std::make_pair(sr, sc));
	while (Q.size() > 0) {
		auto p = Q.front();
		Q.pop();
		int r = p.first;
		int c = p.second;
		image[r][c]->setColor(newColor);
		if ((r < height - 1) && (c < width - 1) && ((image[r + 1][c]->getColor() == color) || (image[r + 1][c + 1]->getColor() == color))) {
			Q.push(std::make_pair(r + 1, c));
		}
		if ((r > 0) && (c < width - 1) && ((image[r - 1][c]->getColor() == color) || (image[r - 1][c + 1]->getColor() == color))) {
			Q.push(std::make_pair(r - 1, c));
		}
		if ((c < width - 1) && (image[r][c + 1]->getColor() == color)) {
			Q.push(std::make_pair(r, c + 1));
		}
		if ((c > 0) && (image[r][c - 1]->getColor() == color)) {
			Q.push(std::make_pair(r, c - 1));
		}
	}
	return 0;
}

int Controller::floodFillCount(const std::vector< std::vector<std::unique_ptr<GameObject> >>& image, int sr, int sc, sf::Color newColor)
{
	int numOfTimes = 0;
	int height = image.size();
	if (height == 0) return numOfTimes;
	int width = image[0].size();
	if (width == 0) return numOfTimes;
	sf::Color color = image[sr][sc]->getColor();
	if (color == newColor) return numOfTimes;
	std::queue<std::pair<int, int>> Q;
	Q.push(std::make_pair(sr, sc));
	while (Q.size() > 0) {
		auto p = Q.front();
		Q.pop();
		int r = p.first;
		int c = p.second;
		image[r][c]->setColor(newColor);
		if ((r < height - 1) && ((image[r + 1][c]->getColor() == color) || (image[r + 1][c]->getColor() == newColor))) {
			if (image[r + 1][c]->getColor() == color)
				Q.push(std::make_pair(r + 1, c));
			numOfTimes++;
		}
		if ((r > 0) && ((image[r - 1][c]->getColor() == color) || (image[r - 1][c]->getColor() == newColor))) {
			if (image[r - 1][c]->getColor() == color)
				Q.push(std::make_pair(r - 1, c));
			numOfTimes++;
		}
		if ((c < width - 1) && ((image[r][c + 1]->getColor() == color) || (image[r][c + 1]->getColor() == newColor))) {
			if (image[r][c + 1]->getColor() == color)
				Q.push(std::make_pair(r, c + 1));
			numOfTimes++;
		}
		if ((c > 0) && ((image[r][c - 1]->getColor() == color) || (image[r][c - 1]->getColor() == newColor))) {
			if (image[r][c - 1]->getColor() == color)
				Q.push(std::make_pair(r, c - 1));
			numOfTimes++;
		}
	}
	return numOfTimes;
}