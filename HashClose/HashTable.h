#pragma once
#include <iostream>
#include <vector>
using namespace std;

enum State{EMPTY, EXIST, DELETE};

// 约定：不存储重复元素
template<class T>
class HashTable
{
	struct Elem
	{
		T _data;
		State _state;
	};
public:
	HashTable(size_t capacity = 10)
		: _table(capacity)
		, _size(0)
	{}

	bool Insert(const T& data)
	{
		// 计算哈希地址
		size_t hashAddr = HashFunc(data);
		size_t i = 0;

		while (_table[hashAddr]._state != EMPTY)
		{
			if (_table[hashAddr]._state == EXIST
				&& _table[hashAddr]._data == data)
			{
				return false;
			}

			// 产生哈希冲突
			// 线性探测
			++hashAddr;
			if (hashAddr == _table.capacity())
				hashAddr = 0;

			// 二次线性探测
			//++i;
			//hashAddr = hashAddr + 2 * i + 1;
			//if (hashAddr >= _table.capacity())
			//	hashAddr %= _table.capacity();
		}

		// 插入元素
		_table[hashAddr]._data = data;
		_table[hashAddr]._state = EXIST;
		++_size;

		return true;
	}

	int Find(const T& data)
	{
		size_t hashAddr = HashFunc(data);

		while (_table[hashAddr]._state != EMPTY)
		{
			if (_table[hashAddr]._state == EXIST
				&& _table[hashAddr]._data == data)
			{
				return hashAddr;
			}

			++hashAddr;
			if (hashAddr == _table.capacity())
				hashAddr = 0;
		}

		return -1;
	}

	bool Erase(const T& data)
	{
		int hashAddr = Find(data);
		if (hashAddr != -1)
		{
			_table[hashAddr]._state = DELETE;
			--_size;
			return true;
		}

		return false;
	}

	void PrintHashTable()
	{
		for (size_t i = 0; i < _table.capacity(); ++i)
		{
			cout << "table[" << i << "]:";
			if (_table[i]._state == EMPTY
				|| _table[i]._state == DELETE)
			{
				cout << "NULL" << endl;
			}
			else 
			{
				cout << _table[i]._data << endl;
			}
			
		}
	}

protected:
	size_t HashFunc(const T& data)
	{
		return data % _table.capacity();
	}

protected:
	vector<Elem> _table;
	size_t _size;
};
