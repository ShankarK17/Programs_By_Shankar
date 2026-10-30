#include <iostream>
#include <stdexcept>

int balance;
int Number;

int divider(int num, int den){
	if(den == 0){
		throw std::runtime_error("Division by Zero\n");
	}
	return num/den;
}

void setBalance(int amount){
	if(amount < 0){
		throw "NegativeValueException\n";
	}
	balance = amount;
}

void setNumber(char num){
	if(num >= 48 && num <= 57){
		Number = num;
	}
	else{
		throw "NotNumbericValue ~ Expects a numberical value";
	}
}


int main(){
	int num1 = 10, num2 = 0;
	try{
		int res = divider(num1,num2);
		std::cout << "Result: " << res << std::endl;
	}

	catch(const std::runtime_error& e){ // catching standard exception i.e runtime_error
		std::cout << "Error caught : " << e.what() << std::endl; //what() function displays the description of error occured.
	}
	/*
	 * If the try, catch blocks are not used the program gets terminate and does not continue it's execution pass the error
	 * but with try and catch we can handle runtime error more effectively without distruting the execution of program.
	 */
	int a = -1;

	/*
	try{
		setBalance(a);
		std::cout << "Balance is " << balance << std::endl;
	}
	
	catch(const char* errMsg){ // Catching an string error message 
		std::cerr << "Caught an error: " << errMsg << std::endl;
	}
	*/
	try{
		setNumber('a');
		std::cout << "Number: " << Number << "\n";
	}

	catch(...){ //generic exception handler, can work as default catch block can catch any exception if no matching try catch blocks are found
		std::cerr << "An exception was caught\n";
	}


	std::cout << "The rest code still continues.....\n";
	return 0;
}
