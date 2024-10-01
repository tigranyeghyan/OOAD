#pragma once

#include <string>

#include "Employee.hpp"

class SalesPerson : public Employee
{
	SalesPerson(std::string name, double baseSalary);
	
	void displayInfo() const override;

	void addSales(double amount);
	double getTotalSales() const;

private:
	double totalSales_;
};
