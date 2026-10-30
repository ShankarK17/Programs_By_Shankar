class Vehicle{
	String model;
	int year;
	public Vehicle(String model, int year){
		this.model = model;
		this.year = year;
	}

	public final void displayInfo(){ // method which is marked final cannot be overriden in inherited classes
		System.out.println("Vehicle Model: " + model + "\tVehicle Year: " + year);
	}
}

class Car extends Vehicle{ // entends keyword use to inherit class 
	int top_speed;
	public Car(String model, int year, int top_speed){
		super(model, year);
		this.top_speed = top_speed;
	}
	/*public void displayInfo(){ // this will throw an error as final method cannot be override 
	       System.out.println("Car Model: " + model + "Car Year: " + year + "Top Speed: " + top_speed);
	}*/
}

class Final_Class_Method{
	public static void main(String[] args){
		Car car_obj = new Car("Mustang", 1989, 273);
		car_obj.displayInfo();
	}
}
