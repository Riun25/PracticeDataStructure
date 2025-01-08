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

	// �ʱ�ȭ
	void Clear()
	{
		mCount = 0;
	}

	// ���ÿ� ����� ����� �� ��ȯ
	inline int Size() const 
	{
		return mCount;
	}

	// ������ ������� Ȯ���ϴ� �Լ�
	inline bool IsEmpty() const
	{
		return mCount == 0;
	}

	// ������ ���� á���� Ȯ���ϴ� �Լ�
	inline bool IsFull() const
	{
		return mCount == _size;
	}

	// ������ ���� �Լ�
	bool Push(T _value)
	{
		// ����ó��
		if (IsFull())
		{
			std::cout << "������ ������ ���� ����\n";
			return false;
		}

		// ���� �� ī��Ʈ ����
		mData[mCount] = _value;
		++mCount;
		return true;
	}

	// ������ ���(����) �Լ�
	bool Pop(T& _outValue)
	{
		// ����ó��
		if (IsEmpty())
		{
			std::cout << "������ �� ������ ��� ����\n";
			return false;
		}

		// ī��Ʈ ���� �� ������ ��ȯ
		--mCount;
		_outValue = mData[mCount];
		return true;
	}

private:
	// ������ ���� �迭
	T mData[_size];

	// ���ÿ� ����� ����� ��(top/head)
	int mCount = 0;
};