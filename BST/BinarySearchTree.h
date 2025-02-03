#pragma once
#include "Node.h"

// ���� Ž�� Ʈ�� Ŭ����
template<typename T>
class BinarySearchTree
{
public:
	BinarySearchTree()
		: root(nullptr)
	{ }

	~BinarySearchTree()
	{
		// ��� ���� �Լ� ȣ��
		Destroy();
	}

	// �˻�
	// �޼ҵ�
	// ���� / ������
	bool SearchNode(const T& _data)
	{
		// ��Ʈ���� ��������� �˻�
		return SearchNodeRecursive(root, _data);
	}

	// ����
	// ��Ģ ->
	// 0. �ߺ� ������� ����
	// 1. ���� -> ��Ʈ�������� �� ����
	// 1-1. ��Ʈ�� ��� ������ �� ��带 ��Ʈ�� ����
	// 2. ���� �߰��ϴ� ���� �� ��庸�� ������ ���� ���� Ʈ���� �񱳸� �̾��.
	// 3. ���� �߰��ϴ� ���� �� ��庸�� ũ�� ������ ���� Ʈ���� �񱳸� �̾��.
	bool InsertNode(const T& _newData)
	{
		// �ߺ��� ������� �ʱ� ������ �̹� ������ ����
		if (SearchNode(_newData))
		{
			// ���� �޽��� ���
			std::cout << "Error: �̹� �ߺ��� ���� �־� �߰� �Ұ���.\n";
			return false;
		}

		// case1. ��Ʈ�� null
		if (root == nullptr)
		{
			// ��Ʈ ���� �� ����
			root = new Node<T>(_newData);
			return true;
		}

		// case2/3. ��� �Լ��� ó��
		root = InsertNodeRecursive(root, nullptr, _newData);
		return true;
	}

	// ����
	bool DeleteNode(const T& _deleteData)
	{
		// ������ ��尡 ������ ����
		if (!SearchNode(_deleteData))
		{
			return false;
		}

		// ��������� �˻��� �����ϴ� �Լ� ȣ��
		root = DeleteNodeRecursive(root, _deleteData);
		return true;
	}

	// ��ȸ(���� ��ȸ)
	void InorderedTraverse(int _depth = 0)
	{
		std::cout << "==== ���� ��ȸ ���� ====\n";

		// ��� �Լ� ȣ��
		InorderedTraverseRecursive(root, _depth);

		std::cout << "==== ���� ��ȸ �� ====\n";
	}
private:

	// node: ���� �湮�Ϸ��� ���
	// depth : ��¿� ����� ���� ��
	void InorderedTraverseRecursive(Node<T>* _node, int _depth = 0)
	{
		// ���� ����
		if (_node == nullptr)
		{
			// ���� ���
			for (int idx = 0; idx < _depth; ++idx)
			{
				// ��ĭ ��
				std::cout << "  ";
			}

			std::cout << "null\n";
			return;
		}

		// ���� ���� Ʈ�� �湮
		InorderedTraverseRecursive(_node->left, _depth + 1);

		// ���� ���
		for (int idx = 0; idx < _depth; ++idx)
		{
			// ��ĭ ��
			std::cout << "  ";
		}

		// �θ� ��� �湮
		std::cout << _node->data << "\n";

		// ������ ���� Ʈ�� �湮
		InorderedTraverseRecursive(_node->right, _depth + 1);
	}

	// node : ���� �˻� ��� ���
	// deleteData : ������ ������
	Node<T>* DeleteNodeRecursive(Node<T>* _node, const T& _deleteData)
	{
		// ���� ����
		if (_node == nullptr)
		{
			return nullptr;
		}

		// ���� ���/ ū ���
		if (_node->data > _deleteData)
		{
			_node->left = DeleteNodeRecursive(_node->left, _deleteData);
		}
		else if (_node->data < _deleteData)
		{
			_node->right = DeleteNodeRecursive(_node->right, _deleteData);
		}
		else // ������ ��带 ã�� ���
		{
			// 1. �ڽ��� ���� ���
			if (_node->left == nullptr && _node->right == nullptr)
			{
				// ��� ���� �� ����
				delete _node;
				return nullptr;
			}

			// 2. �ڽ��� ���� ���
			if (_node->left && _node->right)
			{
				// ���ʿ��� �ִ밪 �Ǵ� �����ʿ��� �ּҰ� ��� ã��
				_node->data = SearchMinValue(_node->right)->data;

				// ������ ���� ���� ���� ���� ���� ��� ����
				_node->right = DeleteNodeRecursive(_node->right, _node->data);
				 
			}
			
			// 3. �ڽ��� �ϳ��� ���
			if (_node->left && _node->right == nullptr ||
				_node->left == nullptr && _node->right)
			{
				// ���� �ڽĸ� �ִ� ���
				if (_node->left != nullptr)
				{
					// �ӽ� ����
					Node<T>* left = _node->left;

					// ����
					delete _node;

					// ���� �ڼ� ��ȯ
					return left;
				}

				// ������ �ڽĸ� �ִ� ���
				else if (_node->right != nullptr)
				{
					// �ӽ� ����
					Node<T>* right = _node->right;

					// ����
					delete _node;

					// ������ �ڼ� ��ȯ
					return right;
				}
			}
		}
		return _node;
	}

	// �ּҰ��� �˻��ϴ� �Լ�
	// node : �˻��� �����ϴ� ���
	Node<T>* SearchMinValue(Node<T>* _node)
	{
		// ���� ��尡 ���� ������ ã�� �� ��ȯ
		while (_node->left != nullptr)
		{
			_node = _node->left;
		}
		return _node;
	}

	// ��������� Ÿ�� �����͸� �˻��ϴ� �Լ�
	bool SearchNodeRecursive(Node<T>* _node, const T& _data)
	{
		// �˻� ����
		if (_node == nullptr)
		{
			return false;
		}

		// �˻� ����
		if (_node->data == _data)
		{
			return true;
		}

		// ������ ��������, ũ�� ���������� �˻�
		if (_node->data > _data)
		{
			return SearchNodeRecursive(_node->left, _data);
		}
		else
		{
			return SearchNodeRecursive(_node->right, _data);
		}
	}

	// node : ���� ���ϴ� ���
	// parent : node�� �θ� ���
	// newData : �����Ϸ��� ������
	Node<T>* InsertNodeRecursive(Node<T>* _node, Node<T>* _parent, const T& _newData)
	{
		// node�� nullptr�̸� �߰�
		if (_node == nullptr)
		{
			return new Node<T>(_newData, _parent); 
		}

		// ���� ���
		if (_node->data > _newData)
		{
			_node->left = InsertNodeRecursive(_node->left, _node, _newData);
		}

		// ū ���
		else
		{
			_node->right = InsertNodeRecursive(_node->right, _node, _newData);
		}

		return _node;
	}

	// ��� ��带 ������ �� ����ϴ� �Լ�.
	void Destroy()
	{
		// ��Ʈ ��尡 null�̸� ����.
		if (root == nullptr)
		{
			return;
		}

		// ���� �ڼ� > ������ �ڼ� > ��Ʈ ������ ����.
		DestroyRecursive(root);
	}

	void DestroyRecursive(Node<T>* node)
	{
		// ����Լ� ���� ����.
		if (node == nullptr)
		{
			return;
		}

		// ���� �ڼ� / ������ �ڼ� Ȯ��.
		Node<T>* left = node->left;
		Node<T>* right = node->right;

		// �ڼ��� ���� ���.
		if (left == nullptr && right == nullptr)
		{
			// ��� ���� �� �Լ� ����.
			delete node;
			return;
		}

		DestroyRecursive(left);
		DestroyRecursive(right);

		delete node;
	}

private:
	// ��Ʈ ���
	Node<T>* root;
};