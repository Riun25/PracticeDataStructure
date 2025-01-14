#include "LinkedList.h"

LinkedList::LinkedList()
{
}

LinkedList::~LinkedList()
{
	if (mpHead != nullptr)
	{
		Node* current = mpHead;
		Node* deleteNode = nullptr;
		while (current != nullptr)
		{
			deleteNode = current;
			current = current->mpNext;

			delete deleteNode;
		}
	}
}

void LinkedList::AddToHead(int _data)
{
	// �� ��� ����
	Node* newNode = new Node(_data);

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

void LinkedList::Insert(int _data)
{
	// �� ��� ����
	Node* newNode = new Node(_data);

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
		Node* current = mpHead;
		Node* trail = nullptr;

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

void LinkedList::Delete(int _data)
{
	// ������ ��� ã��
	// ���� ó��
	if (mpHead == nullptr)
	{
		std::cout << "����Ʈ�� ����־� ������ �Ұ����մϴ�.\n";
		return;
	}

	// �˻� ����
	Node* current = mpHead;
	Node* trail = nullptr;

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

void LinkedList::Print()
{
	Node* current = mpHead;
	while (current != nullptr)
	{
		std::cout << *current << "\n";
		current = current->mpNext;
	}
}

Node* LinkedList::Reverse()
{
	Node* first = nullptr;
	Node* current = mpHead;
	Node* last = nullptr;

	while (current != nullptr)
	{
		last = current->mpNext; // �� ���� ��带 �����صд�.
		current->mpNext = first; // �� ���� ��带 ���� ���� �ٲ۴�.
		first = current; // �����͸� �� �Ű������� ��带 �ٲ۴�.
		current = last;
	}
	return first;
}

void  LinkedList::ReversePrint()
{
	mpHead = Reverse();
	Print();
}

int LinkedList::Count() const
{
	return mCount;
}
