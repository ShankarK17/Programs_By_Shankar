#pragma once
#include <iostream>
#include <string>
class Base{
	public:
		std::string status;
		void startProcess(){
			status = "In progress";
			std::cout << "Process Status: " << status << std::endl;
		}
		Base(){
			startProcess();
		}
		void endProcess(Install& ip);
};


