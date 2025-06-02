#include <iostream>
#include <string>

class Vehicle
{
	private:
	std::string model;
	public:
	Vehicle();
	virtual ~Vehicle();
	virtual void describe() const;
};

class Car : public Vehicle
{
	public:
	Car();
	~Car();
	void describe() const override;
};

Vehicle::Vehicle() : model("Generic Vehicle") {
	std::cout << "Vehicle created: " << model << std::endl;
}

Vehicle::~Vehicle() {
	std::cout << "Vehicle destroyed: " << model << std::endl;
}

Car::Car() {
	std::cout << "Car created." << std::endl;
}

Car::~Car() {
	std::cout << "Car destroyed." << std::endl;
}

void Vehicle::describe() const {
	std::cout << "This is a vehicle." << std::endl;
}

void Car::describe() const {
	std::cout << "This is a car." << std::endl;
}

int main()
{
	Car a;
	a.describe(); // Calls the Car's describe method
}
