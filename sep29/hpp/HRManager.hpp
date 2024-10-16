#pragma once 
#include "Employee.hpp"
#include "HRRepresentative.hpp"
#include "Manager.hpp"
#include <vector>
#include <memory>
#include <string>

class HRManager : public Employee, public Manager
{
public:
	void removeEmployee(size_t id) override;
	HRManager(std::string name, double baseSalary = 2000.0);
	void displayInfo() const override;
	void setFinalSalary() override;	
	size_t getHRsCount() const;
	void addHR(std::shared_ptr<HRRepresentative> newHR);
	std::vector<std::shared_ptr<HRRepresentative>> getHRs() const;
private:
	std::vector<std::shared_ptr<HRRepresentative>> HRs_; 
	size_t HRsCount_;
};



