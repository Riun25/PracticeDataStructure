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

	// ������ �����ε�
	// ==�� !=
	bool operator==(const Pair<KeyType, ValueType>& _other)
	{
		return key == _other.key && value == _other.value;
	}
	bool operator!=(const Pair<KeyType, ValueType>& _other)
	{
		return key != _other.key || value != _other.value;
	}

public:
	// Ű(key)
	KeyType key;

	// ��(value)
	ValueType value;
};