#include <iostream>
#include "../hpp/DepartmentType.hpp"
#include "../hpp/EmployeeManagmentSystem.hpp"
#include "../hpp/FileInitializer.hpp"

int main()
{
    FileInitializer::clearOldData();
    EmployeeManagmentSystem::createManagmentSystem();
    EmployeeManagmentSystem::addEmployee("John", DepartmentType::HumanResources);
    EmployeeManagmentSystem::addEmployee("Jane", DepartmentType::Finance);
    EmployeeManagmentSystem::addEmployee("Jack", DepartmentType::Sales);
    EmployeeManagmentSystem::addEmployee("Jill", DepartmentType::Development);
    EmployeeManagmentSystem::addEmployee("Jilasdinasdl", DepartmentType::Development);
    EmployeeManagmentSystem::addEmployee("Afdisghd", DepartmentType::Development);
    EmployeeManagmentSystem::addEmployee("Jack Daniels", DepartmentType::Sales);

    FileInitializer::showEmployeesBySalaryRange(800.0, 1800.0);
    std::cout <<"____________________________________________" << std::endl;
    EmployeeManagmentSystem::removeEmployeeFromDepartment(1);

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

