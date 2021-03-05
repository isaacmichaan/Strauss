#include <iostream>
#include "Board.h"
#include "Robot.h"
#include "Guard.h"
using namespace std;
int LEVEL = 1;
int SCORE = 0;

int main()
{
	Board player("board.txt");
	Robot robot;
	Guard guard;
	std::vector <int> m_robot, m_tnt, m_guard;
	std::vector <char> tnt;
	int restant_guards = 0;

	//Building
	guard.buildVector(LEVEL, player);
	player.startGuard(guard.getPosition());
	player.printBoard(robot.getSteps());

	while (robot.getLife() && robot.getSteps()/* && LEVEL < (4 + 1)*/)
	{
		//Move Robot
		do { robot.move(player); } while (!robot.getAgain());
		m_robot = robot.getPosition();
		m_tnt = robot.getTNTVec1();
		tnt = robot.getTNTVec2();
		bool explode = player.moveRobot(m_robot, m_tnt, tnt);

		//Move Guard
		if (!robot.getRestart())
		{
			guard.move(player);
			m_guard = guard.getPosition();
			player.moveGuard(m_guard, m_tnt, tnt, SCORE, guard.getNumOfGuards(), restant_guards);
		}

		//In case of Restart or Change Level
		if (robot.getRestart() || guard.getRestart() || !explode)
		{
			bool life = true;
			if (player.getChar(m_robot[0], m_robot[1]) == 'D'/* && LEVEL < 4*/)
			{
				life = false;
				LEVEL++;
				SCORE += (20 * guard.getNumOfGuards() + (5 * guard.getNumOfGuards()) * (guard.getNumOfGuards() - restant_guards));
				player.buildBoard();
				guard.buildVector(LEVEL, player);
			}
			else if (player.getChar(m_robot[0], m_robot[1]) == 'D') LEVEL++;
			robot.restart(life);
			guard.restart();
			player.startGuard(guard.getPosition());
			restant_guards = 0;
		}
		player.printBoard(robot.getSteps());
		cout << robot.getLife() << endl;
		cout << SCORE << endl;
	}
}