#include <iostream>
#include "Queue.h"

int main()
{
	// ť ����
	Queue queue;

	// ť ������ ����
	for (int i = 0; i < 10; i++)
	{
		queue.Enqueue(i + 10);
	}

	// ť ���
	queue.Print();

	// ť ������ ����

	std::cout << " === ť ��� ���� === \n";
	int value = 0;
	queue.Dequeue(value);
	queue.Dequeue(value);
	queue.Dequeue(value);
	queue.Print();

	std::cin.get();
	return 0;
}