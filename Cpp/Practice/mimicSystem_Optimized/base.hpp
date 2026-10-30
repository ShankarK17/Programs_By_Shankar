#pragma once
#include <iostream>
#include <string>

using namespace std;

class Base{
	protected:
		string process_name;
		static int d_status;
		static int i_status;
	public:
		void startProcess(string);
		virtual void startDownload() = 0;
};


