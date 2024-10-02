#pragma once
#include <stddef.h>
#include "DepartmentType.hpp"
class ISalary
{
public:
	virtual double calculateSalary(size_t spec, double bonus, double baseSalary) = 0;
	virtual double calculateSalary(double spec, double bonus, double baseSalary) = 0;
};
