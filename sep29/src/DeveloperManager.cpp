#include "../hpp/DeveloperManager.hpp"
#include "../hpp/DepartmentType.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "DeveloperManager.hpp"

DeveloperManager::DeveloperManager(std::string name, double baseSalary = 2000.0) : Employee{name, baseSalary, DepartmentType::Development}, developerCount_ { 0 }
{
}

void DeveloperManager::displayInfo() const
{
	std::cout << "Name: " << name_ << std::endl;
	std::cout << "Department: " << getDepartmentString() << std::endl;
	std::cout << "Salary: " << finalSalary_ << "$" << std::endl;
	std::cout << "Developers Managed: " << developerCount_ << std::endl;
	std::cout << "ID: " << id_ << std::endl;
}

void DeveloperManager::setFinalSalary()
{
	const double bonus = 30.0;
	finalSalary_ = salary_.calculateSalary(developerCount_, bonus, baseSalary_);
}

size_t DeveloperManager::getDeveloperCount() const
{
	return developerCount_;
}

void DeveloperManager::addDeveloper(std::shared_ptr<Developer> newDeveloper)
{
	developers_.push_back(std::move(newDeveloper));
    developerCount_ = developers_.size();
}

std::vector<std::shared_ptr<Developer>> DeveloperManager::getDevelopers() const
{
	return developers_;
}

void DeveloperManager::removeEmployee(size_t id)
{
	developers_.erase(developers_.begin() + id);
	--developerCount_;
}