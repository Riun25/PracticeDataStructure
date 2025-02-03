#pragma once
#include "Node.h"

// 이진 탐색 트리 클래스
template<typename T>
class BinarySearchTree
{
public:
	BinarySearchTree()
		: root(nullptr)
	{ }

	~BinarySearchTree()
	{
		// 재귀 삭제 함수 호출
		Destroy();
	}

	// 검색
	// 메소드
	// 공개 / 감출지
	bool SearchNode(const T& _data)
	{
		// 루트부터 재귀적으로 검색
		return SearchNodeRecursive(root, _data);
	}

	// 삽입
	// 규칙 ->
	// 0. 중복 허용하지 않음
	// 1. 시작 -> 루트에서부터 비교 시작
	// 1-1. 루트가 비어 있으면 새 노드를 루트로 지정
	// 2. 새로 추가하는 값이 비교 노드보다 작으면 왼쪽 하위 트리로 비교를 이어간다.
	// 3. 새로 추가하는 값이 비교 노드보다 크면 오른쪽 하위 트리로 비교를 이어간다.
	bool InsertNode(const T& _newData)
	{
		// 중복을 허용하지 않기 때문에 이미 있으면 실패
		if (SearchNode(_newData))
		{
			// 오류 메시지 출력
			std::cout << "Error: 이미 중복된 값이 있어 추가 불가능.\n";
			return false;
		}

		// case1. 루트가 null
		if (root == nullptr)
		{
			// 루트 생성 후 성공
			root = new Node<T>(_newData);
			return true;
		}

		// case2/3. 재귀 함수로 처리
		root = InsertNodeRecursive(root, nullptr, _newData);
		return true;
	}

	// 삭제
	bool DeleteNode(const T& _deleteData)
	{
		// 삭제할 노드가 없으면 실패
		if (!SearchNode(_deleteData))
		{
			return false;
		}

		// 재귀적으로 검색해 삭제하는 함수 호출
		root = DeleteNodeRecursive(root, _deleteData);
		return true;
	}

	// 순회(중위 순회)
	void InorderedTraverse(int _depth = 0)
	{
		std::cout << "==== 중위 순회 시작 ====\n";

		// 재귀 함수 호출
		InorderedTraverseRecursive(root, _depth);

		std::cout << "==== 중위 순회 끝 ====\n";
	}
private:

	// node: 현재 방문하려는 노드
	// depth : 출력에 사용할 깊이 값
	void InorderedTraverseRecursive(Node<T>* _node, int _depth = 0)
	{
		// 종료 조건
		if (_node == nullptr)
		{
			// 깊이 출력
			for (int idx = 0; idx < _depth; ++idx)
			{
				// 두칸 빈간
				std::cout << "  ";
			}

			std::cout << "null\n";
			return;
		}

		// 왼쪽 하위 트리 방문
		InorderedTraverseRecursive(_node->left, _depth + 1);

		// 깊이 출력
		for (int idx = 0; idx < _depth; ++idx)
		{
			// 두칸 빈간
			std::cout << "  ";
		}

		// 부모 노드 방문
		std::cout << _node->data << "\n";

		// 오른쪽 하위 트리 방문
		InorderedTraverseRecursive(_node->right, _depth + 1);
	}

	// node : 현재 검색 대상 노드
	// deleteData : 삭제할 데이터
	Node<T>* DeleteNodeRecursive(Node<T>* _node, const T& _deleteData)
	{
		// 종료 조건
		if (_node == nullptr)
		{
			return nullptr;
		}

		// 작은 경우/ 큰 경우
		if (_node->data > _deleteData)
		{
			_node->left = DeleteNodeRecursive(_node->left, _deleteData);
		}
		else if (_node->data < _deleteData)
		{
			_node->right = DeleteNodeRecursive(_node->right, _deleteData);
		}
		else // 삭제할 노드를 찾은 경우
		{
			// 1. 자식이 없는 경우
			if (_node->left == nullptr && _node->right == nullptr)
			{
				// 노드 삭제 후 종료
				delete _node;
				return nullptr;
			}

			// 2. 자식이 둘인 경우
			if (_node->left && _node->right)
			{
				// 왼쪽에서 최대값 또는 오른쪽에서 최소값 노드 찾기
				_node->data = SearchMinValue(_node->right)->data;

				// 위에서 구한 가장 작은 값을 가진 노드 삭제
				_node->right = DeleteNodeRecursive(_node->right, _node->data);
				 
			}
			
			// 3. 자식이 하나인 경우
			if (_node->left && _node->right == nullptr ||
				_node->left == nullptr && _node->right)
			{
				// 왼쪽 자식만 있는 경우
				if (_node->left != nullptr)
				{
					// 임시 저장
					Node<T>* left = _node->left;

					// 삭제
					delete _node;

					// 왼쪽 자손 반환
					return left;
				}

				// 오른쪽 자식만 있는 경우
				else if (_node->right != nullptr)
				{
					// 임시 저장
					Node<T>* right = _node->right;

					// 삭제
					delete _node;

					// 오른쪽 자손 반환
					return right;
				}
			}
		}
		return _node;
	}

	// 최소값을 검색하는 함수
	// node : 검색을 시작하는 노드
	Node<T>* SearchMinValue(Node<T>* _node)
	{
		// 왼쪽 노드가 없을 때까지 찾은 후 반환
		while (_node->left != nullptr)
		{
			_node = _node->left;
		}
		return _node;
	}

	// 재귀적으로 타겟 데이터를 검색하는 함수
	bool SearchNodeRecursive(Node<T>* _node, const T& _data)
	{
		// 검색 실패
		if (_node == nullptr)
		{
			return false;
		}

		// 검색 성공
		if (_node->data == _data)
		{
			return true;
		}

		// 작으면 왼쪽으로, 크면 오른쪽으로 검색
		if (_node->data > _data)
		{
			return SearchNodeRecursive(_node->left, _data);
		}
		else
		{
			return SearchNodeRecursive(_node->right, _data);
		}
	}

	// node : 현재 비교하는 노드
	// parent : node의 부모 노드
	// newData : 삽입하려는 데이터
	Node<T>* InsertNodeRecursive(Node<T>* _node, Node<T>* _parent, const T& _newData)
	{
		// node가 nullptr이면 추가
		if (_node == nullptr)
		{
			return new Node<T>(_newData, _parent); 
		}

		// 작은 경우
		if (_node->data > _newData)
		{
			_node->left = InsertNodeRecursive(_node->left, _node, _newData);
		}

		// 큰 경우
		else
		{
			_node->right = InsertNodeRecursive(_node->right, _node, _newData);
		}

		return _node;
	}

	// 모든 노드를 제거할 때 사용하는 함수.
	void Destroy()
	{
		// 루트 노드가 null이면 종료.
		if (root == nullptr)
		{
			return;
		}

		// 왼쪽 자손 > 오른쪽 자손 > 루트 순으로 제거.
		DestroyRecursive(root);
	}

	void DestroyRecursive(Node<T>* node)
	{
		// 재귀함수 종료 조건.
		if (node == nullptr)
		{
			return;
		}

		// 왼쪽 자손 / 오른쪽 자손 확인.
		Node<T>* left = node->left;
		Node<T>* right = node->right;

		// 자손이 없는 경우.
		if (left == nullptr && right == nullptr)
		{
			// 노드 삭제 후 함수 종료.
			delete node;
			return;
		}

		DestroyRecursive(left);
		DestroyRecursive(right);

		delete node;
	}

private:
	// 루트 노드
	Node<T>* root;
};