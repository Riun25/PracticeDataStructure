#include <iostream>
#include <vector>	// 동적 배열
//#include <list>	// 연결 리스트

// 반복자(Iterator) 클래스
template<typename List>
class ListIterator
{
public:
// 타입 지정
	using ValueType = typename List::ValueType;
	using PointerType = ValueType*;
	using RefernceType = ValueType&;

public:
	ListIterator(PointerType _pointer)
		:mPointer(_pointer)
	{

	}

	// 포인터 증감 연산자 오버로딩
	// 전위 증가 연산자
	ListIterator& operator++()
	{
		++mPointer;
		return *this;
	}

	// 포인터 후위 증가 연산자 오버로딩
	ListIterator& operator++(int)
	{
		ListIterator iterator = *this;
		++(*this);
		return iterator;
	}

	// 전위 감소 연산자
	ListIterator& operator--()
	{
		--mPointer;
		return *this;
	}

	// 포인터 후위 감소 연산자 오버로딩
	ListIterator& operator--(int)
	{
		ListIterator iterator = *this;
		--(*this);
		return iterator;
	}

	// 인덱스 연산자 오버로딩
	RefernceType operator[](int _idx)
	{
		return *(mPointer + _idx);
	}

	// 포인터 연산자 오버로딩
	PointerType operator->()
	{
		return mPointer;
	}

	// 값 반환 연산자
	RefernceType operator*()
	{
		return *mPointer;
	}

	// 비교 연산자
	bool operator==(const ListIterator& _other) const 
	{
		return mPointer == _other.mPointer;
	}
	bool operator!=(const ListIterator& _other) const
	{
		return mPointer != _other.mPointer;
		//return !(*this == _other);
	}

private:
	PointerType mPointer;
};

// 동적 배열(리스트) 클래스
// 템플릿
template<typename T>
class List
{
public:
	using ValueType = T;
	using Iterator = ListIterator<List<T>>;

public:
	List()
	{
		// 초기 데이터 공간 설정
		mData = new T[mCapacity];
	}
	~List()
	{
		// 포인터가 가리키는 힙 배열 변수 삭제
		if (mData != nullptr)
		{
			delete[] mData;
		}
	}

	// 원소 추가
	void PushBack(const T& _value)
	{
		// 자료를 추가할 수 있는 충분한 공간이 있는지 확인
		if (mCount == mCapacity)
		{
			ReAllocate(mCapacity * 2);
		}

		// 현재 배열의 마지막 요소에 전달받은 데이터 설정
		mData[mCount] = _value;

		// 저장된 요소의 수 증가 처리
		mCount++;
	}

	// Move 추가
	void PushBack(T&& _value)
	{
		// 자료를 추가할 수 있는 충분한 공간이 있는지 확인
		if (mCount == mCapacity)
		{
			ReAllocate(mCapacity * 2);
		}

		// 현재 배열의 마지막 요소에 전달받은 데이터 설정
		mData[mCount] = std::move(_value);

		// 저장된 요소의 수 증가 처리
		mCount++;
	}

	// 접근 함수
	T& At(int _idx)
	{
		// 예외 처리
		if (_idx >= mCount)
		{
			__debugbreak();
		}
		return mData[_idx];
	}

	const T& At(int _idx) const
	{
		// 예외 처리
		if (_idx >= mCount)
		{
			__debugbreak();
		}
		return mData[_idx];
	}

	// 연산자 오버로딩
	T& operator[](int _idx) const
	{
		// 예외 처리
		if (_idx >= mCount)
		{
			__debugbreak();
		}
		return mData[_idx];
	}

	// Iterator 관련 함수
	Iterator begin()
	{
		return Iterator(mData);
	}

	Iterator end()
	{
		return Iterator(mData + mCount);
	}

	// Getter
	// 요소 수 반환
	int Size() const { return mCount; }
	// 저장 용량 반환
	int Capacity() const { return mCapacity; }
	// 배열 주소 반환
	T* Data() const { return mData; }

private:
	// 저장할 공간이 부족할 때 공간을 늘리는 함수
	void ReAllocate(int _newCapacity)
	{
		// 1. 새로운 메모리 공간 할당(Allocate)
		// 2. 기존 데이터 복사
		// 3. 기존 데이터 및 임시 데이터 삭제
		T* newBlock = new T[_newCapacity];
		memset(newBlock, 0, sizeof(T) * _newCapacity); // 이걸 해주면 쓰레기값을 0으로 바꿔줌!
		// 복사
		//for (int idx = 0; idx < mCount; i++)
		//{
		//	//newBlock[idx] = mData[idx];
		//	newBlock[idx] = std::move(mData[idx]);
		//}

		memcpy(newBlock, mData, sizeof(T) * mCount);

		delete[] mData;
		mData = newBlock;
		mCapacity = _newCapacity;
	}

private:
	// 데이터 선언 (힙에 할당할 배열 변수)
	T* mData = nullptr;

	// 용량
	int mCapacity = 2;

	// 배열 원소의 수
	int mCount = 0;
};

int main()
{
	// 동적 배열 객체 생성
	List<int> list;

	// 원소 추가
	for (int i = 0; i < 100; i++)
	{
		list.PushBack(i);
	}

	char buffer[256];
	snprintf(buffer, 256, "%d, %d\n", list.Size(), list.Capacity());

	//const int& value = list[100];
	//std::cout << list.Size() << ", " << list.Capacity() << "\n";
	std::cout << buffer;

	// Standard Template Library(STL) 동적 배열
	std::vector<int> vector{ /*1, 2, 3, 4, 5*/ };
	for (int i = 0; i < 100; i++)
	{
		vector.push_back(i);
	}

	// 읽기
	// Range-Based Loop / Ranged Loop
	// forEach/Foreach
	for (const auto& e : vector)
	{
		std::cout << e << " ";
	}

	std::cout << "\n";

	for (const auto& e : list)
	{
		std::cout << e << " ";
	}

	std::cout << "\n";

	for (List<int>::Iterator iterator = list.begin(); iterator != list.end(); ++iterator)
	{
		std::cout << *iterator << " ";
	}

	std::cout << "\n";

	snprintf(buffer, 256, "%d, %d", static_cast<int>(vector.size()), static_cast<int>(vector.capacity()));
	std::cout << buffer;
}