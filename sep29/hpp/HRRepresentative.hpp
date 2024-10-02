#pragma once 

#include <string>

#include "Employee.hpp"

class HRRepresentative : public Employee
{
public:
	HRRepresentative(std::string name, double baseSalary);
	void displayInfo() const override;
	void setFinalSalary() override;
	void addEmployee();
	size_t getEmployeesManaged() const;
private:
	size_t employeesManaged_;
};