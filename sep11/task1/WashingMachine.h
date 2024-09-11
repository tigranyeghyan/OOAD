#pragma once 
#include "Appliance.h"

class WashingMachine : public Appliance
{
public:
	void turnOn() override;
	WashingMachine();
	WashingMachine(const WashingMachine&) = default;
	WashingMachine(WashingMachine&&) = default;
	WashingMachine& operator=(const WashingMachine&) = default;
	WashingMachine& operator=(WashingMachine&&) = default;
	~WashingMachine() = default;
};
