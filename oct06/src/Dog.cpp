#include "../hpp/Dog.hpp"
#include <iostream>
#include <string>

Dog::Dog(std::string name, size_t age) : Pet(name, age)
{
    std::cout << "Dog created Successfully" << std::endl;
}

void Dog::make_sound() const
{
    std::cout << "Haf Haf Haf" << std::endl;
}

void Dog::eat() const
{
    std::cout << "Chkl CHkl Chkl" << std::endl;
}

void Dog::chlp()
{
}
