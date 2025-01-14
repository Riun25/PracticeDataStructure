#pragma once
#include "Node.h"

template <typename T>
class BinaryTree
{
	template<typename T>
	friend class Node;

public:
	// 생성자
	BinaryTree(const T& _data)
	{
		root = new Node<T>(_data);
	}

	// 소멸자
	~BinaryTree()
	{
		// 모든 노드 제거
		root->Destroy();
		delete root;
	}

	void AddLeftChild(const T& _parentData, const T& _childData)
	{
		// 부모 노드 검색
		Node<T>* outParent = nullptr;
		if (Find(_parentData, &outParent))
		{
			outParent->AddLeftChild(_childData);
			return;
		}

		// 검색 실패하면 메시지 출력
		std::cout << "Error: 부모 노드를 찾지 못해 자손 노드 추가 실패.\n";
	}

	void AddRightChild(const T& _parentData, const T& _childData)
	{
		// 부모 노드 검색
		Node<T>* outParent = nullptr;
		if (Find(_parentData, &outParent))
		{
			outParent->AddRightChild(_childData);
			return;
		}

		// 검색 실패하면 메시지 출력
		std::cout << "Error: 부모 노드를 찾지 못해 자손 노드 추가 실패.\n";
	}

	bool Find(const T& _data, Node<T>** _outNode)
	{
		return FindRecursive(_data, root, _outNode);
	}

	// 데이터를 기반으로 노드를 삭제하는 함수
	bool DeleteNode(const T& _data)
	{
		// 삭제 노드 검색
		Node<T>* outNode = nullptr;
		if (Find(_data, &outNode))
		{
			// 검색된 노드 제거
			outNode->Destroy();
			return true;
		}

		// 검색에 실패했으면 메시지 출력
		std::cout << "삭제할 노드 검색 실패. 삭제 실패.\n";
		return false;
	}

	// 전위 순회 함수
	void PreorderTraverse(int _depth = 0)
	{
		std::cout << "전위 순회 시작 -----------\n";
		PreorderTraverseRecursive(root, _depth);
		std::cout << "전위 순회 끝 -----------\n";
	}

private:
	void PreorderTraverseRecursive(Node<T>* _node, int _depth)
	{
		// 탈출 조건
		if (_node == nullptr)
		{
			return;
		}

		// 뎁스 출력
		for (int i = 0; i < _depth; i++)
		{
			std::cout << " ";
		}

		// 부모 노드 출력
		std::cout << _node->data << "\n";

		// 왼쪽 하위 노드 출력
		PreorderTraverseRecursive(_node->left, _depth + 1);
		
		// 오른쪽 하위 노드 출력
		PreorderTraverseRecursive(_node->right, _depth + 1);
	}

	// 검색 재귀 함수
	bool FindRecursive(const T& _data, Node<T>* _node, Node<T>** _outNode)
	{
		// 탈출 조건
		if (_node == nullptr)
		{
			*_outNode = nullptr;
			return false;
		}

		// 현재 노드에서 검색
		if (_node->data == _data)
		{
			*_outNode = _node;
			return true;
		}

		// 왼쪽 하위로 내려가 검색
		if (FindRecursive(_data, _node->left, _outNode))
		{
			return true;
		}

		// 오른쪽 하위로 내려가 검색
		if (FindRecursive(_data, _node->right, _outNode))
		{
			return true;
		}

		// 검색 실패
		*_outNode = nullptr;
		return false;
	}

private:
	// 루트 노드
	Node<T>* root = nullptr;



};