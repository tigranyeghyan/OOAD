#pragma once 

#include "Employee.hpp"

#include <vector>
#include <memory>
#include <string>

class HRManager : public Employee
{
public:
	HRManager(std::string name, double baseSalary);
	void displayInfo() const override;
	void setFinalSalary() override;	
	size_t getHRsCount() const;
	std::vector<std::shared_ptr<Employee>> getHRs() const;
private:
	std::vector<std::shared_ptr<Employee>> HRs_; 
	size_t HRsCount_;
};
