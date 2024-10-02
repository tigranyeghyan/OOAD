#include "../hpp/SalesManager.hpp"
#include "../hpp/DepartmentType.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <memory>

SalesManager::SalesManager(std::string name, double baseSalary) : Employee{name, baseSalary, DepartmentType::Sales}, SalesPersonCount_ {0}
{
}

void SalesManager::displayInfo() const
{
	std::cout << "Name: " << name_ << std::endl;
	std::cout << "Department: " << getDepartmentString() << std::endl;
	std::cout << "Salary: " << finalSalary_ << "$" << std::endl;
	std::cout << "Developers Managed: " << SalesPersonCount_ << std::endl;
	std::cout << "ID: " << id_ << std::endl;
}

void SalesManager::setFinalSalary()
{
	const double bonus = 30.0;
	finalSalary_ = salary_.calculateSalary(SalesPersonCount_, bonus, baseSalary_);
}

std::vector<std::shared_ptr<Employee>> SalesManager::getSalesPersons() const
{
	return SalesPersons_;
}

size_t SalesManager::getSalesPersonCount() const
{
	return SalesPersonCount_;
}