#include "../hpp/EmployeeManagmentSystem.hpp"
#include "../hpp/DepartmentType.hpp"
#include <iostream>
#include <memory>
#include <string>
#include "EmployeeManagmentSystem.hpp"

std::shared_ptr<EmployeeManagmentSystem> EmployeeManagmentSystem::ptr = nullptr;

void EmployeeManagmentSystem::addEmployee(std::string name, DepartmentType department)
{
    if(department == DepartmentType::HumanResources)
    {
        if(!hr_manager_)
        {
            hr_manager_ = std::make_shared<HRManager>(name);
        }
        else
        {
            std::shared_ptr<HRRepresentative> newHR = std::make_shared<HRRepresentative>(name);
            hr_manager_ -> addHR(newHR);
        }
    }
    else if(department == DepartmentType::Finance)
    {
        if(!finance_manager_)
        {
            finance_manager_= std::make_shared<FinanceManager>(name);
        }
        else
        {
            std::shared_ptr<Accountant> newAccountant = std::make_shared<Accountant>(name);
            finance_manager_ -> addAccountant(newAccountant);
        }
    }
    else if(department == DepartmentType::Sales)
    {
        if(!sales_manager_)
        {
            sales_manager_ = std::make_shared<SalesManager>(name);
        }
        else
        {
            std::shared_ptr<SalesPerson> newSalesPerson = std::make_shared<SalesPerson>(name);
            sales_manager_ -> addSalesPerson(newSalesPerson);
        }
    }
    else if(department == DepartmentType::Development)
    {
        if(!developer_manager_)
        {
            developer_manager_ = std::make_shared<DeveloperManager>(name);
        }
        else
        {
            std::shared_ptr<Developer> newDeveloper = std::make_shared<Developer>(name);
            developer_manager_ -> addDeveloper(newDeveloper);
        }
    }
}

void EmployeeManagmentSystem::displayAllEmployeesByDepartment(DepartmentType department)
{
    if(department == DepartmentType::HumanResources)
    {
        if(!hr_manager_)
        {
            std::cout << "No employees in Human Resources Department" << std::endl;
        }
        else
        {
            hr_manager_ -> displayInfo();
            std::cout << "----------------------------" << std::endl;
            std::vector<std::shared_ptr<HRRepresentative>> myvec = hr_manager_ -> getHRs();
            for (auto it : myvec)
            {
                it -> displayInfo();
            }
        }
    }
    else if(department == DepartmentType::Finance)
    {
        if(!finance_manager_)
        {
            std::cout << "No employees in Finance Department" << std::endl;
        }
        else
        {
            finance_manager_ -> displayInfo();
            std::cout << "----------------------------" << std::endl;
            std::vector<std::shared_ptr<Accountant>> myvec = finance_manager_ -> getAccountants();
            for (auto it : myvec)
            {
                it -> displayInfo();
            }
        }
    }
    else if(department == DepartmentType::Sales)
    {
        if(!sales_manager_)
        {
            std::cout << "No employees in Sales Department" << std::endl;
        }
        else
        {
            sales_manager_ -> displayInfo();
            std::cout << "----------------------------" << std::endl;
            std::vector<std::shared_ptr<SalesPerson>> myvec = sales_manager_ -> getSalesPersons();
            for (auto it : myvec)
            {
                it -> displayInfo();
            }
        }
    }
    else if(department == DepartmentType::Development)
    {
        if(!developer_manager_)
        {
            std::cout << "No employees in Development Department" << std::endl;
        }
        else
        {
            developer_manager_ -> displayInfo();
            std::cout << "----------------------------" << std::endl;
            std::vector<std::shared_ptr<Developer>> myvec = developer_manager_ -> getDevelopers();
            for (auto it : myvec)
            {
                it -> displayInfo();
            }
        }
    }
}

void EmployeeManagmentSystem::calculateTotalSalaryByDepartment(DepartmentType department)
{
    if(department == DepartmentType::HumanResources)
    {
        if(!hr_manager_)
        {
            std::cout << "No employees in Human Resources Department" << std::endl;
        }
        else
        {
            double sum = hr_manager_ -> getFinalSalary(); 
            std::vector<std::shared_ptr<HRRepresentative>> myvec = hr_manager_ -> getHRs();
            for (auto it : myvec)
            {
                sum += it -> getFinalSalary();
            }
            std::cout << "Total Salary of Human Resources Department -> " << sum << "$" << std::endl; 
        }
    }
    else if(department == DepartmentType::Finance)
    {
        if(!finance_manager_)
        {
            std::cout << "No employees in Finance Department" << std::endl;
        }
        else
        {
            double sum = finance_manager_ -> getFinalSalary();
            std::vector<std::shared_ptr<Accountant>> myvec = finance_manager_ -> getAccountants();
            for (auto it : myvec)
            {
                sum += it -> getFinalSalary();
            }
            std::cout << "Total Salary of Finance Department Department -> " << sum << "$" << std::endl; 
        }
    }
    else if(department == DepartmentType::Sales)
    {
        if(!sales_manager_)
        {
            std::cout << "No employees in Sales Department" << std::endl;
        }
        else
        {
            double sum = sales_manager_ -> getFinalSalary();
            std::vector<std::shared_ptr<SalesPerson>> myvec = sales_manager_ -> getSalesPersons();
            for (auto it : myvec)
            {
                sum += it -> getFinalSalary();
            }
            std::cout << "Total Salary of Sales Department Department -> " << sum << "$" << std::endl; 

        }
    }
    else if(department == DepartmentType::Development)
    {
        if(!developer_manager_)
        {
            std::cout << "No employees in Development Department" << std::endl;
        }
        else
        {
            double sum = developer_manager_ -> getFinalSalary();
            std::vector<std::shared_ptr<Developer>> myvec = developer_manager_ -> getDevelopers();
            for (auto it : myvec)
            {
                sum += it -> getFinalSalary();
            }
            std::cout << "Total Salary of Development Department Department -> " << sum << "$" << std::endl; 
        }
    }
}

void EmployeeManagmentSystem::removeEmployeeFromDepartment(size_t id)
{
    auto finance_vec = finance_manager_ -> getAccountants();
    auto hr_vec = hr_manager_ -> getHRs();
    auto sales_vec = sales_manager_ -> getSalesPersons();
    auto developer_vec = developer_manager_ -> getDevelopers();
    int i = 0;
    for (auto it : finance_vec)
    {
        if(it -> getID() == id)
        {
            finance_manager_ -> removeEmployee(i);
            return; 
        }
        i++;
    }
    i = 0; 
    for (auto it : hr_vec)
    {
        if(it -> getID() == id)
        {
            hr_manager_ -> removeEmployee(i);
            return; 
        }
        i++;
    }
    i = 0; 
    for (auto it : sales_vec)
    {
        if(it -> getID() == id)
        {
            sales_manager_ -> removeEmployee(i);
            return; 
        }
        i++;
    }
    i = 0; 
    for (auto it : developer_vec)
    {
        if(it -> getID() == id)
        {
            developer_manager_ -> removeEmployee(i);
            return; 
        }
        i++;
    }
    std::cout << "No Employee With ID" << id << std::endl;
}

void EmployeeManagmentSystem::createManagmentSystem()
{
    if(!ptr)
    {
        ptr = std::make_shared<EmployeeManagmentSystem>();
    }
}



