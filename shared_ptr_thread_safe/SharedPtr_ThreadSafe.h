#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <mutex>
#include <thread>	
using namespace std;

// new
template<class T>
class DFDel
{
public:
	void operator()(T*& p)
	{
		if (p)
		{
			delete p;
			p = nullptr;
		}
	}
};

// malloc
template<class T>
class Free
{
public:
	void operator()(T*& p)
	{
		if (p)
		{
			free(p);
			p = nullptr;
		}
	}
};

// file
class FClose
{
public:
	void operator()(FILE*& pf)
	{
		if (pf)
		{
			fclose(pf);
			pf = nullptr;
		}
	}
};

template<class T, class DF = DFDel<T>>
class SharedPtr
{
public:
	SharedPtr(T* ptr = nullptr)
		: _ptr(ptr)
		, _pCount(nullptr)
		, _pMutex(new mutex)
	{
		if (_ptr)
			_pCount = new int(1);
	}

	SharedPtr(const SharedPtr<T>& sp)
		: _ptr(sp._ptr)
		, _pCount(sp._pCount)
		, _pMutex(sp._pMutex)
	{
		if (_ptr)
			AddRef();
	}

	SharedPtr<T>& operator=(const SharedPtr<T>& sp)
	{
		if (this != &sp)
		{
			// 让当前对象与管理资源断开联系
			// sp2 = sp1
			// sp2:没有管理资源、独自管理资源、与其它对象共享资源
			release();

			// 让当前对象与sp共享资源
			_ptr = sp._ptr;
			_pCount = sp._pCount;
			_pMutex = sp._pMutex;
			if (_ptr)
				AddRef();
		}

		return *this;
	}

	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}

	~SharedPtr()
	{
		release();
	}

	int use_count()
	{
		return *_pCount;
	}
private:
	void AddRef()
	{
		if (_pCount)
		{
			_pMutex->lock();
			++(*_pCount);
			_pMutex->unlock();
		}
	}

	int& SubRef()
	{
		if (_pCount)
		{
			_pMutex->lock();
			--(*_pCount);
			_pMutex->unlock();
		}
		return *_pCount;
	}

	void release()
	{
		if (_ptr && SubRef() == 0)
		{
			//DF df;
			////df.operator()(_ptr);
			//df(_ptr);
			DF()(_ptr);

			delete _pCount;
			_pCount = nullptr;
			delete _pMutex;
			_pMutex = nullptr;
		}
	}
private:
	T* _ptr; // 资源
	int* _pCount; // 指向计数的空间
	mutex* _pMutex; // 保证计数是线程安全，不能保证用户数据安全
};
