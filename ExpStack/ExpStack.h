#pragma once

#include <iostream>

//스택 최대 개수
const int maxCount = 10;

// 경험치를 저장하는 스택 클래스
class ExpStack
{
public:
	ExpStack() 
	{
		// 배열 0.0f으로 초기화
		memset(mData, 0.0f, sizeof(float) * maxCount);
	}
	~ExpStack() {}

	// 스택 비우는 함수
	void Clear()
	{
		mCount = 0;
	}

	// 스택에 저장된 요소의 수 반환 함수
	int Size() const
	{
		return mCount;
	}

	// 스택이 비었는지 확인하는 함수
	bool IsEmpty() const 
	{
		return mCount == 0;
	}

	// 데이터 추가 함수(push)
	// Silent is violent.
	void Push(float _exp)
	{
		// 스택이 가득 찼는지 확인
		if (mCount == maxCount)
		{
			std::cout << "스택이 가득 차서 데이터 저장에 실패했습니다.\n";
			return;
		}

		// 경험치 저장
		mData[mCount] = _exp;

		// 저장된 데이터 수 증가 처리
		++mCount;
	}

	// 데이터 삭제(값 반환) 함수(pop)
	bool Pop(float& _outValue)
	{
		// 스택이 비었으면 종료
		if (IsEmpty())
		{
			std::cout << "스택이 비어서 데이터 반환에 실패했습니다.\n";
			return false;
		}

		// 개수를 하나 감소 시킨 뒤에 값을 반환
		--mCount;
		_outValue = mData[mCount];

		return true;
	}

private:
	// 스택의 저장소
	float mData[maxCount];

	// 스택에 저장된 요소의 수 (top/head)
	int mCount = 0;
};