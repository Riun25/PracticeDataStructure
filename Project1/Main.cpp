#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Stack.h"

// �ּ�/�ִ� �� ������ ������ ��ȯ�ϴ� �Լ�
int RandomRange(int _min, int _max)
{
	// ����
	int diff = (_max - _min) + 1;
	return ((rand() * diff) / (RAND_MAX + 1)) + _min;
}

int main()
{
	// ���� �߻��� ����
	srand((unsigned int)time(nullptr));

	// ���� ��ü
	Stack<float, 3> stack;

	for (int i = 0; i < 3; i++)
	{
		stack.Push(RandomRange(0, 100));
	}
	//{
	//	// ���� ��ü
	//	Stack<float> stack;

	//	std::cout << "ù ��° ���� ���� - ����ġ 140\n";
	//	stack.Push(140.0f);

	//	std::cout << "�� ��° ���� ���� - ����ġ 180\n";
	//	stack.Push(180.0f);

	//	std::cout << "�� ��° ���� ���� - ����ġ 200\n";
	//	stack.Push(200.0f);

	//	std::cout << "�� ��° ���� ���� - ����ġ 300\n";
	//	stack.Push(300.0f);
	//}

	// ���
	int idx = 0;
	//while (!stack.IsEmpty())
	while(idx < 10)
	{
		float value;
		if (stack.Pop(value))
		{
			std::cout << "���� ����ġ: " << value << "\n";
		}
		++idx;
	}

	std::cin.get();
}