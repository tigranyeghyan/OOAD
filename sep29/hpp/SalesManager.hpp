#pragma once
#include <string>
#include <vector>
#include "SalesPerson.hpp"
#include "Manager.hpp"

class SalesManager : public Employee, public Manager
{
public:
	void removeEmployee(size_t id) override;
	SalesManager(std::string name, double baseSalary = 2000.0);
	void displayInfo() const override;
	void setFinalSalary() override;
	size_t getSalesPersonCount() const;
	void addSalesPerson(std::shared_ptr<SalesPerson> newSalesPerson);
	std::vector<std::shared_ptr<SalesPerson>> getSalesPersons() const;
private:
	std::vector<std::shared_ptr<SalesPerson>> SalesPersons_;
	size_t SalesPersonCount_;
};

