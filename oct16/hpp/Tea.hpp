#pragma once 

#include "Beverage.hpp"
#include <string>

class Tea : public Beverage
{
public:
    std::string getDescription() const override;
    double cost() const override;
};