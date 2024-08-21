#include "DynamicArray.h"
#include <iostream>

DynamicArray::DynamicArray()
{
	size = 0;
	capacity = 5;
	arr = new int[capacity];
}

DynamicArray::DynamicArray(int setcapacity)
{
	size = 0;
	capacity = setcapacity;
	arr = new int[capacity];
}

DynamicArray::DynamicArray(const DynamicArray& other)
{
 	
	arr = new int[other.capacity];
    	
	for (int i = 0; i < other.size; ++i)
   	{
		arr[i] = other.arr[i];
    	}
    	size = other.size;
    	capacity = other.capacity;
}

DynamicArray::~DynamicArray()
{
	delete[] arr;
	arr = nullptr;
}

void DynamicArray::push(int num)
{
      	if (size == capacity)
	{
		capacity *= 2;
		int* tmp = new int[capacity];
		for (int i = 0; i < size; ++i)
		{
			tmp[i] = arr[i];
		}
		delete[] arr;
		arr = tmp;
		tmp = nullptr;
	}
	arr[size++] = num;
}

void DynamicArray::display() const
{
	for (int i = 0; i < size; ++i)
	{
		std::cout << arr[i] << std::endl;
	}
}

