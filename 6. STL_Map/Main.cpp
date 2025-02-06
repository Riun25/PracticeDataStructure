// Map (Key, Value)
#include <iostream>
#include <string>
#include <map>
#include <Windows.h>
#include <io.h>
#include <fcntl.h>
// ����ü
struct Item
{
	std::wstring name;
	unsigned int kind = 0;
	int price = 0;
	int code = 0;
};

// ����� ���� ������ �����ε�
std::wostream& operator<<(std::wostream& os, const Item& item)
{
	return os << TEXT("�̸�: ") << item.name << TEXT(", ����: ") << item.price << TEXT(", �ڵ�: ") << item.code;
}

int main()
{
	_setmode(_fileno(stdout), _O_U16TEXT);

	// �� ����
	std::map<std::wstring, Item, std::greater<std::wstring>> items;

	//  ������ �߰�
	items.insert({ TEXT("���"), {TEXT("���"), 1, 200, 0} });
	items.insert({ TEXT("�ظ�"), {TEXT("�ظ�"), 1, 1000, 4} });
	items.insert({ TEXT("����"), {TEXT("����"), 2, 500, 3} });

	// ���� Ȯ�� �� ���
	if (!items.empty())
	{
		std::wcout << TEXT("����� ������ ��: ") << items.size() << "\n";
	}

	// ���
	for (auto& pair : items)
	{
		std::wcout << pair.second << "\n";
	}

	// �˻�.
	auto it = items.find(TEXT("�ظ�"));
	if (it != items.end())
	{
		std::wcout
			<< TEXT("�ظ� �������� �ֽ��ϴ�. �ظ��� ������ ")
			<< it->second.price
			<< TEXT("�Դϴ�.\n");
	}

	// ����.
	if (it != items.end())
	{
		items.erase(it);

		std::wcout << TEXT("�ظ� ������ ���� �� ���\n");
		for (auto& pair : items)
		{
			std::wcout << pair.second << TEXT("\n");
		}
	}

	std::cin.get();
}