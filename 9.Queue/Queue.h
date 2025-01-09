#pragma once
#include <iostream>

// ť�� �ִ� ũ��
const int maxSize = 100;

// ť Ŭ����
class Queue
{
public:
	Queue()
	{
		// �迭�� �ʱ� ���� 0���� ����
		memset(mData, 0, sizeof(int) * maxSize);
	}

	// ť�� ������� Ȯ���ϴ� �Լ�
	bool IsEmpty() const
	{
		return front == rear;
	}

	// ť�� ����á���� Ȯ���ϴ� �Լ�
	bool IsFull() const
	{
		return (rear + 1) % maxSize == front;
	}

	// ������ �߰�
	void Enqueue(int _value)
	{
		if (IsFull())
		{
			std::cout << "Error : ť�� ������\n";
			return;
		}

		// ������ �߰��� �ε��� ��� �� ����
		rear = (rear + 1) % maxSize;
		mData[rear] = _value;
	}


	// ������ ����
	bool Dequeue(int& _outValue)
	{
		if (IsEmpty())
		{
			std::cout << "Error : ť�� �������\n";
			return false;
		}

		// ������ ������ ��ġ�� ã�Ƽ� ����
		front = (front + 1) % maxSize;
		_outValue = mData[front];
		return true;
	}

	// ���
	void Print()
	{
		std::cout << "ť ����: ";
		int max = (front < rear) ? rear : rear + maxSize;
		for (int idx = front + 1; idx <= max; idx++)
		{
			std::cout << mData[idx % maxSize] << " ";
		}

		/*while (!IsEmpty())
		{
			int value = 0;
			if (Dequeue(value))
			{
				std::cout << value << " ";
			}
		}*/
		std::cout << "\n";
	}

private:
	// �����Ͱ� ��µǴ� ��ġ
	int front = 0;

	// �����Ͱ� �ԷµǴ� ��ġ
	int rear = 0;

	// ������ �����
	int mData[maxSize];
};