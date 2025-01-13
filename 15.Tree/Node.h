#pragma once


#include "List.h"

// Ʈ���� ��� Ŭ����
template <typename T>
class Node
{
	// ģ�� ���
	template<typename T>
	friend class Tree;

public:
	Node(const T& _data = T()) 
		: mData(_data)
	{
		// �ڼ� ��� ������ ����Ʈ ����
		children = new List<Node<T>*>();
	}

	// ���� ������ ����
	Node(const Node& _other) = delete;

	// �Ҹ���
	~Node()
	{
		parent = nullptr;
		if (children)
		{
			delete children;
			children = nullptr;
		}
	}

	// ���� �����ؼ� �ڼ��� �߰��ϴ� �Լ�
	void AddChild(const T& _newData)
	{
		AddChild(new Node<T>(_newData));
	}

	void AddChild(Node<T>* _newChild)
	{
		// �θ� ��� ����
		_newChild->parent = this;

		// �ڼ� ��� ����Ʈ�� ���ο� �ڼ� �߰�
		children->PushBack(_newChild);
	}

	// �ڼ� ���� �Լ� - ������ �ڼ� ��带 ������ ����
	void RemoveChild(Node<T>& _child)
	{
		// @Todo : ��������� �˻��ؼ� ����
		RemoveChildRecursive(_child);
	}

	// ���� ��带 ������ ����� ���� ��ȯ�ϴ� �Լ�
	int GetCount()
	{
		// ��� ���� �� �� �ڽ� ����
		int count = 1;

		// �ڼ� ��� �� ����
		for (int i = 0; i < children->Size(); i++)
		{
			count += children->At(i)->GetCount();
		}

		// ī��Ʈ ��ȯ
		return count;
	}

private:
	// ��������� �����ϴ� �Լ�
	void RemoveChildRecursive(Node<T>* _child)
	{
		// ����ó��
		if (_child == nullptr)
		{
			return;
		}

		// ã�Ƽ� ����

		// ���� ��� ����Ʈ Ȯ��
		List<Node<T>*>* children = _child->children;

		// ����� ��1: �ڼ��� ���� ���
		// children�� null�̰ų� ũ�Ⱑ 0�� ���
		if (children == nullptr || children->Size() == 0)
		{
			// �θ��� �ڼ� ��Ͽ��� �ڽ��� ����
			_child->parent->children->Remove(_child);

			// ��� ����
			delete _child;
			_child = nullptr;

			return;
		}

		// ����� ��2 : �ڼ��� �ִ� ���
		while (children != nullptr && children->Size() > 0)
		{
			// �ڼ��� ��ȸ�ϸ鼭 ��������� �ڼ��� ���� ��� ����
			RemoveChildRecursive(children->At(0));
		}

		// ��� �ڼ��� ������ �Ŀ� �θ� ��忡�� ����
		_child->parent->children->Remove(_child);

		// �޸� ����
		delete _child;
		_child = nullptr;
	}

private:
	// ��忡 �����ϴ� ������
	T mData;

	// �θ� ��� ���� ����
	Node<T>* parent = nullptr;

	// �ڼ� ��� ���
	List<Node<T>*>* children = nullptr;
};