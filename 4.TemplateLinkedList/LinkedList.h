#pragma once

#include "Node.h"


// ��带 ����� �ڷḦ �����ϴ� ��ũ�� ����Ʈ
template <typename T>
class LinkedList
{
public:
	LinkedList()
	{ }
	~LinkedList()
	{
		if (mpHead != nullptr)
		{
			Node<T>* current = mpHead;
			Node<T>* deleteNode = nullptr;
			while (current != nullptr)
			{
				deleteNode = current;
				current = current->mpNext;

				delete deleteNode;
			}
		}
	}

	// ��忡 �߰��ϴ� �Լ�
	void AddToHead(const T& _data)
	{
		// �� ��� ����
		Node<T>* newNode = new Node<T>(_data);

		// #1. ���� ��尡 ���� ���
		if (mpHead == nullptr)
		{
			mpHead = newNode;
		}
		// #2. ��尡 �ִ� ���
		else
		{
			// �� ����� ���� ��带 ������ ��� ���� ����
			newNode->mpNext = mpHead;

			// ��� ��带 �� ���� ��ü
			mpHead = newNode;
		}

		// ����� ��� �� ���� ó��
		++mCount;
	}

	// �� �ڿ� �����ϴ� �Լ�
	void Insert(const T& _data)
	{
		// �� ��� ����
		Node<T>* newNode = new Node<T>(_data);

		// ������ ��ġ ã��

		// #1. ��尡 ��� �ִ� ���
		if (mpHead == nullptr)
		{
			mpHead = newNode;
		}
		// ������ ��ġ�� �˻� �� ��� ����
		else
		{
			// ��� ������ 2���� ����� �˻�
			Node<T>* current = mpHead;
			Node<T>* trail = nullptr;

			// ��ġ �˻�
			while (current != nullptr)
			{
				// �� ��
				if (current->mData >= _data)
				{
					break;
				}

				// ���� ���� �̵�
				trail = current;
				current = current->mpNext;
			}

			// �˻��� ����� Ȯ���ؼ� ó��
			if (current == mpHead)
			{
				newNode->mpNext = mpHead;
				mpHead = newNode;
			}
			else
			{
				newNode->mpNext = current;
				trail->mpNext = newNode;
			}
		}
		// ��� �� ���� ó��
		++mCount;
	}

	// �����͸� ������ �˻� �� �����ϴ� �Լ�
	void Delete(const T& _data)
	{
		// ������ ��� ã��
// ���� ó��
		if (mpHead == nullptr)
		{
			std::cout << "����Ʈ�� ����־� ������ �Ұ����մϴ�.\n";
			return;
		}

		// �˻� ����
		Node<T>* current = mpHead;
		Node<T>* trail = nullptr;

		while (current != nullptr)
		{
			// �� ��
			if (current->mData == _data)
			{
				break;
			}

			// ��� �̵�
			trail = current;
			current = current->mpNext;
		}

		// �˻��� ��� 2����
		// #1 �� ã�� ���
		if (current == nullptr)
		{
			std::cout << "�� " << _data << "�� ã�� ���߽��ϴ�.\n";
			return;
		}
		// #2 ã�� ���
		else if (current == mpHead)
		{
			mpHead = mpHead->mpNext;
		}
		else
		{
			trail->mpNext = current->mpNext;
		}

		// ��� ����
		delete current;

		// ����� ����� �� ���� ó��
		--mCount;
	}

	// ����� ��� ��� �Լ�
	void Print()
	{
		Node<T>* current = mpHead;
		while (current != nullptr)
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
	Node<T>* mpHead = nullptr;

	// ����� �ڷ� ���� ��Ÿ���� ����
	int mCount = 0;
};