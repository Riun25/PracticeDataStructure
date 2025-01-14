#pragma once
#include "BinaryTree.h"

#include <iostream>

// ���� Ʈ���� ����� ��� Ŭ����
template <typename T>
class Node
{
	// ���� Ʈ�� Ŭ������ ������� ����
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
		// 1. ���ο� �ڼ��� �θ� �� ���� ����
		_child->parent = this;

		// 2. �� ����� ���� �ڼ��� �� ���� ����
		left = _child;
	}

	void AddLeftChild(const T& _data)
	{
		AddLeftChild(new Node<T>(_data));
	}

	void AddRightChild(Node<T>* _child)
	{
		// 1. ���ο� �ڼ��� �θ� �� ���� ����
		_child->parent = this;

		// 2. �� ����� ������ �ڼ��� �� ���� ����
		right = _child;
	}

	void AddRightChild(const T& _data)
	{
		AddRightChild(new Node<T>(_data));
	}

	// ���� �Լ�
	void Destroy()
	{
		// ����� �θ� �ִ� ��� ���� ����
		if (parent)
		{
			// �� ��尡 �θ��� ���� �ڼ��� ��
			if (parent->left == this)
			{
				parent->left = nullptr;
			}

			// �� ��尡 �θ��� ������ �ڼ��� ��
			if (parent->right == this)
			{
				parent->right = nullptr;
			}

			// �� ��带 ������ �ڼձ��� ��ȸ�ϸ鼭 ����
			DestroyRecursive(this);
		}
	}

private:

	//���� ��� �Լ�
	void DestroyRecursive(Node<T>* _node)
	{
		// Ż�� ����
		if (_node == nullptr)
		{
			return;
		}

		// �ڼ� ����� ���� Ȯ��
		Node<T>* leftChild = _node->left;
		Node<T>* rightChild = _node->right;
		
		// �ڼ��� ���� ���
		if (leftChild == nullptr && rightChild == nullptr)
		{
			delete _node;
			_node = nullptr;
			return;
		}

		// �ڼ� ��� �Լ�
		DestroyRecursive(leftChild);
		DestroyRecursive(rightChild);

		// ����
		delete _node;
		_node = nullptr;
	}

private:

	// ������
	T data;

	// �θ� ���
	Node<T>* parent = nullptr;

	// ���� �ڼ� ���
	Node<T>* left = nullptr;

	// ������ �ڼ� ���
	Node<T>* right = nullptr;
};