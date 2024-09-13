#pragma once
class Vehicle
{
public:
	virtual void move() = 0;
	virtual Vehicle() = default;
};
