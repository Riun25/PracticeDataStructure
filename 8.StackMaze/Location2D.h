#pragma once

class Location2D
{
public:
	Location2D(int _row = 0, int _col = 0)
		: row(_row), col(_col)
	{
	}
public:
	int row = 0;
	int col = 0;
};