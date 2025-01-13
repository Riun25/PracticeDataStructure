#pragma once

#include "List.h"
#include "Node.h"

template<typename T>
class Tree
{
	// 친구 등록
	friend class Node<T>;

public:
	Tree(const T& _data)
	{
		// 루트 노드 생성
		root = new Node<T>(_data);
	}

	~Tree()
	{
		// @Todo : 재귀적으로 자손 노드 삭제
		DestroyRecursive(root);
	}

	// 부모 노드 값을 사용해 자손을 추가하는 함수
	void AddChild(const T& _parentData, const T& _childData)
	{
		// 부모 노드 검색
		Node<T>* parent = nullptr;
		if (FindRecursive(_parentData, root, &parent))
		{
			parent->AddChild(_childData);
			return;
		}
		std::cout << "해당 값을 찾는 부모 노드가 없어 추가 실패.\n";
	}

	// 자손 추가
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
		// 재귀적으로 함수 호출 및 결과 반환
		return RemoveRecursive(_data, root);
	}

	// 노드 검색 함수
	bool Find(const T& _data, Node<T>** _outNode)
	{
		// 재귀 검색 함수 호출 및 결과 반환
		return FindRecursive(_data, root, _outNode);
	}

	// 순회(방문)

	// 전위 순회(부모 -> 자손)
	void PreorderTraverse(int _depth = 0)
	{
		PreorderTraverseRecursive(root, _depth);
	}


private:
	// 전위 순회 재귀 함수
	void PreorderTraverseRecursive(Node<T>* _node, int _depth = 0)
	{
		// 종료 조건
		if (_node == nullptr)
		{
			return;
		}

		// 뎁스 출력
		for (int i = 0; i < _depth; i++)
		{
			std::cout << "  ";
		}

		// 부모 노드
		std::cout << _node->mData << "\n";

		// 자손 노드 출력
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

	// 노드 삭제 재귀 함수
	bool RemoveRecursive(const T& _data, Node<T>* _node)
	{
		// 삭제할 노드 검색
		Node<T>* outNode = nullptr;
		if (FindRecursive(_data, outNode))
		{
			// 검색 성공

			// 부모 노드의 자손 목록에서 제거
			Node<T>* parent = outNode->parent;
			if (parent != nullptr)
			{
				parent->children->Remove(outNode);
			}

			// 제거할 자손이 있는 경우에는 자손 제거
			List<Node<T>*>* children = outNode->children;
			while (children != nullptr && children->Size() > 0)
			{
				outNode->RemoveChild(children->At(0));
			}

			// 메모리 삭제
			delete outNode;
			outNode = nullptr;

			// 삭제 성공
			return true;
		}

		// 삭제 실패
		return false;
	}

	// 자손 노드를 포함해 모든 노드를 재귀적으로 삭제하는 함수
	void DestroyRecursive(Node<T>* _node)
	{
		// @Todo : 구현
		// 자손 리스트 확인 후 재귀적으로 삭제 진행
		List<Node<T>*>* children = _node->children;
		while (children != nullptr && children->Size() > 0)
		{
			Node<T>* child = children->At(0);
			DestroyRecursive(child);
		}

		// 부모 노드가 있으면 부모의 자손 목록에서 자신 제거
		Node<T>* parent = _node->parent;
		if (parent != nullptr)
		{
			parent->children->Remove(_node);
		}
		//삭제
		delete _node;
		_node = nullptr;
	}

	// 재귀적으로 검색하는 함수
	// _data : 검색에 사용할 값. 이 값을 가진 노드를 검색
	// _node : 검색 위치
	// _outNode : 검색에 성공했을 때 출력(반환)할 파라미터
	bool FindRecursive(const T& _data, Node<T>* _node, Node<T>** _outNode)
	{
		// 예외처리
		if (_node == nullptr)
		{
			*_outNode = nullptr;
			return false;
		}

		// 노드 검색에 성공한 경우
		if (_node->mData == _data)
		{
			*_outNode = _node;
			return true;
		}

		// 재귀적으로 자손 노드 검색 진행
		List<Node<T>*>* children = _node->children;
		int size = children->Size();
		for (int i = 0; i < size; i++)
		{
			// 자손 노드 검색
			Node<T>* child = children->At(i);
			bool result = FindRecursive(_data, child, _outNode);

			// 검색에 성공했으면 종료
			if (result == true)
			{
				return true;
			}
		}

		// 검색 실패
		*_outNode = nullptr;
		return false;
	}

private:

	// 루트 노드
	Node<T>* root = nullptr;
};