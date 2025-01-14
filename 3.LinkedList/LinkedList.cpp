#include "LinkedList.h"

LinkedList::LinkedList()
{
}

LinkedList::~LinkedList()
{
	if (mpHead != nullptr)
	{
		Node* current = mpHead;
		Node* deleteNode = nullptr;
		while (current != nullptr)
		{
			deleteNode = current;
			current = current->mpNext;

			delete deleteNode;
		}
	}
}

void LinkedList::AddToHead(int _data)
{
	// 새 노드 생성
	Node* newNode = new Node(_data);

	// #1. 현재 헤드가 없는 경우
	if (mpHead == nullptr)
	{
		mpHead = newNode;
	}
	// #2. 헤드가 있는 경우
	else
	{
		// 새 노드의 다음 노드를 기존의 헤드 노드로 설정
		newNode->mpNext = mpHead;

		// 헤드 노드를 새 노드로 교체
		mpHead = newNode;
	}

	// 저장된 노드 수 증가 처리
	++mCount;
}

void LinkedList::Insert(int _data)
{
	// 새 노드 생성
	Node* newNode = new Node(_data);

	// 삽입할 위치 찾기

	// #1. 헤드가 비어 있는 경우
	if (mpHead == nullptr)
	{
		mpHead = newNode;
	}
	// 삽일할 위치를 검색 후 노드 삽입
	else
	{
		// 노드 포인터 2개를 사용해 검색
		Node* current = mpHead;
		Node* trail = nullptr;

		// 위치 검색
		while (current != nullptr)
		{
			// 값 비교
			if (current->mData >= _data)
			{
				break;
			}

			// 다음 노드로 이동
			trail = current;
			current = current->mpNext;
		}

		// 검색된 결과를 확인해서 처리
		if (current == mpHead)
		{
			newNode->mpNext = mpHead;
			mpHead = newNode;
		}
		else
		{
			newNode->mpNext = current;
			trail->mpNext = newNode;
		}
	}
	// 요소 수 증가 처리
	++mCount;
}

void LinkedList::Delete(int _data)
{
	// 삭제할 노드 찾기
	// 예외 처리
	if (mpHead == nullptr)
	{
		std::cout << "리스트가 비어있어 삭제가 불가능합니다.\n";
		return;
	}

	// 검색 진행
	Node* current = mpHead;
	Node* trail = nullptr;

	while (current != nullptr)
	{
		// 값 비교
		if (current->mData == _data)
		{
			break;
		}

		// 노드 이동
		trail = current;
		current = current->mpNext;
	}

	// 검색의 결과 2가지
	// #1 못 찾은 경우
	if (current == nullptr)
	{
		std::cout << "값 " << _data << "를 찾지 못했습니다.\n";
		return;
	}
	// #2 찾은 경우
	else if (current == mpHead)
	{
		mpHead = mpHead->mpNext;
	}
	else
	{
		trail->mpNext = current->mpNext;
	}

	// 노드 삭제
	delete current;

	// 저장된 요소의 수 감소 처리
	--mCount;
}

void LinkedList::Print()
{
	Node* current = mpHead;
	while (current != nullptr)
	{
		std::cout << *current << "\n";
		current = current->mpNext;
	}
}

Node* LinkedList::Reverse()
{
	Node* first = nullptr;
	Node* current = mpHead;
	Node* last = nullptr;

	while (current != nullptr)
	{
		last = current->mpNext; // 내 다음 노드를 복사해둔다.
		current->mpNext = first; // 내 다음 노드를 이전 노드로 바꾼다.
		first = current; // 포인터를 다 옮겨줬으니 노드를 바꾼다.
		current = last;
	}
	return first;
}

void  LinkedList::ReversePrint()
{
	mpHead = Reverse();
	Print();
}

int LinkedList::Count() const
{
	return mCount;
}
