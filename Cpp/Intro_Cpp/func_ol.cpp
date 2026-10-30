#include <iostream>

int add(int a, int b){
	return a+b;
}

double add(double x, double y){
	return x+y;
}

/*
 * Here two functions are defined with the same names
 * but they differ in types of return values and parameters
 * this is call "function overloading" where functions are be manipulated 
 * for similar functionality based on types, numbers and order of arguments/
 */

int main(){
	std::cout << add(11, 6) << std::endl;
	std::cout << add(10.3, 2.5) << "\n";
	// although the function names are same they differ in arguments passed
	// and based on that the appropriate function is called.
	return 0;
}
