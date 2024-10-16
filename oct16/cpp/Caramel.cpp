#include "../hpp/Caramel.hpp"
#include "../hpp/Beverage.hpp"
#include <string>

Caramel::Caramel(Beverage *ptr) : AddOnDecorator(ptr)
{ 
}

std::string Caramel::getDescription() const 
{
    return  m_ptr -> getDescription() + " & Caramel"; 
}

double Caramel::cost() const
{
    return 250 + m_ptr -> cost();
} 