#pragma once

#include <string>
#include <vector>
#include <memory>

#include "Employee.hpp"
#include "ISalaryCal.hpp"

class DeveloperManager : public Employee, public ISalaryCal
{
public:
	
	DeveloperManager(std::string name, double baseSalary);

	void displayInfo() const override;
	double calculateSalary(shared_ptr<Employee> empl) override;	
	size_t getDeveloperCount() const;
	std::vector<shared_ptr<Employee>> getDevelopers() const;

private:
	std::vector<shared_ptr<Employee>> developers_; 
	size_t developerCount_;
};
