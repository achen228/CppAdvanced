#pragma once
#include <iostream>
using namespace std;
#include <string>

size_t GetNextPrime(size_t prime);


template<class T>
class T2INTDef
{
public:
	T operator()(const T& data)
	{
		return data;
	}
};


// 字符串哈希算法
class Str2INT
{
public:
	size_t operator()(const string& s)
	{
		return BKDRHash(s.c_str());
	}

	size_t BKDRHash(const char *str)
	{
		register size_t hash = 0;
		while (size_t ch = (size_t)*str++)
		{
			hash = hash * 131 + ch;
		}
		return hash;
	}
};
