#include <iostream>

class Vehicle{
	protected: // protected data members & member function can be accessible inside base class as well as derived class
		   // not cannot be accessed outside.
		std::string model;
		int engine_power;
		int seating_capacity;
	public:
		Vehicle(std::string v_model, int v_engine, int v_seating){
			model = v_model;
			engine_power = v_engine;
			seating_capacity = v_seating;
		}
		void display(){
			std::cout << "\nModel Name: " << model << "\n";
			std::cout << "Engine Power: " << engine_power << " hp\n";
			std::cout << "Seating Capacity: " << seating_capacity << " Passengers\n";
		}
};

class Car : public Vehicle{
	private:
		int boot_space;
	public:
		Car(std::string car_name, int car_engine, int car_seating, int car_boot) 
			: Vehicle(car_name, car_engine, car_seating){
			boot_space = car_boot;
		}
		void displayCar(){
			display();
			std::cout << "Boot space: " << boot_space << " litres\n";
		}
};

class Bike : public Vehicle{
	private:
		int fuel_tank;
	public:
		Bike(std::string bike_name, int bike_engine, int bike_seating, int bike_tank)
			: Vehicle(bike_name, bike_engine, bike_seating){
				fuel_tank = bike_tank;
			}
		void displayBike(){
			display();
			std::cout << "Fuel Tank: " << fuel_tank << " Litres\n";
		}
};

int main(){
	Car c1("Thar", 117, 5, 447);
	Bike b1("CB 350", 21, 2, 15);
	c1.displayCar();
	b1.displayBike();
	return 0;
}


