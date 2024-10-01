#include "../hpp/FinanceManager.hpp"
#include "../hpp/DepartmentType.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <memory>

FinanceManager::FinanceManager(std::string name, double baseSalary) : Employee{name, baseSalary, DepartmentType::Finance}, AccountantCount_ {0}
{
}

double FinanceManager::calculateSalary(shared_ptr<Employee> empl)
{
	const double commissionRate = 20.0;
	double final_amount = empl -> getBaseSalary() + commissionRate * (empl -> getFinancialReport());
	empl -> setFinalSalary(final_amount); 
}

void FinanceManager::displayInfo() const
{
	std::cout << "Name: " << name_ << std::endl;
	std::cout << "Department: " << getDepartmentString() << std::endl;
	std::cout << "Salary: " << finalSalary_ << "$" << std::endl;
	std::cout << "Accountants Managed: " << AccountantCount_ << std::endl;
	std::cout << "ID: " << id_ << std::endl;
}


size_t FinanceManager::getAccountantCount() const
{
	return AccountantCount_;
}


std::vector<shared_ptr<Employee>> FinanceManager::getAccountants() const
{
	return accountants_;
}
