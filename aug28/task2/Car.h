#pragma once
#include "Driver.h"
#include "Engine.h"
#include <vector>
class Car
{
public:

	Car();
	Car(const Car&) = delete;
	Car(Car&&) = delete;
	Car& operator=(const Car&) = delete;
	Car& operator=(Car&&) = delete;
	~Car() = default;
	void add_driver(Driver&);
	void start();

private:
	Engine m_engine;
	Driver* m_driver;
};
