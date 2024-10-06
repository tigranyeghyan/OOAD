#pragma once
#include "Pet.hpp"
#include <string>

class Abstract_Pet_Factory
{
public:
    virtual Pet* create_mammal(std::string name, size_t age) = 0;
    virtual Pet* create_bird(std::string name, size_t age) = 0;
};