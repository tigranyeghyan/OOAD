#include "../hpp/Eagle.hpp"
#include <iostream>
#include <string>

Eagle::Eagle(std::string name, size_t age) : Pet(name, age)
{
    std::cout << "Eagle Created Successfully" << std::endl;
}

void Eagle::make_sound() const
{
    std::cout << "Arciv civ civ" << std::endl;
}

void Eagle::eat() const
{
    std::cout << "Arciv eat Successfully" << std::endl;
}

