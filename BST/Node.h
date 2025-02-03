#pragma once


template<typename T>
class Node
{
	// ������ ����
	template<typename T>
	friend class BinarySearchTree;

public:

	// ������
	Node(const T& _data)
		: data(_data), parent(nullptr), left(nullptr), right(nullptr)
	{ }

	Node(const T& _data, Node<T>* _parent)
		: data(_data), parent(_parent), left(nullptr), right(nullptr)
	{
	}

	~Node()
	{
		parent = nullptr;
		left = nullptr;
		right = nullptr;
	}

private:
	// ����
	T data;

	// �θ� ���
	Node<T>* parent;

	// ���� �ڼ�
	Node<T>* left;

	// ������ �ڼ�
	Node<T>* right;
};