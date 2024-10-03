#include "../hpp/SalesPerson.hpp"
#include "../hpp/DepartmentType.hpp"
#include <iostream>
#include <string>

SalesPerson::SalesPerson(std::string name, double baseSalary) : Employee{name, baseSalary, DepartmentType::Sales}, totalSales_ {0.0} 
{
}

void SalesPerson::displayInfo() const
{
	std::cout << "Name: " << name_ << std::endl;
	std::cout << "Department: " << getDepartmentString() << std::endl;
	std::cout << "Salary: " << finalSalary_ << "$" << std::endl;
	std::cout << "Total Sales: " << totalSales_ << "$" << std::endl;
	std::cout << "ID: " << id_ << std::endl;
}

void SalesPerson::setFinalSalary()
{
	const double commissionRate = 20.0;
	finalSalary_ = salary_.calculateSalary(totalSales_, commissionRate, baseSalary_);
}

void SalesPerson::addSales(double amount)
{
	if(amount > 0)
	{
		totalSales_ += amount;
	}
}

double SalesPerson::getTotalSales() const
{
	return totalSales_;
}