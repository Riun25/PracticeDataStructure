#include "HashTable.h"
#include <iostream>

// �ؽ� �Լ�
int GenerateHash(std::string _keyString)
{
    // ������ Ű
    int hash = 0;
    for (int i = 0; i < static_cast<int>(_keyString.size()); i++)
    {
        // �ؽ� �Լ� �ٽ� ����
        hash = hash * 31 + _keyString[i];
    }

    // �ؽ� ���� �ʹ� ũ�� ������ �Ǵ� ��찡 �־ ����� �ٲٱ�
    return hash < 0? -hash : hash;
}

void HashTable::Add(const std::string& _key, const std::string& _value)
{
    // �ε��� ���ϱ�
    int bucketIdx = GenerateHash(_key) % bucketCount;

    // ������ ��ġ�� �ִ� �����̳� ��������
    auto& position = table[bucketIdx];

    // �ؽ� ���̺��� �ߺ��� ������� ����
    // �˻�
    for (int i = 0; i < static_cast<int>(position.size()); i++)
    {
        // Ű ��
        if (position[i].key == _key)
        {
            std::cout << "�̹� ���� Ű�� ����Ǿ� �־� ���� ����\n";
            return;
        }
    }

    // ������ ����
    position.push_back(Entry(_key, _value));
}

void HashTable::Delete(const std::string& _key)
{
	// �ε��� ���ϱ�
	int bucketIdx = GenerateHash(_key) % bucketCount;

	// ������ ��ġ�� �ִ� �����̳� ��������
	auto& position = table[bucketIdx];

    // �˻�
    for (int i = 0; i < (int)position.size(); i++)
    {
		// Ű ��
		if (position[i].key == _key)
		{
            position.erase(position.begin() + i);
            std::cout << "Ű: " << _key << " �׸��� ����\n";
            return;
		}
    }

    // �˻� ����
    std::cout << "������ �׸��� ã�� ���߽��ϴ�.\n";
}

bool HashTable::Find(const std::string& _key, Entry& _outValue)
{
	// �ε��� ���ϱ�
	int bucketIdx = GenerateHash(_key) % bucketCount;

	// ������ ��ġ�� �ִ� �����̳� ��������
	auto& position = table[bucketIdx];
	
    // ���� ó��
    if (position.size() == 0)
    {
        std::cout << "�ش� Ű�� �׸��� ã�� ���߽��ϴ�.\n";
        return false;
    }
    
    // �˻�
	for (int i = 0; i < (int)position.size(); i++)
	{
		// Ű ��
		if (position[i].key == _key)
		{
            // �˻��� ���������� ���� ���
            _outValue = position[i];
			return true;
		}
	}

	// �˻� ����
	std::cout << "�ش� Ű�� �׸��� ã�� ���߽��ϴ�.\n";
	return false;
}

void HashTable::Print()
{
    for (int i = 0; i < bucketCount; i++)
    {
        // �ǳʶٱ�
        if (table[i].size() == 0)
        {
            continue;
        }

        // ���
        for (auto& e : table[i])
        {
            std::cout << "Ű: " << e.key << ",\t��: " << e.value << "\n";
        }
    }
}
