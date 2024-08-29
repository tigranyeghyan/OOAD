#pragma once
#include "IntArray.h"
class MyArray
{
public:
	MyArray();
	MyArray(int);
	~MyArray() = default;
	MyArray(const MyArray&);
	MyArray(MyArray&&);
private:
	int m_size;
	int m_cap;
	IntArray data;
};
