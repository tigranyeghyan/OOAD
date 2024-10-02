#pragma once
#include <string>
#include <vector>
#include <memory>
#include "Employee.hpp"

class SalesManager : public Employee
{
public:
	SalesManager(std::string name, double baseSalary);
	void displayInfo() const override;
	void setFinalSalary() override;
	size_t getSalesPersonCount() const;
	std::vector<std::shared_ptr<Employee>> getSalesPersons() const;
private:
	std::vector<std::shared_ptr<Employee>> SalesPersons_;
	size_t SalesPersonCount_;
};
