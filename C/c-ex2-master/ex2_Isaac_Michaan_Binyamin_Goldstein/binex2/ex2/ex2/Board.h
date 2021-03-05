#pragma once
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Board
{
private:
	ifstream file; // Hold Phase File
	string updateInfo; // First Line used to Update Information 
	string line; // Hold string from File
	vector <string> data; // Hold game Data from File
	vector <string> t_data; // Hold game temp Data from File

public:
	// Build Board first time
	Board(const string & newFile);
	~Board();
	// Build Board for next times
	void buildBoard();
	// move Robot
	bool moveRobot(std::vector <int> robot, std::vector<int> tnt1, std::vector <char> tnt2);
	// move Guard
	void moveGuard(std::vector<int> guard, std::vector<int> tnt1, std::vector <char> tnt2, int& score, int num_of_guards, int& restant_guards);
	// return true if future position is allowed
	bool checkPosition(int i, int j) const;
	// return next posittion Char
	char getChar(int i, int j) const;
	// print board
	void printBoard(int) const;
	// start Guard position
	void startGuard(std::vector <int>);
};

