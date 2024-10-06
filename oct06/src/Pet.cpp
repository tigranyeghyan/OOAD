#include "../hpp/Pet.hpp"
#include <iostream>
#include <string>

Pet::Pet(std::string name, size_t age)
{
    name_ = name;
    age_ = age;
}

void Pet::display_info () const 
{
    std::cout << "Name: " << name_ << std::endl;
    std::cout << "Age: " << age_ << std::endl;
}