#pragma once
#include "Node.h"

template <typename T>
class BinaryTree
{
	template<typename T>
	friend class Node;

public:
	// ������
	BinaryTree(const T& _data)
	{
		root = new Node<T>(_data);
	}

	// �Ҹ���
	~BinaryTree()
	{
		// ��� ��� ����
		root->Destroy();
		delete root;
	}

	void AddLeftChild(const T& _parentData, const T& _childData)
	{
		// �θ� ��� �˻�
		Node<T>* outParent = nullptr;
		if (Find(_parentData, &outParent))
		{
			outParent->AddLeftChild(_childData);
			return;
		}

		// �˻� �����ϸ� �޽��� ���
		std::cout << "Error: �θ� ��带 ã�� ���� �ڼ� ��� �߰� ����.\n";
	}

	void AddRightChild(const T& _parentData, const T& _childData)
	{
		// �θ� ��� �˻�
		Node<T>* outParent = nullptr;
		if (Find(_parentData, &outParent))
		{
			outParent->AddRightChild(_childData);
			return;
		}

		// �˻� �����ϸ� �޽��� ���
		std::cout << "Error: �θ� ��带 ã�� ���� �ڼ� ��� �߰� ����.\n";
	}

	bool Find(const T& _data, Node<T>** _outNode)
	{
		return FindRecursive(_data, root, _outNode);
	}

	// �����͸� ������� ��带 �����ϴ� �Լ�
	bool DeleteNode(const T& _data)
	{
		// ���� ��� �˻�
		Node<T>* outNode = nullptr;
		if (Find(_data, &outNode))
		{
			// �˻��� ��� ����
			outNode->Destroy();
			return true;
		}

		// �˻��� ���������� �޽��� ���
		std::cout << "������ ��� �˻� ����. ���� ����.\n";
		return false;
	}

	// ���� ��ȸ �Լ�
	void PreorderTraverse(int _depth = 0)
	{
		std::cout << "���� ��ȸ ���� -----------\n";
		PreorderTraverseRecursive(root, _depth);
		std::cout << "���� ��ȸ �� -----------\n";
	}

private:
	void PreorderTraverseRecursive(Node<T>* _node, int _depth)
	{
		// Ż�� ����
		if (_node == nullptr)
		{
			return;
		}

		// ���� ���
		for (int i = 0; i < _depth; i++)
		{
			std::cout << " ";
		}

		// �θ� ��� ���
		std::cout << _node->data << "\n";

		// ���� ���� ��� ���
		PreorderTraverseRecursive(_node->left, _depth + 1);
		
		// ������ ���� ��� ���
		PreorderTraverseRecursive(_node->right, _depth + 1);
	}

	// �˻� ��� �Լ�
	bool FindRecursive(const T& _data, Node<T>* _node, Node<T>** _outNode)
	{
		// Ż�� ����
		if (_node == nullptr)
		{
			*_outNode = nullptr;
			return false;
		}

		// ���� ��忡�� �˻�
		if (_node->data == _data)
		{
			*_outNode = _node;
			return true;
		}

		// ���� ������ ������ �˻�
		if (FindRecursive(_data, _node->left, _outNode))
		{
			return true;
		}

		// ������ ������ ������ �˻�
		if (FindRecursive(_data, _node->right, _outNode))
		{
			return true;
		}

		// �˻� ����
		*_outNode = nullptr;
		return false;
	}

private:
	// ��Ʈ ���
	Node<T>* root = nullptr;



};