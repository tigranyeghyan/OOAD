#pragma once
#include "Pet.hpp"
#include <string>

class Eagle : public Pet
{
public:
    Eagle(std::string name, size_t age);
    void make_sound() const override;
    void eat() const override;
};
