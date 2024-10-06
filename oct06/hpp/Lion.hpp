#pragma once
#include "Pet.hpp"
#include <string>

class Lion : public Pet
{
public:
    Lion(std::string name, size_t age);
    void make_sound() const override;
    void eat() const override;
};