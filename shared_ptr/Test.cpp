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

int main()
{
	TestSharedPtr1();
	system("pause");
	return 0;
}
