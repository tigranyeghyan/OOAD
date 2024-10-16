#pragma once 

#include "AddOnDecorator.hpp"
#include "Beverage.hpp"
#include <string>

class Milk : public AddOnDecorator
{
public:
    Milk(Beverage* ptr);
    std::string getDescription() const override;
    double cost() const override;
};


