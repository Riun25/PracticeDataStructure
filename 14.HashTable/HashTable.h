#pragma once
#include <vector>
#include "Pair.h"
#include <string>

class HashTable
{
	// Alias(��Ī) ����
	using Entry = Pair<std::string, std::string>;

public:
	HashTable() = default;
	~HashTable() = default;

	void Add(const std::string& _key, const std::string& _value);
	void Delete(const std::string& _key);
	bool Find(const std::string& _key, Entry& _outValue);
	void Print();

private:
	// ���� ������� ũ�� (�Ҽ�(Prime Number)�� ����ϴ� ���� ����)
	// �ؽ� �浹�� �Ͼ Ȯ���� �ٰ�, �����ϸ� Ŭ���� ����.
	static const int bucketCount = 10;
	std::vector<Entry> table[bucketCount];
};