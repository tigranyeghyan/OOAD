#include "Car.h"
#include "Engine.h"
#include "Driver.h"
#include <iostream>
#include <vector>

Car::Car() : m_engine ({}), m_driver {nullptr} { }

void Car::add_driver(Driver& driver)
{
	if(m_driver != nullptr)
	{
		std::cout << "There are driver in Car" << std::endl;
	}
	else
	{
		m_driver = &driver;
	}
}

void Car::start()
{
	if(m_driver == nullptr)
	{
		std::cout << "There are no Driver!" << std::endl;
	}
	else
	{
		std::cout << "Vroom .. Vroom Vrooom..." << std::endl;
		m_driver -> go();
		std::cout << "The trip is over!" << std::endl;
		m_driver = nullptr;
	}
}
