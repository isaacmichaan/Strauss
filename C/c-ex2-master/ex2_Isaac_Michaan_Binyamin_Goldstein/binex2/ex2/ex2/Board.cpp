#include "Board.h"


Board::Board(const string & newFile)
{
	data.clear();
	file.open(newFile);
	getline(file, updateInfo);

	while (getline(file, line) && line != "")
	{
		data.push_back(line);
	}
	data[1][1] = '/';
	t_data = data;
}


Board::~Board()
{
	file.close();
}


void Board::buildBoard()
{
	data.clear();
	getline(file, updateInfo);

	while (getline(file, line) && line != "")
	{
		data.push_back(line);
	}
	data[1][1] = '/';
	t_data = data;
}


bool Board::moveRobot(std::vector <int> robot, std::vector<int> tnt1, std::vector <char> tnt2)
{
	bool y = true;

	for (int i = 0, j = 0, n = 0; j < tnt1.size(); j += 2, n += 1)
	{
		if (tnt2[n] == 'y') continue;
		else if (data[robot[i + 2]][robot[i + 3]] != '%' && tnt2[n] != 'x')
			data[tnt1[j]][tnt1[j + 1]] = tnt2[n];
		if (tnt2[n] == '0')
		{
			if (data[robot[i + 2]][robot[i + 3]] == data[tnt1[j]][tnt1[j + 1]])
				return false;
			data[tnt1[j]][tnt1[j + 1]] = ' ';
			if (data[tnt1[j] - 1][tnt1[j + 1]] != '#')
				data[tnt1[j] - 1][tnt1[j + 1]] = '*';
			if (data[tnt1[j]][tnt1[j + 1] - 1] != '#')
				data[tnt1[j]][tnt1[j + 1] - 1] = '*';
			if (data[tnt1[j]][tnt1[j + 1] + 1] != '#')
				data[tnt1[j]][tnt1[j + 1] + 1] = '*';
			if (data[tnt1[j] + 1][tnt1[j + 1]] != '#')
				data[tnt1[j] + 1][tnt1[j + 1]] = '*';
			if (data[robot[i + 2]][robot[i + 3]] == data[tnt1[j] - 1][tnt1[j + 1]])
				return false;
			if (data[robot[i + 2]][robot[i + 3]] == data[tnt1[j]][tnt1[j + 1] - 1])
				return false;
			if (data[robot[i + 2]][robot[i + 3]] == data[tnt1[j]][tnt1[j + 1] + 1])
				return false;
			if (data[robot[i + 2]][robot[i + 3]] == data[tnt1[j] - 1][tnt1[j + 1]])
				return false;
		}
		else if (tnt2[n] == 'x')
		{
			if (data[tnt1[j] - 1][tnt1[j + 1]] == '*')
				data[tnt1[j] - 1][tnt1[j + 1]] = ' ';
			if (data[tnt1[j]][tnt1[j + 1] - 1] == '*')
				data[tnt1[j]][tnt1[j + 1] - 1] = ' ';
			if (data[tnt1[j]][tnt1[j + 1] + 1] == '*')
				data[tnt1[j]][tnt1[j + 1] + 1] = ' ';
			if (data[tnt1[j] + 1][tnt1[j + 1]] == '*')
				data[tnt1[j] + 1][tnt1[j + 1]] = ' ';
		}
		else if (data[robot[i + 2]][robot[i + 3]] == '%') { y = false; data[tnt1[j]][tnt1[j + 1]] = tnt2[n]; data[robot[i]][robot[i + 1]] = '/'; }
		else if (data[robot[i + 2]][robot[i + 3]] == '4' || data[robot[i + 2]][robot[i + 3]] == '3' || data[robot[i + 2]][robot[i + 3]] == '2' || data[robot[i + 2]][robot[i + 3]] == '1') { y = false; data[robot[i + 2]][robot[i + 3]] = '%'; }
		else if (data[robot[i]][robot[i + 1]] == '4' || data[robot[i]][robot[i + 1]] == '3' || data[robot[i]][robot[i + 1]] == '2' || data[robot[i]][robot[i + 1]] == '1') { y = false; data[robot[i + 2]][robot[i + 3]] = ' '; data[robot[i]][robot[i + 1]] = '%'; }
	}

	for (int i = 0; i < robot.size() && y; i += 4)
	{
		if (data[robot[i]][robot[i + 1]] == 'D') return false;
		swap(data[robot[i]][robot[i + 1]], data[robot[i + 2]][robot[i + 3]]);
	}
	return true;
}


void Board::moveGuard(std::vector <int> guard, std::vector<int> tnt1, std::vector <char> tnt2, int& score, int num_of_guards, int& restant_guards)
{
	bool y = true;

	for (int i = 0; i < guard.size(); i += 4)
	{
		if (data[guard[i]][guard[i + 1]] == '*')
			data[guard[i]][guard[i + 1]] = ' ';
	}

	for (int i = 0; i < guard.size() && y; i += 4)
	{
		swap(data[guard[i]][guard[i + 1]], data[guard[i + 2]][guard[i + 3]]);
	}
}


bool Board::checkPosition(int i, int j) const
{
	if (data[i][j] == '#' || data[i][j] == '@')
		return false;
	return true;
}


char Board::getChar(int i, int j) const
{
	return data[i][j];
}


void Board::printBoard(int getSteps) const
{
	std::system("cls");
	cout << updateInfo << endl;
	for (const auto & s : data)
	{
		cout << s << endl;
	}
	cout << getSteps << endl;
}


void Board::startGuard(std::vector <int> guard)
{
	data = t_data;
	for (int i = 0; i < guard.size(); i += 4)
	{
		data[guard[i]][guard[i + 1]] = '!';
	}
}
