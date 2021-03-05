#include "Guard.h"
#include "Board.h"


void Guard::move(const Board& board)
{
	for (int i = 0; i < m_guard.size(); i += 4)
	{
		m_guard[i + 2] = m_guard[i];
		m_guard[i + 3] = m_guard[i + 1];

		int c;
		do {
			c = rand() % 9 + 72;
		} while (c != 72 && c != 75 && c != 77 && c != 80);

		switch (c)
		{
		case 72:
			if (!board.checkPosition(m_guard[i] - 1, m_guard[i + 1]) || board.getChar(m_guard[i] - 1, m_guard[i + 1]) == 'D') break;
			if (board.getChar(m_guard[i] - 1, m_guard[i + 1]) == '/') m_restart = 1;
			else --m_guard[i];
			break;
		case 75:
			if (!board.checkPosition(m_guard[i], m_guard[i + 1] - 1) || board.getChar(m_guard[i], m_guard[i + 1] - 1) == 'D') break;
			if (board.getChar(m_guard[i], m_guard[i + 1] - 1) == '/') m_restart = 1;
			else --m_guard[i + 1];
			break;
		case 77:
			if (!board.checkPosition(m_guard[i], m_guard[i + 1] + 1) || board.getChar(m_guard[i], m_guard[i + 1] + 1) == 'D') break;
			if (board.getChar(m_guard[i], m_guard[i + 1] + 1) == '/') m_restart = 1;
			else ++m_guard[i + 1];
			break;
		case 80:
			if (!board.checkPosition(m_guard[i] + 1, m_guard[i + 1]) || board.getChar(m_guard[i] + 1, m_guard[i + 1]) == 'D') break;
			if (board.getChar(m_guard[i] + 1, m_guard[i + 1]) == '/') m_restart = 1;
			else ++m_guard[i];
			break;
		}
	}
}


std::vector<int> Guard::getPosition() const
{
	return m_guard;
}


int Guard::getRestart() const
{
	return m_restart;
}


void Guard::restart()
{
	m_guard = m_temp_guard;
	m_restart = 0;
}

int Guard::getNumOfGuards() const
{
	return m_num_of_guards;
}


void Guard::buildVector(int level, const Board& board)
{
	m_guard.clear();
	switch (level)
	{
	case 1:
	case 2:
		m_num_of_guards = 3;
		break;
	case 3:
		m_num_of_guards = 4;
		break;
	case 4:
	case 5:
		m_num_of_guards = 6;
		break;
	default:
		m_num_of_guards = 7;
		break;
	}
	int counter = 0;

	do {
		int i = rand() % 20;
		int j = rand() % 20;
		if (board.getChar(i, j) == ' ')
		{
			m_guard.push_back(i);
			m_guard.push_back(j);
			m_guard.push_back(i);
			m_guard.push_back(j);
			counter++;
		}
	} while (counter < m_num_of_guards);

	m_temp_guard = m_guard;
}