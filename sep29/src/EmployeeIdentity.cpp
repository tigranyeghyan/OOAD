#include "../hpp/EmployeeIdentity.hpp"

#include <iostream>

EmployeeIdentity::EmployeeIdentity() 
{
}

size_t EmployeeIdentity::identity = 0;

size_t EmployeeIdentity::getIdentity() 
{
	return ++identity;
}
