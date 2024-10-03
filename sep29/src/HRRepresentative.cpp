#include "../hpp/HRRepresentative.hpp"
#include "../hpp/DepartmentType.hpp"
#include <iostream>
#include <string>

HRRepresentative::HRRepresentative(std::string name, double baseSalary = 1000.0) : Employee{name, baseSalary, DepartmentType::HumanResources}, employeesManaged_ {0}
{
}

void HRRepresentative::displayInfo() const
{
	std::cout << "Name: " << name_ << std::endl;
	std::cout << "Department: " << getDepartmentString() << std::endl;
	std::cout << "Salary: " << finalSalary_ << "$" << std::endl;
	std::cout << "Employees Managed: " << employeesManaged_ << std::endl;
	std::cout << "ID: " << id_ << std::endl;
}

void HRRepresentative::setFinalSalary()
{
	const double bonus = 10.0;
	finalSalary_ = salary_.calculateSalary(employeesManaged_, bonus, baseSalary_);
}

void HRRepresentative::addEmployee()
{
	++employeesManaged_;
}

size_t HRRepresentative::getEmployeesManaged() const
{
	return employeesManaged_;
}
