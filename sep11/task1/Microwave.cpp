#include <iostream>
#include "Microwave.h"

Microwave::Microwave()
{
	m_state = false;
	std::cout << "Microwave DEF CTOR" << std::endl;
}

void Microwave::turnOn()
{
	if(m_state)
	{
		std::cout << "Microwave is already ON!" << std::endl;
	}
	else
	{
		m_state = true;
		std::cout << "Microwave TURN ON!" << std::endl;
	}
}
