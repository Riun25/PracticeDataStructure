#include<forward_list>
#include <stack>
#include <iostream>

int main()
{
	std::forward_list<int> myList1;
	std::stack<int> myStack;

	for (int i = 1; i < 5; i++)
	{
		myList1.push_front(i * 10);
		myStack.push(i * 10);
	}

	std::cout << "== List 출력 == \n";
	for (auto& e : myList1)
	{
		std::cout << e << "\n";
	}

	std::cout << "== stack 출력 == \n";
	while (!myStack.empty())
	{
		std::cout << myStack.top() << "\n";
		myStack.pop();
	}

	std::forward_list<int> myList2;

	for (int i = 1; i < 5; i++)
	{
		myList2.push_front(i * 10);
	}


	return 0;
}