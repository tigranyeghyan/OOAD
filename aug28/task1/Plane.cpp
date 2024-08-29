#include "Plane.h"
#include "Engine.h"
#include "Pilot.h"
#include <iostream>
#include <vector>

Plane::Plane() : m_engine ({}) { }

void Plane::add_pilot(const Pilot& pilot)
{
	if(m_pilots.size() == 2)
	{
		std::cout << "Enough Pilots to fly" << std::endl;
	}
	else
	{
		m_pilots.push_back(pilot);
	}
}

void Plane::fly()
{
	if(m_pilots.empty())
	{
		std::cout << "There are no any Pilots!" << std::endl;
	}
	else
	{
		std::cout << "Vjuuuuuuuuuuuuhhhhhhhhh" << std::endl;
		m_pilots.clear();
	}
}
