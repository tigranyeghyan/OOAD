#pragma once 

#include "Beverage.hpp"
#include <string>

class AddOnDecorator : public Beverage
{
public:
    AddOnDecorator(Beverage *ptr);
    virtual std::string getDescription() const = 0;
    virtual double cost() const = 0;
protected:
    Beverage *m_ptr;
};