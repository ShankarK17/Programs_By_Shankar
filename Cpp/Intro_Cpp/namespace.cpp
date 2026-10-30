#include <iostream>

namespace FileA{
	void display();
}

namespace FileB{
	void display();
}

int main(){
	//without namespace this would cause an naming conflict error 
	//but with namespace we can use objects with same name as long as they are within different namespaces
	FileA::display();
	FileB::display();	
	return 0;
}
