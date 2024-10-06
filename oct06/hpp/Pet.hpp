#pragma once
#include <string>

class Pet
{
public:
    Pet(std::string name, size_t age);
    virtual void make_sound() const = 0;
    virtual void eat() const = 0;
    void display_info () const;
private:
    std::string name_;
    size_t age_;
};