#pragma once
#include <stddef.h>
class EmployeeIdentity
{
public:
	static size_t getIdentity();
private:
	EmployeeIdentity() = default;
};