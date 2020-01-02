#include "UniquePtr.h"

void TestUniquePtr()
{
	UniquePtr<int> up1(new int);
	UniquePtr<int> up2(up1); // 出错

	UniquePtr<int> up3;
	up3 = up1; // 出错
}

int main()
{
	TestUniquePtr();
	system("pause");
	return 0;
}
