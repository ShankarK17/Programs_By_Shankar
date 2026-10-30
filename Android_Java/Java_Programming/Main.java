class Student{
	static int studentCount = 0; // Shared data which is define once in memory and every object shares it.
	String name;
	int id;
	static { // static block it execute first even before the object creation on main starts
		System.out.println("Student Data:- Name\tID");
	}
	
	public Student(String name, int id){
		this.name = name;
		this.id = id;
		studentCount++;
	}

	public void displayStudent(){
		System.out.println("Name: " + name + "\tID: " + id);
	}

	static int getStudentInfo(){ // static function is associated with a class instead of any instance(object).
		return studentCount; // cannot access non-static variables
	}
}

public class Main{
	public static void main(String[] args){
		Student s1 = new Student("Aman", 11);
		Student s2 = new Student("Manav", 14);
		Student s3 = new Student("Sanjay", 28);
		Student s4 = new Student("Vansh", 34);

		s1.displayStudent();
		System.out.println("Total Students : " + Student.getStudentInfo());
	}
}

