#pragma once
#include <stack>
#include "Node.h"


// ��带 ����� �ڷḦ �����ϴ� ��ũ�� ����Ʈ
class LinkedList
{
public:
	LinkedList();
	~LinkedList();

	// ��忡 �߰��ϴ� �Լ�
	void AddToHead(int _data);

	// �� �ڿ� �����ϴ� �Լ�
	void Insert(int _data);

	// �����͸� ������ �˻� �� �����ϴ� �Լ�
	void Delete(int _data);

	// ����� ��� ��� �Լ�
	void Print();

	// ������ ���� ����ϴ� �Լ�
	void ReversePrint();

	// ���ÿ� �ִ� ���
	void PushToStack(std::stack<int>& _stack);

	// ��� �Լ��� �̿��� ���
	void RecursivePrint();

	// ����� ����� �� ��ȯ �Լ�(Getter)
	int Count() const;

private:
	void RecursivePrint(Node* _node);
	// �����͸� ������ �Լ�
	Node* Reverse();

private:
	// ��� ���
	Node* mpHead = nullptr;

	// ����� �ڷ� ���� ��Ÿ���� ����
	int mCount = 0;
};