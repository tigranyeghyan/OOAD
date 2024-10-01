#include "../hpp/Employee.hpp"
#include "../hpp/DepartmentType.hpp"
#include "../hpp/EmployeeIdentity.hpp"

#include <iostream>
#include <string>

Employee::Employee(std::string name, double baseSalary, DepartmentType department) : name_{name}, baseSalary_ {baseSalary}, department_ {department}, id_ {EmployeeIdentity::getIdentity()}, finalSalary_ {baseSalary}
{
}

std::string Employee::getName() const
{
	return name_;
}

double Employee::getBaseSalary() const
{
	return baseSalary_;
}

double Employee::getFinalSalary() const
{
	return finalSalary_;
}

size_t Employee::getID() const
{
	return id_;
}

DepartmentType Employee::getDepartment() const
{
	return department;
}

void Employee::setFinalSalary(double amount)
{
	if(amount >= baseSalary_)
	{
		finalSalary_ = amount;
	}
}  

std::string Employee::getDepartmentString() const 
{
	switch (department_) 
	{
		case DepartmentType::Development: 
			return "Development Department";
		case DepartmentType::HumanResources: 
			return "Human Resources Department";
		case DepartmentType::Finance: 
			return "Finance Department";
		case DepartmentType::Sales: 
			return "Sales Department";
		default: 
			return "Unknown";
	}
}
