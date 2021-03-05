#pragma once
#include <vector>
#include <string>
#include "Keyboard.h"
class Board;
enum index_r { NEW_R, NEW_C, OLD_R, OLD_C, KEY, STEPS, LIFE, AGAIN, RESTART };

class Robot
{
private:
	std::vector <int> m_robot; // Holds what is enumerated in index_r
	std::vector<int> m_tnt; // Holds bomb Postion
	std::vector<char> tnt; // Holds a char between 1 - 4 to know when to explode

public:
	// Builds m_robot
	Robot();
	~Robot();
	// Moves Guard Position
	void move(const Board& board);
	// getch()
	int keyBoard() const;
	// check if Movement is allowed so than proceed with the movement
	void checkMove(int, const Board&);
	// Get Vector of Older Position and Newer Position of the robot
	std::vector <int> getPosition() const;
	// Check if we need to restart
	int getRestart() const;
	// return Life
	int getLife() const;
	// return Steps
	int getSteps() const;
	// return 0 in case of attempt to go to '#' or '@'
	int getAgain() const;
	// In case of restart
	void restart(bool life);
	// return m_tnt
	std::vector<int> getTNTVec1() const;
	// return tnt
	std::vector<char> getTNTVec2() const;
	// start bomb
	void bomb();
};

