#include <iostream>

double areaCircle(const double pi, int r){
	//pi = 5.12; will coz an error stating assignment of read only data; 
	return pi*r*r;
}

int main(){
	double radius = 5, pi = 3.14159, area;
	area = areaCircle(pi, radius);
	std::cout << "Area of circle with radius " << radius << " is " << area << "\n";
	return 0;
}


