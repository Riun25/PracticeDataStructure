#pragma once

template<typename KeyType, typename ValueType>
class Pair
{
public:
	Pair()
		:key(), value()
	{
	}

	Pair(KeyType _key, ValueType _value)
		: key(_key), value(_value)
	{
	}

	// 연산자 오버로딩
	// ==과 !=
	bool operator==(const Pair<KeyType, ValueType>& _other)
	{
		return key == _other.key && value == _other.value;
	}
	bool operator!=(const Pair<KeyType, ValueType>& _other)
	{
		return key != _other.key || value != _other.value;
	}

public:
	// 키(key)
	KeyType key;

	// 값(value)
	ValueType value;
};