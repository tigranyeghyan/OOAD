#pragma once
#include <memory>

class Employee;

class ISalaryCal
{
public:
	virtual double calculateSalary(shared_ptr<Employee> empl) = 0;
};
