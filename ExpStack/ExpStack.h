#pragma once

#include <iostream>

//���� �ִ� ����
const int maxCount = 10;

// ����ġ�� �����ϴ� ���� Ŭ����
class ExpStack
{
public:
	ExpStack() 
	{
		// �迭 0.0f���� �ʱ�ȭ
		memset(mData, 0.0f, sizeof(float) * maxCount);
	}
	~ExpStack() {}

	// ���� ���� �Լ�
	void Clear()
	{
		mCount = 0;
	}

	// ���ÿ� ����� ����� �� ��ȯ �Լ�
	int Size() const
	{
		return mCount;
	}

	// ������ ������� Ȯ���ϴ� �Լ�
	bool IsEmpty() const 
	{
		return mCount == 0;
	}

	// ������ �߰� �Լ�(push)
	// Silent is violent.
	void Push(float _exp)
	{
		// ������ ���� á���� Ȯ��
		if (mCount == maxCount)
		{
			std::cout << "������ ���� ���� ������ ���忡 �����߽��ϴ�.\n";
			return;
		}

		// ����ġ ����
		mData[mCount] = _exp;

		// ����� ������ �� ���� ó��
		++mCount;
	}

	// ������ ����(�� ��ȯ) �Լ�(pop)
	bool Pop(float& _outValue)
	{
		// ������ ������� ����
		if (IsEmpty())
		{
			std::cout << "������ �� ������ ��ȯ�� �����߽��ϴ�.\n";
			return false;
		}

		// ������ �ϳ� ���� ��Ų �ڿ� ���� ��ȯ
		--mCount;
		_outValue = mData[mCount];

		return true;
	}

private:
	// ������ �����
	float mData[maxCount];

	// ���ÿ� ����� ����� �� (top/head)
	int mCount = 0;
};