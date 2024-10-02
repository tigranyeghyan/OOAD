#include "Salary.hpp"
#include <iostream>

double Salary::calculateSalary(size_t spec, double bonus, double baseSalary) const
{
    return baseSalary + bonus * spec;
}

double Salary::calculateSalary(double spec, double bonus, double baseSalary) const
{
    return baseSalary + bonus * spec;
}