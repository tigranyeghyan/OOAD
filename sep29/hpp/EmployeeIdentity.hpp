#pragma once

class EmployeeIdentity
{
public:
	static size_t getIdentity();
private:
	EmployeeIdentity();
	static size_t identity;
};