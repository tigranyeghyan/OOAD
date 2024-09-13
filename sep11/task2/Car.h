#pragma once
#include "Vehicle.h"

class Car : public Vehicle
{
public:
	// Polymorphism
	void move() override;
	// Setters
	void setMake(const std::string&);
    void setModel(const std::string&);
    void setYear(int Year);
 	void setMileage(double Mileage);
	// Getters
    std::string getMake() const;
    std::string getModel() const;
    int getYear() const;
   	double getMileage() const;
	// display info 
	void displayInfo() const;
	// CTOR DTOR
	Car();
	Car(const Car&) = default;
	Car(Car&&) = default;
	Car& operator=(const Car&) = default;
	Car& operator=(Car&&) = default;
	~Car() = default
private:
	std::string make;
	std::string model;
	int year;
	double mileage;
};
