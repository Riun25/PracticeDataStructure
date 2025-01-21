#pragma once

template <typename T>
class Node
{
	template <typename T>
	friend class List;

public:
	Node() {}
	Node(T _data) : mData(_data) {}

private:
	T mData = T();
	Node<T>* mpNext = nullptr;
};

