#pragma once
#include <string>
#include "DepartmentType.hpp"

class Employee
{
public:

	virtual void displayInfo() const = 0;
	Employee(std::string name, double baseSalary, DepartmentType department);
	
	double getBaseSalary() const;
	std::string getName() const;
	double getFinalSalary() const;
	size_t getID() const;
	std::string getDepartmentString() const;
	DepartmentType getDepartment() const; 
	
protected:	
	
	void setFinalSalary(double amount);  
	
	std::string name_;
	double baseSalary_;
	DepartmentType department_;
	size_t id_;
	double finalSalary_;

};
