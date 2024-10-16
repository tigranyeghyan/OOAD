#pragma once 

#include "Beverage.hpp"
#include <string>

class Espresso : public Beverage
{
public:
    std::string getDescription() const override;
    double cost() const override;
};