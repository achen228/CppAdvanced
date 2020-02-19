#include "BSTree.h"

void TestBSTree()
{
	int a[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	BSTree<int> t; 

	for (auto e : a)
	{
		t.Insert(e);
	}

	t.InOrder();
	cout << endl;

	auto pRet = t.Find(0);
	if (pRet)
	{
		cout << "0 is in BSTree" << endl;
	}
	else 
	{
		cout << "0 is not in BSTree" << endl;
	}

	t.Erase(6);
	t.InOrder();
	cout << endl;
	t.Erase(8);
	t.InOrder();
	cout << endl;
	t.Erase(5);
	t.InOrder();
	cout << endl;
}

int main()
{
	TestBSTree();
	system("pause");
	return 0;
}
