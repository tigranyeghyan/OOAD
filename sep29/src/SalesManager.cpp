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

std::vector<shared_ptr<Employee>> SalesManager::getSalesPersons() const
{
	return SalesPersons_;
}

size_t SalseManager::getSalesPersonCount() const
{
	return SalesPersonCount_;
}

double SalesManager::calculateSalary(shared_ptr<Employee> empl)
{
	const double commissionRate = 10.0;
	double final_amount = empl -> getBaseSalary() + commissionRate * (empl -> getTotalSales());
	empl -> setFinalSalary(final_amount);
	return final_amount;
}
