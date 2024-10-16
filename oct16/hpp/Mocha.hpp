#pragma once 

#include "AddOnDecorator.hpp"
#include "Beverage.hpp"
#include <string>

class Mocha : public AddOnDecorator
{
public:
    Mocha(Beverage* ptr);
    std::string getDescription() const override;
    double cost() const override;
};
