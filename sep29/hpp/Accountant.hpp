#pragma once

#include <string>

#include "Employee.hpp"

class Accountant : public Employee
{
	Accountant(std::string name, double baseSalary);
	
	void displayInfo() const override;

	void addFinancialReport();
	size_t getFinancialReport() const;

private:
	size_t financialReports_;
};
