#include <iostream>

class Employee{
	private:
		std::string e_name;
		int e_id;
		std::string e_profile;
	public:
		Employee(std::string s){
			e_id = 0;
			e_name = s;
			e_profile = "Intern";
		} // the constructor has been overloaded means the compiler will call the appropriate constructor
		  // based on the arguments passed to it.

		Employee(int id, std::string name, std::string role){ //here this is a parameterized contructor as it accepts 
								      //arguments required for providing initial values for the objects. 
			e_name = name;
			e_id = id;
			e_profile = role;
		}

		void display(){
			std::cout << "Employee Name: " << e_name << "\tEmployee Id: " << e_id << "\tJob Profile: " << e_profile << "\n";
		}
};

int main(){
	Employee e1(101, "Mahesh Arora", "Associate Software Developer");
//	Employee e2; // here if the parameters are not provided so it will throw an error as we have already defined the constructor 
		     // with parameters and compiler won't handle default constructor and cause an error.
	e1.display();
	Employee e3("Arjun Dave");
	e3.display();
//	e2.display();
	return 0;
}

