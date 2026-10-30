#include <iostream>
#include <string>
#include <random>
#include <cstdlib>

class OTP{ // This will be a singleton class the entire system will use this to generate otps
	private:
		static OTP* instance;
		OTP(){} // Constructor
		~OTP(){} //Destructor
	public:
		static OTP* getInstance(){
			if(instance == nullptr){
				instance = new OTP();
				if(instance == nullptr){
					std::cerr << "Couldn't allocate memory";
					std::exit(EXIT_FAILURE);
				}
			}
			return instance;
		}
		OTP(const OTP&) = delete; //disabling copy constructor. 
		OTP& operator=(const OTP&) = delete; // disabling assignment operator(=) for copy via assigning 
						     // also called operator overloading.
		int generateOtp(){
			std::random_device rd;
			std::mt19937 gen(rd());
			std::uniform_int_distribution<int> distrib(1000, 9999);

			return distrib(gen);
		}
};

OTP* OTP::instance = nullptr; 

class Verify{
	protected:
		int otp;
		int checker;
	public:
		virtual void verify(std::string input, int code) = 0; // pure virtual function i.e Abstract class
		virtual ~Verify(){};
};


class Number: public Verify{
	private:
		std::string number;
	public:
		void verify(std::string number, int otp) override{
			this->otp = otp;
			this->number = number;
			std::cout << "Enter OTP: ";
			std::cin >> checker;
			if(this->otp == checker){
				std::cout << "Number "<< this->number << " verified Successful\n";
			}
			else{
				std::cout << "Number verification Failed\n";
			}
		}
};

class Email: public Verify{
	private:
		std::string mail;
	public:
		void verify(std::string mail, int otp) override{
			this->mail = mail;
			this->otp = otp;
			std::cout << "Enter OTP: ";
			std::cin >> checker;
			if(this->otp == checker){
				std::cout << "Email " << this->mail << " verified Successful\n";
			}
			else{
				std::cout << "Email verification failed!\n";
			}
		}
};

class VerifyFactory{ //Factory class reponsible for creating object of the class dynamically based on type provided.
	public:
	Verify* verifyUser(std::string& type){
		if(type == "number" || type == "Number"){
			return new Number();
		}
		if(type == "email" || type == "Email"){
			return new Email();
		}
		else{
			std::cerr << "Invalid option!\n";
			std::exit(EXIT_FAILURE);
			return nullptr;
		}
	}
};

void validateNumber(std::string s){	
		if(s.empty()){
		std::cerr << "cannot be empty\n";
		std::exit(EXIT_FAILURE);
		}
		else if(s.length() != 10){
			std::cerr << "Invalid Phone Number\n";
			std::exit(EXIT_FAILURE);
		}
		else if(s.find(' ') != std::string::npos){
			std::cerr << "cannot contain spaces\n";
			std::exit(EXIT_FAILURE);
		}
}
void validateMail(std::string s){	
		if(s.empty()){
			std::cerr << "cannot be empty\n";
			std::exit(EXIT_FAILURE);
		}
		if(s.find("@gmail.com") != std::string::npos){
		}
		else{
			std::cerr << "Not a valid mail address\n";
			std::exit(EXIT_FAILURE);
		}
		if(s.length() > 30 || s.length() < 15){
			std::cerr << "Length must be > 15 and < 30 \n";
			std::exit(EXIT_FAILURE);
		}
		if(s.find(' ') != std::string::npos){
			std::cerr << "cannot contain spaces\n";
			std::exit(EXIT_FAILURE);
		}
}

int main(){
	std::string choice, input;
	std::cout << "Enter your choice for verification (Number or Emai): ";
	std::getline(std::cin, choice);
	VerifyFactory* vf = new VerifyFactory(); 
	Verify* v = vf->verifyUser(choice);
	std::cout << "Enter here: ";
	std::getline(std::cin, input);
	if(choice == "number" || choice == "Number"){
		validateNumber(input);
	}
	if(choice == "Email" || choice == "email"){
		validateMail(input);
	}
	OTP* otp = OTP::getInstance();
	/*
	OTP* otp2 = OTP::getInstance();
	if(otp == otp2){
		std::cout << "same\n";
	}
	*/
	int code = otp->generateOtp();
	std::cout << "Your otp for verification is " << code << "\n"; 
	v->verify(input, code);
	delete vf;
	delete v;
	v = nullptr;
	return 0;
}
		

		


