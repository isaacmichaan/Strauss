#pragma once
#include <vector>
class Board;

class Guard
{
private:
	std::vector <int> m_guard; // HOLD Index of N guards in the Older Position and Newer Position
	int m_restart = 0; // In case we need to restart the game, because the Guard caches the Robot
	std::vector <int> m_temp_guard; // Holds the start position of the guards in case of restart
	int m_num_of_guards;

public:
	// Moves Guard Position
	void move(const Board& board);
	// Get Vector of Older Position and Newer Position of the guards
	std::vector<int> getPosition() const;
	// Check if we need to restart
	int getRestart() const;
	// Build --> std::vector <int> m_guard;
	void buildVector(int level, const Board& board);
	// In case of restart
	void restart();
	int getNumOfGuards() const;
};

