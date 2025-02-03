#include <vector>
#include <iostream>

int main()
{
	// vector ���� ����
	std::vector<int> vector;

	// ������� Ȯ��
	// if(vector.size() == 0)
	if (vector.empty())
	{
		std::cout << "vector�� �����\n";
	}

	// �ڷ� ����
	for (int idx = 0; idx < 1000; ++idx)
	{
		vector.emplace_back(idx + 1);
	}

	for (auto it = vector.begin(); it != vector.end();)
	{
		it = vector.erase(it);
		if (it != vector.end())
		{
			it++;
		}
	}

	size_t size = vector.size();
	for (int i = 0; static_cast<int>(vector.size()); ++i)
	{
		vector[i++];
	}


	// ��� ���� : �̷��� �ϸ� ��� �մ������ �̻�������.
	//for (int idx = 0; idx < 1000; idx += 10)
	//{
	//	// ������ ���ϴ� ��ġ�� �ݺ���(iterator) ����
	//	auto iterator = vector.begin() + idx;
	//	// �տ��� ���� �ݺ��ڸ� Ȱ���� �迭 ���� ����
	//	vector.erase(iterator);
	//}

	// ��� �Ұ�
	// ���� ���� ������ �������� ��쿡�� ���� �����ؾ� ��
	vector.clear();

	// ������� Ȯ��
	if (vector.empty())
	{
		std::cout << "vector�� �����\n";
	}

	// ũ�� ����
	vector.resize(0);

	// ���� Ȯ��
	// ���Ҵ� ���� ���� / ���� ����ȭ
	vector.reserve(0);

	// ũ�� ���� �� ���
	vector.shrink_to_fit();

	std::cin.get();
}