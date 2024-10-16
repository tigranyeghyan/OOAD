#pragma once 

#include "AddOnDecorator.hpp"
#include "Beverage.hpp"
#include <string>

class Sugar : public AddOnDecorator
{
public:
    Sugar(Beverage* ptr);
    std::string getDescription() const override;
    double cost() const override;
};
