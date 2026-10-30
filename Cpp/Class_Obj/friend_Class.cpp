#include <iostream>
#include <string>
#include <cstdlib>
class ForgetPassword; // declaration to avoid undefined error

class UserInfo{
	private:
		std::string username;
		std::string password;
	public:
		void addUser(std::string, std::string);
		friend class ForgetPassword; // friend class can access private and protected members of class in which it it set friend
					     // but be-friend class cannot access private or protected members of friend class,
					     // bcoz friendship is not always mutual.
		void displayUser(){
			std::cout << "Username: " << username << "\tPassword: " << password << "\n";
		}
};

class ForgetPassword{ //class ForgetPassword can access members of class UnserInfo as it is a friend of it.
	public:
		void setPassword(UserInfo &);
};

void UserInfo::addUser(std::string u, std::string p){
	username = u;
	password = p;
}

void checkCredential(std::string s){
	if(s.empty()){
		std::cerr << "cannot be empty\n";
		std::exit(EXIT_FAILURE);
	}

	if(s.length() > 20){
		std::cerr << "lenght cannot be > 20\n";
		std::exit(EXIT_FAILURE);
	}

	if(s.find(' ') != std::string::npos){
		std::cerr << "cannot contain spaces\n";
		std::exit(EXIT_FAILURE);
	}
}



void ForgetPassword::setPassword(UserInfo &user){
	std::string newpass;
	std::cout << "Enter new password: ";
	std::getline(std::cin, newpass);
	checkCredential(newpass);
	if(newpass == user.password){
		std::cerr << "New password cannot be same as old one\n";
		std::exit(EXIT_FAILURE);
	}
	user.password = newpass;
	std::cout << "Password changed Successfully\n";
}


int main(){
	std::string usern, pass;
	std::cout << "Enter username: ";
	std::getline(std::cin, usern);
	checkCredential(usern);
	std::cout << "Enter password: ";
	std::getline(std::cin, pass);
	checkCredential(pass);
	UserInfo user1;
	user1.addUser(usern, pass);
	user1.displayUser();
	ForgetPassword fuser1;
	fuser1.setPassword(user1);
	user1.displayUser();

	return 0;
}

