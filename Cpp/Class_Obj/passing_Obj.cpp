#include <iostream>
#include <string>

class Student{
	private:
		std::string name;
		int marks;
	public:
		void addStu(std::string, int);
		static void checkStu(Student);
};

void Student::addStu(std::string stu_name, int stu_marks){
	name = stu_name;
	marks = stu_marks;
}

void Student::checkStu(Student s){
	if(s.marks < 35){
		std::cout << "Student Name: " << s.name << "\tStatus: Fail\n";
	}
	else{
		std::cout << "Student Name: " << s.name << "\tStatus: Pass\n";
	}
}

int main(){
	Student s[4];
	s[0].addStu("Satyam", 42);
	s[1].addStu("Abhishek", 73);
	s[2].addStu("Rohit", 28);
	s[3].addStu("Manesh", 34);
	for(int i = 0; i<4; i++){
		Student::checkStu(s[i]); // passing the object as value(copy of object is created).
	}

	return 0;
}



			

