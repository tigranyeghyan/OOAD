#include <iostream>
#include "Appliance.h"

void Appliance::turnOff()
{
	m_state = false;
	std::cout << "Turning OFF!" << std::endl;
}

bool Appliance::getState() const 
{
	return m_state;
}
