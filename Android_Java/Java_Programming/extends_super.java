class Parent{
	public void display(){
		System.out.println("Parent Display Method");
	}
}

class Child extends Parent{
	@Override public void display(){
		super.display(); // referes to the display method of Parent, with super keyword we can
				 // get access or point to parents attributes
		System.out.println("Child display Method");
	}

	public static void main(String[] args){
		Child cldObj = new Child();
		cldObj.display();		
	}

}
