#pragma once
#include "ISalary.hpp"

class Salary : public ISalary
{
public:
    double calculateSalary(size_t spec, double bonus, double baseSalary) const override;
	double calculateSalary(double spec, double bonus, double baseSalary) const override;
};

