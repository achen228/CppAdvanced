#pragma once
#include <iostream>
using namespace std;

template<class T>
class UniquePtr
{
public:
	UniquePtr(T* ptr = nullptr)
		:_ptr(ptr)
	{}

	~UniquePtr()
	{
		if (_ptr)
		{
			delete _ptr;
			_ptr = nullptr;
		}
	}

	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}

	// 资源独占，不允许发生拷贝
	// C++11 delete：禁止默认成员函数的生成
	UniquePtr(const UniquePtr<T> &) = delete;
	UniquePtr<T>& operator=(const UniquePtr<T> &) = delete;

//	// C++98解决办法
//private:
//	UniquePtr(const UniquePtr<T> &);
//	UniquePtr<T>& operator=(const UniquePtr<T> &);
private:
	T* _ptr;
};
