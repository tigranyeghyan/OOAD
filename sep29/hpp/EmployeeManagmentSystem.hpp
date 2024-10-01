#pragma once

#include "ISalaryCal.hpp"
#include "Employee.hpp"
#include "DepartmentType.hpp"

#include "FinanceManager.hpp"
#include "HRManager.hpp"
#include "SalesManager.hpp"
#include "DeveloperManager"

#include <memory>

class EmployeeManagmentSystem : public ISalaryCal
{
public:
	void addEmployee(std::string name, DepartmentType department);
	void displayAllEmployeesByDepartment(DepartmentType department) const;
	void calculateTotalSalaryByDepartment(DepartmentType department) const;
	void removeEmployeeFromDepartment(const int id, DepartmentType department);
	double calculateSalary(shared_ptr<Employee> empl) override;
	
private:
	shared_ptr<FinanceManager> finance_manager_;
	shared_ptr<HRManager> hr_manager_;
	shared_ptr<SalesManager> sales_manager_;
	shared_ptr<DeveloperManager> developer_manager_;
	
};
