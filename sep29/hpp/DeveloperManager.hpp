#pragma once
#include <string>
#include <vector>
#include <memory>
#include "Employee.hpp"
#include "Developer.hpp"
#include "Manager.hpp"

class DeveloperManager : public Employee, public Manager
{
public:
	void removeEmployee(size_t id) override;

	DeveloperManager(std::string name, double baseSalary = 2000.0);
	void setFinalSalary() override;
	void displayInfo() const override;
	size_t getDeveloperCount() const;
	void addDeveloper(std::shared_ptr<Developer> newDeveloper); 
	std::vector<std::shared_ptr<Developer>> getDevelopers() const;
private:
	std::vector<std::shared_ptr<Developer>> developers_;
	size_t developerCount_;
};
