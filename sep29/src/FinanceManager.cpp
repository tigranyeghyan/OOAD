#include "../hpp/FinanceManager.hpp"
#include "../hpp/DepartmentType.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "FinanceManager.hpp"

FinanceManager::FinanceManager(std::string name, double baseSalary = 2000.0) : Employee{name, baseSalary, DepartmentType::Finance}, AccountantCount_ { 0 }
{
}

void FinanceManager::setFinalSalary()
{
	const double bonus = 30.0;
	finalSalary_ = salary_.calculateSalary(AccountantCount_, bonus, baseSalary_);
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

void FinanceManager::addAccountant(std::shared_ptr<Accountant> newAccountant)
{
	accountants_.push_back(std::move(newAccountant));
    AccountantCount_ = accountants_.size();
}

std::vector<std::shared_ptr<Accountant>> FinanceManager::getAccountants() const
{
	return accountants_;
}

void FinanceManager::removeEmployee(size_t id)
{
	accountants_.erase(accountants_.begin() + id);
	--AccountantCount_;
}