#pragma once

#include <iostream>

template <typename T, int _size = 3>
class Stack
{
public:
	Stack()
	{
		memset(mData, 0, sizeof(T) * _size);
	}

	// 초기화
	void Clear()
	{
		mCount = 0;
	}

	// 스택에 저장된 요소의 수 반환
	inline int Size() const 
	{
		return mCount;
	}

	// 스택이 비었는지 확인하는 함수
	inline bool IsEmpty() const
	{
		return mCount == 0;
	}

	// 스택이 가득 찼는지 확인하는 함수
	inline bool IsFull() const
	{
		return mCount == _size;
	}

	// 데이터 저장 함수
	bool Push(T _value)
	{
		// 예외처리
		if (IsFull())
		{
			std::cout << "스택이 가득차 저장 실패\n";
			return false;
		}

		// 저장 및 카운트 증가
		mData[mCount] = _value;
		++mCount;
		return true;
	}

	// 데이터 출력(삭제) 함수
	bool Pop(T& _outValue)
	{
		// 예외처리
		if (IsEmpty())
		{
			std::cout << "스택이 비어서 데이터 출력 실패\n";
			return false;
		}

		// 카운트 감소 후 데이터 반환
		--mCount;
		_outValue = mData[mCount];
		return true;
	}

private:
	// 데이터 저장 배열
	T mData[_size];

	// 스택에 저장된 요소의 수(top/head)
	int mCount = 0;
};