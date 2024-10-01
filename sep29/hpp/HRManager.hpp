#pragma once 

#include "Employee.hpp"
#include "ISalaryCal.hpp"

#include <vector>
#include <memory>
#include <string>

class HRManager : public Employee, public ISalaryCal
{
public:
	HRManager(std::string name, double baseSalary);
	
	void displayInfo() const override;
	double calculateSalary(shared_ptr<Employee> empl) override;	
	size_t getHRsCount() const;
	std::vector<shared_ptr<Employee>> getHRs() const;

private:
	std::vector<shared_ptr<Employee>> HRs_; 
	size_t HRsCount_;
};
