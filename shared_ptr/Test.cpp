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

void TestSharedPtr3()
{
	SharedPtr<int> sp1(new int);
	// 代码中所有资源都是采用delete方式进行释放
	// 正确释放方式：根据资源的类型去释放
	// 析构资源时，析构方式必须灵活
	// 解决办法：使用仿函数，配置删除器
	SharedPtr<int, Free<int>> sp2((int*)malloc(sizeof(int)));
	SharedPtr<FILE, FClose> sp3(fopen("1.txt", "w"));
}

int main()
{
	TestSharedPtr1();
	system("pause");
	return 0;
}
