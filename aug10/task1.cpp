#include <iostream>
#include <string>

class Car
{
private:
	std::string make;
	std::string model;
	int year;
	double mileage;
public:
	//Constructors
	Car();
	Car(std::string, std::string, int, double);
	Car(const Car&);
	// Setters
    	void setMake(std::string Make) { make = Make; }
    	void setModel(std::string Model) { model = Model; }
    	void setYear(int Year) { year = Year; }
 	void setMileage(double Mileage) { mileage = Mileage; }
	// Getters
    	std::string getMake() const { return make; }
    	std::string getModel() const { return model; }
    	int getYear() const { return year; }
   	double getMileage() const { return mileage; }
	// display info 
	void displayInfo();
	//other
	void drive(double distance) {mileage += distance;}
	void service() {mileage = 0;}
	
};

//Constructors

Car::Car()
{
	make = "";
	model = "";
	year = 0;
	mileage = 0;
}

Car::Car(std::string Make, std::string Model, int Year, double Mileage)
{
	make = Make;
	model = Model;
	year = Year;
	mileage = Mileage;
}

Car::Car(const Car& obj)
{
	make = obj.make;
	model = obj.model;
	year = obj.year;
	mileage  = obj.mileage;
}


// display info

void Car::displayInfo()
{
	std::cout << "Car inforamation:" << std::endl;
	std::cout << "Make      | " << make << std::endl;
	std::cout << "Model     | " << model << std::endl;
	std::cout << "Year      | " << year << std::endl;
	std::cout << "Mileage   | " << mileage << std::endl;
}

int main()
{
	Car car1("BMW", "M4 G82", 2020, 52222);
	Car car2(car1);
	car2.displayInfo();
	car2.drive(50000);
	car2.displayInfo();
	car2.service();
	car2.displayInfo();
	return 0;
}
