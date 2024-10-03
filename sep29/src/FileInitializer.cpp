#include "../hpp/FileInitializer.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void FileInitializer::saveEmployeeState(Employee *employee)
{
    // name
    std::ofstream nameFile("../db/name.txt", std::ios::app);
    if (nameFile.is_open())
    {
        nameFile << employee->getName() << std::endl;
        nameFile.close();
    }
    else
    {
        std::cerr << "Unable to open name.txt for writing.\n";
    }
    // id
    std::ofstream idFile("../db/identity.txt", std::ios::app);
    if (idFile.is_open())
    {
        idFile << employee->getID() << std::endl;
        idFile.close();
    }
    else
    {
        std::cerr << "Unable to open id.txt for writing.\n";
    }
    // department
    std::ofstream departmentFile("../db/department.txt", std::ios::app);
    if (departmentFile.is_open())
    {
        departmentFile << employee->getDepartmentString() << std::endl;
        departmentFile.close();
    }
    else
    {
        std::cerr << "Unable to open department.txt for writing.\n";
    }
    // salary
    std::ofstream salaryFile("../db/salary.txt", std::ios::app);
    if (salaryFile.is_open())
    {
        salaryFile << employee->getFinalSalary() << std::endl;
        salaryFile.close();
    }
    else
    {
        std::cerr << "Unable to open salary.txt for writing.\n";
    }
    // specific
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

void FileInitializer::setSpecificParameter(size_t id, double specificParameter)
{
    std::string filename = "../db/specific.txt";
    std::ifstream inputFile(filename);

    if (!inputFile)
    {
        std::cerr << "Error opening file for reading.\n";
        return;
    }
    std::vector<std::string> lines;
    std::string line;
    while (std::getline(inputFile, line))
    {
        lines.push_back(line);
    }
    inputFile.close();
    if (id >= lines.size())
    {
        std::cerr << "ID out of range. No line to modify.\n";
        return;
    }

    lines[id] = std::to_string(specificParameter);

    std::ofstream outputFile(filename);
    if (!outputFile)
    {
        std::cerr << "Error opening file for writing.\n";
        return;
    }

    for (const auto &l : lines)
    {
        outputFile << l << "\n";
    }
    outputFile.close();
}

void FileInitializer::setSpecificParameter(size_t id, size_t specificParameter)
{
    std::string filename = "../db/specific.txt";
    std::ifstream inputFile(filename);

    if (!inputFile)
    {
        std::cerr << "Error opening file for reading.\n";
        return;
    }
    std::vector<std::string> lines;
    std::string line;
    while (std::getline(inputFile, line))
    {
        lines.push_back(line);
    }
    inputFile.close();
    if (id >= lines.size())
    {
        std::cerr << "ID out of range. No line to modify.\n";
        return;
    }

    lines[id] = std::to_string(specificParameter);

    std::ofstream outputFile(filename);
    if (!outputFile)
    {
        std::cerr << "Error opening file for writing.\n";
        return;
    }

    for (const auto &l : lines)
    {
        outputFile << l << "\n";
    }
    outputFile.close();
}

void FileInitializer::showEmployeeByID(size_t id)
{
    // File names
    const std::string identityFile = "../db/identity.txt";
    const std::string nameFile = "../db/name.txt";
    const std::string departmentFile = "../db/department.txt";
    const std::string salaryFile = "../db/salary.txt";
    const std::string specificFile = "../db/specific.txt";

    // Vectors to hold data from files
    std::vector<int> identities;
    std::string names;
    std::string departments;
    std::string salaries;
    std::string specifics;

    // Read identity.txt
    std::ifstream identityStream(identityFile);
    if (!identityStream)
    {
        std::cerr << "Error opening " << identityFile << std::endl;
        return;
    }

    int identityID;
    while (identityStream >> identityID)
    {
        identities.push_back(identityID);
    }
    identityStream.close();

    if (id >= identities.size())
    {
        std::cerr << "Provided ID is out of range." << std::endl;
        return;
    }

    int i = 0;

    std::ifstream nameStream(nameFile);
    if (!nameStream)
    {
        std::cerr << "Error opening " << nameFile << std::endl;
        return;
    }
    while (std::getline(nameStream, names))
    {
        if (i == id)
        {
            break;
        }
        i++;
    }
    nameStream.close();

    std::ifstream departmentStream(departmentFile);
    if (!departmentStream)
    {
        std::cerr << "Error opening " << departmentFile << std::endl;
        return;
    }

    i = 0;
    while (std::getline(departmentStream, departments))
    {
        if (i == id)
        {
            break;
        }
        i++;
    }
    departmentStream.close();

    std::ifstream salaryStream(salaryFile);
    if (!salaryStream)
    {
        std::cerr << "Error opening " << salaryFile << std::endl;
        return;
    }

    i = 0;
    while (std::getline(salaryStream, salaries))
    {
        if (i == id)
        {
            break;
        }
        i++;
    }
    salaryStream.close();

    std::ifstream specificStream(specificFile);
    if (!specificStream)
    {
        std::cerr << "Error opening " << specificFile << std::endl;
        return;
    }

    i = 0;
    while (std::getline(specificStream, specifics))
    {
        if (i == id)
        {
            break;
        }
        i++;
    }
    specificStream.close();
    if (identities[id] == -1)
    {
        std::cout << "Employee ID " << id << " is marked as removed (-1)." << std::endl;
    }
    else
    {
        std::cout << "ID: " << identities[id] << "\n";
    }
    std::cout << "Name: " << names << "\n";
    std::cout << "Department: " << departments << "\n";
    std::cout << "Salary: " << salaries << "\n";
    std::cout << "Specific: " << specifics << "\n";
}

void FileInitializer::showEmployeesByName(std::string name)
{
    std::ifstream file("../db/name.txt");
    if (!file.is_open())
    {
        std::cerr << "Failed to open file" << std::endl;
        return;
    }

    std::string line;
    size_t row = 0;
    std::vector<size_t> rows;

    while (std::getline(file, line))
    {
        if (line == name)
        {
            rows.push_back(row);
        }
        row++;
    }

    if (rows.empty())
    {
        std::cout << "Employee with name \"" << name << "\" not found." << std::endl;
    }
    else
    {
        for (size_t i : rows)
        {
            FileInitializer::showEmployeeByID(i);
        }
    }

    file.close();
}

void FileInitializer::showEmployeesBySalaryRange(double from, double to)
{
    if (from > to)
    {
        std::swap(from, to);
    }

    std::ifstream file("../db/salary.txt");
    if (!file.is_open())
    {
        std::cerr << "Failed to open file" << std::endl;
        return;
    }

    std::string line;
    size_t row = 0;
    std::vector<size_t> rows;

    while (std::getline(file, line))
    {
        if (std::stod(line) >= from && std::stod(line) <= to)
        {
            rows.push_back(row);
        }
        row++;
    }
    if (rows.empty())
    {
        std::cout << "Employee with Salary range " << from << "-> " << to << " not found." << std::endl;
    }
    else
    {
        for (size_t i : rows)
        {
            FileInitializer::showEmployeeByID(i);
        }
    }
    file.close();
}

void FileInitializer::showEmployeeByDepartment(DepartmentType department)

{
    std::string dep;
    switch (department) 
	{
		case DepartmentType::Development: 
		{
            dep = "Development Department";
        }
        case DepartmentType::HumanResources: 
		{
        	dep = "Human Resources Department";
        }
        case DepartmentType::Finance: 
		{
            dep = "Finance Department";
        }
        case DepartmentType::Sales: 
		{
        	dep = "Sales Department";
        }
        default: 
        {
		    dep = "";
        }
	}

    std::ifstream file("../db/department.txt");
    if (!file.is_open())
    {
        std::cerr << "Failed to open file" << std::endl;
        return;
    }

    std::string line;
    size_t row = 0;
    std::vector<size_t> rows;

    while (std::getline(file, line))
    {
        if (line == dep)
        {
            rows.push_back(row);
        }
        row++;
    }
    
    if (rows.empty())
    {
        std::cout << "Employee in " << dep << " not found." << std::endl;
    }
    else
    {
        for (size_t i : rows)
        {
            FileInitializer::showEmployeeByID(i);
        }
    }
    file.close();
}

