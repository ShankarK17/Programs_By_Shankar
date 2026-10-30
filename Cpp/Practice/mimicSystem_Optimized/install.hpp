#pragma once
#include <iostream>
#include <string>
#include "download.hpp"

using namespace std;

class Install:public Download{
	public:
		void startInstall();
		static int getDstatus();
		static int getIstatus();
};
		
