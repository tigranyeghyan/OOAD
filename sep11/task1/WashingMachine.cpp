#include <iostream>
#include "WashingMachine.h"

WashingMachine::WashingMachine()
{	
	m_state = false;
	std::cout << "Waching Machine DEF CTOR" << std::endl;
}

void WashingMachine::turnOn()
{
	if(m_state)
	{
		std::cout << "Washing Machine is already ON!" << std::endl;
	}
	else
	{
		m_state = true;
		std::cout << "Washing Machine TURN ON!" << std::endl;
	}
}
