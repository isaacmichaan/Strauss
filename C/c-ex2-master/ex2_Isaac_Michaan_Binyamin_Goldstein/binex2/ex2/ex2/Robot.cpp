#include "Robot.h"
#include "Board.h"

Robot::Robot()
{
	m_robot = { 1, 1, 1, 1, 0, 200, 3, 1, 0 };
}


Robot::~Robot()
{
}


void Robot::move(const Board& board)
{
	m_robot[AGAIN] = 1;
	m_robot[OLD_R] = m_robot[NEW_R];
	m_robot[OLD_C] = m_robot[NEW_C];
	m_robot[KEY] = keyBoard();

	for (int i = 0; i < tnt.size(); i++)
		if (tnt[i] != '0' && tnt[i] != 'x' && tnt[i] != 'y')
			--tnt[i];
		else if (tnt[i] == '0') tnt[i] = 'x';
		else tnt[i] = 'y';

	if (m_robot[KEY] != 32)
		checkMove(m_robot[KEY], board);
}


int Robot::keyBoard() const
{
	return  Keyboard::getch();
}


void Robot::checkMove(int switch_on, const Board& board)
{
	switch (switch_on)
	{
	case 72:
		if (!board.checkPosition(m_robot[NEW_R] - 1, m_robot[NEW_C])) { m_robot[AGAIN] = 0; break; }
		if (board.getChar(m_robot[NEW_R] - 1, m_robot[NEW_C]) == '!') m_robot[RESTART] = 1;
		else --m_robot[NEW_R];
		--m_robot[STEPS];
		break;
	case 75:
		if (!board.checkPosition(m_robot[NEW_R], m_robot[NEW_C] - 1)) { m_robot[AGAIN] = 0; break; }
		if (board.getChar(m_robot[NEW_R], m_robot[NEW_C] - 1) == '!') m_robot[RESTART] = 1;
		else --m_robot[NEW_C];
		--m_robot[STEPS];
		break;
	case 77:
		if (!board.checkPosition(m_robot[NEW_R], m_robot[NEW_C] + 1)) { m_robot[AGAIN] = 0; break; }
		if (board.getChar(m_robot[NEW_R], m_robot[NEW_C] + 1) == '!') m_robot[RESTART] = 1;
		else ++m_robot[NEW_C];
		--m_robot[STEPS];
		break;
	case 80:
		if (!board.checkPosition(m_robot[NEW_R] + 1, m_robot[NEW_C])) { m_robot[AGAIN] = 0; break; }
		if (board.getChar(m_robot[NEW_R] + 1, m_robot[NEW_C]) == '!') m_robot[RESTART] = 1;
		else ++m_robot[NEW_R];
		--m_robot[STEPS];
		break;
	case 98:
		bomb();
		break;
	default:
		break;
	}
}


std::vector <int> Robot::getPosition() const
{
	std::vector <int> robot = { m_robot[NEW_R], m_robot[NEW_C],  m_robot[OLD_R], m_robot[OLD_C] };
	return robot;
}


int Robot::getRestart() const
{
	return m_robot[RESTART];
}


int Robot::getLife() const
{
	return m_robot[LIFE];
}


int Robot::getSteps() const
{
	return m_robot[STEPS];
}


int Robot::getAgain() const
{
	return m_robot[AGAIN];
}

void Robot::restart(bool life)
{
	m_robot[NEW_R] = 1;
	m_robot[NEW_C] = 1;
	m_robot[OLD_R] = 1;
	m_robot[OLD_C] = 1;
	if (life)
		--m_robot[LIFE];
	else m_robot[STEPS] = 200;
	m_robot[RESTART] = 0;
	m_tnt.clear();
	tnt.clear();
}


std::vector<int> Robot::getTNTVec1() const
{
	return m_tnt;
}

std::vector<char> Robot::getTNTVec2() const
{
	return tnt;
}

void Robot::bomb()
{
	m_tnt.push_back(m_robot[OLD_R]);
	m_tnt.push_back(m_robot[OLD_C]);
	tnt.push_back('4');
}