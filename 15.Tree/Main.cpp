#include <iostream>
#include "String.h"
#include "Node.h"
#include "Tree.h"

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define new new
#endif

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

int main()
{
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Tree<String> tree("A");
	tree.AddChild("B");
	tree.AddChild("B", "E");
	tree.AddChild("B", "F");
	tree.AddChild("B", "G");

	tree.AddChild("C");
	tree.AddChild("C", "H");

	tree.AddChild("D");
	tree.AddChild("D", "I");
	tree.AddChild("D", "J");

	// �˻� �׽�Ʈ
	Node<String>* outNode = nullptr;
	if (tree.Find("D", &outNode))
	{
		std::cout << "D ��� �˻� ����. �ڽ� �� : " << outNode->GetCount() << "\n";
	}
	else
	{
		std::cout << "D ��� �˻� ����\n";
	}

	// ���� ��ȸ
	std::cout << "---- ���� ��ȸ ----\n";
	tree.PreorderTraverse();

	std::cin.get();

	return 0;
}