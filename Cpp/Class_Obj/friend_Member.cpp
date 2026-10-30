#include <iostream>

class Bank;

class User{
	public:
		void changePin(Bank &);
		void changeAcc(Bank &);
};

class Bank{
	private:
		int acc;
		int balance;
		int pin;
	public:
		void addAcc(int a, int p, int b){
			acc = a;
			pin = p;
			balance = b;
		}
		void displayAcc(){
			std::cout << "Acc no: " << acc << "\tBalance" << balance << "\tPin: " << pin << "\n";
		}
		friend void User::changePin(Bank &); // declare as friend function of Bank, means only this single function
						     // can access private and protected data.
};

void User::changePin(Bank &b){
	int newpin;
	std::cout << "Enter new pin: ";
	std::cin >> newpin;
	b.pin = newpin;
}
/*
void User::changeAcc(Bank &b){
	int demoAcc = 4321;
	b.acc = demoAcc; // cause an error and function changeAcc doesn't have permission to access data of class Bank.
}
*/
int main(){
	Bank b1;
	b1.addAcc(1234, 4444, 500);
	b1.displayAcc();
	User user1;
	user1.changePin(b1);
	b1.displayAcc();
	//user1.changeAcc(b1); can't access data of class Bank as it it not a friend.
	return 0;
}





