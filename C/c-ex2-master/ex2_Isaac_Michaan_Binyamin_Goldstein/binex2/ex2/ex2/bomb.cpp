#include "bomb.h"



int bomb::getRow()
{
	return m_row;
}

int bomb::getCol()
{
	return m_col;
}

bomb::bomb(int row, int col)
{
	m_row = row;
	m_col = col;
	m_count = 5;
}


bomb::~bomb()
{
}
