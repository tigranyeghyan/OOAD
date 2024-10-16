#pragma once 

#include "AddOnDecorator.hpp"
#include "Beverage.hpp"
#include <string>


class WhippedCream : public AddOnDecorator
{
public:
    WhippedCream(Beverage* ptr);
    std::string getDescription() const override;
    double cost() const override;
};
