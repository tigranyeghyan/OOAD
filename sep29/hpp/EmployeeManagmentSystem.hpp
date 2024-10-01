#pragma once

class EmployeeManagmentSystem : public ISalaryCal
{
	void addEmployee(shared_ptr<Employee> employee);
	void displayAllEmployeesByDepartment(DepartmentType department) const;
	void calculateTotalSalaryByDepartment(DepartmentType department) const;
	void removeEmployeeFromDepartment(const int id);
	double calculateSalary(shared_ptr<Employee> empl) override;
private:
	shared_ptr<FinanceManager> finance_manager_;
	shared_ptr<HRManager> hr_manager_;
	shared_ptr<SalesManager> sales_manager_;
	shared_ptr<DeveloperManager> developer_manager_;
};
