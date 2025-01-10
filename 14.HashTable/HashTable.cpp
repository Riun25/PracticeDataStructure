#include "HashTable.h"
#include <iostream>

// 해시 함수
int GenerateHash(std::string _keyString)
{
    // 생성할 키
    int hash = 0;
    for (int i = 0; i < static_cast<int>(_keyString.size()); i++)
    {
        // 해시 함수 핵심 로직
        hash = hash * 31 + _keyString[i];
    }

    // 해시 값이 너무 크면 음수가 되는 경우가 있어서 양수로 바꾸기
    return hash < 0? -hash : hash;
}

void HashTable::Add(const std::string& _key, const std::string& _value)
{
    // 인덱스 구하기
    int bucketIdx = GenerateHash(_key) % bucketCount;

    // 저장할 위치에 있는 컨테이너 가져오기
    auto& position = table[bucketIdx];

    // 해시 테이블은 중복을 허용하지 않음
    // 검색
    for (int i = 0; i < static_cast<int>(position.size()); i++)
    {
        // 키 비교
        if (position[i].key == _key)
        {
            std::cout << "이미 같은 키가 저장되어 있어 삽입 실패\n";
            return;
        }
    }

    // 데이터 삽입
    position.push_back(Entry(_key, _value));
}

void HashTable::Delete(const std::string& _key)
{
	// 인덱스 구하기
	int bucketIdx = GenerateHash(_key) % bucketCount;

	// 삭제할 위치에 있는 컨테이너 가져오기
	auto& position = table[bucketIdx];

    // 검색
    for (int i = 0; i < (int)position.size(); i++)
    {
		// 키 비교
		if (position[i].key == _key)
		{
            position.erase(position.begin() + i);
            std::cout << "키: " << _key << " 항목을 삭제\n";
            return;
		}
    }

    // 검색 실패
    std::cout << "삭제할 항목을 찾지 못했습니다.\n";
}

bool HashTable::Find(const std::string& _key, Entry& _outValue)
{
	// 인덱스 구하기
	int bucketIdx = GenerateHash(_key) % bucketCount;

	// 삭제할 위치에 있는 컨테이너 가져오기
	auto& position = table[bucketIdx];
	
    // 예외 처리
    if (position.size() == 0)
    {
        std::cout << "해당 키로 항목을 찾지 못했습니다.\n";
        return false;
    }
    
    // 검색
	for (int i = 0; i < (int)position.size(); i++)
	{
		// 키 비교
		if (position[i].key == _key)
		{
            // 검색에 성공했으면 값을 출력
            _outValue = position[i];
			return true;
		}
	}

	// 검색 실패
	std::cout << "해당 키로 항목을 찾지 못했습니다.\n";
	return false;
}

void HashTable::Print()
{
    for (int i = 0; i < bucketCount; i++)
    {
        // 건너뛰기
        if (table[i].size() == 0)
        {
            continue;
        }

        // 출력
        for (auto& e : table[i])
        {
            std::cout << "키: " << e.key << ",\t값: " << e.value << "\n";
        }
    }
}
