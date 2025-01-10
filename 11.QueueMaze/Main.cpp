#include "Location2D.h"
#include "Queue.h"
#include <iostream>
#include <Windows.h>

// �� ������ ����
const size_t MAZE_SIZE = 17;
const size_t MAZE_MIN_SIZE = 0;

// 0 : �̵� ����
// 1 : ��, �̵� �Ұ�
// s : ���� ��ġ
// e : ��ǥ ��ġ

char map[MAZE_SIZE][MAZE_SIZE] =
{
	//{'1','1','1','1','1','1'},
	//{'s','0','1','0','0','1'},
	//{'1','0','0','0','1','1'},
	//{'1','0','1','0','1','1'},
	//{'1','0','1','0','0','e'},
	//{'1','1','1','1','1','1'}
		{'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
		{'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '0', '0', '0', '1'},
		{'1', '0', '1', '1', '1', '1', '1', '1', '1', '0', '1', '0', '1', '0', '1', '0', '1'},
		{'1', '0', '1', '0', '0', '0', '1', '0', '0', '0', '1', '0', '0', '0', '1', '0', '1'},
		{'1', '0', '1', '0', '1', '0', '1', '0', '1', '1', '1', '1', '1', '1', '1', '0', '1'},
		{'1', '0', '0', '0', '1', '0', '1', '0', '0', '0', '0', '0', '0', '0', '1', '0', '1'},
		{'1', '1', '1', '1', '1', '0', '1', '1', '1', '1', '1', '1', '1', '0', '1', '0', '1'},
		{'s', '0', '1', '0', '0', '0', '0', '0', '0', '0', '1', '0', '0', '0', '1', '0', '1'},
		{'1', '0', '1', '1', '1', '1', '1', '1', '1', '0', '1', '0', '1', '1', '1', '0', '1'},
		{'1', '0', '1', '0', '0', '0', '0', '0', '1', '0', '1', '0', '1', '0', '1', '0', '1'},
		{'1', '0', '1', '0', '1', '1', '1', '0', '1', '0', '1', '0', '1', '0', '1', '0', '1'},
		{'1', '0', '0', '0', '1', '0', '1', '0', '1', '0', '1', '0', '1', '0', '0', '0', '1'},
		{'1', '1', '1', '1', '1', '0', '1', '0', '1', '1', '1', '0', '1', '1', '1', '0', '1'},
		{'1', '0', '0', '0', '0', '0', '1', '0', '0', '0', '1', '0', '0', '0', '1', '0', '1'},
		{'1', '0', '1', '1', '1', '1', '1', '1', '1', '0', '1', '1', '1', '0', '1', '0', '1'},
		{'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '0', 'e'},
		{'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'}
};

// �̵��Ϸ��� ��ġ�� ��ȿ�� ��ġ���� Ȯ��
bool IsVaildLocation(int _row, int _col)
{
	// ���� ������ ������� Ȯ��
	// ������� ����
	if (_row >= MAZE_SIZE || _col >= MAZE_SIZE)
	{
		return false;
	}

	if (_row < MAZE_MIN_SIZE || _col < MAZE_MIN_SIZE)
	{
		return false;
	}

	// ��ȿ�� Ȯ��
	// �̵��Ϸ��� ��ġ�� 0(�̵� ����)�̰ų� e(��ǥ ��ġ)��� �̵� ���� ��ȯ
	return map[_row][_col] == '0' || map[_row][_col] == 'e';
}

// ȭ�� ����� �Լ�
void ClearScreen()
{
	// Ŀ�� ���� ������ ���� ����ü ���� 
	CONSOLE_CURSOR_INFO info = {};
	info.dwSize = 1;
	info.bVisible = FALSE;

	// �ܼ� ��� ���� �ڵ�(������) ��������
	static HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

	// Ŀ�� �׸���
	SetConsoleCursorInfo(handle, &info);

	// ȭ�� ��ǥ �ű��
	SetConsoleCursorPosition(handle, { 0, 0 });

	// �� ���� ���
	for (int y = 0; y < MAZE_SIZE; y++)
	{
		for (int x = 0; x < MAZE_SIZE; x++)
		{
			std::cout << " ";
		}
		std::cout << "\n";
	}
	SetConsoleCursorPosition(handle, { 0, 0 });
}

// �� ��� �Լ�
void PrintLocation(int _row, int _col, int _delay)
{
	// ������
	Sleep(_delay);

	// ȭ�� �����
	ClearScreen();

	for (int idx = 0; idx < MAZE_SIZE; idx++)
	{
		for (int jdx = 0; jdx < MAZE_SIZE; jdx++)
		{
			// ���� �湮 ���� ��ġ�� Ư�� ���ڷ� ���
			if (idx == _row && jdx == _col)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
				std::cout << "�� ";
				continue;
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);

			// ���
			std::cout << map[idx][jdx] << " ";
		}
		std::cout << "\n";
	}
}

int main()
{
	// ���� ��ġ �˻�
	int startRow = 0;
	int startCol = 0;

	// �̷��� ���� ���� �˻�
	for (int idx = 0; idx < MAZE_SIZE; idx++)
	{
		for (int jdx = 0; jdx < MAZE_SIZE; jdx++)
		{
			// ���
			std::cout << map[idx][jdx] << " ";

			// ���� �����̶�� ��ġ ����
			if (map[idx][jdx] == 's') // y�� x�� �ٲ�� �� ����ϰ� ����!
			{
				startRow = idx;
				startCol = jdx;
			}
		}
		std::cout << "\n";
	}

	// ���� ������ Ž���ϱ� ���� ���ÿ� ����
	Queue<Location2D> queue;
	queue.Enqueue(Location2D(startRow, startCol));

	// �̷� Ž��
	while (!queue.IsEmpty())
	{
		// ���� �ֻ����� �ִ� ��ġ ��ȯ
		Location2D current;
		queue.Dequeue(current);

		int row = current.row;
		int col = current.col;

		// Ž���� ��ġ ���
		// std::cout << "(" << row << "," << col << ") ";

		PrintLocation(row, col, 500);

		// �����ߴ��� Ȯ��
		if (map[row][col] == 'e')
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY); // RGB ���ϸ� 7��(�Ͼ�)
			std::cout << "\n�̷� Ž�� ����\n";
			std::cin.get();
			return 0;
		}

		// �湮�� ���� �ٸ� ���ڷ� ����
		map[row][col] = '.';

		// ��/��/��/�� ��ġ �� �̵� ������ ��ġ�� ���ÿ� ����
		if (IsVaildLocation(row - 1, col) == true) // ��
		{
			queue.Enqueue(Location2D(row - 1, col));
		}
		if (IsVaildLocation(row + 1, col) == true) // ��
		{
			queue.Enqueue(Location2D(row + 1, col));
		}
		if (IsVaildLocation(row, col - 1) == true) // ��
		{
			queue.Enqueue(Location2D(row, col - 1));
		}
		if (IsVaildLocation(row, col + 1) == true) // ��
		{
			queue.Enqueue(Location2D(row, col + 1));
		}
	}

	std::cout << "�̷� Ž�� ����\n";
	std::cin.get();

	return 0;
}