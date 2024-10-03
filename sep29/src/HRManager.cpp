#include "../hpp/HRManager.hpp"
#include "../hpp/DepartmentType.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <memory>

HRManager::HRManager(std::string name, double baseSalary) : Employee{name, baseSalary, DepartmentType::HumanResources}, HRsCount_ { 0 }
{
}

void HRManager::displayInfo() const
{
	std::cout << "Name: " << name_ << std::endl;
	std::cout << "Department: " << getDepartmentString() << std::endl;
	std::cout << "Salary: " << finalSalary_ << "$" << std::endl;
	std::cout << "HR Representative Managed: " << HRsCount_ << std::endl;
	std::cout << "ID: " << id_ << std::endl;
}

void HRManager::setFinalSalary()
{
	const double bonus = 30.0;
	finalSalary_ = salary_.calculateSalary(HRsCount_, bonus, baseSalary_);
}

size_t HRManager::getHRsCount() const
{
	return HRsCount_;
}

void HRManager::addHR(std::shared_ptr<HRRepresentative> newHR)
{
	HRs_.push_back(std::move(newHR));
    HRsCount_ = HRs_.size();
}

std::vector<std::shared_ptr<HRRepresentative>> HRManager::getHRs() const
{
	return HRs_;
}

void HRManager::removeEmployee(size_t id)
{
	HRs_.erase(HRs_.begin() + id);
	--HRsCount_;
}