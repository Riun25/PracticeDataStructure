#include <list>
#include <iostream>

// 아이템 구조체
struct Item
{
	Item(int code = 0, int price = 0)
		:code(code), price(price)
	{
	}

	int code = 0;		// 아이템 코드
	int price = 0;		// 아이템 가격
};

// 데이터 출력용 연산자 오버로딩
std::ostream& operator<<(std::ostream& os, const Item& item)
{
	return os << "코드: " << item.code << ", 가격: " << item.price << "\n";
}

// 아이템 코드를 기준으로 정렬하는 함수 객체(Functor)
struct ItemLessComparer
{
	bool operator()(const Item& left, const Item& right)
	{
		return left.code < right.code;
	}
};

int main()
{
	// 리스트 생성
	std::list<Item> itemList;

	// 데이터 추가
	itemList.emplace_front(Item(1, 200));
	itemList.emplace_front(Item(2, 1000));

	// 뒤에 추가
	itemList.emplace_front(Item(3, 3000));
	itemList.emplace_front(Item(4, 4500));

	// 출력
	for (/*std::list<Item>::iterator*/auto iterator = itemList.begin();
		iterator != itemList.end(); ++iterator)
	{
		// 반복자(Iterator)는 포인터이기 때문에 데이터를 읽을 때는 *을 붙여야 함
		std::cout << *iterator;
	}

	// 삭제
	itemList.pop_front();

	// 맨 앞에 있는 데이터 읽기
	Item frontItem = itemList.front();

	// 출력
	std::cout << frontItem;

	itemList.emplace_front(Item(8, 9000));
	itemList.emplace_front(Item(6, 4500));
	itemList.emplace_front(Item(7, 700));
	itemList.emplace_front(Item(5, 800));

	// 정렬
	itemList.sort(ItemLessComparer());

	// 정렬 후 출력
	std::cout << "----- 정렬 후 출력 -----\n";
	for (auto& item : itemList)
	{
		std::cout << item;
	}

	// 정렬2
	itemList.sort([](const Item& left, const Item& right)
		{
			return left.code > right.code;
		}
	);

	// 정렬 후 출력
	std::cout << "----- 정렬2 후 출력 -----\n";
	for (auto& item : itemList)
	{
		std::cout << item;
	}

	std::cin.get();
}