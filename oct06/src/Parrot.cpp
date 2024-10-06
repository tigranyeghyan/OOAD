#include "../hpp/Parrot.hpp"
#include <iostream>
#include <string>

Parrot::Parrot(std::string name, size_t age) : Pet(name, age)
{
    std::cout << "Parrot created Successfully" << std::endl;
}

void Parrot::make_sound() const
{
    std::cout << "Squawk Squawk Squawk" << std::endl;
}

void Parrot::eat() const
{
    std::cout << "Parrot eats...." << std::endl;
}

