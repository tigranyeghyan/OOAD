#pragma once
#include "Appliance.h"

class Microwave : public Appliance
{
public:
	void turnOn() override;
	Microwave();
	Microwave(const Microwave&) = default;
	Microwave(Microwave&&) = default;
	Microwave& operator=(const Microwave&) = default;
	Microwave& operator=(Microwave&&) = default;
	~Microwave() = default;
};
