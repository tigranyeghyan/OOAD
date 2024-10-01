#pragma once

class EmployeeManagmentSystem
{
	void addEmployee(shared_ptr<Employee> employee);
	void displayAllEmployeesByDepartment(Type department) const;
	void calculateTotalSalaryByDepartment(Type department) const;
	removeEmployeeFromDepartment(const int id, Type);

private:
	shared_ptr<FinanceManager> finance_manager_;
	shared_ptr<HRManager> hr_manager_;
	shared_ptr<SalesManager> sales_manager_;
	shared_ptr<DeveloperManager> developer_manager_;
};
