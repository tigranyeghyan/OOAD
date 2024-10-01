#pragma once
#include <string>
#include "DepartmentType.hpp"

class Employee
{
public:

	virtual void displayInfo() const = 0;
	Employee(std::string name, double baseSalary, DepartmentType department);
	
	std::string getName() const;
	double getBaseSalary() const;
	double getFinalSalary() const;
	size_t getID() const;
	DepartmentType getDepartment() const; 
	std::string getDepartmentString() const;
	
protected:	
	
	void setFinalSalary(double amount);  
	
	std::string name_;
	double baseSalary_;
	DepartmentType department_;
	size_t id_;
	double finalSalary_;

};
