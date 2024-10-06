#pragma once
#include "Abstract_Pet_Factory.hpp"

class Wild_Pet_Factory : public Abstract_Pet_Factory
{
public:
    Pet* create_mammal(std::string name, size_t age) override;
    Pet* create_bird(std::string name, size_t age) override;
};