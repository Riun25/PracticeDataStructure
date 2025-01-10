#include "Location2D.h"
#include "Queue.h"
#include <iostream>
#include <Windows.h>

// 맵 데이터 선언
const size_t MAZE_SIZE = 17;
const size_t MAZE_MIN_SIZE = 0;

// 0 : 이동 가능
// 1 : 벽, 이동 불가
// s : 시작 위치
// e : 목표 위치

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

// 이동하려는 위치가 유효한 위치인지 확인
bool IsVaildLocation(int _row, int _col)
{
	// 맵의 범위를 벗어났는지 확인
	// 벗어났으면 오류
	if (_row >= MAZE_SIZE || _col >= MAZE_SIZE)
	{
		return false;
	}

	if (_row < MAZE_MIN_SIZE || _col < MAZE_MIN_SIZE)
	{
		return false;
	}

	// 유효성 확인
	// 이동하려는 위치가 0(이동 가능)이거나 e(목표 위치)라면 이동 가능 반환
	return map[_row][_col] == '0' || map[_row][_col] == 'e';
}

// 화면 지우는 함수
void ClearScreen()
{
	// 커서 정보 설정을 위한 구조체 변수 
	CONSOLE_CURSOR_INFO info = {};
	info.dwSize = 1;
	info.bVisible = FALSE;

	// 콘솔 제어를 위한 핸들(포인터) 가져오기
	static HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

	// 커서 그리기
	SetConsoleCursorInfo(handle, &info);

	// 화면 좌표 옮기기
	SetConsoleCursorPosition(handle, { 0, 0 });

	// 빈 문자 찍기
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

// 맵 출력 함수
void PrintLocation(int _row, int _col, int _delay)
{
	// 딜레이
	Sleep(_delay);

	// 화면 지우기
	ClearScreen();

	for (int idx = 0; idx < MAZE_SIZE; idx++)
	{
		for (int jdx = 0; jdx < MAZE_SIZE; jdx++)
		{
			// 현재 방문 중인 위치를 특정 문자로 출력
			if (idx == _row && jdx == _col)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
				std::cout << "♠ ";
				continue;
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);

			// 출력
			std::cout << map[idx][jdx] << " ";
		}
		std::cout << "\n";
	}
}

int main()
{
	// 시작 위치 검색
	int startRow = 0;
	int startCol = 0;

	// 미로의 시작 지점 검색
	for (int idx = 0; idx < MAZE_SIZE; idx++)
	{
		for (int jdx = 0; jdx < MAZE_SIZE; jdx++)
		{
			// 출력
			std::cout << map[idx][jdx] << " ";

			// 시작 지점이라면 위치 저장
			if (map[idx][jdx] == 's') // y와 x가 바뀌는 거 기억하고 있죠!
			{
				startRow = idx;
				startCol = jdx;
			}
		}
		std::cout << "\n";
	}

	// 시작 지점을 탐색하기 위해 스택에 삽입
	Queue<Location2D> queue;
	queue.Enqueue(Location2D(startRow, startCol));

	// 미로 탐색
	while (!queue.IsEmpty())
	{
		// 스택 최상위에 있는 위치 반환
		Location2D current;
		queue.Dequeue(current);

		int row = current.row;
		int col = current.col;

		// 탐색한 위치 출력
		// std::cout << "(" << row << "," << col << ") ";

		PrintLocation(row, col, 500);

		// 도착했는지 확인
		if (map[row][col] == 'e')
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY); // RGB 더하면 7임(하양)
			std::cout << "\n미로 탐색 성공\n";
			std::cin.get();
			return 0;
		}

		// 방문한 곳은 다른 문자로 설정
		map[row][col] = '.';

		// 상/하/좌/우 위치 중 이동 가능한 위치를 스택에 삽입
		if (IsVaildLocation(row - 1, col) == true) // 상
		{
			queue.Enqueue(Location2D(row - 1, col));
		}
		if (IsVaildLocation(row + 1, col) == true) // 하
		{
			queue.Enqueue(Location2D(row + 1, col));
		}
		if (IsVaildLocation(row, col - 1) == true) // 좌
		{
			queue.Enqueue(Location2D(row, col - 1));
		}
		if (IsVaildLocation(row, col + 1) == true) // 우
		{
			queue.Enqueue(Location2D(row, col + 1));
		}
	}

	std::cout << "미로 탐색 실패\n";
	std::cin.get();

	return 0;
}