#include <iostream>
#include "BinarySearchTree.h"

struct List
{

};

List* Avc(List* _list)
{
	List* a = _list;
	return a;
}

int main()
{
	// ���� Ž�� Ʈ�� ����
	BinarySearchTree<int> tree;

	// ��� �߰�
	tree.InsertNode(50);
	tree.InsertNode(30);
	tree.InsertNode(20);
	tree.InsertNode(70);
	tree.InsertNode(80);
	tree.InsertNode(100);

	// �˻�
	int searchData = 50;
	if (tree.SearchNode(searchData))
	{
		std::cout << searchData << " �˻� ����.\n";
	}
	else
	{
		std::cout << searchData << " �˻� ����.\n";
	}

	// ����
	int keyToDelete = 30;
	if (tree.DeleteNode(keyToDelete))
	{
		std::cout << keyToDelete << " ��� ���� ����\n";
	}
	else
	{
		std::cout << keyToDelete << " ��� ���� ����\n";
	}

	tree.InorderedTraverse();

	std::cin.get();
}