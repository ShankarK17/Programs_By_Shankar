#include <iostream>

using namespace std;

class Class{
	public:
		int data1; //Non-static data member can only be accessed by non-static functions and not by static member function
		static float data2; // static data member can be accessed by static as well as non-static functions
		Class(int data1){
			this->data1 = data1;
		}
		void setData2(float fvalue){
			data2 = fvalue;
		}
};

float Class::data2 = 0.0;

int main(){
	Class obj(12);
	obj.setData2(3.14f);
	cout << obj.data2 << endl;
	return 0;
}


