#include <iostream>
#include "Queue.h"

int main()
{
	Queue<int> queue;

	for (int i = 1; i < 8; i++)
	{
		queue.Enqueue(i * 10);
	}

	std::cout << "--- 데이터 추가 후 출력 ----\n";
	queue.Print();

	int outValue = 0;

	for (int i = 1; i < 4; i++)
	{
		if (queue.Dequeue(outValue))
		{
			std::cout << "큐에서 출력된 값: " << outValue << "\n";
		}
	}

	std::cout << "--- 데이터 삭제 후 출력 ----\n";
	queue.Print();

}