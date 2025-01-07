#pragma once

#include <iostream>

// ��ũ�� ����Ʈ�� ����� ��� Ŭ����
class Node
{
	// std::cout�� ���� ����� �� �ֵ��� �����ε�
	friend std::ostream& operator<<(std::ostream& _os, const Node& _node);

	// ����
	friend class LinkedList;

public:
	Node();
	Node(int _data);

private:
	// ������ �ʵ�
	int mData = 0;

	// ��ũ �ʵ�
	Node* mpNext = nullptr;
};