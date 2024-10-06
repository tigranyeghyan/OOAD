#include <iostream>
#include "../hpp/Pet_Adoption_Center.hpp"
#include "../hpp/Pet_Type.hpp"

int main()
{
    Pet_Adoption_Center *ptr = Pet_Adoption_Center::get_instance(Pet_Type::Domestic);
    Abstract_Pet_Factory *abstract = nullptr; 
    abstract = ptr -> get_factory_pointer();
    Pet* ptt = abstract -> create_mammal("Jeko", 1);
    ptt -> display_info();
    ptt -> make_sound();
    ptt -> eat();
    delete ptt;
    Pet_Adoption_Center::destroy_instance();
    return 0;
}

