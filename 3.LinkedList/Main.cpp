#include <iostream>
#include "LinkedList.h"
#include <stack>

int main()
{
	LinkedList list;

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

	std::cout << "----- ����Ʈ ������ ������ �� ��� ----\n";
	list.ReversePrint();

	std::cout << "----- ����Ʈ ������ ������ �� ��� ----\n";
	std::stack<int> myStack;

	for (int i = 0; list.Count(); i++)
	{
		myStack.push(i);
	}

	for (int i = 0; myStack.size(); i++)
	{
		std::cout << myStack.top() << "\n";
		myStack.pop();
	}

	std::cin.get();

	return 0;
}