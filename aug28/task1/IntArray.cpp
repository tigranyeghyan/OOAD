#include <iostream>
#include "IntArray.h"

IntArray::IntArray() : ptr {nullptr} 
{
	std::cout << "Default Ctor ----------" << std::endl;
}

IntArray::~IntArray()
{
	if(ptr != nullptr)
	{
		delete []ptr;
		ptr = nullptr;
	}
}

IntArray::IntArray(int cap) : m_cap {cap} 
{
	std::cout << "Parametrized Ctor --------- " << std::endl;
	ptr = new int[m_cap];
}

IntArray::IntArray(const IntArray& other) : m_cap {other.m_cap}
{
	std::cout << "Copy Ctor ------------" << std::endl;
	ptr = new int[m_cap];
	for(int i = 0; i < m_cap; ++i)
	{
		ptr[i] = other.ptr[i];
	}
}

IntArray::IntArray(IntArray&& obj) : m_cap {obj.m_cap}, ptr {obj.ptr}
{
	std::cout << "Move Ctor -----------" << std::endl;
	obj.ptr = nullptr;
	obj.m_cap = 0;
}

IntArray& IntArray::operator=(const IntArray& other) 
{
	if(this == &other)
	{
		return *this;
	}
	m_cap = other.m_cap;
	ptr = new int[m_cap];
	for(int i = 0; i < m_cap; ++i)
	{
		ptr[i] = other.ptr[i];
	}
	return *this;
}

IntArray& IntArray::operator=(IntArray&& other)
{
	if(this == &other)
	{
		return *this;
	}
	m_cap = other.m_cap;
	ptr = other.ptr;
	other.m_cap = 0;
	other.ptr = nullptr;
	return *this;
}
