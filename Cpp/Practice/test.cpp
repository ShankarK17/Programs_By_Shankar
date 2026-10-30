#include <iostream>
#include <string>
using namespace std;

class MyClass{
	public:
		static int count;
	private:
		int func(){
			return count;
		}
};

int MyClass::count = 0;

int main(){
	MyClass obj1;
	cout << "Size of Object: " << sizeof(obj1) << endl;
	cout << "Size of Class: " << sizeof(MyClass) << endl;
	return 0;
}
