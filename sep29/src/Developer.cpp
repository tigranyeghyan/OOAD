#include "../hpp/Developer.hpp"
#include "../hpp/DepartmentType.hpp"

#include <string>
#include <iostream>

Developer::Developer(std::string name, double baseSalary) : Employee{name, baseSalary, DepartmentType::Development}, projects_ {0} 
{
}

void Developer::displayInfo() const
{
	std::cout << "Name: " << name_ << std::endl;
	std::cout << "Department: " << getDepartmentString() << std::endl;
	std::cout << "Salary: " << finalSalary_ << "$" << std::endl;
	std::cout << "Projects: " << projects_ << std::endl;
	std::cout << "ID: " << id_ << std::endl;
}

void Developer::addProject()
{
	++projects_;
}

size_t Developer::getProjectCount() const
{
	return projects_;
}
