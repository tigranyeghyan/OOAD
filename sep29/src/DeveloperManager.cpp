#include "../hpp/DeveloperManager.hpp"
#include "../hpp/DepartmentType.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <memory>

DeveloperManager::DeveloperManager(std::string name, double baseSalary) : Employee{name, baseSalary, DepartmentType::Development}, developerCount_ {0} 
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

size_t DeveloperManager::getDeveloperCount() const
{
	return developerCount_;
}

std::vector<shared_ptr<Employee>> DeveloperManager::getDevelopers() const
{
	return developers_;
}

double DeveloperManager::calculateSalary(shared_ptr<Employee> empl)
{
	const double bonus = 50.0;
	double final_amount = empl -> getBaseSalary() + bonus * (empl -> getProjectCount());
	empl -> setFinalSalary(final_amount); 
}
