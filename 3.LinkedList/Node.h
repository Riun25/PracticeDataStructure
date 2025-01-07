#pragma once

#include <iostream>

// 링크드 리스트의 요소인 노드 클래스
class Node
{
	// std::cout에 쉽게 출력할 수 있도록 오버로딩
	friend std::ostream& operator<<(std::ostream& _os, const Node& _node);

	// 에외
	friend class LinkedList;

public:
	Node();
	Node(int _data);

private:
	// 데이터 필드
	int mData = 0;

	// 링크 필드
	Node* mpNext = nullptr;
};