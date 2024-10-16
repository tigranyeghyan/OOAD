#pragma once
#include "Employee.hpp"
#include "Accountant.hpp"
#include "Manager.hpp"
#include <string>
#include <vector>
#include <memory>

class FinanceManager : public Employee, public Manager
{
public:
	void removeEmployee(size_t id) override;
	FinanceManager(std::string name, double baseSalary = 2000.0);
	void setFinalSalary() override;
	void displayInfo() const override;
	size_t getAccountantCount() const;
	void addAccountant(std::shared_ptr<Accountant> newAccountant);
	std::vector<std::shared_ptr<Accountant>> getAccountants() const;
private:
	std::vector<std::shared_ptr<Accountant>> accountants_;
	size_t AccountantCount_;
};


