#include <iostream>
#include <string>

//Defining a class doesn't allocate memory, memory is allocated at the time of object creation
class Student{
	private: //private keyword allows us to keep data unaccessiable from outside of this class.
		// by default a class is set to be private.
		std::string name; //here these variables are data members 
		int rolln;
		int marks;
		static int sum;
	public: //whereas, public keyword means the data or function can be accessed from outside of this class.
		static int stud_count;
		void addData(std::string, int, int); // and these are called member function
		void displayData(){ //defined inside the class itself it might be treated as inline function.
			std::cout << "Student Name: " << name;
			std::cout << "\tRoll no. " << rolln;
			std::cout << "\tMarks obtained: " << marks << "\n";
			sum = 5;
			std::cout << "Sum: " << sum << "\n";
		}


		static float cal_avg(){ // static member function, can be called without an object and can access only static member.
			return (float)sum/stud_count;
		}
	Student(){ // constructor function evoked everytime when an object is created
		stud_count++;
	}
};

// With scope resolution (::) we can define member function and also we can access private members via functions declared inside class.
void Student::addData(std::string stu_Name, int stu_Roll, int stu_marks){
	name = stu_Name;
	rolln = stu_Roll;
	marks = stu_marks;
	sum += marks;
}

int Student::sum = 0;
int Student::stud_count = 0;

int main(){
	Student Std1; // Std1 is an object of class Student
	/*
	 * Memory/space will be allocated for data members of 
	 * every individual objects created, whereas the memory will
	 * be allocated only once for member functions.
	 */
       Std1.addData("Rohan", 16, 48); // Only those data member and member function which are defined public
       Std1.displayData(); // can be accessed via object, private one's can't be accessed.
       
       Student Std2, Std3;
       Std2.addData("Abhijeet", 3, 72);
       Std2.displayData();
       Std3.addData("Manas", 13, 68);
       Std3.displayData();       
       std::cout << "Total Students: " << Student::stud_count << "\n";
       float avg = Student::cal_avg();
       std::cout << "Average Marks: " << avg << "\n";
       return 0;
}


	
