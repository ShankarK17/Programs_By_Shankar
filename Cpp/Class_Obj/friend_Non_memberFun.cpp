#include <iostream>
#include <cstdlib>
class Income{
	private:
		int tax = 18;
		int salary;
	public:
		void addIncome(int amount){
			salary = amount;
		}
		friend double cal_tax(Income);
};

double cal_tax(Income i){
	double tax_deduct = (double)i.tax / 100 * i.salary;
	double final_sum = (double)i.salary - tax_deduct; 
	return final_sum;
}
		

int main(){
	int base_sal;
	std::cout << "Enter your salary: ";
	std::cin >> base_sal;
	if(base_sal <= 0){
		std::cerr << "Invalid input entered\n";
		std::exit(EXIT_FAILURE);
	}
	Income i1;
	i1.addIncome(base_sal);
	double in_hand = cal_tax(i1);
	std::cout << "Your in-hand salary after tax deduction will be " << in_hand << "\n";
	return 0;
}

