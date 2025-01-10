#include <iostream>
#include "HashTable.h"

int main()
{
	// �ؽ� ���̺� ��ü
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
		std::cout << "Ű : Jane �׸��� ã�ҽ��ϴ�.\n";
	}
	else
	{
		std::cout << "Ű : Jane �׸��� �� ã�ҽ��ϴ�.\n";
	}

	table.Delete("Riun");

	std::cout << "���� �� ���----\n";
	table.Print();

	std::cin.get();

	return 0;
}

