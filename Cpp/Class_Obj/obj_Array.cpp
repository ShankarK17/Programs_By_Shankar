#include <iostream>
#include <string>

using namespace std;
class Cars{
	private:
		string model;
		int year;
		char fuel;
	public:
		void addCar(string, int, char);
		void displayCar(){
			cout << "Car Model: " << model << "\tModel Year: " << year << "\tFuel Type: " << fuel << "\n";
		}
};

void Cars::addCar(string car_model, int model_year, char fuel_type){
	model = car_model;
	year = model_year;
	fuel = fuel_type;
}

int main(){
	Cars c[3]; // Array of object of class Cars.
	c[0].addCar("Mustang", 1968, 'P');
	c[1].addCar("Camero", 2004, 'P');
	c[2].addCar("Hellcat", 2008, 'D');
	for(int i = 0; i<3; i++){
		c[i].displayCar();
	}

	return 0;
}



		
