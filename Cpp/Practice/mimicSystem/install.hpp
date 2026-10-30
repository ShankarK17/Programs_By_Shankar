#pragma once
#include <iostream>
#include <string>
#include "download.hpp"

using namespace std;

class Install:public Download{
	protected:
		string i_status;
	public:
		void startInstall();
};
		
