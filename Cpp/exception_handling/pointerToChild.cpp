#include <iostream>
#include <string>
#include <exception>

class InvalidProcessException: public std::exception{
	private:
		std::string errmsg;
	public:
		InvalidProcessException(const std::string msg):errmsg(msg){}
		const char* what() const noexcept override{
			return errmsg.c_str();
		}
};

class Payment { //Abstract Base Class, as it have a pure virtual function
	protected:
		double balance;
		int amount;
		double processing_fee;
	public:
		Payment(int balance, int amount, double fee){
			this->balance = balance;
			this->amount = amount;
			processing_fee = fee;
		}
		virtual void processPayment() = 0; // pure virtual method
		virtual void displayRecipt(){ // virtual methods means it can be override by derived classes.
			std::cout << "\nTransferred Amount : " << amount << "\n";
			std::cout << "Charge fee: " << processing_fee << "\n";
			double charge = (processing_fee / 100) * amount;
			balance = balance - (amount + charge);
			std::cout << "Available Balance: " << balance << "\n";

		}
		virtual ~Payment(){}
};

class Card: public Payment{
	private:
		std::string card_no;
		void displayRecipt(){ // overriddinf the virtual function of base class.
			std::cout << "\n==========RECIPT==========\n";
			std::cout << "Transaction of Amount " << amount << " Successful\n"; 
			std::cout << "Card Number: " << card_no << "\n";
			std::cout << "Convinence fee: " << processing_fee << "%\n";
			std::cout << "Available Balance: " << balance << "\n";
		}
	public:
		Card(std::string card_no, double c_balance, int t_amount)
			: Payment(c_balance, t_amount, 2.0){
				this->card_no = card_no;
			}
		void processPayment(){ // To avoid class Card being an abstract class it is required to override a pure
				       // virtual method
			double fee_amount = (processing_fee / 100) * amount;
			try{
				if(amount <= 0){
					std::cout << "Invalid Amount! Amount must be greater than 0\n";
				}
				if(balance < amount + fee_amount){
					throw InvalidProcessException("Insufficient funds");
				}
				else{
					std::cout << "\nProcessing... Transaction of amount " << amount << "\n";
					balance = balance  - (amount + fee_amount);
					displayRecipt();
				}
			}
			catch(const InvalidProcessException& p){
				std::cerr << "Error while processing card payment ~ " << p.what() << std::endl;
				throw;
			}	
		}
};

class UPI: public Payment{ 
	private: 
		std::string upi_id;
	public:
		UPI(std::string upi_id, double a_balance, int u_amount)
			: Payment(a_balance, u_amount, 1.5){
				this->upi_id = upi_id;
			}
		void processPayment(){
			double upi_fee = (processing_fee / 100) * amount;
			try{
			if(amount <= 0){
				std::cout << "Invalid Amount! Amount must be greater than 0\n";
			}
			if(balance < amount + upi_fee){
				throw InvalidProcessException("Insufficient funds");
			}
			
			else{
				std::cout << "\nProcessing... Transaction of amount " << amount << "\n";
				displayRecipt(); //here the displayRecipt function has not been overrided 
						 //therefore it will rely on same function of the base class.
			}
			}
			catch(const InvalidProcessException& p){
				std::cerr << "Error while UPI transaction ~ " << p.what() << std::endl;
				throw;
			}
		}
};

void validateInput(int i){
	if(i <= 0){
		throw 201; // throwing integer value as code
	}

}

void validateInput(double d){
	if(d <= 0){
		throw "Invalid Balance Value"; // throwing a string literal as exception message
	}

}

class InvalidInputException: public std::exception{ //custom exception class for checking invalid inputs
	private:
		std::string errMsg;
	public:
		InvalidInputException(const std::string msg): errMsg(msg){}
		const char* what() const noexcept override{ // overriding what() function to provide custom description of the exception occured
			return errMsg.c_str();
		}
};

void validateInput(const std::string& s){	
		if(s.empty()){
			throw InvalidInputException("Invalid input! Empty Input");
		}
		else if(s.find(' ') != std::string::npos){
			throw InvalidInputException("Invalid input! Contains Space");
		}
		else if(s.length() != 16){
			throw InvalidInputException("Invalid input! Wrong Length");
		}
}


int main(){
	std::string input;
	double AccBalance;
	int amount, choice;
       	std::cout << "--------Welcome to Payment Application--------\n";
	std::cout << "Enter Your current balance: ";
	std::cin >> AccBalance;
	try{
		validateInput(AccBalance);
	}	
	catch(const char* errmsg){ //this catch block will look for try block return a const string
		std::cerr << "\nException caught ~ " << errmsg << "\n";
		std::exit(EXIT_FAILURE);
	}
	try{
	std::cout << "Enter amount to transfer: ";
	std::cin >> amount;
		validateInput(amount);
	}
	catch(int errCode){ // this catch block will correspond to try block with returning integer value
		std::cerr << "\nCaught an integer error code: " << errCode << " Invalid value entered\n";
		std::exit(EXIT_FAILURE);
	}
	std::cout << "Choose mode of payment: \n1.Card\t2.UPI: ";
	std::cin >> choice;
	Payment *Pptr = nullptr; // Initializing an object pointer of Base class type to point to derived class.
	switch(choice){
		case 1:
			std::cout << "Enter card no: ";
			std::cin.ignore();
			std::getline(std::cin,input);
			try{
				validateInput(input);
			}
			catch(const InvalidInputException& e){
				std::cerr << "\nInvalidInputException caught: " << e.what() << std::endl;
				std::exit(EXIT_FAILURE);
			}
			Pptr = new Card(input, AccBalance, amount);
			try{
				Pptr->processPayment();
			}
			catch(const InvalidProcessException& p){
				std::cerr << "Caught rethrown InvalidProcessException in MAIN ~ " << p.what() << std::endl;
			}
			delete Pptr; 
			break;
		case 2:	
			std::cout << "Enter UPI id: ";
			std::cin.ignore();
			std::getline(std::cin, input);
			try{
				validateInput(input);
			}
			catch(const InvalidInputException& e){
				std::cerr << "InvalidInputException caught: " << e.what() << std::endl;
				std::exit(EXIT_FAILURE);
			}
			Pptr = new UPI(input, AccBalance, amount);
			try{
				Pptr->processPayment();
			}
			catch(const InvalidProcessException& p){
				std::cerr << "Caught rethrown InvalidProcessException in MAIN ~ " << p.what() << std::endl;
			}	
			delete Pptr;
			break;
		default:
			std::cout << "Invalid Choice\n";
	}
	return 0;
}
