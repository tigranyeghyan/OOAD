#include <iostream>
#include "MyArray.h"

int main()
{
	MyArray obj(6);
	MyArray cp1(obj);
	MyArray cp2(std::move(obj));
	return 0;
}
