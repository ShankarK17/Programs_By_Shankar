#include <iostream>
using namespace std;

template <typename T>

T funDiv(T x, T y){ // generic function, can accept any datatype 
	return x/y;
}

int main(){
	cout << "The division of integers 12 & 6 is " << funDiv<int>(12,6) << endl; // we can either pass <datatype> along with the function call
										    // or we can omit it as well the compiler will decide based on arguments
	cout << "The division of floats 15.1 & 3.4 is " << funDiv(15.1f, 3.4f) << endl;
	cout << "The division of doubles 17.2 & 4.8 is " << funDiv(17.2, 4.8) << endl;
	return 0;
}
