#include "HashTable.h"

void TestHashTable()
{
	HashTable<int> ht;
	ht.Insert(21);
	ht.Insert(13);
	ht.Insert(15);
	ht.Insert(31);
	ht.Insert(47);
	ht.Insert(88);

	ht.PrintHashTable();

	if (ht.Find(31) != -1)
	{
		cout << "15 is in HashTable" << endl;
	}
	else
	{
		cout << "15 is not in HashTable" << endl;
	}

	ht.Erase(31);

	ht.PrintHashTable();

	if (ht.Find(31) != -1)
	{
		cout << "15 is in HashTable" << endl;
	}
	else
	{
		cout << "15 is not in HashTable" << endl;
	}
}

int main()
{
	TestHashTable();
	system("pause");
	return 0;
}
