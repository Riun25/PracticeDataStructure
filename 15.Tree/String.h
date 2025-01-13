#pragma once
#include <iostream>

// 직접 구현해보는 문자열 클래스
// MFC - UI
class String
{
public:
	// 일반 생성자
	String(const char* _string = nullptr);

	// 복사 생성자
	String(const String& _other);

	// 소멸자
	~String();

	// 연산자 오버로딩
	friend std::ostream& operator<<(std::ostream& _os, const String& _string);

	// 대입 연산자
	String& operator=(const String& _other);

	// 비교 연산자
	bool operator==(const String& _other);
	bool operator!=(const String& _other);

	// Getter
	const int Length() const;
	const char* Data() const;

private:
	int mLength;	// 문자열 길이
	char* mData;	// 문자열 저장하는 변수(저장소/컨테이너/Container)
};

