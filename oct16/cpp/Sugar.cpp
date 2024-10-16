#include "../hpp/Sugar.hpp"
#include "../hpp/Beverage.hpp"
#include <string>

Sugar::Sugar(Beverage *ptr) : AddOnDecorator(ptr)
{ 
}

std::string Sugar::getDescription() const 
{
    return  m_ptr -> getDescription() + " & Sugar";
}

double Sugar::cost() const
{
    return 50 + m_ptr -> cost();
} 