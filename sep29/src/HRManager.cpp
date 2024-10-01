#include "../hpp/HRManager.hpp"
#include "../hpp/DepartmentType.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <memory>

HRManager::HRManager(std::string name, double baseSalary) : Employee{name, baseSalary, DepartmentType::HumanResources}, HRsCount_ {0}
{
}

void HRManager::displayInfo() const
{
	std::cout << "Name: " << name_ << std::endl;
	std::cout << "Department: " << getDepartmentString() << std::endl;
	std::cout << "Salary: " << finalSalary_ << "$" << std::endl;
	std::cout << "HR Representative Managed: " << SalesPersonCount_ << std::endl;
	std::cout << "ID: " << id_ << std::endl;
}


double HR::ManagercalculateSalary(shared_ptr<Employee> empl)
{
	const double bonus = 15.0;
	double final_amount = empl -> getBaseSalary() + bonus * (empl -> getEmployeesManaged());
	empl -> setFinalSalary(final_amount);
	return final_amount;
}


size_t HRManager::getHRsCount() const
{
	return HRsCount_;
}

std::vector<shared_ptr<Employee>> HRManager::getHRs() const
{
	return HRs_;
}
