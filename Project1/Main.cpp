#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Stack.h"

// 최소/최대 값 사이의 랜덤을 반환하는 함수
int RandomRange(int _min, int _max)
{
	// 차이
	int diff = (_max - _min) + 1;
	return ((rand() * diff) / (RAND_MAX + 1)) + _min;
}

int main()
{
	// 난수 발생기 설정
	srand((unsigned int)time(nullptr));

	// 스택 객체
	Stack<float, 3> stack;

	for (int i = 0; i < 3; i++)
	{
		stack.Push(RandomRange(0, 100));
	}
	//{
	//	// 스택 객체
	//	Stack<float> stack;

	//	std::cout << "첫 번째 게임 종료 - 경험치 140\n";
	//	stack.Push(140.0f);

	//	std::cout << "두 번째 게임 종료 - 경험치 180\n";
	//	stack.Push(180.0f);

	//	std::cout << "세 번째 게임 종료 - 경험치 200\n";
	//	stack.Push(200.0f);

	//	std::cout << "네 번째 게임 종료 - 경험치 300\n";
	//	stack.Push(300.0f);
	//}

	// 출력
	int idx = 0;
	//while (!stack.IsEmpty())
	while(idx < 10)
	{
		float value;
		if (stack.Pop(value))
		{
			std::cout << "현재 경험치: " << value << "\n";
		}
		++idx;
	}

	std::cin.get();
}