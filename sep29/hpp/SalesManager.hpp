#pragma once

#include <string>
#include <vector>
#include <memory>

#include "Employee.hpp"
#include "ISalaryCal.hpp"

class SalesManager : public Employee, public ISalaryCal
{
public:

	SalesManager(std::string name, double baseSalary);

	void displayInfo() const override;
	double calculateSalary(shared_ptr<Employee> empl) override;

	size_t getSalesPersonCount() const;
	std::vector<shared_ptr<Employee>> getSalesPersons() const;

private:
	std::vector<shared_ptr<Employee>> SalesPersons_;
	size_t SalesPersonCount_;
};
