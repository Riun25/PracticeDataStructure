#include <iostream>
#include "Queue.h"

int main()
{
	Queue<int> queue;

	for (int i = 1; i < 8; i++)
	{
		queue.Enqueue(i * 10);
	}

	std::cout << "--- ������ �߰� �� ��� ----\n";
	queue.Print();

	int outValue = 0;

	for (int i = 1; i < 4; i++)
	{
		if (queue.Dequeue(outValue))
		{
			std::cout << "ť���� ��µ� ��: " << outValue << "\n";
		}
	}

	std::cout << "--- ������ ���� �� ��� ----\n";
	queue.Print();

}