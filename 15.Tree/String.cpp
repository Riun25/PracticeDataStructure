#pragma once
#include "String.h"

String::String(const char* _string)
{
    // 길이 확인
    mLength = _string == nullptr ? 1 : static_cast<int>(strlen(_string));

    // 동적 할당 및 문자열 복사
    mData = new char[mLength + 1];

    if (_string != nullptr)
    {
        strcpy_s(mData, mLength + 1, _string);
    }
}

String::String(const String& _other)
{
    mLength = _other.mLength;
    mData = new char[mLength + 1];
    strcpy_s(mData, mLength + 1, _other.mData);
}

String::~String()
{
    // 메모리 해제
    delete[] mData;
    mData = nullptr;
}

String& String::operator=(const String& _other)
{
    // 기존의 data 제거
    delete[] mData;

    mLength = _other.mLength;
    mData = new char[mLength + 1];
    strcpy_s(mData, mLength + 1, _other.mData);

    return *this;
}

bool String::operator==(const String& _other)
{
    // 문자열 비교 C 라이브러리 함수
    return strcmp(mData, _other.mData) == 0;
}

bool String::operator!=(const String& _other)
{
    //return strcmp(mData, _other.mData) != 0;
    return !(*this == _other);
}

const int String::Length() const
{
    return mLength;
}

const char* String::Data() const
{
    return mData;
}

std::ostream& operator<<(std::ostream& _os, const String& _string)
{
    _os << _string.mData;
    return _os;
}
