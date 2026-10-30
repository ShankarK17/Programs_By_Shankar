#include <iostream>
#include <string>

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
	public:
		Card(std::string card_no, double c_balance, int t_amount)
			: Payment(c_balance, t_amount, 2.0){
				this->card_no = card_no;
			}
		void displayRecipt(){ // overriddinf the virtual function of base class.
			std::cout << "\n==========RECIPT==========\n";
			std::cout << "Transaction of Amount " << amount << " Successful\n"; 
			std::cout << "Card Number: " << card_no << "\n";
			std::cout << "Convinence fee: " << processing_fee << "%\n";
			std::cout << "Available Balance: " << balance << "\n";
		}
		void processPayment(){ // To avoid class Card being an abstract class it is required to override a pure
				       // virtual method
			double fee_amount = (processing_fee / 100) * amount;
			if(amount <= 0){
				std::cout << "Invalid Amount! Amount must be greater than 0\n";
			}
			if(balance <= amount + fee_amount){
				std::cout << "Transaction Failed! Not Sufficient Balance\n";
			}
			else{
				std::cout << "\nProcessing... Transaction of amount " << amount << "\n";
				double charge = (processing_fee / 100) * amount; 
				balance = balance - (amount + charge);
				displayRecipt();
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
			if(amount <= 0){
				std::cout << "Invalid Amount! Amount must be greater than 0\n";
			}
			if(balance <= amount){
				std::cout << "UPI Transaction Failed! Not Sufficient Balance\n";
			}
			else{
				std::cout << "\nProcessing... Transaction of amount " << amount << "\n";
				displayRecipt(); //here the displayRecipt function has not been overrided 
						 //therefore it will rely on same function of the base class.
			}
		}
};

void validateInput(int i){
	if(i <= 0){
		std::cerr << "Invalid Input!\n";
		std::exit(EXIT_FAILURE);
	}

}

void validateInput(double d){
	if(d <= 0){
		std::cerr << "Invalid Input!\n";
		std::exit(EXIT_FAILURE);
	}

}

void validateInput(std::string s){	
		if(s.empty()){
		std::cerr << "cannot be empty\n";
		std::exit(EXIT_FAILURE);
		}
		if(s.length() != 16){
			std::cerr << "lenght must be 16\n";
			std::exit(EXIT_FAILURE);
		}
		if(s.find(' ') != std::string::npos){
			std::cerr << "cannot contain spaces\n";
			std::exit(EXIT_FAILURE);
		}
}


int main(){
	std::string input;
	double AccBalance;
	int amount, choice;
       	std::cout << "--------Welcome to Payment Application--------\n";
	std::cout << "Enter Your current balance: ";
	std::cin >> AccBalance;
	validateInput(AccBalance);
	std::cout << "Enter amount to transfer: ";
	std::cin >> amount;
	validateInput(amount);
	std::cout << "Choose mode of payment: \n1.Card\t2.UPI: ";
	std::cin >> choice;
	Payment *Pptr = nullptr; // Initializing an object pointer of Base class type to point to derived class.
	switch(choice){
		case 1:
			std::cout << "Enter card no: ";
			std::cin >> input;
			validateInput(input);
			Pptr = new Card(input, AccBalance, amount);
			Pptr->processPayment();
			delete Pptr; 
			break;
		case 2:	
			std::cout << "Enter UPI id: ";
			std::cin >> input;
			validateInput(input);
			Pptr = new UPI(input, AccBalance, amount);
			Pptr->processPayment();
			delete Pptr;
			break;
		default:
			std::cout << "Invalid Choice\n";
	}
	return 0;
}
