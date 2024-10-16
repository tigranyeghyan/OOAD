#include <iostream>
#include "../hpp/Beverage.hpp"
#include "../hpp/AddOnDecorator.hpp"
#include "../hpp/Coffee.hpp"
#include "../hpp/Milk.hpp"
#include "../hpp/Caramel.hpp"
#include "../hpp/Sugar.hpp"

void manage_beverage(Beverage *p) 
{
    int act;
    while(act != 0) {
        std::cout << "1. Add Milk:\n2. Add Sugar:\n3. Add Caramel:\n0. Exit:\n";
        std::cin >> act;
        switch(act) {
            case 1:
                p = new Milk(p);
                std::cout << p->getDescription() << std::endl;
                std::cout << "Cost: " << p-> cost() << std::endl;
                break;
            case 2:
                p = new Sugar(p);
                std::cout << p->getDescription() << std::endl;
                std::cout << "Cost: " << p-> cost() << std::endl;
                break;
            case 3:
                p = new Caramel(p);
                std::cout << p->getDescription() << std::endl;
                std::cout << "Cost: " << p-> cost() << std::endl;
                break;
            case 0:
                break;
        }
    }
}

int main() {
    Beverage *p1 = new Coffee();
    std::cout << p1 -> cost() << std::endl;
    manage_beverage(p1);
    delete p1;
    return 0;
}