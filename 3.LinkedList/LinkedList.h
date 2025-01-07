#pragma once

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

	// ����� ����� �� ��ȯ �Լ�(Getter)
	__forceinline int Count() const;

private:
	// ��� ���
	Node* mpHead = nullptr;

	// ����� �ڷ� ���� ��Ÿ���� ����
	int mCount = 0;
};