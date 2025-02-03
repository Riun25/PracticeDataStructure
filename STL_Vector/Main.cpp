#include <vector>
#include <iostream>

int main()
{
	// vector 변수 선언
	std::vector<int> vector;

	// 비었는지 확인
	// if(vector.size() == 0)
	if (vector.empty())
	{
		std::cout << "vector가 비었음\n";
	}

	// 자료 삽입
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


	// 요소 삭제 : 이렇게 하면 계속 앞당겨져서 이상해진다.
	//for (int idx = 0; idx < 1000; idx += 10)
	//{
	//	// 삭제를 원하는 위치의 반복자(iterator) 저장
	//	auto iterator = vector.begin() + idx;
	//	// 앞에서 구한 반복자를 활용해 배열 원소 삭제
	//	vector.erase(iterator);
	//}

	// 모두 소거
	// 내부 저장 변수가 포인터일 경우에는 직접 해제해야 함
	vector.clear();

	// 비었는지 확인
	if (vector.empty())
	{
		std::cout << "vector가 비었음\n";
	}

	// 크기 조정
	vector.resize(0);

	// 공간 확보
	// 재할당 방지 목적 / 공간 최적화
	vector.reserve(0);

	// 크기 줄일 때 사용
	vector.shrink_to_fit();

	std::cin.get();
}