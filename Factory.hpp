#include <iostream>
#include <string>

class Vehicle {
public:
	virtual void displayVehicle() = 0;
};

class Car : public Vehicle {
public:
	void displayVehicle() {
    	std::cout << "I am a Car." << std::endl;
  	}
};

class Truck : public Vehicle {
public:
  	void displayVehicle() {
    	std::cout << "I am a Truck." << std::endl;
  	}
};

class VehicleFactory {
public:
  	static Vehicle* createVehicle(std::string type) {
    	if (type == "Car")
      		return new Car();
    	if (type == "Truck")
      		return new Truck();
    	return nullptr;
  }
};

int main() {
	Vehicle* car = VehicleFactory::createVehicle("Car");
	Vehicle* truck = VehicleFactory::createVehicle("Truck");

  	car -> displayVehicle();
  	truck -> displayVehicle();

  	delete car;
  	delete truck;

  	return 0;
}

/**
 * Why factory pattern?
 * 
 * I think:
 * 1. Hide the complexity in creating the instance.
 * 2. We don't need to know which type of concrete object is created.
 */
