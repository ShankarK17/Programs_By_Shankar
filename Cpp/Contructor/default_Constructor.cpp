#include <iostream>

class Student{
	private:
		int rolln;
		std::string name;
	public:
		/*
		Student(){ // This is called the default constructor, a special member function envoked when an object is created of it's
			   // class, the name of constructor is same as class. If we don't constructor function the compiler do this work.
			   // Default constructor doesn't accept any arguments and don't return either. If we create object without defining
			   // constuctor, compiler will assign garbage value to variables except the string variable.
			rolln = 0;
			name = "John Doe";
		}
		*/
		void display(){
			std::cout << "Roll No: " << rolln << "\tName: " << name << "\n";
		}
};

int main(){
	Student s1, s2, s3;
	s1.display();
	s3.display();
	return 0;
}
