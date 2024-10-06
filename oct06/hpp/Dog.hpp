#pragma once
#include "Pet.hpp"
#include <string>

class Dog : public Pet
{
public:
    Dog(std::string name, size_t age);
    void make_sound() const override;
    void eat() const override;
    void chlp();
};