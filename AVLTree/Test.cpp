#include "AVLTree.h"

void TestAVLTree()
{
	AVLTree<int> at;
	int a[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	for (auto e : a)
	{
		at.Insert(e);
	}

	at.InOrder();
	cout << endl;

	auto ret = at.Find(4);
	if (ret)
	{
		cout << "4 is in AVLTree" << endl;
	}
	else
	{
		cout << "4 is not in AVLTree" << endl;
	}
}

int main()
{
	TestAVLTree();
	system("pause");
	return 0;
}
