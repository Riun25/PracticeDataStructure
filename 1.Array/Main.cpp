//#include <iostream>
//template <typename T, size_t size>
//class Array
//{
//public:
//	T& operator[](int _idx)
//	{
//		// ���� ó��
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
//	// ũ�Ⱑ 10�� int�� �迭
//	int array[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//
//	// �� �迭
//	int* heapArray = new int[10] { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//
//	// ����
//	delete[] heapArray;
//
//	// �迭 ��ü
//	Array<int, 10> arrayObj;
//	arrayObj[0] = 10;
//	arrayObj[1] = 20;
//	arrayObj[2] = 30;
//
//
//	std::cout << arrayObj.Count() << "\n";
//	return 0;
//}