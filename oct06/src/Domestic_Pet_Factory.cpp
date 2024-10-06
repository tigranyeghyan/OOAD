#include "../hpp/Domestic_Pet_Factory.hpp"
#include "../hpp/Dog.hpp"
#include "../hpp/Parrot.hpp"
#include <string>
#include <memory>

Pet *Domestic_Pet_Factory::create_mammal(std::string name, size_t age)
{
    Dog *ptr = new Dog(name, age);
    return ptr;
}

Pet *Domestic_Pet_Factory::create_bird(std::string name, size_t age)
{
    Parrot *ptr = new Parrot(name, age);
    return ptr;
}
