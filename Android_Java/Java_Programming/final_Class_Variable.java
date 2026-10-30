class Student{
	final int id; // if a class variable is marked final it must be initialised at the time of object
		      // creation otherwise compiler with throw an error 
	public Student(int id){
		this.id = id; // final variable must be initialized immediately
	}
	public void display(){
		System.out.println("ID: " + id);
	}
}


class Final_Class_Variable{
	public static void main(String[] args){
		Student Std1 = new Student(); // object creation + initialization
		Std1.display();
	}
}

