#include <iostream>
#include "LinkedList.h"
#include "Node.h"

int main()
{
	LinkedList<int> list;

	list.Insert(10);
	list.Insert(20);
	list.Insert(30);
	list.Insert(40);
	list.Insert(50);

	std::cout << "----- ����Ʈ ������ ��� ----\n";
	list.Print();

	list.Delete(30);
	list.Delete(50);

	std::cout << "----- ����Ʈ ������ ���� �� ��� ----\n";
	list.Print();

	std::cin.get();

	return 0;


	return 0;
}