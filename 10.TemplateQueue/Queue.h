#pragma once
#include <iostream>

// 큐 클래스
template <typename T, int size = 10>
class Queue
{
public:
	Queue()
	{
		// 배열의 초기 값을 0으로 설정
		memset(mData, 0, sizeof(T) * size);
	}

	// 큐가 비었는지 확인하는 함수
	bool IsEmpty() const
	{
		return front == rear;
	}

	// 큐가 가득찼는지 확인하는 함수
	bool IsFull() const
	{
		return (rear + 1) % size == front;
	}

	// 데이터 추가
	bool Enqueue(const T& _value)
	{
		if (IsFull())
		{
			std::cout << "Error : 큐가 가득참\n";
			return false;
		}

		// 데이터 추가할 인덱스 계산 후 삽입
		rear = (rear + 1) % size;
		mData[rear] = _value;
		return true;
	}


	// 데이터 추출
	bool Dequeue(T& _outValue)
	{
		if (IsEmpty())
		{
			std::cout << "Error : 큐가 비어있음\n";
			return false;
		}

		// 데이터 추출할 위치를 찾아서 추출
		front = (front + 1) % size;
		_outValue = mData[front];
		//mData[front] = T();
		memset(&mData[front], 0, sizeof(T) * size);
		return true;
	}

	// 출력
	void Print()
	{
		std::cout << "큐 내용: ";
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
	// 데이터가 출력되는 위치
	int front = 0;

	// 데이터가 입력되는 위치
	int rear = 0;

	// 데이터 저장소
	T mData[size];
};