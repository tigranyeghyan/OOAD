#include "../hpp/FileInitializer.hpp"

#include <iostream>
#include <fstream>
#include <string>

void FileInitializer::saveEmployeeState(Employee* ptr)
{
	//name
	std::ofstream nameFile("../db/name.txt", std::ios::app);
	if (nameFile.is_open()) 
	{
		nameFile << employee -> getName() << std::endl;
		nameFile.close();
	}
	else 
	{
		std::cerr << "Unable to open name.txt for writing.\n";
	}
	//id
	std::ofstream idFile("../db/identity.txt", std::ios::app);
	if (idFile.is_open()) 
	{
		idFile << employee -> getID() << std::endl;
		idFile.close();
	} 
	else 
	{
		std::cerr << "Unable to open id.txt for writing.\n";
	}
	//department
	std::ofstream departmentFile("../db/department.txt", std::ios::app);
	if (departmentFile.is_open()) 
	{
		departmentFile << employee -> getDepartmentString() << std::endl;
		departmentFile.close();
	}
	else 
	{
		std::cerr << "Unable to open department.txt for writing.\n";
	}
	//salary
	std::ofstream salaryFile("../db/salary.txt", std::ios::app);
	if (salaryFile.is_open()) 
	{
		salaryFile << emp -> getFinalSalary() << std::endl;
		salaryFile.close();
	}
	else 
	{
		std::cerr << "Unable to open salary.txt for writing.\n";
	}
	//specific
	std::ofstream specificFile("../db/specific.txt", std::ios::app);
	if (specificFile.is_open()) 
	{
		specificFile << 0 << std::endl;
		specificFile.close();
	}
	else 
	{
		std::cerr << "Unable to open salary.txt for writing.\n";
	}
}
