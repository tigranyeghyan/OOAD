#include <iostream>
#include <cmath>
#include "Circle.h"

Circle::Circle(int rad) :  radius{rad} { }

void Circle::draw() 
{
	int diameter = radius * 2;
	for (int i = 0; i <= diameter; ++i) 
	{
        for (int j = 0; j <= diameter; ++j) 
		{
            double distance = sqrt((i - radius) * (i - radius) + (j - radius) * (j - radius));
            if (distance > radius - 0.5 && distance < radius + 0.5) 
			{
                std::cout << "*";
            } 
			else 
			{
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
}
