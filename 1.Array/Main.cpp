//#include <iostream>
//template <typename T, size_t size>
//class Array
//{
//public:
//	T& operator[](int _idx)
//	{
//		// 예외 처리
//
//		return mData[_idx];
//	}
//
//	size_t Count() const { return size; }
//
//private:
//	T mData[size];
//};
//
//int main()
//{
//	// 크기가 10인 int형 배열
//	int array[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//
//	// 힙 배열
//	int* heapArray = new int[10] { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//
//	// 삭제
//	delete[] heapArray;
//
//	// 배열 객체
//	Array<int, 10> arrayObj;
//	arrayObj[0] = 10;
//	arrayObj[1] = 20;
//	arrayObj[2] = 30;
//
//
//	std::cout << arrayObj.Count() << "\n";
//	return 0;
//}