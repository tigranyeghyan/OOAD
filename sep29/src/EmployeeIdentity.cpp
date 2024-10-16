#include "../hpp/EmployeeIdentity.hpp"
#include <iostream>

size_t EmployeeIdentity::getIdentity() 
{
	static size_t identity = 0;
	return ++identity;
}

