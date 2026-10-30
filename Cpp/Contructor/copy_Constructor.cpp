#include <iostream>
#include <cstring>

class MyClass{
	char *name;
	public:
		MyClass(const char *n){
			name = new char[strlen(n) + 1];
			strcpy(name, n);
		}
		// This is a copy constructor that too a shallow copy constructor means it's just that they both point 
		// to the same object which seems like they are copied.
		/*Shallow copy 
		MyClass(const MyClass &other){
			name = other.name;
		}
		*/
		MyClass(const MyClass &other){
			name = new char[strlen(other.name) + 1];
			strcpy(name, other.name);
		}

		~MyClass(){
			delete[] name;
		}

