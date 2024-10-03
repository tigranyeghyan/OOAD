#include <iostream>
#include "../hpp/DepartmentType.hpp"
#include "../hpp/EmployeeManagmentSystem.hpp"
#include "../hpp/FileInitializer.hpp"

int main()
{
    EmployeeManagmentSystem::createManagmentSystem();
    EmployeeManagmentSystem::addEmployee("John", DepartmentType::HumanResources);
    EmployeeManagmentSystem::addEmployee("Jane", DepartmentType::Finance);
    EmployeeManagmentSystem::addEmployee("Jack", DepartmentType::Sales);
    EmployeeManagmentSystem::addEmployee("Jill", DepartmentType::Development);

    //EmployeeManagmentSystem::removeEmployeeFromDepartment(1);

    EmployeeManagmentSystem::displayAllEmployeesByDepartment(DepartmentType::HumanResources);
    EmployeeManagmentSystem::displayAllEmployeesByDepartment(DepartmentType::Finance);
    EmployeeManagmentSystem::displayAllEmployeesByDepartment(DepartmentType::Sales);
    EmployeeManagmentSystem::displayAllEmployeesByDepartment(DepartmentType::Development);

    EmployeeManagmentSystem::calculateTotalSalaryByDepartment(DepartmentType::HumanResources);
    EmployeeManagmentSystem::calculateTotalSalaryByDepartment(DepartmentType::Finance);
    EmployeeManagmentSystem::calculateTotalSalaryByDepartment(DepartmentType::Sales);
    EmployeeManagmentSystem::calculateTotalSalaryByDepartment(DepartmentType::Development);
    return 0;
}