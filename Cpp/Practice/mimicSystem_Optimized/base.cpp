#include <iostream>
#include <string>
#include "base.hpp"

using namespace std;

void Base::startProcess(string name){
	process_name = name;
	cout << "Starting process: " << process_name << endl;
	d_status = 1;
}
