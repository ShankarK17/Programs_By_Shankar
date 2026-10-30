#include <iostream>

class SingleTon{
	private:

		static SingleTon* instance;
		SingleTon(){
			std::cout << "Object Created\n";
		}

	public:
		static SingleTon* getInstance(){
			if(instance == nullptr){
				instance = new SingleTon();
			}
			return instance;
		}
};

SingleTon* SingleTon::instance = nullptr;

int main(){
	SingleTon* s1 = SingleTon::getInstance();
	SingleTon* s2 = SingleTon::getInstance();

	if(s1 == s2){
		std::cout << "Same\n";
	}
	else{
		std::cout << "Not Same!\n";
	}

	return 0;
}	

