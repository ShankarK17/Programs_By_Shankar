#include <iostream>
#include <string>

using namespace std;

class Base{
	protected:
		int a;
		float b;
		char c;
	public:
		Base(int x1, float x2, char x3){
			a = x1;
			b = x2;
			c = x3;
		}

		virtual void fun(){ //display all three values
			cout << "Base Integer value: " << a << endl;	
			cout << "Base Float value: " << b << endl;	
			cout << "Base Character value: " << c << endl;
		}	
		
};

class Child1: public Base{
	public:
		Child1(int y1, float y2, char y3)
			:Base(y1, y2, y3){}
		
		void fun() override{ //displaying only 2 values
			cout << "Child1 Integer value: " << a << endl;
			cout << "Child1 Float value: " << b << endl;
		}

		void fun(int p, float q, char r){ // same function is overloaded with different parameters
			a = p;
			b = q;
			c = r;
			cout << "Updated child1 Integer value: " << a << endl;
			cout << "Updated child1 Float value: " << b << endl;
			cout << "Updated child1 Character value: " << c << endl;
		}
};

class Child2: public Base{
	public:
		Child2(int z1, float z2, char z3)
			:Base(z1, z2, z3){}
		
		void fun() override{
			cout << "Child2 Float value: " << b << endl;
			cout << "child2 Character value: " << c << endl;
		}
		

		void fun(float s1, char s2){ //overloading the function but only updating float and character value
			b = s1;
			c = s2;
			cout << "child2 Integer value: " << a << endl;
			cout << "child2 Updated Float value: " << b << endl;
			cout << "child2 Updated Character value: " << c << endl;
		}
	
};

int main(){
	/*
	//Base base_obj(1, 1.1, 'a'); 
       	Child1 cld1_obj(2, 2.2, 'b'); //this is static polymorphism or early binding, possible when explicitly 
				      //object is created of that class.
	Base *bptr = nullptr;
	//base_obj.fun();
	cld1_obj.fun(4, 4.4, 'd'); // this fun() with parameters is responsible for updatind the values as well as displaying them
	cld1_obj.fun();// whereas this fun() without parameters just displays the values	
	bptr = new Child2(3, 3.3, 'c');
	if(bptr == nullptr){
		cout << "Not allocated\n";
	}
	*/
	Child2 cld2_obj(5, 5.5, 'z');
	Base *ptr = &cld2_obj;
	ptr->fun(7.7f, 's');
	//bptr->fun();
	//bptr->fun(5.5f, 'e');

	return 0;
}	

	


