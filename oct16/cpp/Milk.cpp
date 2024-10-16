#include "../hpp/Milk.hpp"
#include "../hpp/Beverage.hpp"
#include <string>

Milk::Milk(Beverage *ptr) : AddOnDecorator(ptr)
{ 
}

std::string Milk::getDescription() const 
{
    return  m_ptr -> getDescription() + " & Milk";
}

double Milk::cost() const
{
    return 200 + m_ptr -> cost();
} 