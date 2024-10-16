#include "../hpp/WhippedCream.hpp"
#include "../hpp/Beverage.hpp"
#include <string>

WhippedCream::WhippedCream(Beverage *ptr) : AddOnDecorator(ptr)
{ 
}

std::string WhippedCream::getDescription() const 
{
    return  m_ptr -> getDescription() + " & Whipped Cream";
}

double WhippedCream::cost() const
{
    return 300 + m_ptr -> cost();
} 