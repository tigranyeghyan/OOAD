#pragma once
#include "../hpp/Pet_Type.hpp"
#include "../hpp/Abstract_Pet_Factory.hpp"
#include <memory>

class Pet_Adoption_Center
{
public:
    static Pet_Adoption_Center* get_instance(Pet_Type type);
    Abstract_Pet_Factory* get_factory_pointer() const;
    ~Pet_Adoption_Center();
    static void destroy_instance();
private:
    Pet_Adoption_Center(Pet_Type type);
    Abstract_Pet_Factory *ptr;
    static std::unique_ptr<Pet_Adoption_Center> single_objcet;
};

