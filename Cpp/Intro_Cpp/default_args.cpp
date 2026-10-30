#include <iostream>

//Here, this function will keep the default value of b as 2,
//and if the value is passed as argument for b the that values will be assigned

int power(int a, int b = 2){
/*int power(int a = 2, int b) this will cause an error bcoz default args are evaluated/assigned right to left and not left to right*/
	int sum = 1;
	for(int i = 0; i<b; i++){
		sum *= a;
	}
	return sum;
}

int main(){
	using namespace std;
	cout << power(2) << endl; // when only 1 argument is passed the default value for b will be 2.
				  // as when function is called values are assigned left to right.
	cout << power(2, 3) << endl; //here two arguments are passed means the value of b will be assigned as passed. 
	cout << power(5, 4) << endl;  

	return 0;
}
	



