#include "../hpp/HRRepresentative.hpp"
#include "../hpp/DepartmentType.hpp"

#include <iostream>
#include <string>

HRRepresentative::HRRepresentative(std::string name, double baseSalary) : Employee{name, baseSalary, DepartmentType::HumanResources}, employeesManaged_ {0}{
}

void HRREpresentative::displayInfo() const
{
	std::cout << "Name: " << name_ << std::endl;
	std::cout << "Department: " << getDepartmentString() << std::endl;
	std::cout << "Salary: " << finalSalary_ << "$" << std::endl;
	std::cout << "Employees Managed: " << employeesManaged_ << std::endl;
	std::cout << "ID: " << id_ << std::endl;
}

void HRRepresentative::addEmployee()
{
	++employeesManaged_;
}

size_t HRRepresentative::getEmployeesManaged() const
{
	return employeesManaged_;
}
