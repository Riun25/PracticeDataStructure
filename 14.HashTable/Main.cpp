#include <iostream>
#include "HashTable.h"

int main()
{
	// 해시 테이블 객체
	HashTable table;

	table.Add("Riun", "010-12345678");
	table.Add("James", "010-12345678");
	table.Add("Riun", "010-12345678");
	table.Add("Jane", "010-12345678");
	table.Add("Jenifer", "010-12345678");
	table.Print();

	Pair<std::string, std::string> value;
	if (table.Find("Jane", value))
	{
		std::cout << "키 : Jane 항목을 찾았습니다.\n";
	}
	else
	{
		std::cout << "키 : Jane 항목을 못 찾았습니다.\n";
	}

	table.Delete("Riun");

	std::cout << "삭제 후 출력----\n";
	table.Print();

	std::cin.get();

	return 0;
}

