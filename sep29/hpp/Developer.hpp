#pragma once
#include <string>
#include "Employee.hpp"

class Developer : public Employee
{
public:
	Developer(std::string name, double baseSalary = 1500.0);
	void displayInfo() const override;
	void setFinalSalary() override;
	void addProject();
	size_t getProjectCount() const; 
private:
	size_t projects_;
};


