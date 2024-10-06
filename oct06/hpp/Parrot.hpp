#pragma once
#include "Pet.hpp"
#include <string>

class Parrot : public Pet
{
public:
    Parrot(std::string name, size_t age);
    void make_sound() const override;
    void eat() const override;
};