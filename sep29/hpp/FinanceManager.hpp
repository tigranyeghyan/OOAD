#pragma once

#include "Employee.hpp"

#include <string>
#include <vector>
#include <memory>

class FinanceManager : public Employee
{
public:
	FinanceManager(std::string name, double baseSalary);
	void setFinalSalary() override;
	void displayInfo() const override;
	void setFinalSalary() override;
	size_t getAccountantCount() const;
	std::vector<std::shared_ptr<Employee>> getAccountants() const;

private:

	std::vector<std::shared_ptr<Employee>> accountants_;
	size_t AccountantCount_;

};
