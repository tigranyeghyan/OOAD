#include "../hpp/Pet_Adoption_Center.hpp"
#include "../hpp/Domestic_Pet_Factory.hpp"
#include "../hpp/Wild_Pet_Factory.hpp"
#include <iostream>
#include <memory>

Pet_Adoption_Center::Pet_Adoption_Center(Pet_Type type)
{
    if(type == Pet_Type::Domestic)
    {
        ptr = new Domestic_Pet_Factory();
    }
    else if (type == Pet_Type::Wild)
    {
        ptr = new Wild_Pet_Factory();
    }
    else 
    {
        std::cerr << "Type not match!" << std::endl;
    }
}

Pet_Adoption_Center::~Pet_Adoption_Center()
{
    delete ptr;
}

Abstract_Pet_Factory *Pet_Adoption_Center::get_factory_pointer() const
{
    if(single_objcet)
    {
        return ptr;
    }
    else
    {
        return nullptr;
    }
}

Pet_Adoption_Center *Pet_Adoption_Center::get_instance(Pet_Type type)
{
    if(!single_objcet)
    {
        single_objcet.reset(new Pet_Adoption_Center(type));
        return single_objcet.get();
    }
    else
    {
        return single_objcet.get();
    }
}

void Pet_Adoption_Center::destroy_instance()
{
    single_objcet.reset(nullptr);
}

std::unique_ptr<Pet_Adoption_Center> Pet_Adoption_Center::single_objcet = nullptr;


