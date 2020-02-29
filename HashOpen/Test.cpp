#include "HashBucket.h"

void TestHashBucket1()
{
	HashBucket<int> hb;
	hb.Insert(21);
	hb.Insert(13);
	hb.Insert(15);
	hb.Insert(31);
	hb.Insert(47);
	hb.Insert(88);

	hb.PrintHashBucket();

	if (hb.Find(47))
	{
		cout << "47 is in HashBucket" << endl;
	}
	else
	{
		cout << "47 is not in HashBucket" << endl;
	}

	hb.Erase(47);
	hb.PrintHashBucket();

	if (hb.Find(47))
	{
		cout << "47 is in HashBucket" << endl;
	}
	else
	{
		cout << "47 is not in HashBucket" << endl;
	}
}

void TestHashBucket2()
{
	HashBucket<string, Str2INT> hb;
	hb.Insert("1111");
	hb.Insert("你好");
	hb.Insert("hello");

	hb.PrintHashBucket();
}

int main()
{
	TestHashBucket2();
	system("pause");
	return 0;
}
