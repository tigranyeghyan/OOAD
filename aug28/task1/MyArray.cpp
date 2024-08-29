#include <iostream>
#include "MyArray.h"
#include"IntArray.h"
MyArray::MyArray() : m_size {0}, m_cap {5}, data {IntArray(5)}
{ 
	std::cout << "Default Ctor" << std::endl;
} 

MyArray::MyArray(int cap) : m_size {0}, m_cap {cap}, data {IntArray(cap)} 
{
	std::cout << "Parametr Ctor" << std::endl;
}

MyArray::MyArray(const MyArray &other)
{
	m_size = other.m_size;
	m_cap = other.m_cap;
	data = other.data;
	std::cout << "Copy Ctor" <<std::endl;
}

MyArray::MyArray(MyArray&& rref) : m_size {rref.m_size}, m_cap {rref.m_size}, data {std::move(rref.data)} 
{
	rref.m_cap = 0;
	rref.m_size = 0;
	std::cout << "Move Ctor" << std::endl;
}
