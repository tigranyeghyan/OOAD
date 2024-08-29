#pragma once
#include "Pilot.h"
#include "Engine.h"
#include <vector>
class Plane
{
public:

	Plane();
	Plane(const Plane&) = delete;
	Plane(Plane&&) = delete;
	Plane& operator=(const Plane&) = delete;
	Plane& operator=(Plane&) = delete;
	~Plane() = default;
	void add_pilot(const Pilot&);
	void fly();

private:
	Engine m_engine;
	std::vector<Pilot> m_pilots;
};
