#pragma once
#include "Node.h"

template <typename T>
class List
{
public:
	List() {}
	~List()
	{
		if (mpHead)
		{
			Node<T>* current = mpHead;
			Node<T>* deleteNode = nullptr;
			while (current)
			{
				deleteNode = current;
				current = current->mpNext;

				delete deleteNode;
			}
		}
	}

	void AddToHead(const T& _data)
	{
		Node<T>* newNode = new Node<T>(_data);

		if (mpHead == nullptr)
		{
			mpHead = newNode;
		}
		else
		{
			newNode->mpNext = mpHead;
			mpHead = newNode;
		}
		++mCount;
	}

	void Insert(const T& _data)
	{
		Node<T>* newNode = new Node<T>(_data);

		if (mpHead == nullptr)
		{
			mpHead = newNode;
		}
		else
		{
			Node<T>* current = mpHead;
			while (current->mpNext)
			{
				current = current->mpNext;
			}

			current->mpNext = newNode;
		}
		++mCount;
	}

	void Delete(const T& _data)
	{
		if (mpHead == nullptr)
		{
			return;
		}

		Node<T>* current = mpHead;
		Node<T>* trail = nullptr;

		while (current)
		{
			if (current->mData == _data)
			{
				break;
			}
			trail = current;
			current = current->mpNext;
		}

		if (current == nullptr)
		{
			return;
		}
		else if (current == mpHead)
		{
			mpHead = mpHead->mpNext;
		}
		else
		{
			trail->mpNext = current->mpNext;
		}

		delete current;
		--mCount;
	}

	void Print()
	{
		Node<T>* current = mpHead;
		while (current)
		{
			std::cout << current->mData << "\n";
			current = current->mpNext;
		}
	}

	void Reverse()
	{
		Node<T>* current = mpHead;
		Node<T>* first = nullptr;
		Node<T>* last = nullptr;

		while (current)
		{
			last = current->mpNext;
			current->mpNext = first;
			first = current;
			current = last;
		}

		mpHead = first;
	}

private:
	Node<T>* mpHead = nullptr;
	int mCount = 0;
};

