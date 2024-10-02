#pragma once
#include <string>
#include <vector>
#include <memory>
#include "Employee.hpp"

class DeveloperManager : public Employee
{
public:
	DeveloperManager(std::string name, double baseSalary);
	void setFinalSalary() override;
	void displayInfo() const override;
	size_t getDeveloperCount() const;
	std::vector<std::shared_ptr<Employee>> getDevelopers() const;
private:
	std::vector<std::shared_ptr<Employee>> developers_;
	size_t developerCount_;
};
