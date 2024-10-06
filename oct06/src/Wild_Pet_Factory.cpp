#include "../hpp/Wild_Pet_Factory.hpp"
#include "../hpp/Lion.hpp"
#include "../hpp/Eagle.hpp"
#include <string>
#include <memory>

Pet *Wild_Pet_Factory::create_mammal(std::string name, size_t age)
{
    std::unique_ptr<Lion> temp (new Lion(name, age));
    return temp.get();
}

Pet *Wild_Pet_Factory::create_bird(std::string name, size_t age)
{
    std::unique_ptr<Eagle> temp (new Eagle(name, age));
    return temp.get();
}
