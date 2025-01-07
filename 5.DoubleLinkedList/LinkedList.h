#pragma once
#include "Node.h"

// ��带 ����� �ڷḦ �����ϴ� ��ũ�� ����Ʈ
template <typename T>
class LinkedList
{
public:
	// ������ �߻����� �� ������ �Լ��� ������ �Լ� ������ ����
	using ListEmptyErrorEvent = void(*)();

	// �� �Լ� Ÿ�� ����
	using Comparer = bool (*)(T& _left, T& _right);

public:
	LinkedList()
		:mpFirst(new Node<T>()), mpLast(new Node<T>())
	{
		mpFirst->mpNext = mpLast;
		mpLast->mpPrevious = mpFirst;
	}

	LinkedList(ListEmptyErrorEvent _errorEvent)
		: LinkedList<T>()
	{
		mErrorEvent = _errorEvent;
	}

	~LinkedList()
	{
		// Todo : ���� �Լ� ���� �� ȣ���ؾ� ��
		if (mCount > 0)
		{
			Clear();
		}

		delete mpFirst;
		delete mpLast;
	}

	// ����Ʈ �ȿ� ��� ��带 �����ϴ� �Լ�
	void Clear()
	{
		// ����Ʈ�� ������� ���� ȣ��
		if (mCount == 0)
		{
			RaiseEmptyErrorEvent();
			return;
		}

		// ù ��忡������ ����
		Node<T>* pCurrent = mpFirst->mpNext;

		// ��� ��� ����
		while (pCurrent != nullptr && pCurrent != mpLast)
		{
			// ���� ����
			Node<T>* pNext = pCurrent->mpNext;
			delete pCurrent;
			pCurrent = pNext;
		}

		// ���� ������ ����
		mCount = 0;
		mpFirst->mpNext = mpLast;
		mpLast->mpPrevious = mpFirst;
	}

	// ����Ʈ�� ����� �� ���� �̺�Ʈ�� �߻���Ű�� �Լ�
	// Invoke(���� ȣ��)
	void RaiseEmptyErrorEvent()
	{
		// �Լ� �����Ͱ� �����Ǿ����� �ش� �Լ� ȣ��
		if (mErrorEvent != nullptr)
		{
			mErrorEvent();
		}
	}

	// ��忡 �߰��ϴ� �Լ�
	void AddToFirst(const T& _data)
	{
		// �� ��� ����
		Node<T>* newNode = new Node<T>(_data);

		// �� ����� ���� ��带 head->next ���� ����
		// �� ����� ���� ��带 head ���� ����
		Node<T>* nextNode = mpFirst->mpNext;
		newNode->mpNext = nextNode;
		newNode->mpPrevious = mpFirst;

		// ù ���(head-next)�� �� ���� ����
		// ���� ù ����� ���� ��带 �� ���� ����
		mpFirst->mpNext = newNode;
		nextNode->mpPrevious = newNode;

		// ����� ��� �� ���� ó��
		++mCount;
	}

	// �������� �߰��ϴ� �Լ�
	void AddToLast(const T& _data)
	{
		// �� ��� ����
		Node<T>* newNode = new Node<T>(_data);

		Node<T>* previousNode = mpLast->mpPrevious;
		newNode->mpPrevious = previousNode;
		newNode->mpNext = mpLast;

		previousNode->mpNext = newNode;
		mpLast->mpPrevious = newNode;

		// ����� ��� �� ���� ó��
		++mCount;
	}

	// �����͸� ������ �˻� �� �����ϴ� �Լ�
	void Delete(const T& _data)
	{
		// ���� ó��
		if (mCount == 0)
		{
			RaiseEmptyErrorEvent();
			return;
		}

		// ������ ��� �˻�
		Node<T>* deleteNode = mpFirst->mpNext;
		while (deleteNode != nullptr && deleteNode != mpLast)
		{
			// ã������ ���� ����
			if (deleteNode->mData == _data)
			{
				break;
			}

			// ���� ���� �̵�(�˻� ��� ����)
			deleteNode = deleteNode->mpNext;
		}

		// ���� ó��
		if (deleteNode == nullptr || deleteNode == mpLast)
		{
			RaiseEmptyErrorEvent();
			return;
		}

		// ��� ����
		deleteNode->mpPrevious->mpNext = deleteNode->mpNext;
		deleteNode->mpNext->mpPrevious = deleteNode->mpPrevious;

		delete deleteNode;

		// ����� ����� �� ���� ó��
		--mCount;
	}

	Node<T>* Find(const T& _data)
	{
		Node<T>* current = mpFirst->mpNext;

		while (current != nullptr && current != mpLast)
		{
			if (current->mData == _data)
			{
				return current;
			}
			current = current->mpNext;
		}
		return nullptr;
	}

	// ����� ��� ��� �Լ�
	void Print()
	{
		Node<T>* current = mpFirst->mpNext;
		while (current != nullptr && current != mpLast)
		{
			std::cout << "Data: " << current->mData << "\n";
			current = current->mpNext;
		}
	}

	// ����� ����� �� ��ȯ �Լ�(Getter)
	__forceinline int Count() const
	{
		return mCount;
	}

private:
	// ��� ���
	Node<T>* mpFirst = nullptr;

	// ������ ���
	Node<T>* mpLast = nullptr;

	// ����� �ڷ� ���� ��Ÿ���� ����
	int mCount = 0;

	// �Լ� ������ ����
	ListEmptyErrorEvent mErrorEvent = nullptr;
};