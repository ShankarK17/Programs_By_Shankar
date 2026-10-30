#include <iostream>
#include <cstring>

using namespace std;

class A{
	protected:
		char* name;

	public:
		A(const char* input){
			cout << "Class A Constructor Activates\n";
			int len = strlen(input);
			name = new char[len+1];
			if(name == nullptr){
				cerr << "Not memory\n";
				exit(EXIT_FAILURE);
			}
			strcpy(name, input);
		}
		~A(){
			delete[] name;
		}
		const char* getName(){
			return name;
		}
};

class B: virtual public A{
	public:
		B(const char* binput)
			:A(binput){
				cout << "Class B Construtor Activates\n";
		}
};

class C: virtual public A{
	public:
		C(const char* cinput)
			:A(cinput){
				cout << "Class C Constructor Activates\n";
			}
};

class D: public B, public C{
	public:
		D(const char* dinput)
			:B(dinput), C(dinput), A(dinput){
			cout << "Class D Constructor Activates\n";
		}
};

int main(){
	D obj("John Cena");
	cout << "And the name is " << obj.getName() << endl;
	return 0;
}


	
