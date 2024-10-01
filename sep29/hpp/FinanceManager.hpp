#pragma once

#include "Employee.hpp"
#include "ISalaryCal.hpp"

#include <string>
#include <vector>
#include <memory>

class FinanceManager : public Employee, public ISalaryCal
{
public:
	
	FinanceManager(std::string name, double baseSalary);

	void displayInfo() const override;
	double calculateSalary(shared_ptr<Employee> empl) override;

	size_t getAccountantCount() const;
	std::vector<shared_ptr<Employee>> getAccountants() const;

private:

	std::vector<shared_ptr<Employee>> accountants_;
	size_t AccountantCount_;

};
