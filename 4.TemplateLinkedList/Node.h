#pragma once

#include <iostream>

// ��ũ�� ����Ʈ�� ����� ��� Ŭ����
template <typename T>
class Node
{
	template <typename T>
	friend class LinkedList;

public:
	Node()
		:mData()
	{ }
	Node(T _data)
		:mData(_data)
	{}

private:
	// ������ �ʵ�
	T mData;

	// ��ũ �ʵ�
	Node<T>* mpNext = nullptr;
};