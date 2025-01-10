#pragma once
#include <iostream>

// ť Ŭ����
template <typename T, int size = 10>
class Queue
{
public:
	Queue()
	{
		// �迭�� �ʱ� ���� 0���� ����
		memset(mData, 0, sizeof(T) * size);
	}

	// ť�� ������� Ȯ���ϴ� �Լ�
	bool IsEmpty() const
	{
		return front == rear;
	}

	// ť�� ����á���� Ȯ���ϴ� �Լ�
	bool IsFull() const
	{
		return (rear + 1) % size == front;
	}

	// ������ �߰�
	bool Enqueue(const T& _value)
	{
		if (IsFull())
		{
			std::cout << "Error : ť�� ������\n";
			return false;
		}

		// ������ �߰��� �ε��� ��� �� ����
		rear = (rear + 1) % size;
		mData[rear] = _value;
		return true;
	}


	// ������ ����
	bool Dequeue(T& _outValue)
	{
		if (IsEmpty())
		{
			std::cout << "Error : ť�� �������\n";
			return false;
		}

		// ������ ������ ��ġ�� ã�Ƽ� ����
		front = (front + 1) % size;
		_outValue = mData[front];
		//mData[front] = T();
		memset(&mData[front], 0, sizeof(T) * size);
		return true;
	}

	// ���
	void Print()
	{
		std::cout << "ť ����: ";
		int max = (front < rear) ? rear : rear + size;
		for (int idx = front + 1; idx <= max; idx++)
		{
			std::cout << mData[idx % size] << " ";
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
	T mData[size];
};