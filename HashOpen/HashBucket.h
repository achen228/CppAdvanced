#pragma once
#include "Common.h"
#include <iostream>
#include <vector>
#include <string>
#include <assert.h>
using namespace std;

template<class T>
struct HashBucketNode
{
	HashBucketNode(const T& data = T())
		: _pNext(nullptr)
		, _data(data)
	{}
	HashBucketNode<T>* _pNext;
	T _data;
};

// 约定：元素唯一即不存储重复元素
template<class T, class T2INT = T2INTDef<T>>
class HashBucket
{
	typedef HashBucketNode<T> Node;
public: 
	HashBucket(size_t capacity = 10)
		: _table(capacity, nullptr) //GetNextPrime(capacity)
		, _size(0)
	{}

	~HashBucket()
	{
		Clear();
	}

	bool Insert(const T& data)
	{
		// 找当前元素存放的桶号
		size_t bucketNo = HashFunc(data);

		// 确认当前元素是否在哈希桶中
		Node* pCur = _table[bucketNo];
		while (pCur)
		{
			if (pCur->_data == data)
				return false;
			pCur = pCur->_pNext;
		}

		// 插入当前元素
		pCur = new Node(data);
		pCur->_pNext = _table[bucketNo];
		_table[bucketNo] = pCur;
		_size++;
		
		return true;
	} 

	Node* Find(const T& data)
	{
		size_t bucketNo = HashFunc(data);
		Node* pCur = _table[bucketNo];

		while (pCur)
		{
			if (pCur->_data == data)
				return pCur;
			pCur = pCur->_pNext;
		}

		return nullptr;
	}

	bool Erase(const T& data)
	{
		size_t bucketNo = HashFunc(data);
		Node* pCur = _table[bucketNo];
		Node* pPrev = nullptr;

		while (pCur)
		{
			if (data == pCur->_data)
			{
				if (nullptr == pPrev)
					_table[bucketNo] = pCur->_pNext;
				else
					pPrev->_pNext = pCur->_pNext;

				delete pCur;
				--_size;
				return true;
			}
			pPrev = pCur;
			pCur = pCur->_pNext;
		}

		return false;
	}

	void Clear()
	{
		for (size_t bucketNo = 0; bucketNo < _table.capacity(); ++bucketNo)
		{
			Node* pCur = _table[bucketNo];
			while (pCur)
			{
				_table[bucketNo] = pCur->_pNext;
				delete pCur;
				pCur = _table[bucketNo];
			}
		}

		_size = 0;
	}

	void Swap(HashBucket<T, T2INT>& newHT)
	{
		_table.swap(newHT._table);
		swap(_size, newHT._size);
	}

	size_t BucketCount() const
	{
		return _table.capacity();
	}

	size_t BucketSize(size_t bucketNo)
	{
		assert(bucketNo < _table.capacity());
		Node* pCur = _table[bucketNo];
		size_t count = 0;
		while (pCur)
		{
			count++;
			pCur = pCur->_pNext;
		}
		return count;
	}

	size_t Bucket(const T& data)
	{
		return HashFunc(data);
	}

	void PrintHashBucket()
	{
		for (size_t i = 0; i < _table.capacity(); ++i)
		{
			cout << "table[" << i << "]:";
			Node* pCur = _table[i];
			while (pCur)
			{
				cout << pCur->_data << "-->";
				pCur = pCur->_pNext;
			}

			cout << "NULL" << endl;
		}
	}

protected:
	// 保证%符号前为整型
	size_t HashFunc(const T& data)
	{
		//T2INT t;
		//t.operator()(data);
		//t(data);

		return T2INT()(data) % _table.capacity();
	}

	void CheckCapacity()
	{
		if (_size == _table.capacity())
		{
			HashBucket<T, T2INT> newHB(GetNextPrime(_table.capacity()));

			for (size_t i = 0; i < _table.capacity(); ++i)
			{
				Node* pCur = _table[i];
				while (pCur)
				{
					// 将pCur结点从旧哈希桶中移除
					_table[i] = pCur->_pNext;

					// 计算pCur在新哈希桶中的位置
					size_t bucketNo = newHB.HashFunc(pCur->_data);

					// 将pCur结点插入到新哈希表bucketNo桶中
					pCur->_pNext = newHB._table[bucketNo];
					newHB._table[bucketNo] = pCur;

					pCur = _table[i];
				}
			}

			this->Swap(newHB);
		}
	}
		
protected:
	vector<Node*> _table;
	size_t _size;
};
