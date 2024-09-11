#pragma once

class Appliance
{
public:
	virtual void turnOn() = 0;
	void turnOff();
	bool getState() const ;
	virtual ~Appliance() = default;
protected:
	bool m_state; // true if on 
};
