#pragma once 

#include "AddOnDecorator.hpp"
#include "Beverage.hpp"

class Caramel : public AddOnDecorator
{
public:
    Caramel(Beverage *ptr);
    std::string getDescription() const override;
    double cost() const override;
};
