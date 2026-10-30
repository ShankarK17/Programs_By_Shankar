#include <iostream>
#include <string>

using namespace std;

template <class T, class U> // we can write typename or class both can be used interchangeably
/*
class Data{
	private:
		T data;
	public:
		void setData(T x){
			data = x;
		}
		void getData(){
			cout << "Data is " << data << endl;
		}
};
*/
class MyClass{ // we can create class with generic data members as well as primitive types
	private:
		T data1;
		U data2;
		char data3;
		float data4;
	public:
		MyClass(T a, U b, char c, float d){
			data1 = a;
			data2 = b;
			data3 = c;
			data4 = d;
		}
		void printData(){
			cout << "Data1: " << data1 << endl;
			cout << "Data2: " << data2 << endl;
			cout << "Data3: " << data3 << endl;
			cout << "Data4: " << data4 << endl;
		}
};


int main(){
	/*
	Data<int> obj1; // object is created with datatype int
	obj1.setData(5);
	obj1.getData();

	Data<string> obj2;
	obj2.setData("Shanks");
	obj2.getData();
	*/
	MyClass<int,string> obj1(12, "Aman", 'd', 4.3f); // datatypes of T & U can we specify here
	obj1.printData();

	MyClass obj2("Shanks", 12, 'c', 3.9f); //order changed otherwise we have to pass arguments in strict order
	obj2.printData();

	return 0;
}


