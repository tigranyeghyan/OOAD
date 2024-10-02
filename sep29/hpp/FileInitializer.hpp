#pragma once

#include "Employee.hpp"


class FileInitializer
{
public:
	static void saveEmployeeState(Employee *employee);
	static void setSpecificParameter(size_t id, double specificParameter);
	static void setSpecificParameter(size_t id, size_t specificParameter);

	static void showEmployeeByID(size_t id);
	static void showEmployeesByName(std::string name);
	static void showEmployeesBySalaryRange(double from, double to);
	static void showEmployeeByDepartment(DepartmentType department);	
	static void showEmployeeBySpecificParameter(double specific);
private:
	FileInitializer() = default;
};