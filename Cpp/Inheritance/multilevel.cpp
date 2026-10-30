#include <iostream>
#include <string>
using namespace std;

class Vehicle{
	protected:
		string model;
		int top_speed;
		int hp;
	public:
		Vehicle(string name, int speed, int power){
				model = name;
				top_speed = speed;
				hp = power;
		}
		void display(){
			cout << "\nModel: " << model << "\n";
			cout << "Top speed: " << top_speed << "\n";
			cout << "Horse Power: " << hp << "\n";
		}
};

class Car : public Vehicle{
	private:
		double mileage;
		int fuel_price;
		double cal_runningCost(double km){
			return (km / mileage) * fuel_price;
		}
	public:
		Car(string car_name, int car_speed, int car_hp, double car_mileage, int car_fuel)
			: Vehicle(car_name, car_speed, car_hp) {
				mileage = car_mileage;
				fuel_price = car_fuel;
			}
		void displayCar(){
			display();
			cout << "Mileage: " << mileage << " Km/l\n";
			cout << "Fuel Price : " << fuel_price << " rs\n";
		}
		double runningCost(double km){
			return cal_runningCost(km);
		}
};

class ElectricCar : public Car{
	private:
		double battery;
		double electricity_rate;
		double cal_chargingCost(){
			return battery * electricity_rate;
		}
	public:
		ElectricCar(string ele_name, int ele_speed, int ele_hp, double ele_battery, double ele_rate)
			: Car(ele_name, ele_speed, ele_hp, ele_battery, ele_rate) {
				battery = ele_battery;
				electricity_rate = ele_rate;
			}
		void displayEle(){
			display();
			cout << "Battery Capacity: " << battery << " kWh\n";
			cout << "Electricity Rate: " << electricity_rate << " Rs/kWh\n";
		}
		double chargingCost(){
			return cal_chargingCost();
		}
};

int main(){
	Car car1("Harrier", 195, 170, 16.8, 102);
	ElectricCar ecar1("Harrier EV", 180, 234, 65, 3.64);
	car1.displayCar();
	cout << "Cost of Running of Car: " << car1.runningCost(300) << "\n";
	ecar1.displayEle();
	cout << "Cost of Charging of Electric car: " << ecar1.chargingCost() << "\n";

	return 0;
}




