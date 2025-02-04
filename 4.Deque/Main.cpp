//덱 사용을 위한 헤더 인클루드
#include <deque>
#include <iostream>

int main()
{
	// 덱 선언
	std::deque<int> deque;

	// 데이터 추가
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

	// 데이터 추출 후 제거
	auto data = deque.back();
	deque.pop_back();

	std::cout << data << "\n";

	deque.clear();
	//비었는지 확인
	if (deque.empty())
	{
		std::cout << "덱이 비었습니다.\n";
	}

	std::cin.get();
}