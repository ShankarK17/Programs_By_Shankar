#include <iostream>

namespace car{
	namespace engine{
		int hp = 350;
	}
}

int main(){
	// access the element of namespace defined within an another namespace
	std::cout << car::engine::hp << std::endl;
	return 0;
}
