#pragma once

#include "Employee.hpp"

class FileInitializer
{
public:
	static void saveEmployeeState(Employee* employee);
private:
	FileInitializer() = default;
};
