#include "../hpp/Lion.hpp"
#include <iostream>
#include <string>

Lion::Lion(std::string name, size_t age) : Pet(name, age)
{
    std::cout << "Ayruc Created Successfully" << std::endl;
}

void Lion::make_sound() const
{
    std::cout << "Rrrrrrrrrrr ..." << std::endl;
}

void Lion::eat() const
{
    std::cout << "Ayruc eat successfully" << std::endl;
}
