#pragma once
#include "Node.h"

// 노드를 사용해 자료를 저장하는 링크드 리스트
template <typename T>
class LinkedList
{
public:
	// 오류가 발생했을 때 실행할 함수를 저장할 함수 포인터 변수
	using ListEmptyErrorEvent = void(*)();

	// 비교 함수 타입 선언
	using Comparer = bool (*)(T& _left, T& _right);

public:
	LinkedList()
		:mpFirst(new Node<T>()), mpLast(new Node<T>())
	{
		mpFirst->mpNext = mpLast;
		mpLast->mpPrevious = mpFirst;
	}

	LinkedList(ListEmptyErrorEvent _errorEvent)
		: LinkedList<T>()
	{
		mErrorEvent = _errorEvent;
	}

	~LinkedList()
	{
		// Todo : 삭제 함수 구현 후 호출해야 함
		if (mCount > 0)
		{
			Clear();
		}

		delete mpFirst;
		delete mpLast;
	}

	// 리스트 안에 모든 노드를 제거하는 함수
	void Clear()
	{
		// 리스트가 비었으면 오류 호출
		if (mCount == 0)
		{
			RaiseEmptyErrorEvent();
			return;
		}

		// 첫 노드에서부터 시작
		Node<T>* pCurrent = mpFirst->mpNext;

		// 모든 노드 삭제
		while (pCurrent != nullptr && pCurrent != mpLast)
		{
			// 삭제 로직
			Node<T>* pNext = pCurrent->mpNext;
			delete pCurrent;
			pCurrent = pNext;
		}

		// 남은 데이터 정리
		mCount = 0;
		mpFirst->mpNext = mpLast;
		mpLast->mpPrevious = mpFirst;
	}

	// 리스트가 비었을 때 오류 이벤트를 발생시키는 함수
	// Invoke(간접 호출)
	void RaiseEmptyErrorEvent()
	{
		// 함수 포인터가 설정되었으면 해당 함수 호출
		if (mErrorEvent != nullptr)
		{
			mErrorEvent();
		}
	}

	// 헤드에 추가하는 함수
	void AddToFirst(const T& _data)
	{
		// 새 노드 생성
		Node<T>* newNode = new Node<T>(_data);

		// 새 노드의 다음 노드를 head->next 노드로 설정
		// 새 노드의 이전 노드를 head 노드로 설정
		Node<T>* nextNode = mpFirst->mpNext;
		newNode->mpNext = nextNode;
		newNode->mpPrevious = mpFirst;

		// 첫 노드(head-next)를 새 노드로 설정
		// 기존 첫 노드의 이전 노드를 새 노드로 설정
		mpFirst->mpNext = newNode;
		nextNode->mpPrevious = newNode;

		// 저장된 노드 수 증가 처리
		++mCount;
	}

	// 마지막에 추가하는 함수
	void AddToLast(const T& _data)
	{
		// 새 노드 생성
		Node<T>* newNode = new Node<T>(_data);

		Node<T>* previousNode = mpLast->mpPrevious;
		newNode->mpPrevious = previousNode;
		newNode->mpNext = mpLast;

		previousNode->mpNext = newNode;
		mpLast->mpPrevious = newNode;

		// 저장된 노드 수 증가 처리
		++mCount;
	}

	// 데이터를 지정해 검색 후 삭제하는 함수
	void Delete(const T& _data)
	{
		// 예외 처리
		if (mCount == 0)
		{
			RaiseEmptyErrorEvent();
			return;
		}

		// 삭제할 노드 검색
		Node<T>* deleteNode = mpFirst->mpNext;
		while (deleteNode != nullptr && deleteNode != mpLast)
		{
			// 찾았으면 루프 종료
			if (deleteNode->mData == _data)
			{
				break;
			}

			// 다음 노드로 이동(검색 계속 진행)
			deleteNode = deleteNode->mpNext;
		}

		// 예외 처리
		if (deleteNode == nullptr || deleteNode == mpLast)
		{
			RaiseEmptyErrorEvent();
			return;
		}

		// 노드 삭제
		deleteNode->mpPrevious->mpNext = deleteNode->mpNext;
		deleteNode->mpNext->mpPrevious = deleteNode->mpPrevious;

		delete deleteNode;

		// 저장된 요소의 수 감소 처리
		--mCount;
	}

	Node<T>* Find(const T& _data)
	{
		Node<T>* current = mpFirst->mpNext;

		while (current != nullptr && current != mpLast)
		{
			if (current->mData == _data)
			{
				return current;
			}
			current = current->mpNext;
		}
		return nullptr;
	}

	// 저장된 요소 출력 함수
	void Print()
	{
		Node<T>* current = mpFirst->mpNext;
		while (current != nullptr && current != mpLast)
		{
			std::cout << "Data: " << current->mData << "\n";
			current = current->mpNext;
		}
	}

	// 저장된 요소의 수 반환 함수(Getter)
	__forceinline int Count() const
	{
		return mCount;
	}

private:
	// 헤드 노드
	Node<T>* mpFirst = nullptr;

	// 마지막 노드
	Node<T>* mpLast = nullptr;

	// 저장된 자료 수를 나타내는 변수
	int mCount = 0;

	// 함수 포인터 변수
	ListEmptyErrorEvent mErrorEvent = nullptr;
};