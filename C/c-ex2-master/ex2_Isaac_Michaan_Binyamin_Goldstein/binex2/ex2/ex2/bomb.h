#pragma once
class bomb
{
private:
	int m_count;
	int m_row;
	int m_col;
public:
	int getRow();
	int getCol();
	bomb(int row,int col);
	~bomb();
};

