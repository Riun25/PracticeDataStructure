#include <iostream>
#include "List.h"

int main()
{
	List<int> list;

	list.Insert(10.0f);
	list.Insert(40.0f);
	list.Insert(20.0f);
	list.Insert(30.0f);
	list.Insert(50.0f);

	std::cout << "----- 리스트 데이터 출력 ----\n";
	list.Print();
	std::cout << "----- 리스트 데이터 출력 ----\n";
	list.Reverse();
	list.Print();

	return 0;
}