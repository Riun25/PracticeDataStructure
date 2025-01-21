#include <iostream>
#include "LinkedList.h"
#include "Node.h"

int main()
{
	LinkedList<int> list;

	list.Insert(10.0f);
	list.Insert(40.0f);
	list.Insert(20.0f);
	list.Insert(30.0f);
	list.Insert(50.0f);

	std::cout << "----- 리스트 데이터 출력 ----\n";
	list.Print();

	list.Delete(30.0f);
	list.Delete(50.0f);

	std::cout << "----- 리스트 데이터 삭제 후 출력 ----\n";
	list.Print();

	std::cin.get();

	return 0;


	return 0;
}