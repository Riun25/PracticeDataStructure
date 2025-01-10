#pragma once
#include <vector>
#include "Pair.h"
#include <string>

class HashTable
{
	// Alias(별칭) 선언
	using Entry = Pair<std::string, std::string>;

public:
	HashTable() = default;
	~HashTable() = default;

	void Add(const std::string& _key, const std::string& _value);
	void Delete(const std::string& _key);
	bool Find(const std::string& _key, Entry& _outValue);
	void Print();

private:
	// 내장 저장소의 크기 (소수(Prime Number)를 사용하는 것이 유리)
	// 해시 충돌이 일어날 확률이 줄고, 가능하면 클수록 좋다.
	static const int bucketCount = 10;
	std::vector<Entry> table[bucketCount];
};