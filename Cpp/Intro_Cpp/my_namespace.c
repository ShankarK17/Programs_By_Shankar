#include <iostream>
#include "my_namespace.h"

int main(){
	using namespace csm;
	greet();
	int n = incr(5);
	std::cout << n << std::endl;
}


