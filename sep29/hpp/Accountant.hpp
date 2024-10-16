#pragma once
#include <string>
#include "Employee.hpp"

class Accountant : public Employee
{
public:
	Accountant(std::string name, double baseSalary = 1300.0);
	void displayInfo() const override;
	void setFinalSalary() override;
	void addFinancialReport();
	size_t getFinancialReport() const;
private:
	size_t financialReports_;
};

