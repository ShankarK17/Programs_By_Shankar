#pragma once
#include <iostream>
#include <string>
#include "base.hpp"

using namespace std;

class Download: public Base{
	protected:
		string d_status;
	public:
		void startDownload();
};

