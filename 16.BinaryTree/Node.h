#pragma once
#include "BinaryTree.h"

#include <iostream>

// 이진 트리에 사용할 노드 클래스
template <typename T>
class Node
{
	// 이진 트리 클래스를 프렌드로 선언
	template<typename T>
	friend class BinaryTree;

public:
	Node()
	{

	}

	Node(const T& _data)
		: data(_data)
	{

	}

	void AddLeftChild(Node<T>* _child)
	{
		// 1. 새로운 자손의 부모를 이 노드로 지정
		_child->parent = this;

		// 2. 이 노드의 왼쪽 자손을 새 노드로 지정
		left = _child;
	}

	void AddLeftChild(const T& _data)
	{
		AddLeftChild(new Node<T>(_data));
	}

	void AddRightChild(Node<T>* _child)
	{
		// 1. 새로운 자손의 부모를 이 노드로 지정
		_child->parent = this;

		// 2. 이 노드의 오른쪽 자손을 새 노드로 지정
		right = _child;
	}

	void AddRightChild(const T& _data)
	{
		AddRightChild(new Node<T>(_data));
	}

	// 삭제 함수
	void Destroy()
	{
		// 노드의 부모가 있는 경우 삭제 진행
		if (parent)
		{
			// 이 노드가 부모의 왼쪽 자손일 때
			if (parent->left == this)
			{
				parent->left = nullptr;
			}

			// 이 노드가 부모의 오른쪽 자손일 때
			if (parent->right == this)
			{
				parent->right = nullptr;
			}

			// 이 노드를 포함해 자손까지 순회하면서 삭제
			DestroyRecursive(this);
		}
	}

private:

	//삭제 재귀 함수
	void DestroyRecursive(Node<T>* _node)
	{
		// 탈출 조건
		if (_node == nullptr)
		{
			return;
		}

		// 자손 노드의 존재 확인
		Node<T>* leftChild = _node->left;
		Node<T>* rightChild = _node->right;
		
		// 자손이 없는 경우
		if (leftChild == nullptr && rightChild == nullptr)
		{
			delete _node;
			_node = nullptr;
			return;
		}

		// 자손 재귀 함수
		DestroyRecursive(leftChild);
		DestroyRecursive(rightChild);

		// 삭제
		delete _node;
		_node = nullptr;
	}

private:

	// 데이터
	T data;

	// 부모 노드
	Node<T>* parent = nullptr;

	// 왼쪽 자손 노드
	Node<T>* left = nullptr;

	// 오른쪽 자손 노드
	Node<T>* right = nullptr;
};