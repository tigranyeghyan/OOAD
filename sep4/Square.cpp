#include <iostream>
#include "Square.h"

Square::Square(int tmp) : side {tmp} { }

void Square::draw()
{
	for (int i = 0; i < side; ++i) 
	{
        for (int j = 0; j < side; ++j) 
		{
            std::cout << "* ";
        }
        std::cout << std::endl;
    }
}
