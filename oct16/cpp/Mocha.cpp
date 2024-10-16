#include "../hpp/Mocha.hpp"
#include "../hpp/Beverage.hpp"
#include <string>

Mocha::Mocha(Beverage *ptr) : AddOnDecorator(ptr)
{ 
}

std::string Mocha::getDescription() const 
{
    return  m_ptr -> getDescription() + " & Mocha";
}

double Mocha::cost() const
{
    return 150 + m_ptr -> cost();
} 