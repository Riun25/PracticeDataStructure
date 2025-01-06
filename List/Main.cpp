#include <iostream>
#include <vector>	// ���� �迭
//#include <list>	// ���� ����Ʈ

// �ݺ���(Iterator) Ŭ����
template<typename List>
class ListIterator
{
public:
// Ÿ�� ����
	using ValueType = typename List::ValueType;
	using PointerType = ValueType*;
	using RefernceType = ValueType&;

public:
	ListIterator(PointerType _pointer)
		:mPointer(_pointer)
	{

	}

	// ������ ���� ������ �����ε�
	// ���� ���� ������
	ListIterator& operator++()
	{
		++mPointer;
		return *this;
	}

	// ������ ���� ���� ������ �����ε�
	ListIterator& operator++(int)
	{
		ListIterator iterator = *this;
		++(*this);
		return iterator;
	}

	// ���� ���� ������
	ListIterator& operator--()
	{
		--mPointer;
		return *this;
	}

	// ������ ���� ���� ������ �����ε�
	ListIterator& operator--(int)
	{
		ListIterator iterator = *this;
		--(*this);
		return iterator;
	}

	// �ε��� ������ �����ε�
	RefernceType operator[](int _idx)
	{
		return *(mPointer + _idx);
	}

	// ������ ������ �����ε�
	PointerType operator->()
	{
		return mPointer;
	}

	// �� ��ȯ ������
	RefernceType operator*()
	{
		return *mPointer;
	}

	// �� ������
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

// ���� �迭(����Ʈ) Ŭ����
// ���ø�
template<typename T>
class List
{
public:
	using ValueType = T;
	using Iterator = ListIterator<List<T>>;

public:
	List()
	{
		// �ʱ� ������ ���� ����
		mData = new T[mCapacity];
	}
	~List()
	{
		// �����Ͱ� ����Ű�� �� �迭 ���� ����
		if (mData != nullptr)
		{
			delete[] mData;
		}
	}

	// ���� �߰�
	void PushBack(const T& _value)
	{
		// �ڷḦ �߰��� �� �ִ� ����� ������ �ִ��� Ȯ��
		if (mCount == mCapacity)
		{
			ReAllocate(mCapacity * 2);
		}

		// ���� �迭�� ������ ��ҿ� ���޹��� ������ ����
		mData[mCount] = _value;

		// ����� ����� �� ���� ó��
		mCount++;
	}

	// Move �߰�
	void PushBack(T&& _value)
	{
		// �ڷḦ �߰��� �� �ִ� ����� ������ �ִ��� Ȯ��
		if (mCount == mCapacity)
		{
			ReAllocate(mCapacity * 2);
		}

		// ���� �迭�� ������ ��ҿ� ���޹��� ������ ����
		mData[mCount] = std::move(_value);

		// ����� ����� �� ���� ó��
		mCount++;
	}

	// ���� �Լ�
	T& At(int _idx)
	{
		// ���� ó��
		if (_idx >= mCount)
		{
			__debugbreak();
		}
		return mData[_idx];
	}

	const T& At(int _idx) const
	{
		// ���� ó��
		if (_idx >= mCount)
		{
			__debugbreak();
		}
		return mData[_idx];
	}

	// ������ �����ε�
	T& operator[](int _idx) const
	{
		// ���� ó��
		if (_idx >= mCount)
		{
			__debugbreak();
		}
		return mData[_idx];
	}

	// Iterator ���� �Լ�
	Iterator begin()
	{
		return Iterator(mData);
	}

	Iterator end()
	{
		return Iterator(mData + mCount);
	}

	// Getter
	// ��� �� ��ȯ
	int Size() const { return mCount; }
	// ���� �뷮 ��ȯ
	int Capacity() const { return mCapacity; }
	// �迭 �ּ� ��ȯ
	T* Data() const { return mData; }

private:
	// ������ ������ ������ �� ������ �ø��� �Լ�
	void ReAllocate(int _newCapacity)
	{
		// 1. ���ο� �޸� ���� �Ҵ�(Allocate)
		// 2. ���� ������ ����
		// 3. ���� ������ �� �ӽ� ������ ����
		T* newBlock = new T[_newCapacity];
		memset(newBlock, 0, sizeof(T) * _newCapacity); // �̰� ���ָ� �����Ⱚ�� 0���� �ٲ���!
		// ����
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
	// ������ ���� (���� �Ҵ��� �迭 ����)
	T* mData = nullptr;

	// �뷮
	int mCapacity = 2;

	// �迭 ������ ��
	int mCount = 0;
};

int main()
{
	// ���� �迭 ��ü ����
	List<int> list;

	// ���� �߰�
	for (int i = 0; i < 100; i++)
	{
		list.PushBack(i);
	}

	char buffer[256];
	snprintf(buffer, 256, "%d, %d\n", list.Size(), list.Capacity());

	//const int& value = list[100];
	//std::cout << list.Size() << ", " << list.Capacity() << "\n";
	std::cout << buffer;

	// Standard Template Library(STL) ���� �迭
	std::vector<int> vector{ /*1, 2, 3, 4, 5*/ };
	for (int i = 0; i < 100; i++)
	{
		vector.push_back(i);
	}

	// �б�
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