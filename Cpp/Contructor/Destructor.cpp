#include <iostream>
#include <cstring>
class Data{
	private:
		char *name;
	public:
		Data(const char *s){
			name = new char[strlen(s) + 1];
			strcpy(name, s);
			std::cout << "Name entered: " << name << "\n";
		}
		~Data(){
			std::cout << "Deleting name... " << name << "\n";
			delete[] name;
			std::cout << "Name deleted Successfully \n";
		}
};

int main(){
	Data d1("Rajesh");
	Data d2("Sachin");
	return 0;
}
