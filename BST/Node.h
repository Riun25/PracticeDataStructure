#pragma once


template<typename T>
class Node
{
	// 프렌드 선언
	template<typename T>
	friend class BinarySearchTree;

public:

	// 생성자
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
	// 변수
	T data;

	// 부모 노드
	Node<T>* parent;

	// 왼쪽 자손
	Node<T>* left;

	// 오른쪽 자손
	Node<T>* right;
};