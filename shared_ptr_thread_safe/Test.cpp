#include "SharedPtr_ThreadSafe.h"

struct Date
{
	Date()
		: _year(0)
		, _month(0)
		, _day(0)
	{}

	int _year;
	int _month;
	int _day;
};

void ThreadFunc(SharedPtr<Date>& sp, size_t n)
{
	for (size_t i = 0; i < n; ++i)
	{
		SharedPtr<Date> copy(sp);
		copy->_year++;
		copy->_month++;
		copy-> _day++;
	}
}

void TestSharedPtr()
{
	SharedPtr<Date> sp1(new Date);
	// 不同操作系统，线程相关的api操作不同-->代码可移植性比较差
	// C++11-->封装了一套线程库
	thread t1(ThreadFunc, ref(sp1), 100000);
	thread t2(ThreadFunc, ref(sp1), 100000);                                        
	t1.join();
	t2.join();

	cout << sp1->_year << endl;
	cout << sp1->_month << endl;
	cout << sp1->_day << endl;
}

int main()
{
	TestSharedPtr();
	system("pause");
	return 0;
}
