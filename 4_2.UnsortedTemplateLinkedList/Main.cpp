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

	std::cout << "----- ����Ʈ ������ ��� ----\n";
	list.Print();
	std::cout << "----- ����Ʈ ������ ��� ----\n";
	list.Reverse();
	list.Print();

	return 0;
}