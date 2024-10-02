#pragma once
#include "Employee.hpp"
#include "DepartmentType.hpp"
#include "FinanceManager.hpp"
#include "HRManager.hpp"
#include "SalesManager.hpp"
#include "DeveloperManager.hpp"
#include <memory>

class EmployeeManagmentSystem
{
public:
	static void addEmployee(std::string name, DepartmentType department);
	static void removeEmployeeFromDepartment(size_t id);
	static void displayAllEmployeesByDepartment(DepartmentType department);
	static void calculateTotalSalaryByDepartment(DepartmentType department);
	static void createManagmentSystem();
private:	
	EmployeeManagmentSystem();
	static EmployeeManagmentSystem* ptr;	
	static std::shared_ptr<FinanceManager> finance_manager_;
	static std::shared_ptr<HRManager> hr_manager_;
	static std::shared_ptr<SalesManager> sales_manager_;
	static std::shared_ptr<DeveloperManager> developer_manager_;

};
