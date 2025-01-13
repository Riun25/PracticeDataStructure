#pragma once

#include "List.h"
#include "Node.h"

template<typename T>
class Tree
{
	// ģ�� ���
	friend class Node<T>;

public:
	Tree(const T& _data)
	{
		// ��Ʈ ��� ����
		root = new Node<T>(_data);
	}

	~Tree()
	{
		// @Todo : ��������� �ڼ� ��� ����
		DestroyRecursive(root);
	}

	// �θ� ��� ���� ����� �ڼ��� �߰��ϴ� �Լ�
	void AddChild(const T& _parentData, const T& _childData)
	{
		// �θ� ��� �˻�
		Node<T>* parent = nullptr;
		if (FindRecursive(_parentData, root, &parent))
		{
			parent->AddChild(_childData);
			return;
		}
		std::cout << "�ش� ���� ã�� �θ� ��尡 ���� �߰� ����.\n";
	}

	// �ڼ� �߰�
	void AddChild(Node<T>* _child, Node<T>* _parent = nullptr)
	{
		_child->parent = _parent == nullptr ? root : _parent;
		_child->parent->AddChild(_child);
	}

	void AddChild(const T& _data, Node<T>* _parent = nullptr)
	{
		AddChild(new Node<T>(_data), _parent);
	}

	bool Remove(const T& _data)
	{
		// ��������� �Լ� ȣ�� �� ��� ��ȯ
		return RemoveRecursive(_data, root);
	}

	// ��� �˻� �Լ�
	bool Find(const T& _data, Node<T>** _outNode)
	{
		// ��� �˻� �Լ� ȣ�� �� ��� ��ȯ
		return FindRecursive(_data, root, _outNode);
	}

	// ��ȸ(�湮)

	// ���� ��ȸ(�θ� -> �ڼ�)
	void PreorderTraverse(int _depth = 0)
	{
		PreorderTraverseRecursive(root, _depth);
	}


private:
	// ���� ��ȸ ��� �Լ�
	void PreorderTraverseRecursive(Node<T>* _node, int _depth = 0)
	{
		// ���� ����
		if (_node == nullptr)
		{
			return;
		}

		// ���� ���
		for (int i = 0; i < _depth; i++)
		{
			std::cout << "  ";
		}

		// �θ� ���
		std::cout << _node->mData << "\n";

		// �ڼ� ��� ���
		List<Node<T>*>* children = _node->children;
		if (children->Size() == 0)
		{
			return;
		}

		for (int i = 0; i < children->Size(); i++)
		{
			Node<T>* child = children->At(i);
			PreorderTraverseRecursive(child, _depth + 1);
		}
	}

	// ��� ���� ��� �Լ�
	bool RemoveRecursive(const T& _data, Node<T>* _node)
	{
		// ������ ��� �˻�
		Node<T>* outNode = nullptr;
		if (FindRecursive(_data, outNode))
		{
			// �˻� ����

			// �θ� ����� �ڼ� ��Ͽ��� ����
			Node<T>* parent = outNode->parent;
			if (parent != nullptr)
			{
				parent->children->Remove(outNode);
			}

			// ������ �ڼ��� �ִ� ��쿡�� �ڼ� ����
			List<Node<T>*>* children = outNode->children;
			while (children != nullptr && children->Size() > 0)
			{
				outNode->RemoveChild(children->At(0));
			}

			// �޸� ����
			delete outNode;
			outNode = nullptr;

			// ���� ����
			return true;
		}

		// ���� ����
		return false;
	}

	// �ڼ� ��带 ������ ��� ��带 ��������� �����ϴ� �Լ�
	void DestroyRecursive(Node<T>* _node)
	{
		// @Todo : ����
		// �ڼ� ����Ʈ Ȯ�� �� ��������� ���� ����
		List<Node<T>*>* children = _node->children;
		while (children != nullptr && children->Size() > 0)
		{
			Node<T>* child = children->At(0);
			DestroyRecursive(child);
		}

		// �θ� ��尡 ������ �θ��� �ڼ� ��Ͽ��� �ڽ� ����
		Node<T>* parent = _node->parent;
		if (parent != nullptr)
		{
			parent->children->Remove(_node);
		}
		//����
		delete _node;
		_node = nullptr;
	}

	// ��������� �˻��ϴ� �Լ�
	// _data : �˻��� ����� ��. �� ���� ���� ��带 �˻�
	// _node : �˻� ��ġ
	// _outNode : �˻��� �������� �� ���(��ȯ)�� �Ķ����
	bool FindRecursive(const T& _data, Node<T>* _node, Node<T>** _outNode)
	{
		// ����ó��
		if (_node == nullptr)
		{
			*_outNode = nullptr;
			return false;
		}

		// ��� �˻��� ������ ���
		if (_node->mData == _data)
		{
			*_outNode = _node;
			return true;
		}

		// ��������� �ڼ� ��� �˻� ����
		List<Node<T>*>* children = _node->children;
		int size = children->Size();
		for (int i = 0; i < size; i++)
		{
			// �ڼ� ��� �˻�
			Node<T>* child = children->At(i);
			bool result = FindRecursive(_data, child, _outNode);

			// �˻��� ���������� ����
			if (result == true)
			{
				return true;
			}
		}

		// �˻� ����
		*_outNode = nullptr;
		return false;
	}

private:

	// ��Ʈ ���
	Node<T>* root = nullptr;
};