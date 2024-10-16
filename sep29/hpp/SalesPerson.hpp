#pragma once
#include <string>
#include "Employee.hpp"

class SalesPerson : public Employee
{
public:
	SalesPerson(std::string name, double baseSalary = 1200.0);
	void displayInfo() const override;
	void setFinalSalary() override;
	void addSales(double amount);
	double getTotalSales() const;
private:
	double totalSales_;
};


