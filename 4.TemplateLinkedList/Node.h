#pragma once

#include <iostream>

// 링크드 리스트의 요소인 노드 클래스
template <typename T>
class Node
{
	template <typename T>
	friend class LinkedList;

public:
	Node()
		:mData()
	{ }
	Node(T _data)
		:mData(_data)
	{}

private:
	// 데이터 필드
	T mData;

	// 링크 필드
	Node<T>* mpNext = nullptr;
};