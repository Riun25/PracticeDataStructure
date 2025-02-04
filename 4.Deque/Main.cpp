//�� ����� ���� ��� ��Ŭ���
#include <deque>
#include <iostream>

int main()
{
	// �� ����
	std::deque<int> deque;

	// ������ �߰�
	deque.emplace_back(100);
	deque.emplace_front(2000);

	for (int i = 0; i < static_cast<int>(deque.size()); ++i)
	{
		std::cout << deque[i] << "\n";
	}

	std::cout << "\n";
	for (auto it = deque.begin(); it != deque.end(); ++it)
	{
		std::cout << *it << "\n";
	}

	// ������ ���� �� ����
	auto data = deque.back();
	deque.pop_back();

	std::cout << data << "\n";

	deque.clear();
	//������� Ȯ��
	if (deque.empty())
	{
		std::cout << "���� ������ϴ�.\n";
	}

	std::cin.get();
}