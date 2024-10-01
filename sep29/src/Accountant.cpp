#include "../hpp/Accountant.hpp"
#include "../hpp/DepartmentType.hpp"
#include <string>
#include <iostream>

Accountant::Accountant(std::string name, double baseSalary) : Employee{name, baseSalary, DepartmentType::Finance}, financialReports_ {0} 
{
}

void Developer::displayInfo() const
{
	std::cout << "Name: " << name_ << std::endl;
	std::cout << "Department: " << getDepartmentString() << std::endl;
	std::cout << "Salary: " << finalSalary_ << "$" << std::endl;
	std::cout << "Financial Reports: " << financialReports_ << std::endl;
	std::cout << "ID: " << id_ << std::endl;
}

void Accountant::addFinancialReport()
{
	++financialReports_;
}

size_t Accountant::getFinancialReport() const
{
	return financialReports_;
}
