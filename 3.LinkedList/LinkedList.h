#pragma once
#include <stack>
#include "Node.h"


// 노드를 사용해 자료를 저장하는 링크드 리스트
class LinkedList
{
public:
	LinkedList();
	~LinkedList();

	// 헤드에 추가하는 함수
	void AddToHead(int _data);

	// 맨 뒤에 삽입하는 함수
	void Insert(int _data);

	// 데이터를 지정해 검색 후 삭제하는 함수
	void Delete(int _data);

	// 저장된 요소 출력 함수
	void Print();

	// 뒤집은 것을 출력하는 함수
	void ReversePrint();

	// 스택에 넣는 경우
	void PushToStack(std::stack<int>& _stack);

	// 재귀 함수를 이용한 경우
	void RecursivePrint();

	// 저장된 요소의 수 반환 함수(Getter)
	int Count() const;

private:
	void RecursivePrint(Node* _node);
	// 포인터를 뒤집는 함수
	Node* Reverse();

private:
	// 헤드 노드
	Node* mpHead = nullptr;

	// 저장된 자료 수를 나타내는 변수
	int mCount = 0;
};