#include "SharedPtr.h"

void TestSharedPtr1()
{
	SharedPtr<int> sp1(new int);
	SharedPtr<int> sp2(sp1);
	cout << sp1.use_count() << endl;
	cout << sp2.use_count() << endl;
	SharedPtr<int> sp3(new int);
	cout << sp3.use_count() << endl;
}

void TestSharedPtr2()
{
	//SharedPtr<int> sp1(new int);
	//SharedPtr<int> sp2;
	//// sp2没有管理资源
	//sp2 = sp1;

	//SharedPtr<int> sp1(new int);
	//SharedPtr<int> sp2(new int);
	//// sp2独自管理资源
	//sp2 = sp1;

	SharedPtr<int> sp1(new int);
	SharedPtr<int> sp2(new int);
	SharedPtr<int> sp3(sp2);
	// sp2与其它对象共享资源
	sp2 = sp1;
}

int main()
{
	TestSharedPtr1();
	system("pause");
	return 0;
}
