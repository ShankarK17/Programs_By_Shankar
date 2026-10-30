abstract class Living_Being{ // abstract class it's cannot be instansize (object creation) must be inherited to 
			     // use the attributes
	int life_span;
	String species;
	/*
	 * Can have constructor as well as regular methods
	 * to initialize inherited attributes unless
	 * define private
	 */
	public Living_Being(String name, int age){
		species = name;
		life_span = age;
	}
	public void display(){
		System.out.println("Species Name: " + species + " " + "Life Span(in Years): " + life_span);
	}
	public abstract void breathing(); // abstract method means it must be override in 
					  // inherited class to avoid being abstract subclasses
}

class Human extends Living_Being{
	int limbs;
	public Human(String name, int span, int parts){
		super(name, span);
		limbs = parts;
	}
	@Override public void breathing(){ //Overriding breathing method to avoid being abstract class
		System.out.println("Human Breathing...");
	}
}

class Abstract{
	public static void main(String[] args){
		//Living_Being octopus = new Living_Being("Octopus", 40); will coz an error
		Human man = new Human("Home Sapiens", 85, 4);
		man.breathing();
		man.display(); // not overrided, will refer to method of parent class
	}
}

	

