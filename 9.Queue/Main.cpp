#include <iostream>
#include "Queue.h"

int main()
{
	// 큐 생성
	Queue queue;

	// 큐 데이터 생성
	for (int i = 0; i < 10; i++)
	{
		queue.Enqueue(i + 10);
	}

	// 큐 출력
	queue.Print();

	// 큐 데이터 제거

	std::cout << " === 큐 요소 제거 === \n";
	int value = 0;
	queue.Dequeue(value);
	queue.Dequeue(value);
	queue.Dequeue(value);
	queue.Print();

	std::cin.get();
	return 0;
}