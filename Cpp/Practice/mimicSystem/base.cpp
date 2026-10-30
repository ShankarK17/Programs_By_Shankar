#include <iostream>
#include <string>
#include "base.hpp"

using namespace std;

void Base::startProcess(string name){
	process_name = name;
	b_status = "In progress";
	cout << "Starting process: " << process_name << endl;
	cout << "Process Status: " << b_status << endl;
}
